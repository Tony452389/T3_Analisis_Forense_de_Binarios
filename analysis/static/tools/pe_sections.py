import pefile
import os
import sys

def main():
    if len(sys.argv) < 2:
        print("Usage: python pe_sections.py <binary_path>")
        
        return
        
    binary_path = sys.argv[1]
    
    if not os.path.exists(binary_path):
        print("File not found.")
        
        return
        
    pe = pefile.PE(binary_path)
    
    output_dir = "outputs/static-analysis"
    os.makedirs(output_dir, exist_ok = True)
    
    output_path = os.path.join(
        output_dir,
        "sections_output.txt"
    )
    
    with open(output_path, "w", encoding = "utf-8") as f:
        f.write("=== PE SECTIONS ===\n\n")
        
        for section in pe.sections:
            name = section.Name.decode().strip('\x00')
            
            f.write(f"Section: {name}\n")
            f.write(f" Virtual Address: {hex(section.VirtualAddress)}\n")
            f.write(f" Virtual Size: {hex(section.Misc_VirtualSize)}\n")
            f.write(f" Raw Size: {hex(section.SizeOfRawData)}\n")
            f.write(f" Characteristics: {hex(section.Characteristics)}\n")
            f.write("\n")
            
    print("")        
    print("[+] Sections Extracted Successfully")
    print(f"[+] Total Sections: {len(pe.sections)}")
    print(f"[+] Output Saved to: {output_path}")
    
if __name__ == "__main__":
    main()
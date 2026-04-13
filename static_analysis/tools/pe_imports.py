import pefile
import os
import sys

def main():
    if len(sys.argv) < 2:
        print("Usage: python pe_imports.py <binary_path>")
        
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
        "imports_output.txt"
    )
    
    total_imports = 0
    
    with open(output_path, "w", encoding = "utf-8") as f:
        f.write("=== IMPORT TABLE ===\n\n")
        
        if hasattr(pe, 'DIRECTORY_ENTRY_IMPORT'):
            for entry in pe.DIRECTORY_ENTRY_IMPORT:
                dll_name = entry.dll.decode()
                
                f.write(f"[DLL] {dll_name}\n")

                for imp in entry.imports:
                    if imp.name:
                        func_name = imp.name.decode()
                        f.write(f"  {func_name}\n")
                        total_imports += 1
                        
                f.write("\n")
    
    print("")        
    print("[+] Imports Extracted Successfully")
    print(f"[+] Total Imported Functions: {total_imports}")
    print(f"[+] Output Saved to: {output_path}")
    
if __name__ == "__main__":
    main()
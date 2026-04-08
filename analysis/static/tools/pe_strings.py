import re
import sys
import os

def extract_ascii_strings(data, min_length = 4):
    pattern = rb"[ -~]{" + str(min_length).encode() + rb",}"
    
    return re.findall(pattern, data)
    
def extract_unicode_strings(data, min_length = 4):
    pattern = rb"(?:[ -~]\x00){" + str(min_length).encode() + rb",}"
    results = re.findall(pattern, data)
    
    return [s.decode("utf-16le") for s in results]
    
def main():
    if len(sys.argv) < 2:
        print("Usage: python pe_strings.py <binary_path>")
        
        return
        
    binary_path = sys.argv[1]
    
    if not os.path.exists(binary_path):
        print("File not found.")
        
        return
        
    with open(binary_path, "rb") as f:
        data = f.read()
        
    ascii_strings = extract_ascii_strings(data)
    unicode_strings = extract_unicode_strings(data)
    
    output_dir = "outputs/static-analysis"
    os.makedirs(output_dir, exist_ok = True)
    
    output_path = os.path.join(
        output_dir,
        "strings_output.txt"
    )
    
    with open(output_path, "w", encoding = "utf-8") as out:
        out.write("=== ASCII STRINGS ===\n\n")
        
        for s in ascii_strings:
            out.write(s.decode(errors = "ignore") + "\n")
        
        out.write("\n=== UNICODE STRINGS ===\n\n")
        
        for s in unicode_strings:
            out.write(s + "\n")
    
    print("")
    print("[+] Strings Extracted Successfully")
    print(f"[+] ASCII Strings: {len(ascii_strings)}")
    print(f"[+] Unicode Strings: {len(unicode_strings)}")
    print(f"[+] Output Saved to: {output_path}")
    
    
if __name__ == "__main__":
    main()
import sys
from BusinessCardParser import BusinessCardParser
from ContactInfo import ContactInfo

def main():
    if len(sys.argv) != 2:
        print("usage:", sys.argv[0], "<filename>")
        return 1
    # read from file
    input = open(sys.argv[1], "r")
    total = input.read()
    print(total)

    # parse file
    bcp = BusinessCardParser()
    ci = bcp.getContactInfo(total)

    print("==>\n")
    
    print("Name:", ci.getName)
    print("Phone:", ci.getPhoneNumber)
    print("Email:", ci.getEmailAddress)
main()
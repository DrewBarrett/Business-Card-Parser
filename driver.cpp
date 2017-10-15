/*********
 *
 * Driver.cpp
 *
 * This file reads input and then retrieves parsed output
 *
 ********/

#include <iostream>
#include <fstream>
#include "BusinessCardParser.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    
    // Read from file
    ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        cout << "Unable to read file\n";
        return 2;
    }
    string tmp;
    string total = "";
    while (getline(input, tmp)) {
        total += tmp + '\n';
    }
    input.close();

    // Parse file
    cout << total << endl; 
    BusinessCardParser bcp = BusinessCardParser();
    ContactInfo ci = bcp.getContactInfo(total);

    cout << "==>\n\n";

    cout << "Name: " << ci.getName() << endl;
    cout << "Phone: " << ci.getPhoneNumber() << endl;
    cout << "Email: " << ci.getEmailAddress() << endl;

    return 0;
}

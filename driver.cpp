/*********
 *
 * Driver.cpp
 *
 * This file reads input and then retrieves parsed output
 *
 ********/

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    return 0;
}

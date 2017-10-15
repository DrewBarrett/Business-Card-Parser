#include "ContactInfo.h"
#include <regex>
#include <vector>
#include <cstddef>
#include <iostream>

ContactInfo::ContactInfo(string document) {
    // Parse document into variables
    smatch match;
    
    // pull phone number and any surrounding chars
    regex e ("\\n.*[[:d:]]?.*[[:d:]]{3}.*[[:d:]]{3}.*[[:d:]]{4}\\n");
    regex_search(document, match, e);
    string tmpPhone = match.str();

    // pull all numbers out of raw phone number string ie (, -
    while( regex_search(tmpPhone, match, regex("[[:d:]]")) ) {
        for(auto tmp : match)
        {
            m_phone += tmp.str();
        }
        tmpPhone = match.suffix().str();
    }
    
    // pull email
    e = "\\S+@.+";
    regex_search(document, match, e);
    m_email = match.str();

    // pull name (Word + space + Word)
    vector<string> names;
    e = "\\w+\\s+\\w+\\n";
    while( regex_search(document, match, e) ) {
        for(auto tmp : match)
        {
            names.push_back(tmp.str());
        }
        document = match.suffix().str();
    }

    // loop over possible names and pull the one that best matches 
    // their email username
    string uname = m_email.substr(0, m_email.find("@"));
    m_name = uname;
    string bestMatch = "";
    int bestMatchCount = 0;
    for(auto tmp : names)
    {
        cout << tmp << endl;
        string orig = tmp;
        string username = uname;
        int count = 0;
        size_t found = username.find_first_of(tmp);
        while (found != string::npos) {
            username.erase(found, 1);
            tmp.erase(0,1);
            found = username.find_first_of(tmp);
            count++;
        }
        cout << count << endl;
        if (count >= bestMatchCount) {
            bestMatchCount = count;
            bestMatch = orig; 
        }
    }
    m_name = bestMatch;
}
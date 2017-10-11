#ifndef CONTACTINFO_H
#define CONTACTINFO_H

/*********
 * Class ContactInfo
 *
 * This class parses a string that it is constructed with and then provides 
 * accessors to the data parsed
 *
 *********/

class ContactInfo
{
private:
    string m_name;
    string m_phone;
    string m_email;

public:
    // Constructor
    // Takes string and parses it
    ContactInfo(string document);
    
    /********
     *
     * Getters
     *
     ********/
    string getName() {
        return m_name;
    }
    string getPhoneNumber() {
        return m_phone;
    }
    string getEmailAddress() {
        return m_email;
    }

};

#endif /* CONTACTINFO_H */

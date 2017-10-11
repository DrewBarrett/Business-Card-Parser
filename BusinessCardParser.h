#ifndef _BUSINESS_CARD_PARSER_H_
#define _BUSINESS_CARD_PARSER_H_

/*****
 * BusinessCardParser.h
 *
 * This class is responsible for taking a string and returning a instance of
 * ContactInfo
 *
 *****/
#include "ContactInfo.h"

class BusinessCardParser
{
private:
    

public:
    // Constructor does nothing
    BusinessCardParser() {};

    // getContactInfo()
    // Takes string input and returns an instance of ContactInfo
    getContactInfo(string document);
};


#endif /* ifndef _BUSIN */

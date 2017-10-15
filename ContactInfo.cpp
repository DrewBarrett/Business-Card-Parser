#include "ContactInfo.h"
#include <regex>

ContactInfo::ContactInfo(string document) {
    // Parse document into variables
    smatch match;
    regex e ("[[:d:]]+");
    regex_search(document, match, e);
    m_phone = match.str();
}

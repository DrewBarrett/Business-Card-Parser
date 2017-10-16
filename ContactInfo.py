import re
import difflib

class ContactInfo:
    def __init__(self, document):
        # search for phone number
        search = re.compile('^.*\\d?.*\\d{3}.*\\d{3}.*\\d{4}$', re.MULTILINE)
        match = re.search(search, document)

        # pull out numbers (get rid of - and stuff)
        match = re.findall('\\d', match.group(0))
        self.m_phone = ''.join(match) # turn array into string

        # pull email
        search = re.compile('\\S+@.+', re.MULTILINE)
        match = re.search(search, document)
        self.m_email = match.group(0)

        #pull name
        search = re.compile('^\\w+\\s+\\w+$', re.MULTILINE)
        match = re.findall(search, document)
        match = [x.lower() for x in match]
        username = self.m_email[:self.m_email.find('@')]
        matches = difflib.get_close_matches(username, match)
        self.m_name = matches[0].title()



    @property
    def getName(self):
        return self.m_name

    @property
    def getPhoneNumber(self):
        return self.m_phone

    @property
    def getEmailAddress(self):
        return self.m_email
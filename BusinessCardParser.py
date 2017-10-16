from ContactInfo import ContactInfo

class BusinessCardParser:
    def getContactInfo(self, document):
        return ContactInfo(document=document)
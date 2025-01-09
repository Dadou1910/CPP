#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact Contacts[8];
    int OldestIndex;
    int TotalContacts;

public:
    PhoneBook();
    void AddContact();
    void SearchContacts() const;
};

#endif

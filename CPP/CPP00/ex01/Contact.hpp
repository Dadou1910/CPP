#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    Contact();
    void SetContact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds);
    void DisplaySummary(int index) const;
    void DisplayDetails() const;
};

#endif
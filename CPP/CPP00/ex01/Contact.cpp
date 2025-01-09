# include "Contact.hpp"

Contact::Contact() {}

void Contact::SetContact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds)
{
    FirstName = fn;
    LastName = ln;
    Nickname = nn;
    PhoneNumber = pn;
    DarkestSecret = ds;
}

void Contact::DisplaySummary(int index) const
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (FirstName.length() > 10 ? FirstName.substr(0, 9) + "." : FirstName) << "|"
              << std::setw(10) << (LastName.length() > 10 ? LastName.substr(0, 9) + "." : LastName) << "|"
              << std::setw(10) << (Nickname.length() > 10 ? Nickname.substr(0, 9) + "." : Nickname) << std::endl;
}

void Contact::DisplayDetails() const
{
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "Nickname: " << Nickname << std::endl;
    std::cout << "Phone Number: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}
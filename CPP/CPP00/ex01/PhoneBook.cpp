# include "PhoneBook.hpp"

PhoneBook::PhoneBook() : OldestIndex(0), TotalContacts(0) {}

void PhoneBook::AddContact()
{
    std::string fn, ln, nn, pn, ds;

    std::cout << "First Name: ";
    std::getline(std::cin, fn);
    std::cout << "Last Name: ";
    std::getline(std::cin, ln);
    std::cout << "Nickname: ";
    std::getline(std::cin, nn);
    std::cout << "Phone Number: ";
    std::getline(std::cin, pn);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, ds);
    if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
    {
        std::cout << "Error: No field can be empty." << std::endl;
        return;
    }
    Contacts[OldestIndex].SetContact(fn, ln, nn, pn, ds);
    OldestIndex = (OldestIndex + 1) % 8;
    if (TotalContacts < 8)
        TotalContacts++;
}

void PhoneBook::SearchContacts() const
{
    if (TotalContacts == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < TotalContacts; ++i)
        Contacts[i].DisplaySummary(i);
    std::string input;
    while (true)
    {
        std::cout << "Enter index (or press ENTER to cancel): ";
        std::getline(std::cin, input);
        if (input.empty())
            break;
        bool valid = true;
        for (size_t i = 0; i < input.length(); ++i)
        {
            if (!std::isdigit(input[i]))
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            int index = 0;
            for (size_t i = 0; i < input.length(); ++i)
                index = index * 10 + (input[i] - '0');
            if (index >= 0 && index < TotalContacts)
            {
                Contacts[index].DisplayDetails();
                break;
            }
        }
        std::cout << "Invalid index. Try again or press ENTER to cancel." << std::endl;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.AddContact();
        else if (command == "SEARCH")
            phoneBook.SearchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }

    return 0;
}
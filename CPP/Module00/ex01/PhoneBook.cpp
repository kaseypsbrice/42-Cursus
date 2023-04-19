#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->is_full = 0;
	return ;
}

Contact	PhoneBook::getContact(int index)
{
	return this->contact[index];
}

int	PhoneBook::getFull(void)
{
	return (this->is_full);
}

std::string PhoneBook::truncate(std::string str)
{
        if (str.length() <= 10)
                return (str);
        str = str.substr(0, 8);
        str.append(".");
        return (str);
}

int	PhoneBook::getIndex()
{
	return this->index;
}

void	PhoneBook::addContact(Contact contact)
{
	if (this->index == 8)
	{
		this->is_full = 1;
		this->index = 0;
	}
	this->contact[index] = contact;
	this->index++;
}

void    PhoneBook::divider()
{
        std::cout << std::setfill('-');
        for (int underscore = 0; underscore < 4; ++underscore)
                std::cout << "+" << std::setw(10) << "";
        std::cout << "+" << std::endl << std::setfill(' ');
}

void	PhoneBook::header()
{
        divider();
        std::cout << "|" << std::setw(10) << "Index";
        std::cout << "|" << std::setw(10) << "First Name";
        std::cout << "|" << std::setw(10) << "Last Name";
        std::cout << "|" << std::setw(10) << "Nickname";
        std::cout << "|" << std::endl;
        divider();
}

void	PhoneBook::printContact()
{
	int	j;
	
	if (is_full == 1)
		j = 8;
	else
		j = this->index;
	for (int i = 0; i < j; i++)
	{
                std::cout << "|" << std::setw(10) << i + 1 << std::flush;
                std::cout << "|" << std::setw(10) << truncate(this->contact[i].getFirstName()) << std::flush;
                std::cout << "|" << std::setw(10) << truncate(this->contact[i].getLastName()) << std::flush;
                std::cout << "|" << std::setw(10) << truncate(this->contact[i].getNickname()) << std::flush;
                std::cout << "|" << std::endl;
                divider();
	}
}

void	PhoneBook::errorMessage(void)
{
        std::cout << "\e[0;31m[!]\e[0m Blank input is not allowed." << std::endl;
        std::cout << "\e[1mPlease enter valid details: \e[0m" << std::endl;
}

bool    PhoneBook::isOnlySpaces(const std::string& str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            return false;
        }
        i++;
    }
    return true;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

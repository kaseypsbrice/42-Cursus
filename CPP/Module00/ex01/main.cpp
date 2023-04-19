#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <sstream>

int	main()
{
	std::string	cmd;
	PhoneBook	phonebook;
	Contact		contact;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	int			index;

	system("clear");
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Use one of the following commands:" << std::endl;
	std::cout << "ADD : adds a contact" << std::endl;
	std::cout << "SEARCH : searches for a contact using it's index" << std::endl;
	std::cout << "EXIT : exits the program" << std::endl;
	while (!std::cin.eof())
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			std::cout << "FirstName:" << std::endl;
			std::getline(std::cin, firstName);
			while (firstName.empty() || phonebook.isOnlySpaces(firstName))
			{
				phonebook.errorMessage();
				std::getline(std::cin, firstName);
			}
			contact.addFirstName(firstName);
			std::cout << "LastName:" << std::endl;
			std::getline(std::cin, lastName);
			while (lastName.empty() || phonebook.isOnlySpaces(lastName))
			{
				phonebook.errorMessage();
				std::getline(std::cin, lastName);
			}
			contact.addlastName(lastName);
			std::cout << "Nickname:" << std::endl;
			std::getline(std::cin, nickName);
        		while (nickName.empty() || phonebook.isOnlySpaces(nickName))
			{
				phonebook.errorMessage();
				std::getline(std::cin, nickName);
			}
			contact.addNickname(nickName);
			std::cout << "Phone Number:" << std::endl;
			std::getline(std::cin, phoneNumber);
			while (phoneNumber.empty() || phonebook.isOnlySpaces(phoneNumber))
			{
				phonebook.errorMessage();
				std::getline(std::cin, phoneNumber);
			}
			contact.addPhoneNumber(phoneNumber);
			std::cout << "DarkestSecret:" << std::endl;
			std::getline(std::cin, darkestSecret);
			while (darkestSecret.empty() || phonebook.isOnlySpaces(darkestSecret))
			{
				phonebook.errorMessage();
				std::getline(std::cin, darkestSecret);
			}
			contact.addDarkestSecret(darkestSecret);
			phonebook.addContact(contact);
			std::cout << "Enter a command (ADD, SEARCH or EXIT)" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			phonebook.header();
			phonebook.printContact();
			while (std::cin.good() == 1)
			{
				std::cout << "Contact index :" << std::endl;
				std::string	input;
				std::getline(std::cin, input);

				std::stringstream stream(input);
				if (stream >> index && stream.eof())
				{
					if ((index < phonebook.getIndex() + 1 || phonebook.getFull() == 1) && index <= 8 && index > 0)
					{
						std::cout << "Firstname:" + phonebook.getContact(index - 1).getFirstName() << std::endl;
						std::cout << "LastName:" + phonebook.getContact(index - 1).getLastName() << std::endl;
						std::cout << "Nickname:" + phonebook.getContact(index - 1).getNickname() << std::endl;
						std::cout << "PhoneNumber:" + phonebook.getContact(index - 1).getPhoneNumber() << std::endl;
						std::cout << "DarkestSecret:" + phonebook.getContact(index - 1).getDarkestSecret() << std::endl;
						std::cout << "Enter a command (ADD, SEARCH or EXIT)" << std::endl;
						break;
					}
					else
					{
						std::cout << "\e[0;31m[!]\e[0m Index error. Undefined contact. The number entered does not exist." << std:: endl;
						std::cout << "Enter a command (ADD, SEARCH or EXIT)" << std:: endl;
						break ;
					}
					
				}
				else 
				{
					std::cout << "\e[0;31m[!]\e[0m Index error. You have entered a character or space instead of a valid index number." << std:: endl;
					std::cout << "Enter a command (ADD, SEARCH or EXIT)" << std:: endl;
					break ;
				}
			}
		}
		else if (cmd == "EXIT")
			return (0);
		else if (cmd != "EXIT" || cmd != "ADD" || cmd != "SEARCH")
			std::cout << "\e[0;31m[!]\e[0m You must enter one of the commands: ADD, SEARCH or EXIT." << std:: endl;
	}
	return (0);
}

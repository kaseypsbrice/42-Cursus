#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		addContact(Contact contact);
		int			getIndex();
		void		printContact();
		Contact		getContact(int index);
		int			getFull(void);
		void		divider();
		void		header();
		void		errorMessage(void);
		bool		isOnlySpaces(const std::string& str);

	private:
		int			index;
		Contact		contact[8];
		int			is_full;
		std::string	truncate(std::string str);

};

#endif

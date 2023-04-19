#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		addFirstName(std::string);
		void		addlastName(std::string);
		void		addNickname(std::string);
		void		addPhoneNumber(std::string);
		void		addDarkestSecret(std::string);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif

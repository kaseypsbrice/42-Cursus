#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	std::string	current_arg;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		current_arg = argv[i];
		int	len = current_arg.length();
		if (i > 1)
		{
			std::cout << " ";
		}
		for (int j = 0; j < len; j++)
		{
			std::cout << (char)(toupper(current_arg[j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
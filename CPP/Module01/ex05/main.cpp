#include "Harl.hpp"

int main()
{
    std::string input;
    Harl        harl;

    do
    {
        std::cout << "Enter one of the following levels (in all caps) or type EXIT to leave the program" << std::endl;
        std::cout << "DEBUG | INFO | WARNING | ERROR" << std::endl;
        std::cout << "Enter a level:" << std::endl;
        std::cin >> input;
        if (input == "EXIT")
            return (EXIT_SUCCESS);
        harl.complain(input);
    } while (input != "EXIT");

    return (EXIT_SUCCESS);
}
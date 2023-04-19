#include "Replace.hpp"

static void   replaceString(std::string& str, const std::string& s1, const std::string& s2)
{
    size_t start = 0;
    while ((start = str.find(s1, start)) != std::string::npos)
    {
        str.erase(start, s1.length());
        str.insert(start, s2);
        start += s2.length();
    }
}
// Uses 'find' to find the starting position of s1.
// 'erase' is used to remove the old substring from the original string
// and then 'insert' inserts the new substring in the same position.
// References are used so that the function can modify the parameters passed
// without having to return a new string.
// s1 & s2 are passed as consts because they are not supposed to be modified.
// It's an extra precaution / just good practice :)

static void    modFileCopy(Replace& replace_o, const std::string& filename)
{
    std::ifstream ifile(filename);
    if (!ifile.is_open())
    {
        std::cerr << "Error: cannot open input file " << filename << std::endl;
        return ;
    }
    std::ofstream ofile(replace_o.getFilename());
    if (!ofile.is_open())
    {
        std::cerr << "Error: cannot open output file " << replace_o.getFilename() << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(ifile, line))
    {
        replaceString(line, replace_o.getStr1(), replace_o.getStr2());
        ofile << line << std::endl;
    }
    std::cout << "Modified duplicate of the file has been created." << std::endl;

    ifile.close();
    ofile.close();
}
// Attempts to open the file through an ifstream object. If the file cannot
// be opened, it will print an error using the cerr output (commonly used for
// error messages, that way you can differentiate them from the standard output
// messages). If the file is successfully opened, it uses an ofstream object to
// write to the output file. If the output file cannot be opened, it prints an
// error message. If both the input and ouput files are opened successfully, 
// the function will read each line of the input file using getline. As it loops
// it will replace all occurences of s1 with s2 using our replaceString function.

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Three arguments must be entered for the program to work." << std::endl;
        return (EXIT_FAILURE);
    }
    Replace ofile = Replace(argv[1], argv[2], argv[3]);
    ofile.setFilename(argv[1]);
    std::string s1;
    std::string s2;
    modFileCopy(ofile, argv[1]);
    ofile.setStr1(argv[2]);
    ofile.setStr2(argv[3]);
    return 0;
}
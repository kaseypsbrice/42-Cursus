#include "Replace.hpp"

Replace::Replace(std::string filnename, std::string s1, std::string s2)
{
    this->filename = filnename;
	this->s1 = s1;
	this->s2 = s2;
	this->replace_str = "";
}

Replace::~Replace()
{
}

void    Replace::setFilename(std::string filename)
{
    std::ifstream ifile;
    ifile.open(filename);
    if (ifile)
    {
        this->filename = filename + ".replace";
    }
    else
    {
        std::cerr << ".replace file cannot be created. Check whether the file exists or the file's permissions." << std::endl;
        exit (EXIT_FAILURE);
    }
}

std::string Replace::getFilename() const
{
	return filename;
}

std::string Replace::getStr1() const
{
	return s1;
}

std::string Replace::getStr2() const
{
	return s2;
}

void Replace::setStr1(std::string s1)
{
	this->s1 = s1;
}


void Replace::setStr2(std::string s2)
{
	this->s2 = s2;
}
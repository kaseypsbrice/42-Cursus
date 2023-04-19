#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

class Replace 
{
    private:
	    std::string filename;
	    std::string s1;
	    std::string s2;
	    std::string replace_str;
    public:
        Replace(std::string filnename, std::string s1, std::string s2);
        ~Replace();
        void        setFilename(std::string filename);
        std::string getFilename() const;
        std::string getStr1() const;
        std::string getStr2() const;
        void        setStr1(std::string s1);
        void        setStr2(std::string s2);
};

#endif
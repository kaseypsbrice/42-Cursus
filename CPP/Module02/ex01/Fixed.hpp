#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 value;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        Fixed(const int value);
        Fixed(const float value);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits(void) const;
        void    setRawBits(int raw);
        ~Fixed();
};

std::ostream &operator<<(std::ostream& out, const Fixed &other);

#endif
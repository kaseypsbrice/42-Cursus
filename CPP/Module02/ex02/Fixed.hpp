#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 value;
        static const int    fractionalBits = 8;
        // Static class member that's shared by all objects of
        // the class. There will only ever be one copy of the static
        // member.
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
        // ----------------- + ------------------ //
        // Arithmetic Operators +-*/
        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
        // Comparison Operators ==!=<><=>=
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        // Increment & Decrement Operators ++--++--
        Fixed   operator++(int);
        Fixed   operator--(int);
        Fixed   operator++(void);
        Fixed   operator--(void);
        // Min - Max Functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        // Static member functions belong to the class itself
        // instead of being instances of the class.
        // By defining these functions as static member functions,
        // they can be called directly by the class itself using
        // 'Fixed::'.
};

std::ostream &operator<<(std::ostream& out, const Fixed &other);

#endif
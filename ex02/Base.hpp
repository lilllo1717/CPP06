#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <random>

#define RED     "\033[31m"
#define GREEN    "\033[32m"
#define PURPLE  "\033[35m"
#define RESET   "\033[0m"

// class Base
// {
//     private:
//         int k;
//     public:
//         int n;
//         Base() :n(42), k(55) {}
//         virtual ~Base() {}

// };


class Base
{

    public:

        Base() {}
        virtual ~Base() {}

};

class A: public Base
{

};

class B: public Base
{

};

class C: public Base
{

};



#endif 
#include "whatever.hpp"
#include <iostream>

class NoCopyConstructor
{
    NoCopyConstructor(const NoCopyConstructor &other);
public:
    int a;
    NoCopyConstructor(int a = 0);
    NoCopyConstructor &operator=(const NoCopyConstructor &other);
    bool	operator<(const NoCopyConstructor &other) const ;
    bool	operator>(const NoCopyConstructor &other) const ;
    bool	operator==(const NoCopyConstructor &other) const ;
    bool	operator!=(const NoCopyConstructor &other) const ;
    bool	operator<=(const NoCopyConstructor &other) const ;
    bool	operator>=(const NoCopyConstructor &other) const ;
    ~NoCopyConstructor();
};
std::ostream &operator<<(std::ostream &os, const NoCopyConstructor &other);

int pdfTest()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

int Test(const char *a, const char *b)
{
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return (0);
}

bool    printResultMsg(bool success, std::string msg)
{
    if (success)
    {
        std::cout << msg << ": OK ✅" << std::endl;
        return (true);
    }
    else
    {
        std::cout << msg << ": NG ❌" << std::endl;
        return (false);
    }
}

template <typename T>
int test(T a, T b, std::string type)
{
    std::cout << "============ " << type << " ==============" << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    T min;
    if (a < b)
        min = a;
    else
        min = b;

    T max;
    if (a > b)
        max = a;
    else
        max = b;

    std::cout << "min: " << min << ", max: " << max << std::endl;
    printResultMsg(::min(a, b) == min, "min");
    printResultMsg(::max(a, b) == max, "max");

    T origin_a = a;
    T origin_b = b;
    ::swap(a, b);
    printResultMsg(a == origin_b && b == origin_a, "swap");
    return (0);
}

int doTest()
{
    test(1, 2, "int");
    test(1.0, 2.0, "double");
    test('a', 'b', "char");
    test("abc", "def", "string");
    test("def", "abc", "string");
    test(4.2f, 8.4f, "float");
    test(4.2l, 8.4l, "long double");
	::min(NoCopyConstructor(100), NoCopyConstructor(200));
    std::cout << "============ pdf test ==============" << std::endl;
    pdfTest();
    return (0);
}

int main()
{
    doTest();
    return (0);
}

    // std::string a = "abc";
    // std::string b = "def";
    // test(a, b, "string");
    // std::cout << (a < b) << std::endl;
    // std::cout << ("abc" < "def") << std::endl;
    // std::cout << ("def" < "abc") << std::endl;

NoCopyConstructor::NoCopyConstructor(int a): a(a) {}

NoCopyConstructor::~NoCopyConstructor() {}

NoCopyConstructor &NoCopyConstructor::operator=(const NoCopyConstructor &other)
{
    this->a = other.a;
    return (*this);
}

NoCopyConstructor::NoCopyConstructor(const NoCopyConstructor &other)
{ this->a = other.a; }

bool	NoCopyConstructor::operator<(const NoCopyConstructor &other) const 
{ return (this->a < other.a); }

bool	NoCopyConstructor::operator>(const NoCopyConstructor &other) const 
{ return (this->a > other.a); }

bool	NoCopyConstructor::operator==(const NoCopyConstructor &other) const 
{ return (this->a == other.a); }

bool	NoCopyConstructor::operator!=(const NoCopyConstructor &other) const 
{ return !(*this == other); }

bool	NoCopyConstructor::operator<=(const NoCopyConstructor &other) const 
{ return !(*this > other); }

bool	NoCopyConstructor::operator>=(const NoCopyConstructor &other) const 
{ return !(*this < other); }

std::ostream &operator<<(std::ostream &os, const NoCopyConstructor &other)
{
	os << other.a;
	return (os);
}

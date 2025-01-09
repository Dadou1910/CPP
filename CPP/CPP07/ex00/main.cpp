#include "whatever.hpp"

int main()
{
    std::cout << "=== TEST 1: INT ===" << std::endl;
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "\n=== TEST 2: STRING ===" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << "\n=== TEST 3: FLOAT ===" << std::endl;
    float x = 4.5f;
    float y = 2.3f;

    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    std::cout << "\n=== TEST 4: CHAR ===" << std::endl;
    char e = 'A';
    char f = 'Z';

    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    return 0;
}

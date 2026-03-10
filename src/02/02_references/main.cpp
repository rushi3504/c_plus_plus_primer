#include <iostream>

int main()
{
    int i = 0, &ri = i;
    double d = 0, &r2 = d;

    r2 = 3.14;
    r2 = ri;
    i = r2;
    ri = d;
    
    std::cout << i << std::endl;
    std::cout << ri << std::endl;
    std::cout << d << std::endl;
    std::cout << r2 << std::endl;

    //----------------------------------

    int x, &refx = x;
    x = 5;
    refx = 10;
    std::cout << x << " " << refx << std::endl;

    return 0;
}
#include <iostream>

int j = 0;
constexpr int i = 42;
int main()
{
    const int *p = nullptr; // p is a pointer to a const int
    constexpr int *q = nullptr; //q is a const pointer to int
    

    constexpr const int *p1 = &i; // p1 is a constant pointer to the const int i
    constexpr int *p2 = &j;       // p2 is a constant pointer to the int j

    //int null = 0, *p3 = null;

    std::cout << "END OF THE PORGRAM !!" << std::endl;
    return 0;
}
#include <iostream>

int main()
{
    //int i = -1, $r = 0; //this statement int allowed
    //std::cout << i << " " << r << std::endl;

    int i1 = 5;
    int i2 = 4;
    int *const p2 = &i2;     //this is allowed
    *p2 = 55;               //this is the const pointer so we can chage the value of i2
    //p2 = &i1;             //this is not allowed
    std::cout << i2 << " " << *p2 << std::endl;

    const int i = -1, &r = 0; //allowed
    std::cout << i << " " << r << std::endl;

    int i3 = 3;
    const int *const p3 = &i3; // this is legal
    //*p3 = 33;                // in this case pointer to const and const pointer used so both are const
    std::cout << i3 << " " << *p3 << std::endl;

    const int *p1 = &i2;        //legal
    std::cout << *p1 << " " << i2 << std::endl;

    //cont int &const r2; //illegal
    

    std::cout << "END OF THE CODE !!" << std::endl;
    return 0;
}
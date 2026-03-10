#include <iostream>

struct Sales_item
{

};

typedef double wages;       // wages is synoname for double
typedef wages base, *p;     // base is synoname for double, p for double*

using SI = Sales_item;      // SI is synoname for Sales_item (this is another method of type aiases)

int main()
{
    wages hourly, weekly;   // same as double hourly, weekly;
    SI item;                // same as Sales_item item;

    std::cout << "END OF PROGRAM !!" << std::endl;
    return 0;
}
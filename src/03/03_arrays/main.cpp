#include <iostream>
#include <vector>

int main()
{
    int *pntrs[10];                           // pntrs is an array of 10 pointer to int
    //int &refs[] = /* ? */;                //error
    int arr[10] = {33};
    int (*Parray)[10] = &arr;               // Parray points to an array arr
    int (&arrRef)[10] = arr;                // arrRef refer to an array arr

    int *(&arry)[10] = pntrs;               // arry is an reference to and array of 10 pointers

    int arr2[] = {1, 2, 3, 4, 5};

    int *p1 = arr2;
    int *p2 = arr2 + 3;
    p1 += p2 - p1;
    std::cout << *p1 << " " << *p2 << std::endl;

    char ca[] = {'C', '+', '+'};            // not gave proper size as no null terminator('\0')
    char ca2[] = "C++";                     // size = 3
    std::cout << std::strlen(ca) << "  " << std::strlen(ca2) << std::endl;


    const char char_arr[] = {'h', 'e', 'l', 'l', 'o'};
    const char *char_p = char_arr;
    while(*char_p)
    {
        std::cout << *char_p << std::endl;
        ++char_p;
    }
    std::cout << *char_p << std::endl;


    int int_arr[] = {0, 1, 2, 3, 45, 76};
    std::vector<int> int_vec(std::begin(int_arr), std::end(int_arr));
    std::cout << int_vec[5] << std::endl;

    int mul[2][2] = {{34, 65}, {76, 87}};
    for(const auto &row : mul)              // & row must needed for outer loop
    {
        for(const auto col : row)
        {
            std:: cout << "multi : " << col << std::endl;
        }
    }

    std::cout << "END OF THE PROGRAM !!" << std::endl;
    return 0;
}
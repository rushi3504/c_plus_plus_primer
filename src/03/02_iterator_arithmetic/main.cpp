#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> text = {"banana", "apple", "cherry", "date", "papaya"};
    std::sort(text.begin(), text.end());

    std::string wanted = "banana2";

    auto beg = text.begin(), end = text.end();
    auto mid = beg + (end - beg) / 2;

    while(mid != end && *mid != wanted)
    {
        //std::cout << *mid << std::endl;
        if(wanted < *mid)
        {
            end = mid;
        }
        else
        {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }

    if(mid == end)
    {
        std::cout << "NOT FOUND !!" << std::endl;
    }
    else
    {
        std::cout << "FOUND !!" << std::endl;
    }

    std::cout<< "END OF THE PROGRAM!!" << std::endl;
}
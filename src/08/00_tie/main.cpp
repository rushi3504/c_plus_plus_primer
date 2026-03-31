#include <iostream>
#include <string>
int main()
{
    // std::cin.tie(&std::cout);
    std::cin.tie(nullptr);
    std::cout << "Enter txt here: ";
    std::string sss;
    std::cin >> sss;

    std::cout << "The text is : " << sss << std::endl; 

	return 0;
}

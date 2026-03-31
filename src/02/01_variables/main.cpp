#include <iostream>

std::string global_string;
int global_int;
int main()
{
    std::string local_string;
    int local_int;

    std::cout << global_string << std::endl;
    std::cout << global_int << std::endl;
    std::cout << local_string << std::endl;
    std::cout << local_int << std::endl;

    return 0;
}
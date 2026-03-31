#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};


int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "no agruments provided!!" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]);

    std::string line, word;
    std::vector<PersonInfo> peopel;

    while (getline(input, line))
    {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        
        peopel.push_back(info);
    }
    
    for(PersonInfo info : peopel)
    {
        std::cout << info.name << " : ";
        for(std::string phone : info.phones)
        {
            std::cout << phone << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
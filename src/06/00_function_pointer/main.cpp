#include <iostream>
#include <string>

bool lengthCompare(const std::string&, const std::string&);

bool (*pf)(const std::string&, const std::string&);

void useBigger(const std::string& s1, const std::string& s2, bool pf(const std::string&, const std::string&const))
{

}

int main()
{

    pf = lengthCompare; // or &lengthCompare :: & operator is optional

    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye"); // both calls are same
    bool b3 = lengthCompare("hello", "goodbye"); // all calls are same

    useBigger("aaaa", "bbbbb", pf);

    return 0;
}

bool lengthCompare(const std::string& s1, const std::string& s2)
{
    if(s1 == s2)
        return true;
    else
        return false;
}

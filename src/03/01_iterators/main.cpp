#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> veci = {2, 6, 18};
    auto b = veci.begin(), e = veci.end(); // type is vector<int>::iterator
    std::cout << *b << " " << *e << std::endl;

    auto cb = veci.cbegin();                // type is vector<int>::const_iterator
    std::cout << *cb << std::endl;

    const std::vector<int> cv = {43, 65, 76, 22, 54};
    auto cvb = cv.begin();                  // type is vector<int>::const_iterator

    std::string name = "rushikesh bodkhe !!";
    for(auto it = name.begin(); it != name.end() && !std::isspace(*it); ++it)
    {
        *it = std::toupper(*it);
    }
    std::cout << name << std::endl;

    std::vector<std::string> vs = {"hjj"};
    auto bvs = vs.begin();
    //bool result = *bvs.empty();                  // not valid
    bool result = (*bvs).empty();                  // valid
    bool result1 = bvs->empty();                   // valid

    std::cout << "result = " << result << std::endl;

    std::cout << "END OF THE PROGRAM !!" << std::endl;
    return 0;
}
#include <iostream>
#include <string>

class Sales_data   // when we use the class keyword then default access specifier is private, for struct its public
{
    // friend used to use this class private members in this functions
    friend Sales_data add(Sales_data &lhs, Sales_data &rhs);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
    // constructors
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), unit_sold(n), revenue(p*n) {}
    Sales_data(std::istream&);
    // othe members
    std::string isbn() const {return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;
    std::string bookNo;
    unsigned int unit_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    unit_sold += rhs.unit_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    if(unit_sold)
    {
        return revenue / unit_sold;
    }
    else
    {
        return 0;
    }
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

int main()
{
    Sales_data demo(std::cin);
    std::cout << "Jai Shree Ram" << std::endl;
    Sales_data total;
    if(read(std::cin, total))
    {
        Sales_data trans;
        while(read(std::cin, trans))
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.unit_sold >> price;
    item.revenue = price * item.unit_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

#include <iostream>
#include <string>


template <typename T> concept ComplexConcept = requires(const T v) 
{
    {v.hash()}->std::convertible_to<long>;
    {v.toString()}->std::same_as<std::string>;
    std::has_virtual_destructor<T>::value;
};

struct Number
{
    int num{0};
    int hash() const { return num + 1; }
    std::string toString() const { return std::to_string(num); }
};

void test(ComplexConcept auto &t)
{
    std::cout << "toString(): " << t.toString() << std::endl;
    std::cout << "hash(): " << t.hash() << std::endl;
}

int main()
{
    Number n{42};
    test(n);
    return 0;
}
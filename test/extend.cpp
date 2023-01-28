#include <iostream>

struct A
{
    int a = 666;

    A(int v) : a(v) {}
    A(const A &from) = default;

    A &operator=(const A &from)
    {
        std::cout << "A" << std::endl;
        return *this;
    }
};

int main()
{
    A a(10);
    A b(a);
    A c(b);
    std::cout << c.a << std::endl;
    return 0;
}
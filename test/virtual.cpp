#include <iostream>

struct Base
{
    int a;

    virtual void func() {}
};

struct Child : public Base
{
    int b;

    void func() {}
};

struct Container
{
    Base a;
    Child b;

    virtual void func() {}
};

void print(const char *str, const void *ptr)
{
    std::cout << str << "\t\t\t\t" << ptr << std::endl;
}

void delta(const char *str, const void *beg, const void *end)
{
    std::cout << str << "\t\t\t\t" << (const void *)(intptr_t(end) - intptr_t(beg)) << std::endl;
}

void split()
{
    std::cout << "----------" << std::endl;
}

template <typename T>
void size(const char *str)
{
    std::cout << str << "\t\t\t\t" << sizeof(T) << std::endl;
}

int main()
{
    Base a;
    print("&a", &a);
    print("&a.a", &a.a);
    delta("&a.a - &a", &a, &a.a);
    size<Base>("sizeof(Base)");

    split();

    Child b;
    print("&b", &b);
    print("&b.a", &b.a);
    print("&b.b", &b.b);
    delta("&b.a - &b", &b, &b.a);
    delta("&b.b - &b.a", &b.a, &b.b);
    size<Child>("sizeof(Child)");

    split();

    Container c;
    print("&c", &c);
    print("&c.a", &c.a);
    print("&c.b", &c.b);
    delta("&c.a - &c", &c, &c.a);
    delta("&c.b - &c.a", &c.a, &c.b);
    size<Container>("sizeof(Container)");

    return 0;
}
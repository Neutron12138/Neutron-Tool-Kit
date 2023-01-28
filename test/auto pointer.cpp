#include <iostream>
#include <string>
#include "../src/Base/BasicObject.hpp"
#include "../src/Base/Object.hpp"
#include "../src/Base/Object.cpp"
#include "../src/Base/BasicDeleter.hpp"
#include "../src/Base/BasicDeleter.cpp"
#include "../src/Base/Pointer.hpp"
#include "../src/Base/Pointer.cpp"
#include "../src/Base/Exception.hpp"
#include "../src/Base/Exception.cpp"
#include "../src/Base/BasicString.hpp"
#include "../src/Base/BasicString.cpp"
#include "../src/Base/BasicStringStream.hpp"
#include "../src/Base/BasicStringStream.cpp"
#include "../src/Base/String.hpp"
#include "../src/Base/String.cpp"
#include "../src/Base/StringStream.hpp"
#include "../src/Base/StringStream.cpp"
#include "../src/Utils/Exception/NullPointerException.hpp"
#include "../src/Utils/Exception/NullPointerException.cpp"
#include "../src/Utils/Memory/SharedPointer.hpp"
#include "../src/Utils/Memory/SharedPointer.cpp"
#include "../src/Utils/Memory/UniquePointer.hpp"
#include "../src/Utils/Memory/UniquePointer.cpp"
#include "../src/Utils/String/StringUtils.hpp"
#include "../src/Utils/String/StringUtils.cpp"

template <typename T>
class Deleter : public ntk::BasicDeleter<T>
{
public:
    Deleter() = default;
    ~Deleter() = default;

public:
    virtual void operator()(T *ptr)
    {
        std::cout << "delete pointer:" << ptr << "\tvalue:" << *((int *)(ptr)) << std::endl;
        delete ptr;
    }
};

template <typename T>
class Deleter<T[]> : public ntk::BasicDeleter<T[]>
{
public:
    Deleter() = default;
    ~Deleter() = default;

public:
    virtual void operator()(T *ptr)
    {
        std::cout << "delete pointer array:" << ptr << std::endl;
        delete[] ptr;
    }
};

struct Item
{
    Item()
    {
        std::cout << "Item()\t" << this << std::endl;
    }

    ~Item()
    {
        std::cout << "~Item()\t" << this << std::endl;
    }
};

int main()
{
    ntk::Utils::SharedPointer<int> p1(new int, Deleter<int>());
    *p1.get() = 666;
    std::cout << "*p1:" << *p1 << std::endl;
    ntk::Utils::SharedPointer<int> p2(p1);
    *p2.get() = 999;
    std::cout << "*p1:" << *p1 << std::endl;

    std::cout << "----------" << std::endl;

    ntk::Utils::UniquePointer<int, Deleter<int>> p3(new int);
    *p3.get() = 123;
    std::cout << "*p3:" << *p3 << std::endl;
    ntk::Utils::UniquePointer<int, Deleter<int>> p4 = std::move(p3);
    *p4.get() = 456;
    std::cout << "p3.get():" << p3.get() << std::endl;
    std::cout << "*p4:" << *p4 << std::endl;

    std::cout << "----------" << std::endl;

    ntk::Utils::SharedPointer<int> p6;
    ntk::Utils::UniquePointer<int> p7;

    try
    {
        *p6;
    }
    catch (const ntk::Utils::NullPointerException &e)
    {
        std::cout << e << '\n';
    }

    try
    {
        *p7;
    }
    catch (const ntk::Utils::NullPointerException &e)
    {
        std::cout << e << '\n';
    }

    std::cout << "----------" << std::endl;

    ntk::Utils::UniquePointer<Item[], Deleter<Item[]>> p8;
std::shared_ptr<int> a;a.operator*();
    try
    {
        p8[10];
    }
    catch (const ntk::Utils::NullPointerException &e)
    {
        std::cout << e << '\n';
    }

    p8.reset(new Item[10]);
    Deleter<Item[]>()(p8.release());

    std::cout << "----------" << std::endl;

    return 0;
}
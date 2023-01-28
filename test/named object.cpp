#include <iostream>
#include "../src/Neutron.hpp"
#include "../src/Neutron.cpp"

class NamedObject : public ntk::NamedObject<std::string>
{
public:
    NamedObject(const std::string &name) : ntk::NamedObject<std::string>(name) {}

public:
    void set_name(const std::string &name) {}
};

class NamedObject2 : public ntk::NamedObject<std::string>
{
public:
    NamedObject2(const std::string &name) : ntk::NamedObject<std::string>(name) {}

public:
    void set_name(const std::string &name)
    {
        std::cout << "before:" << m_name << "\t"
                  << "after:" << name << std::endl;
        ntk::NamedObject<std::string>::set_name(name);
    }
};

int main()
{
    ntk::NamedObject<std::string> object1("666");
    std::cout << object1.get_name() << std::endl;
    object1.set_name("999");
    std::cout << object1.get_name() << std::endl;

    std::cout << "----------" << std::endl;

    NamedObject object2("123");
    std::cout << object2.get_name() << std::endl;
    object2.set_name("456");
    std::cout << object2.get_name() << std::endl;

    std::cout << "----------" << std::endl;

    NamedObject2 object3("abc");
    std::cout << object3.get_name() << std::endl;
    object3.set_name("xyz");
    std::cout << object3.get_name() << std::endl;
    return 0;
}
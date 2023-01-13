#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

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

class MyNode : public ntk::Utils::Node<std::string, MyNode>
{
public:
    MyNode(const std::string &name) : ntk::Utils::Node<std::string, MyNode>(name) {}
};

void print(MyNode &root, int tab);

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

    std::cout << "----------" << std::endl;

    MyNode root("root");

    try
    {
        root.get_child_node("abc");
    }
    catch (const ntk::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    std::cout << "----------" << std::endl;

    root.add_child_node("abc", MyNode("abc"));
    std::cout << root.get_child_node("abc").get_name() << std::endl;
    root.remove_child_node("abc");
    std::cout << root.is_exist("abc") << std::endl;

    std::cout << "----------" << std::endl;

    MyNode node_a("a");
    node_a.add_child_node("a1", MyNode("a1"));
    node_a.add_child_node("a2", MyNode("a2"));

    MyNode node_b("b");
    node_b.add_child_node("b1", MyNode("b1"));
    node_b.add_child_node("b2", MyNode("b2"));

    root.add_child_node("a", node_a);
    root.add_child_node("b", node_b);

    print(root, 0);

    std::cout << "----------" << std::endl;

    root.remove_child_node("a");
    root.get_child_node("b").remove_child_node("b1");

    print(root, 0);

    std::cout << "----------" << std::endl;

    ntk::String str1 = "123";
    std::cout << str1 << std::endl;
    std::wcout << str1 << std::endl;

    std::cout << "----------" << std::endl;

    ntk::String str2 = L"456";
    std::cout << str2 << std::endl;
    std::wcout << str2 << std::endl;

    std::cout << "----------" << std::endl;

    ntk::String str3 = str1 + str2;
    std::cout << str3 << std::endl;
    std::wcout << str3 << std::endl;

    return 0;
}

void print(MyNode &root, int tab)
{
    for (size_t i = 0; i < tab; i++)
    {
        std::cout << "\t";
    }
    std::cout << root.get_name() << std::endl;

    auto childs = root.get_child_nodes();
    for (auto iter = childs.begin(); iter != childs.end(); iter++)
    {
        print(iter->second, tab + 1);
    }
}
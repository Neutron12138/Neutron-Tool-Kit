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

    std::cout << "----------" << std::endl;

    ntk::StringStream sstr;
    sstr << ntk::String("666");
    std::cout << sstr.to_string() << std::endl;
    std::wcout << sstr.to_string() << std::endl;

    std::cout << "----------" << std::endl;

    ntk::String str4 = ntk::Utils::construct_string("a", ",", "c");
    ntk::String str5 = ntk::Utils::construct_string(123, ",", nullptr, ',', 456.789);
    std::cout << str4 << std::endl;
    std::wcout << str4 << std::endl;
    std::cout << str5 << std::endl;
    std::wcout << str5 << std::endl;

    ntk::Utils::Log log;
    log.logd("test1", L"test1");
    log.logi(L"test2", "test2");
    log.logi(std::string("test3"), std::wstring(L"test3"));
    log.logi(std::wstring(L"test4"), std::string("test4"));
    log.logi(ntk::String("test5"), ntk::String(L"test5"));
    log.logi(ntk::String(L"test6"), ntk::String("test6"));

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
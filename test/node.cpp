#include <iostream>
#include "../src/Neutron.hpp"
#include "../src/Neutron.cpp"

class MyNode : public ntk::Utils::Node<std::string, MyNode>
{
public:
    MyNode(const std::string &name) : ntk::Utils::Node<std::string, MyNode>(name) {}
};

void print(MyNode &root, int tab);

int main()
{
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

    print(root,0);

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
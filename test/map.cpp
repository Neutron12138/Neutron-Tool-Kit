#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string,int> m;
    m.insert({"a",0});
    m.insert({"b",1});
    m.insert({"c",2});
    m.insert({"a",3});
    std::cout << (m.find("a") == m.end());
    for(auto ptr = m.begin();ptr != m.end();ptr++)
    {
        std::cout << ptr->first << "\t" << ptr->second << std::endl;
    }
    return 0;
}
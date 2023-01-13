#include <iostream>
#include "../src/Base/Object.hpp"
#include "../src/Base/Object.cpp"
#include "../src/Base/String.hpp"
#include "../src/Base/String.cpp"
#include "../src/Utils/String/StringUtils.hpp"
#include "../src/Utils/String/StringUtils.cpp"

int main()
{
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
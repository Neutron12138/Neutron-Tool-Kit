#include <iostream>
#include "../src/Base/Object.hpp"
#include "../src/Base/Object.cpp"
#include "../src/Base/String.hpp"
#include "../src/Base/String.cpp"
#include "../src/Utils/String/StringUtils.hpp"
#include "../src/Utils/String/StringUtils.cpp"
#include "../src/Base/StringStream.hpp"
#include "../src/Base/StringStream.cpp"
#include "../src/Utils/Log/BasicLog.hpp"
#include "../src/Utils/Log/BasicLog.cpp"
#include "../src/Utils/Log/Log.hpp"
// #include "../src/Utils/Log/Log.cpp"
#include "../src/Utils/Log/LogLevel.hpp"
#include "../src/Utils/Log/LogLevel.cpp"
#include "../src/Utils/Log/LogItem.hpp"
#include "../src/Utils/Log/LogItem.cpp"

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

    std::cout << "----------" << std::endl;

    ntk::Utils::Log log;
    log.logd("test1", L"test1");
    log.logi(L"test2", "test2");
    log.logi(std::string("test3"), std::wstring(L"test3"));
    log.logi(std::wstring(L"test4"), std::string("test4"));
    log.logi(ntk::String("test5"), ntk::String(L"test5"));
    log.logi(ntk::String(L"test6"), ntk::String("test6"));

    return 0;
}
#include <iostream>
#include <fstream>
#include <dirent.h>

size_t count_file(const std::string &filename);

int main()
{
    DIR *dir = opendir("../src/Base.cpp");
    dirent* drt;
    size_t count = 0;
    while ((drt = readdir(dir)) != nullptr)
    {
        count += count_file(drt->d_name);
        std::cout << drt->d_name << std::endl;
    }
    closedir(dir);

    std::cout << count << std::endl;

    return 0;
}

size_t count_file(const std::string &filename)
{
    std::ifstream fin;
    fin.open(filename);
    size_t result = 0;
    std::string temp;
    while (std::getline(fin, temp))
        result++;
    fin.close();
    return result;
}
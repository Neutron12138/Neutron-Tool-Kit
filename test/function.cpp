#include <iostream>
#include <functional>
#include <string>

struct Connectable
{
    Connectable *obj;

    template <typename T, typename F, typename... Ts>
    void connect(Connectable *object, const std::function<F> &func, Ts... args)
    {
    }
};

struct Weight : public Connectable
{
    virtual void onEvent(const std::string &event)
    {
        std::cout << "Weight onEvent:" << event << std::endl;
    }
};

struct Button : public Weight
{
};

int main()
{
    return 0;
}
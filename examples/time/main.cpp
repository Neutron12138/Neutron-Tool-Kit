#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyCT : public ntk::Utils::CountdownTimer
{
public:
    ntk::Utils::Timer t;

public:
    MyCT() = default;
    ~MyCT() = default;

public:
    void onStarted()
    {
        t.reset();
        t.start();
    }

    void onStoped()
    {
        t.stop();
        std::cout << "stoped" << std::endl;
        std::cout << t.get_total_time().as_milliseconds() << std::endl;
    }
};

int main()
{
    MyCT ct;
    ct.set_duration(ntk::Instance::OneSecond);

    // 以阻塞模式启动
    ct.start(ntk::Utils::CountdownTimer::CountdownType::Block);
    ct.stop();

    std::cout << "----------" << std::endl;

    // 以异步模式启动
    ct.start(ntk::Utils::CountdownTimer::CountdownType::Async);
    ct.stop();

    return 0;
}
#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    float color;
    float step;

public:
    MyApp() : ntk::Window::SFApplication("Base Window", glm::ivec2(640, 480)) {}

public:
    void onCreated()
    {
        ntk::Instance::log.logi("Window", "Window Created");

        // 限制帧率
        get_window().setFramerateLimit(60);

        // 加载OpenGL
        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        color = 0.0f;
        step = 0.01f;
    }

    void onDisplay()
    {
        // 清空颜色缓冲区
        glClear(GL_COLOR_BUFFER_BIT);
        // 颜色缓冲区的颜色
        glClearColor(color, color, color, 1.0f);

        color += step;
        if (color > 1.0f || color < 0.0f)
            step *= -1.0f;
    }

    void onDestroyed()
    {
        ntk::Instance::log.logi("Window", "Window Destroyed");
    }
};

int main(int argc, char *argv[])
{
    MyApp app;
    return app.run();
}
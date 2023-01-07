#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    std::ofstream fout;
    ntk::Graphics::Program program;
    ntk::Graphics::RectangleShape rect;

public:
    MyApp() : ntk::Window::SFApplication("Shape", glm::ivec2(640, 480)), rect(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.5f)) {}
    ~MyApp() {}

public:
    virtual void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_SUCCESS);

        if (!program.load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        rect.generate_shape();
    }

    virtual void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        rect.render();
    }

    virtual void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        rect.release();
        fout.close();
    }
};

int main()
{
    std::cout << "Hello NTK " << NEUTRON_INFO_VERSION_FULL << "!" << std::endl;
    std::cout << "major:" << NEUTRON_INFO_VERSION_MAJOR << "\tminor:" << NEUTRON_INFO_VERSION_MINOR << std::endl;
    std::cout << NEUTRON_INFO_UPDATE_DESCRIPTION << std::endl;

    MyApp app;
    return app.run();
}
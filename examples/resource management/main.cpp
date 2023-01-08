#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class ProgramDeleter : public ntk::Utils::GLObjectDeleter<ntk::Graphics::Program>
{
public:
    ProgramDeleter() {}
    ~ProgramDeleter() {}

public:
    void operator()(ntk::Graphics::Program *ptr)
    {
        ptr->delete_object();
        ptr->delete_shaders();
        delete ptr;
        ntk::Instance::log.logi("Program Deleter", "program deleted");
    }
};

class RectangleShapeDeleter : public ntk::Utils::ResourceDeleter<ntk::Graphics::RectangleShape>
{
public:
    RectangleShapeDeleter() {}
    ~RectangleShapeDeleter() {}

public:
    void operator()(ntk::Graphics::RectangleShape *ptr)
    {
        ptr->release();
        delete ptr;
        ntk::Instance::log.logi("Rectangle Shape Deleter", "rect deleted");
    }
};

class MyApp : public ntk::Window::SFApplication
{
private:
    std::ofstream fout;
    std::unique_ptr<ntk::Graphics::Program, ProgramDeleter> program;
    std::unique_ptr<ntk::Graphics::RectangleShape, RectangleShapeDeleter> rect;

public:
    MyApp() : ntk::Window::SFApplication("Resource Management", glm::ivec2(640, 480)) {}
    ~MyApp() {}

public:
    virtual void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_SUCCESS);

        program.reset(new ntk::Graphics::Program());
        if (!program->load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        rect.reset(new ntk::Graphics::RectangleShape(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.5f)));
        rect->generate_shape();
    }

    virtual void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program->use_program();
        rect->render();
    }

    virtual void onDestroyed()
    {
        fout.close();
        ntk::Instance::log.set_output(&std::cout);
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
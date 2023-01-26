#include <iostream>
#include <fstream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::VertexAttribDescriber describer;
    ntk::Graphics::ModelObject circle_model;
    ntk::Graphics::ModelInstance circle_instance;
    std::wofstream fout;

public:
    MyApp() : ntk::Window::SFApplication("Shapes", glm::ivec2(640, 480), glm::uvec2(4, 6)) {}

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        if (!program.load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        circle_model = ntk::Graphics::ModelBuilder::create_regular_polygon_triangulated(0.25f, 6);
        circle_instance = circle_model.create_instance();
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        circle_instance.render();std::cout << glGetError() << std::endl;
    }

    void onDestroyed()
    {
        program.release();
        circle_model.release();
        fout.close();
    }

    void onResized(const glm::uvec2 &new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);
    }
};

int main()
{
    MyApp app;
    return app.run();
}
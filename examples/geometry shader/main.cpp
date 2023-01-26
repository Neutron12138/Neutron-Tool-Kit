#include <iostream>
#include <fstream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::GeometryProgram program;
    ntk::Graphics::VertexAttribDescriber describer;
    ntk::Graphics::ModelObject model;
    ntk::Graphics::ModelInstance instance;
    std::wofstream fout;

public:
    MyApp() : ntk::Window::SFApplication("Triangle", glm::ivec2(640, 480)) {}

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        if (!program.load_from_file("shaders/1.vert", "shaders/1.geom", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        std::vector<ntk::Graphics::Vertex> vertices =
            {
                ntk::Graphics::Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(), glm::vec2()),
                ntk::Graphics::Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(), glm::vec2()),
                ntk::Graphics::Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(), glm::vec2()),
            };

        model = ntk::Graphics::ModelObject(ntk::Graphics::VertexModel(vertices), ntk::Graphics::DrawInfo(ntk::Graphics::PrimitiveType::PrimitiveType::Points, 0, 3));
        instance = model.create_instance();
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        instance.render();
    }

    void onDestroyed()
    {
        program.release();
        model.release();
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
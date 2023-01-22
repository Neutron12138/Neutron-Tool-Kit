#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::VertexArrayObject vao;
    ntk::Graphics::VertexAttribDescriber describer;
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

        if (!program.load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        std::vector<ntk::Graphics::Vertex> vertices =
            {
                ntk::Graphics::Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(), glm::vec2()),
                ntk::Graphics::Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(), glm::vec2()),
                ntk::Graphics::Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(), glm::vec2()),
            };

        ntk::Graphics::VertexModel model(vertices);

        model.generate_VAO(vao, program, describer);
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        vao.unbind();
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        vao.delete_object();
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
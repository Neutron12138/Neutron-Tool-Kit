#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    std::ofstream fout;
    ntk::Graphics::Program program;
    ntk::Graphics::Model<> model;
    ntk::Graphics::VertexArrayObject vao;
    ntk::Graphics::View view;
    ntk::Graphics::PerspectiveProjection projection;

public:
    MyApp() : ntk::Window::SFApplication("Simple 3D", glm::ivec2(640, 480))
    {
    }

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        program.load_from_file("shaders/2.vert", "shaders/2.frag");

        model = ntk::Graphics::ModelBuilder::create_quad_triangulated();
        vao = model.generate_VAO();

        view.set_position(glm::vec3(1.0f, 1.0f, 2.0f));
        view.update();
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        program.use_program();
        program.set_uniform("u_model", glm::mat4(1.0f));
        program.set_uniform("u_view", view.get_matrix());
        program.set_uniform("u_projection", projection.get_matrix());
        program.set_uniform("u_color", glm::vec3(0.0f, 0.0f, 1.0f));
        program.set_uniform("u_view_position", view.get_position());
        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);
        vao.unbind();
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        vao.delete_object();
        fout.close();
    }

    void onResized(const glm::uvec2& new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);
    }
};

int main()
{
    MyApp app;
    return app.run();
}
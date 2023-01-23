#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    std::wofstream fout;
    ntk::Graphics::Program program;
    ntk::Graphics::UniformDescriber describer;
    ntk::Graphics::DefaultCamera<ntk::Graphics::TrackingView> camera;
    ntk::Graphics::ModelObject grid_model;
    ntk::Graphics::ModelObject axis_model;
    ntk::Graphics::ModelObject quad_model;
    ntk::Graphics::ModelInstance grid;
    ntk::Graphics::ModelInstance axis;
    ntk::Graphics::ModelInstance quad;

public:
    MyApp() : ntk::Window::SFApplication("Tracking", glm::ivec2(640, 480)) {}
    ~MyApp() {}

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        m_window->setFramerateLimit(60);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        program.load_from_file("shaders/3.vert", "shaders/3.frag");

        ntk::Graphics::ModelObject grid_model = ntk::Graphics::ModelBuilder::create_gridxy_wireframe(glm::vec2(5.0f, 5.0f), glm::uvec2(10, 10));
        ntk::Graphics::ModelObject axis_model = ntk::Graphics::ModelBuilder::create_axis();
        ntk::Graphics::ModelObject quad_model = ntk::Graphics::ModelBuilder::create_quad_triangulated();

        grid_model.apply(ntk::Graphics::Transform().rotated(glm::vec3(90.0f, 0.0f, 0.0f)));
        grid_model.update_VAO();

        grid = grid_model.create_instance();
        axis = axis_model.create_instance();
        quad = quad_model.create_instance();

        camera.set_position(glm::vec3(2.0f, 2.0f, 2.0f));
        camera.set_target_object(&quad);
        camera.update_view();

        glEnable(GL_DEPTH_TEST);
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        // camera.update_view();

        program.use_program();
        program.set_uniform("u_view", camera.get_view());
        program.set_uniform("u_projection", camera.get_projection());

        program.set_uniform("u_color", glm::vec3(0.0f, 0.0f, 1.0f));
        quad.render(program, describer);

        program.set_uniform("u_color", glm::vec3(1.0f, 0.0f, 0.0f));
        axis.render(program, describer);

        program.set_uniform("u_color", glm::vec3(0.0f, 1.0f, 0.0f));
        // grid.render(program, describer);
        ntk::Graphics::VertexArrayObject v = grid.get_VAO();
        v.bind();
        glDrawArrays(GL_TRIANGLES, 0, 52);

        quad.translate(glm::vec3(0.01f, 0.01f, 0.0f));
        quad.update();
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        grid_model.release();
        axis_model.release();
        quad_model.release();
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
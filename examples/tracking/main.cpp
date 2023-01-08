#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class Camera : public ntk::Graphics::Camera, public ntk::Graphics::OrbitView, public ntk::Graphics::PerspectiveProjection
{
public:
    Camera() : ntk::Graphics::OrbitView(), ntk::Graphics::PerspectiveProjection() {}
    ~Camera() {}

public:
    virtual const glm::mat4 &get_view() const
    {
        return ntk::Graphics::OrbitView::get_matrix();
    }

    virtual const glm::mat4 &get_projection() const
    {
        return ntk::Graphics::PerspectiveProjection::get_matrix();
    }

    virtual void update_view()
    {
        ntk::Graphics::OrbitView::update();
    }

    virtual void update_projection()
    {
        ntk::Graphics::PerspectiveProjection::update();
    }
};

class Sprite : public ntk::Graphics::Sprite
{
private:
    ntk::Graphics::VertexArrayObject m_vao;
    size_t m_count;
    GLenum m_mode;

public:
    Sprite() {}
    ~Sprite() {}

public:
    void init(const ntk::Graphics::VertexArrayObject &vao, size_t count, GLenum mode)
    {
        m_vao = vao;
        m_count = count;
        m_mode = mode;
    }

    void term()
    {
        m_vao.delete_object();
    }

public:
    virtual void render()
    {
        m_vao.bind();
        glDrawArrays(m_mode, 0, m_count);
        m_vao.unbind();
    }
};

class MyApp : public ntk::Window::SFApplication
{
private:
    std::ofstream fout;
    ntk::Graphics::Program program;
    Camera camera;
    Sprite quad;
    Sprite axis;
    Sprite target;

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

        ntk::Graphics::Model<> quad_model = ntk::Graphics::ModelBuilder::create_gridxy_wireframe(glm::vec2(5.0f, 5.0f), glm::uvec2(10, 10));
        quad.init(quad_model.generate_VAO(), quad_model.get_vertices().size(), GL_LINES);
        axis.init(ntk::Graphics::ModelBuilder::create_axis().generate_VAO(), 6, GL_LINES);
        target.init(ntk::Graphics::ModelBuilder::create_quad_triangulated().generate_VAO(), 6, GL_TRIANGLES);

        quad.set_rotation(glm::vec3(90.0f, 0.0f, 0.0f));
        quad.update();

        camera.set_position(glm::vec3(2.0f, 2.0f, 2.0f));
        camera.set_target_object(&target);
        camera.update_view();

        glEnable(GL_DEPTH_TEST);
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        camera.update_view();

        program.use_program();
        program.set_uniform("u_view", camera.get_view());
        program.set_uniform("u_projection", camera.get_projection());

        program.set_uniform("u_color", glm::vec3(0.0f, 0.0f, 1.0f));
        program.set_uniform("u_model", target.get_matrix());
        target.render();

        program.set_uniform("u_color", glm::vec3(1.0f, 0.0f, 0.0f));
        program.set_uniform("u_model", glm::mat4(1.0f));
        axis.render();

        program.set_uniform("u_color", glm::vec3(0.0f, 1.0f, 0.0f));
        program.set_uniform("u_model", quad.get_matrix());
        quad.render();

        target.translate(glm::vec3(0.01f, 0.01f, 0.0f));
        target.update();
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        target.term();
        axis.term();
        quad.term();
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
#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    float pitch = 0.0f, yaw = 0.0f;
    std::ofstream fout;
    ntk::Graphics::DefaultCamera<> camera;
    ntk::Graphics::UniformDescriber describer;
    std::unique_ptr<ntk::Graphics::Program, ntk::Utils::ProgramDeleter> program;
    std::unique_ptr<ntk::Graphics::Texture2D, ntk::Utils::GLObjectDeleter<ntk::Graphics::Texture2D>> texture;
    std::unique_ptr<ntk::Graphics::CuboidSpatial<>, ntk::Utils::ResourceDeleter<ntk::Graphics::CuboidSpatial<>>> cuboid;

public:
    MyApp() : ntk::Window::SFApplication("Spatial", glm::ivec2(640, 480)) {}
    ~MyApp() {}

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        m_window->setFramerateLimit(60);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        camera.set_position(glm::vec3(0.0f, 0.0f, 2.0f));
        camera.update_view();
        camera.set_aspect(640.0f / 480.0f);
        camera.update_projection();

        program.reset(new ntk::Graphics::Program());
        if (!program->load_from_file("shaders/2.vert", "shaders/2.frag"))
            quit(EXIT_FAILURE);

        texture.reset(new ntk::Graphics::Texture2D());
        if (!texture->load_from_file("textures/image.jpg"))
            quit(EXIT_FAILURE);

        cuboid.reset(new ntk::Graphics::CuboidSpatial<>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
        cuboid->generate_shape();
        cuboid->set_material(ntk::Graphics::Material<>(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), 32.0f));

        glEnable(GL_DEPTH_TEST);

        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        program->use_program();
        program->set_uniform("u_light_color", glm::vec3(1.0f, 1.0f, 1.0f));
        camera.set_uniforms(*program.get(), describer);
        texture->bind();
        cuboid->render(*program.get(), describer);

        update();
    }

    void onDestroyed()
    {
        fout.close();
    }

    void onResized(const glm::uvec2 &new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);

        camera.set_aspect(static_cast<float>(new_size.x) / static_cast<float>(new_size.y));
        camera.update_projection();
    }

    void update()
    {
        glm::vec3 pos = glm::vec3(glm::cos(yaw) * glm::cos(pitch), glm::sin(pitch), glm::sin(yaw) * glm::cos(pitch)) * 2.0f;
        camera.set_position(pos);
        camera.update_view();

        pitch += glm::radians(0.1f);
        yaw += glm::radians(1.0f);
    }
};

int main()
{
    MyApp app;
    return app.run();
}
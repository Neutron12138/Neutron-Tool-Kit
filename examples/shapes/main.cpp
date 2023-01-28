#include <iostream>
#include <fstream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::UniformDescriber describer;
    ntk::Graphics::DefaultCamera<> camera;
    ntk::Graphics::Texture2D texture;
    ntk::Graphics::ModelObject model;
    ntk::Graphics::ModelInstance instance;
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

        // 启用深度测试
        glEnable(GL_DEPTH_TEST);

        // 设置点精灵大小
        glPointSize(10.0f);

        // 面剔除
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
        // glCullFace(GL_FRONT);

        if (!program.load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        if (!texture.load_from_file("resources/2.jpg"))
            quit(EXIT_FAILURE);

        /*
        model = ntk::Graphics::ModelBuilder::create_regular_polygon_triangulated(0.25f, 36);
        */

        /*
        model = ntk::Graphics::ModelBuilder::create_lines(std::vector<glm::vec3>{glm::vec3(-1, -1, 0), glm::vec3(1, 1, 0), glm::vec3()});
        std::cout << model.get_vertices().size() << std::endl;
        */

        /*
        model = ntk::Graphics::ModelBuilder::create_cube_triangulated(1.0f);
        */

        model = ntk::Graphics::ModelBuilder::create_sphere_triangulated(1.0f, 36, 36, true);

        instance = model.create_instance();

        camera.set_position(glm::vec3(0.0f, 2.0f, 2.0f));
        camera.update_view();
        camera.set_aspect(640.0f / 480.0f);
        camera.update_projection();
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        program.use_program();
        camera.set_uniforms(program, describer);
        texture.bind();
        instance.render(program, describer);
    }

    void onDestroyed()
    {
        program.release();
        texture.release();
        model.release();
        fout.close();
    }

    void onResized(const glm::uvec2 &new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);
        camera.set_aspect(static_cast<float>(new_size.x) / static_cast<float>(new_size.y));
        camera.update_projection();
    }

    void onKeyPressed(std::uint32_t key)
    {
        sf::Keyboard::Key const k = static_cast<sf::Keyboard::Key>(key);
        float const speed = 1.0f;
        switch (k)
        {
        case sf::Keyboard::Key::W:
            instance.rotate(glm::vec3(speed, 0.0f, 0.0f));
            break;
        case sf::Keyboard::Key::S:
            instance.rotate(glm::vec3(-speed, 0.0f, 0.0f));
            break;
        case sf::Keyboard::Key::A:
            instance.rotate(glm::vec3(0.0f, -speed, 0.0f));
            break;
        case sf::Keyboard::Key::D:
            instance.rotate(glm::vec3(0.0f, speed, 0.0f));
            break;
        case sf::Keyboard::Key::Q:
            instance.rotate(glm::vec3(0.0f, 0.0f, speed));
            break;
        case sf::Keyboard::Key::E:
            instance.rotate(glm::vec3(0.0f, 0.0f, -speed));
            break;

        default:
            break;
        }
        instance.update();
    }
};

int main()
{
    MyApp app;
    return app.run();
}
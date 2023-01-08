#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    std::ofstream fout;
    std::unique_ptr<ntk::Graphics::Texture2D, ntk::Utils::GLObjectDeleter<ntk::Graphics::Texture2D>> texture;
    std::unique_ptr<ntk::Graphics::Program, ntk::Utils::ProgramDeleter> program;
    std::unique_ptr<ntk::Graphics::PointShape, ntk::Utils::ResourceDeleter<ntk::Graphics::PointShape>> point;
    std::unique_ptr<ntk::Graphics::LineShape, ntk::Utils::ResourceDeleter<ntk::Graphics::LineShape>> line;
    std::unique_ptr<ntk::Graphics::RectangleShape, ntk::Utils::ResourceDeleter<ntk::Graphics::RectangleShape>> rect;
    std::unique_ptr<ntk::Graphics::CircleShape, ntk::Utils::ResourceDeleter<ntk::Graphics::CircleShape>> circle;

public:
    MyApp() : ntk::Window::SFApplication("Shape", glm::ivec2(640, 480)) {}
    ~MyApp() {}

public:
    virtual void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_SUCCESS);

        texture.reset(new ntk::Graphics::Texture2D());
        if (!texture->load_from_file("textures/image.jpg"))
            quit(EXIT_FAILURE);

        program.reset(new ntk::Graphics::Program());
        if (!program->load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        point.reset(new ntk::Graphics::PointShape(glm::vec2(-0.5f, -0.5f)));
        point->generate_shape();
        point->set_fill_color(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
        glPointSize(10.0f);

        line.reset(new ntk::Graphics::LineShape(glm::vec2(-0.5f, 0.5f), glm::vec2(0.5f, -0.5f)));
        line->set_shape_position(glm::vec2(-0.5f, 0.0f));
        line->generate_shape();
        line->set_fill_color(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
        glLineWidth(5.0f);

        rect.reset(new ntk::Graphics::RectangleShape(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.5f)));
        rect->set_shape_position(glm::vec2(0.25f, -0.5f));
        rect->set_outline_width(0.05f);
        rect->generate_shape();
        rect->set_fill_color(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        rect->set_outline_color(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

        circle.reset(new ntk::Graphics::CircleShape(0.5f));
        circle->set_shape_position(glm::vec2(0.25f, 0.5f));
        circle->set_outline_width(0.05f);
        circle->generate_shape();
        circle->set_fill_color(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
        circle->set_outline_color(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

        glViewport(0, 0, 640, 480);
    }

    virtual void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        program->use_program();
        texture->bind();
        point->render(*program.get(), ntk::Graphics::UniformDescriber());
        line->render(*program.get(), ntk::Graphics::UniformDescriber());
        rect->render(*program.get(), ntk::Graphics::UniformDescriber());
        circle->render(*program.get(), ntk::Graphics::UniformDescriber());
    }

    virtual void onDestroyed()
    {
        fout.close();
    }

    virtual void onResized(const glm::uvec2 &new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);
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
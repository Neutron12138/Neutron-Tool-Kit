#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::VertexArrayObject vao;
    ntk::Graphics::Texture2D texture;
    std::ofstream fout;
    bool first = true;

public:
    MyApp() : ntk::Window::SFApplication("Texture", glm::ivec2(640, 480)) {}

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        if (!program.load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        if (!texture.load_from_file("textures/image.jpg"))
            quit(EXIT_FAILURE);

        vao = ntk::Graphics::ModelBuilder().create_quad_triangulated().generate_VAO();
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        vao.bind();
        texture.bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);
        texture.unbind();
        vao.unbind();

        if (first)
        {
            ntk::Utils::Timer timer;
            timer.start();

            std::uint8_t *pixels = new std::uint8_t[640 * 480 * 3];
            glReadPixels(0, 0, 640, 480, GL_RGB, GL_UNSIGNED_BYTE, pixels);
            ntk::Utils::Image image;
            image.own_from_memory(640, 480, ntk::Utils::ColorChannel::ColorChannel::RGB, pixels);
            image.write_as_png("output.png");
            image.release();

            timer.stop();
            ntk::Instance::log.logi("", ntk::Instance::string_utils.to_string("total time:", timer.get_total_time().as_seconds(), " seconds"));

            first = false;
        }
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        vao.delete_object();
        texture.delete_object();
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
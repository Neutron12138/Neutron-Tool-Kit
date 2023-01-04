#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::PrimitiveSprite sprite;
    ntk::Graphics::TrueTypeFont font;
    std::ofstream fout;

public:
    MyApp() : ntk::Window::SFApplication("Glyph", glm::ivec2(640, 480)) {}

public:
    void onCreated()
    {
        fout.open("log.txt");
        ntk::Instance::log.set_output(&fout);

        if (!ntk::Graphics::loadGL())
            quit(EXIT_FAILURE);

        if (!program.load_from_file("shaders/1.vert", "shaders/1.frag"))
            quit(EXIT_FAILURE);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        if (!font.load_font("resources/simsun.ttc"))
            quit(EXIT_FAILURE);
        if (!font.load_glyph('6', 48))
            quit(EXIT_FAILURE);
        font.close_font();

        sprite = ntk::Graphics::PrimitiveSprite(ntk::Graphics::ModelBuilder().create_quad_triangulated().generate_VAO(), ntk::Graphics::PrimitiveType::PrimitiveType::Triangles, 6);
        ntk::Graphics::GlyphCollection *gc = font.get_glyph('6');
        if (gc != nullptr)
        {
            ntk::Graphics::Glyph *glyph = gc->get_glyph(48);
            if (glyph != nullptr)
            {
                sprite.set_scale(glm::vec3(1.0f, static_cast<float>(glyph->get_size().y) / static_cast<float>(glyph->get_size().x), 1.0f));
            }
        }
        sprite.update();
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        ntk::Graphics::GlyphCollection *gc = font.get_glyph('6');
        if (gc != nullptr)
        {
            ntk::Graphics::Glyph *glyph = gc->get_glyph(48);
            if (glyph != nullptr)
            {
                glyph->bind_texture();
            }
        }
        sprite.render(program);
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        sprite.release();
        font.release_all();
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
#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::TrueTypeFont<> font;
    ntk::Graphics::Text<std::wstring> text;
    std::ofstream fout;
    glm::vec2 scale;

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

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        if (!font.load_font("resources/simsun.ttc"))
            quit(EXIT_FAILURE);

        std::wstring str = L"中文符号会出问题！\n比如像这样没对齐。\n不知道是我的问题还是怎么样";
        text.set_shape_position(glm::vec2(-0.5f, 0.0f));
        text.generate_shape();
        text.set_text(str);
        text.set_font(&font);
        // text.set_multi_line(false);

        scale = 2.0f / glm::vec2(640.0f, 480.0f);
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        text.render(scale);
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        text.release();
        font.close_font();
        font.release_all();
        fout.close();
    }

    void onResized(const glm::uvec2 &new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);
        scale = 2.0f / glm::vec2(static_cast<float>(new_size.x), static_cast<float>(new_size.y));
    }
};

int main()
{
    MyApp app;
    return app.run();
}
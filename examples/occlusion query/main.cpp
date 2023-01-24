#include <iostream>
#include <fstream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::VertexAttribDescriber describer;
    ntk::Graphics::ModelObject model;
    ntk::Graphics::ModelInstance instance;
    ntk::Graphics::OcclusionQuery query;
    bool first;
    bool second;
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

        model = ntk::Graphics::ModelBuilder::create_quad_triangulated();
        instance = model.create_instance();

        query.generate();
        first = true;
        second = true;
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        if (first)
        {
            query.begin_query(ntk::Graphics::OcclusionQuery::QueryType::Accurate);
            instance.render();
            query.end_query();
            first = false;
        }
        else
        {
            query.begin_conditional_render(ntk::Graphics::OcclusionQuery::ConditionalRenderType::Wait);
            instance.render();
            query.end_conditional_render();
            if (second)
            {
                if (query.is_result_available())
                {
                    std::cout << "result:" << query.check_result() << std::endl;
                    std::cout << "any passed:" << (query.any_passed() ? "true" : "false") << std::endl;
                    second = false;
                }
            }
        }
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        model.release();
        query.delete_object();
        fout.close();
    }

    void onResized(const glm::uvec2 &new_size)
    {
        glViewport(0, 0, new_size.x, new_size.y);
        first = true;
        second = true;
    }
};

int main()
{
    MyApp app;
    return app.run();
}
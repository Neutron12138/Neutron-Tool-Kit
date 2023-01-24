#include <iostream>
#include <fstream>
#include <vector>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

class alignas(1) MyInstancingData : public ntk::Graphics::InstancingData
{
public:
    glm::vec2 m_position;
    glm::vec3 m_color;

public:
    MyInstancingData(const glm::vec2 &position, const glm::vec3 &color) : m_position(position), m_color(color) {}
    ~MyInstancingData() = default;
};

class MyInstancingDataArray : public ntk::Graphics::InstancingDataArray<MyInstancingData>
{
public:
    MyInstancingDataArray() = default;
    MyInstancingDataArray(const std::vector<MyInstancingData> &data) : ntk::Graphics::InstancingDataArray<MyInstancingData>(data) {}
    ~MyInstancingDataArray() = default;

public:
    virtual ntk::Graphics::VertexBufferObject generate_VBO()
    {
        const std::vector<MyInstancingData> &data = ntk::Graphics::InstancingDataArray<MyInstancingData>::m_data;
        ntk::Graphics::VertexBufferObject vbo;
        vbo.generate();
        vbo.bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(MyInstancingData) * size(), data.data(), GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MyInstancingData), nullptr);
        glVertexAttribDivisor(1, 1);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(MyInstancingData), reinterpret_cast<const void *>(sizeof(glm::vec2)));
        glVertexAttribDivisor(2, 1);
        return vbo;
    }

    virtual ntk::Graphics::VertexBufferObject generate_VBO(const ntk::Graphics::BasicProgram &, const ntk::Graphics::VertexAttribDescriber &)
    {
        return ntk::Graphics::VertexBufferObject();
    }
};

class MyApp : public ntk::Window::SFApplication
{
private:
    ntk::Graphics::Program program;
    ntk::Graphics::InstancedModelObject<MyInstancingDataArray> model;
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

        std::vector<MyInstancingData> data =
            {
                MyInstancingData(glm::vec2(0.25f, 0.25f), glm::vec3(1.0f, 0.0f, 0.0f)),
                MyInstancingData(glm::vec2(-0.25f, 0.25f), glm::vec3(0.0f, 1.0f, 0.0f)),
                MyInstancingData(glm::vec2(-0.25f, -0.25f), glm::vec3(0.0f, 0.0f, 1.0f)),
                MyInstancingData(glm::vec2(0.25f, -0.25f), glm::vec3(1.0f, 1.0f, 0.0f)),
            };

        model = ntk::Graphics::InstancedModelObject<MyInstancingDataArray>(ntk::Graphics::ModelBuilder::create_quad_triangulated(glm::vec2(0.25f, 0.25f)), MyInstancingDataArray(data));
    }

    void onDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use_program();
        model.render();
    }

    void onDestroyed()
    {
        program.delete_object();
        program.delete_shaders();
        model.release();
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
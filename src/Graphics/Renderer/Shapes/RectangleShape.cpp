#ifndef __NEUTRON_GRAPHICS_RECTANGLESHAPE_CPP__
#define __NEUTRON_GRAPHICS_RECTANGLESHAPE_CPP__

#include "RectangleShape.hpp"
#include "../../Vertex/VertexArrayObject.hpp"
#include "../../Vertex/VertexAttributeEnum.hpp"

namespace ntk
{
    namespace Graphics
    {
        RectangleShape::RectangleShape() : BaseShape() {}
        RectangleShape::RectangleShape(const glm::vec2 &position, const glm::vec2 &size) : BaseShape(position), m_shape_size(size) {}
        RectangleShape::RectangleShape(const RectangleShape &from) { *this = from; }
        RectangleShape::~RectangleShape() {}

        RectangleShape &RectangleShape::operator=(const RectangleShape &from)
        {
            BaseShape::operator=(from);
            m_shape_size = from.m_shape_size;
            return *this;
        }

        const glm::vec2 &RectangleShape::get_shape_size() const
        {
            return m_shape_size;
        }

        void RectangleShape::set_shape_size(const glm::vec2 &size)
        {
            m_shape_size = size;
        }

        void RectangleShape::generate_shape()
        {
            m_primitive_type = PrimitiveType::TriangleFan;
            m_vertex_count = 4;

            std::vector<glm::vec2> texCoords =
                {
                    glm::vec2(0.0f, 0.0f),
                    glm::vec2(0.0f, 1.0f),
                    glm::vec2(1.0f, 1.0f),
                    glm::vec2(1.0f, 0.0f),
                };

            m_VAO.generate();
            m_VAO.bind();
            m_VBOs.at(BaseShape::VBOIndex::Vertices) = VertexBufferObject::createVBO_single(4 * sizeof(glm::vec3), nullptr, GL_STATIC_DRAW, VertexAttributeEnum::VertexAttributeLocation::Position, 3, GL_FLOAT, sizeof(glm::vec3));
            m_VBOs.at(BaseShape::VBOIndex::TexCoords) = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_VBOs.at(BaseShape::VBOIndex::Colors) = VertexBufferObject::createVBO_single(4 * sizeof(glm::vec4), nullptr, GL_STATIC_DRAW, VertexAttributeEnum::VertexAttributeLocation::Color, 4, GL_FLOAT, sizeof(glm::vec4));
            m_VAO.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            update_VAO();
        }

        void RectangleShape::update_VAO()
        {
            float x = m_shape_position.x;
            float y = m_shape_position.y;
            float w = m_shape_size.x;
            float h = m_shape_size.y;
            std::vector<glm::vec3> vertices =
                {
                    glm::vec3(x, y, 0.0f),
                    glm::vec3(x, y - h, 0.0f),
                    glm::vec3(x + w, y - h, 0.0f),
                    glm::vec3(x + w, y, 0.0f),
                };

            m_VAO.bind();
            m_VBOs.at(BaseShape::VBOIndex::Vertices).bind();
            m_VBOs.at(BaseShape::VBOIndex::Vertices).sub_data(vertices);
            m_VAO.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    } // namespace Graphics

} // namespace ntk

#endif
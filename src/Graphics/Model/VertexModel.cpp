#ifndef __NEUTRON_GRAPHICS_VERTEXMODEL_CPP__
#define __NEUTRON_GRAPHICS_VERTEXMODEL_CPP__

#include "VertexModel.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        // Vertex的内存布局（BasicVertex<glm::vec3,glm::vec3,glm::vec2>）
        //     vtable      8字节
        // m_position    3*4字节
        //   m_normal    3*4字节
        // m_texCoord    2*4字节
        //      total     40字节

        // 所以TriangleFace无法作为VertexArray模板m_VertexType的参数
        // 因为TriangleFace自带一个虚函数表位于最前端
        // TriangleFace内存布局：vtable,vertex0,vertex1,vertex2

        BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::BasicVertexModel(const typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ContainerType &vertices) : BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::BasicVertexModel::ParentType(vertices) {}

        void BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::push_back(const typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType &vertex)
        {
            BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ParentType::m_vertices.push_back(vertex);
        }

        void BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::pop_back(const typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType &vertex)
        {
            BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ParentType::m_vertices.pop_back();
        }

        void BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::generate_VAO(VertexArrayObject &VAO, GLenum usage)
        {
            VertexBufferObject VBO;
            generate_VAO(VAO, VBO, usage);
            VBO.release();
        }

        void BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, GLenum usage)
        {
            VAO.generate();
            VAO.bind();

            VBO.generate();
            VBO.bind();

            const BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ContainerType &vertices = BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ParentType::m_vertices;

            // 虚函数表的大小
            const GLsizei vt_size = 8;
            // 顶点大小
            const GLsizei v_size = static_cast<GLsizei>(sizeof(typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType));
            // 顶点数据偏移，Vertex的虚函数表（8字节）
            const GLsizei v_offset = vt_size;
            // 法线数据偏移，顶点数据偏移+顶点尺寸（12字节）
            const GLsizei n_offset = v_offset + static_cast<GLsizei>(sizeof(typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType::PositionType));
            // 纹理坐标数据偏移，法线数据偏移+法线尺寸（12字节）
            const GLsizei t_offset = n_offset + static_cast<GLsizei>(sizeof(typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType::NormalType));

            const GLint position = static_cast<GLint>(VertexAttributeEnum::VertexAttributeLocation::Position);
            const GLint normal = static_cast<GLint>(VertexAttributeEnum::VertexAttributeLocation::Normal);
            const GLint texCoord = static_cast<GLint>(VertexAttributeEnum::VertexAttributeLocation::TexCoord);

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices.size()) * v_size, vertices.data(), usage);

            glEnableVertexAttribArray(position);
            glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, v_size, reinterpret_cast<const void *>(v_offset));

            glEnableVertexAttribArray(normal);
            glVertexAttribPointer(normal, 3, GL_FLOAT, GL_FALSE, v_size, reinterpret_cast<const void *>(n_offset));

            glEnableVertexAttribArray(texCoord);
            glVertexAttribPointer(texCoord, 2, GL_FLOAT, GL_FALSE, v_size, reinterpret_cast<const void *>(t_offset));

            VAO.unbind();
            VBO.unbind();
        }

        void BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::generate_VAO(VertexArrayObject &VAO, const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            VertexBufferObject VBO;
            generate_VAO(VAO, VBO, program, describer, usage);
            VBO.release();
        }

        void BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            VAO.generate();
            VAO.bind();

            VBO.generate();
            VBO.bind();

            const BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ContainerType &vertices = BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::ParentType::m_vertices;

            // 虚函数表的大小
            const GLsizei vt_size = 8;
            // 顶点大小
            const GLsizei v_size = static_cast<GLsizei>(sizeof(typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType));
            // 顶点数据偏移，Vertex的虚函数表（8字节）
            const GLsizei v_offset = vt_size;
            // 法线数据偏移，顶点数据偏移+顶点尺寸（12字节）
            const GLsizei n_offset = v_offset + static_cast<GLsizei>(sizeof(typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType::PositionType));
            // 纹理坐标数据偏移，法线数据偏移+法线尺寸（12字节）
            const GLsizei t_offset = n_offset + static_cast<GLsizei>(sizeof(typename BasicVertexModel<Vertex, Transform, std::vector<Vertex>>::VertexType::NormalType));

            const GLint position = glGetAttribLocation(program.get_objectID(), describer.get_name(VertexAttributeEnum::VertexAttributeLocation::Position).data());
            const GLint normal = glGetAttribLocation(program.get_objectID(), describer.get_name(VertexAttributeEnum::VertexAttributeLocation::Normal).data());
            const GLint texCoord = glGetAttribLocation(program.get_objectID(), describer.get_name(VertexAttributeEnum::VertexAttributeLocation::TexCoord).data());

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices.size()) * v_size, vertices.data(), usage);

            if (position != -1)
            {
                glEnableVertexAttribArray(position);
                glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, v_size, reinterpret_cast<const void *>(v_offset));
            }

            if (normal != -1)
            {
                glEnableVertexAttribArray(normal);
                glVertexAttribPointer(normal, 3, GL_FLOAT, GL_FALSE, v_size, reinterpret_cast<const void *>(n_offset));
            }

            if (texCoord != -1)
            {
                glEnableVertexAttribArray(texCoord);
                glVertexAttribPointer(texCoord, 2, GL_FLOAT, GL_FALSE, v_size, reinterpret_cast<const void *>(t_offset));
            }

            VAO.unbind();
            VBO.unbind();
        }
    } // namespace Graphics

} // namespace ntk

#endif
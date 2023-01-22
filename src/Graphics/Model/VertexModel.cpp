#ifndef __NEUTRON_GRAPHICS_TRIANGULATEDMODEL_CPP__
#define __NEUTRON_GRAPHICS_TRIANGULATEDMODEL_CPP__

#include "VertexModel.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexModel() {}
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexModel(const typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::ContainerType &vertices) : VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexModel::ParentType(vertices) {}
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexModel(const typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &from) { *this = from; }
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::~VertexModel() {}

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::operator=(const typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &from)
        {
            VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::ParentType::operator=(from);
            return *this;
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        void VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::generate_VAO(VertexArrayObject &VAO, const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            VertexBufferObject VBO;
            generate_VAO(VAO, VBO, program, describer, usage);
            VBO.delete_object();
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        void VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            VAO.generate();
            VAO.bind();

            VBO.generate();
            VBO.bind();

            const VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::ContainerType &vertices = VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::ParentType::m_vertices;

            // 虚函数表的大小
            const GLsizei vt_size = 8;
            // 顶点大小
            const GLsizei v_size = static_cast<GLsizei>(sizeof(typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexType));
            // 顶点数据偏移，Vertex的虚函数表
            const GLsizei v_offset = vt_size;
            // 法线数据偏移，顶点数据偏移+顶点尺寸
            const GLsizei n_offset = v_offset + static_cast<GLsizei>(sizeof(typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexType::PositionType));
            // 纹理坐标数据偏移，法线数据偏移+法线尺寸
            const GLsizei t_offset = n_offset + static_cast<GLsizei>(sizeof(typename VertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexType::NormalType));

            GLint position = glGetAttribLocation(program.get_objectID(), describer.get_name(VertexAttributeEnum::VertexAttributeLocation::Position).data());
            GLint normal = glGetAttribLocation(program.get_objectID(), describer.get_name(VertexAttributeEnum::VertexAttributeLocation::Normal).data());
            GLint texCoord = glGetAttribLocation(program.get_objectID(), describer.get_name(VertexAttributeEnum::VertexAttributeLocation::TexCoord).data());

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
#ifndef __NEUTRON_GRAPHICS_MODEl_CPP__
#define __NEUTRON_GRAPHICS_MODEL_CPP__

#include "Model.hpp"
#include "../Buffer/VertexBufferObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        Model<m_VertexType, m_NormalType, m_TexCoordType>::Model() {}

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        Model<m_VertexType, m_NormalType, m_TexCoordType>::Model(const std::vector<m_VertexType> &vertices, const std::vector<m_NormalType> &normals, const std::vector<m_TexCoordType> &texCoords) : m_vertices(vertices), m_normals(normals), m_texCoords(texCoords) {}

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        Model<m_VertexType, m_NormalType, m_TexCoordType>::Model(const Model &from) { *this = from; }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        Model<m_VertexType, m_NormalType, m_TexCoordType>::~Model() {}

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        Model<m_VertexType, m_NormalType, m_TexCoordType> &Model<m_VertexType, m_NormalType, m_TexCoordType>::operator=(const Model<m_VertexType, m_NormalType, m_TexCoordType> &from)
        {
            m_vertices = from.m_vertices;
            m_normals = from.m_normals;
            m_texCoords = from.m_texCoords;
            return *this;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        const std::vector<m_VertexType> &Model<m_VertexType, m_NormalType, m_TexCoordType>::get_vertices() const
        {
            return m_vertices;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        const std::vector<m_NormalType> &Model<m_VertexType, m_NormalType, m_TexCoordType>::get_normals() const
        {
            return m_normals;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        const std::vector<m_TexCoordType> &Model<m_VertexType, m_NormalType, m_TexCoordType>::get_texCoords() const
        {
            return m_texCoords;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        void Model<m_VertexType, m_NormalType, m_TexCoordType>::set_vertices(const std::vector<m_VertexType> &vertices)
        {
            vertices = vertices;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        void Model<m_VertexType, m_NormalType, m_TexCoordType>::set_normals(const std::vector<m_NormalType> &normals)
        {
            normals = normals;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        void Model<m_VertexType, m_NormalType, m_TexCoordType>::set_texCoords(const std::vector<m_TexCoordType> &texCoords)
        {
            texCoords = texCoords;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        const m_VertexType &Model<m_VertexType, m_NormalType, m_TexCoordType>::get_vertex(size_t index) const
        {
            return m_vertices.at(index);
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        const m_NormalType &Model<m_VertexType, m_NormalType, m_TexCoordType>::get_normal(size_t index) const
        {
            return m_normals.at(index);
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        const m_TexCoordType &Model<m_VertexType, m_NormalType, m_TexCoordType>::get_texCoord(size_t index) const
        {
            return m_texCoords.at(index);
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        void Model<m_VertexType, m_NormalType, m_TexCoordType>::set_vertex(size_t index, const m_VertexType &vertex)
        {
            m_vertices.at(index) = vertex;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        void Model<m_VertexType, m_NormalType, m_TexCoordType>::set_normal(size_t index, const m_NormalType &normal)
        {
            m_normals.at(index) = normal;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        void Model<m_VertexType, m_NormalType, m_TexCoordType>::set_texCoord(size_t index, const m_TexCoordType &texCoord)
        {
            m_texCoords.at(index) = texCoord;
        }

        template <typename m_VertexType, typename m_NormalType, typename m_TexCoordType>
        VertexArrayObject Model<m_VertexType, m_NormalType, m_TexCoordType>::generate_VAO()
        {
            VertexArrayObject VAO;
            VAO.generate();
            VAO.bind();
            VertexBufferObject VBO1 = VertexBufferObject::createVBO_single(m_vertices, 0, GL_STATIC_DRAW);
            VertexBufferObject VBO2 = VertexBufferObject::createVBO_single(m_normals, 1, GL_STATIC_DRAW);
            VertexBufferObject VBO3 = VertexBufferObject::createVBO_single(m_texCoords, 2, GL_STATIC_DRAW);
            VAO.unbind();
            VBO1.unbind();
            VBO1.delete_object();
            VBO2.delete_object();
            VBO3.delete_object();
            return VAO;
        }
    } // namespace Graphics

} // namespace ntk

#endif
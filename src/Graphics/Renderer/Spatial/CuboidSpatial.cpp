#ifndef __NEUTRON_GRAPHICS_CUBOIDSPATIAL_CPP__
#define __NEUTRON_GRAPHICS_CUBOIDSPATIAL_CPP__

#include "CuboidSpatial.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_MaterialType>
        CuboidSpatial<m_MaterialType>::CuboidSpatial() : BaseSpatial<m_MaterialType>() {}
        template <typename m_MaterialType>
        CuboidSpatial<m_MaterialType>::CuboidSpatial(const glm::vec3 &position, const glm::vec3 &size) : BaseSpatial<m_MaterialType>(), m_cuboid_position(position), m_cuboid_size(size) {}
        template <typename m_MaterialType>
        CuboidSpatial<m_MaterialType>::CuboidSpatial(const CuboidSpatial<m_MaterialType> &from) { *this = from; }
        template <typename m_MaterialType>
        CuboidSpatial<m_MaterialType>::~CuboidSpatial() {}

        template <typename m_MaterialType>
        CuboidSpatial<m_MaterialType> &CuboidSpatial<m_MaterialType>::operator=(const CuboidSpatial<m_MaterialType> &from)
        {
            BaseSpatial<m_MaterialType>::operator=(from);
            m_cuboid_position = from.m_cuboid_position;
            m_cuboid_size = from.m_cuboid_size;
            return *this;
        }

        template <typename m_MaterialType>
        const glm::vec3 &CuboidSpatial<m_MaterialType>::get_cuboid_position() const
        {
            return m_cuboid_position;
        }

        template <typename m_MaterialType>
        void CuboidSpatial<m_MaterialType>::set_cuboid_position(const glm::vec3 &position)
        {
            m_cuboid_position = position;
        }

        template <typename m_MaterialType>
        const glm::vec3 &CuboidSpatial<m_MaterialType>::get_cuboid_size() const
        {
            return m_cuboid_size;
        }

        template <typename m_MaterialType>
        void CuboidSpatial<m_MaterialType>::set_cuboid_size(const glm::vec3 &size)
        {
            m_cuboid_size = size;
        }

        template <typename m_MaterialType>
        void CuboidSpatial<m_MaterialType>::generate_shape()
        {
            const glm::vec3 pos = CuboidSpatial<m_MaterialType>::m_spatial_position + CuboidSpatial<m_MaterialType>::m_cuboid_position;
            const glm::vec3 half = CuboidSpatial<m_MaterialType>::m_cuboid_size / 2.0f;

            glm::vec3 v0 = pos + glm::vec3(-half.x, half.y, half.z);
            glm::vec3 v1 = pos + glm::vec3(-half.x, -half.y, half.z);
            glm::vec3 v2 = pos + glm::vec3(half.x, -half.y, half.z);
            glm::vec3 v3 = pos + glm::vec3(half.x, half.y, half.z);
            glm::vec3 v4 = pos + glm::vec3(-half.x, half.y, -half.z);
            glm::vec3 v5 = pos + glm::vec3(-half.x, -half.y, -half.z);
            glm::vec3 v6 = pos + glm::vec3(half.x, -half.y, -half.z);
            glm::vec3 v7 = pos + glm::vec3(half.x, half.y, -half.z);

            glm::vec3 n0 = glm::vec3(0.0f, 0.0f, 1.0f);
            glm::vec3 n1 = glm::vec3(1.0f, 0.0f, 0.0f);
            glm::vec3 n2 = glm::vec3(0.0f, 1.0f, 0.0f);
            glm::vec3 n3 = glm::vec3(0.0f, 0.0f, -1.0f);
            glm::vec3 n4 = glm::vec3(-1.0f, 0.0f, 0.0f);
            glm::vec3 n5 = glm::vec3(0.0f, -1.0f, 0.0f);

            glm::vec2 t0 = glm::vec2(0.0f, 0.0f);
            glm::vec2 t1 = glm::vec2(0.0f, 0.0f);
            glm::vec2 t2 = glm::vec2(0.0f, 0.0f);
            glm::vec2 t3 = glm::vec2(0.0f, 0.0f);

            std::vector<glm::vec3> vertices =
                {
                    // 正Z轴
                    v0,
                    v1,
                    v2,

                    v0,
                    v2,
                    v3,

                    // 正X轴
                    v3,
                    v2,
                    v6,

                    v3,
                    v6,
                    v7,

                    // 正Y轴
                    v0,
                    v3,
                    v7,

                    v0,
                    v7,
                    v4,

                    // 负Z轴
                    v7,
                    v6,
                    v5,

                    v7,
                    v5,
                    v4,

                    // 负X轴
                    v4,
                    v5,
                    v1,

                    v4,
                    v1,
                    v0,

                    // 负Y轴
                    v1,
                    v5,
                    v6,

                    v1,
                    v6,
                    v2,
                };

            std::vector<glm::vec3> normals =
                {
                    n0,
                    n0,
                    n0,

                    n0,
                    n0,
                    n0,

                    n1,
                    n1,
                    n1,

                    n1,
                    n1,
                    n1,

                    n2,
                    n2,
                    n2,

                    n2,
                    n2,
                    n2,

                    n3,
                    n3,
                    n3,

                    n3,
                    n3,
                    n3,

                    n4,
                    n4,
                    n4,

                    n4,
                    n4,
                    n4,

                    n5,
                    n5,
                    n5,

                    n5,
                    n5,
                    n5,
                };

            std::vector<glm::vec2> texCoords =
                {
                    t0,
                    t1,
                    t2,

                    t0,
                    t2,
                    t3,

                    t0,
                    t1,
                    t2,

                    t0,
                    t2,
                    t3,

                    t0,
                    t1,
                    t2,

                    t0,
                    t2,
                    t3,

                    t0,
                    t1,
                    t2,

                    t0,
                    t2,
                    t3,

                    t0,
                    t1,
                    t2,

                    t0,
                    t2,
                    t3,

                    t0,
                    t1,
                    t2,

                    t0,
                    t2,
                    t3,
                };

            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.generate();
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.bind();
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_buffer = VertexBufferObject::createVBO_single(vertices, VertexAttributeEnum::VertexAttributeLocation::Position);
            CuboidSpatial<m_MaterialType>::m_vertices.normal_buffer = VertexBufferObject::createVBO_single(normals, VertexAttributeEnum::VertexAttributeLocation::Normal);
            CuboidSpatial<m_MaterialType>::m_vertices.texCoord_buffer = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        template <typename m_MaterialType>
        void CuboidSpatial<m_MaterialType>::update_VAO()
        {
            const glm::vec3 pos = CuboidSpatial<m_MaterialType>::m_spatial_position + CuboidSpatial<m_MaterialType>::m_cuboid_position;
            const glm::vec3 half = CuboidSpatial<m_MaterialType>::m_cuboid_size / 2.0f;

            glm::vec3 v0 = pos + glm::vec3(-half.x, half.y, half.z);
            glm::vec3 v1 = pos + glm::vec3(-half.x, -half.y, half.z);
            glm::vec3 v2 = pos + glm::vec3(half.x, -half.y, half.z);
            glm::vec3 v3 = pos + glm::vec3(half.x, half.y, half.z);
            glm::vec3 v4 = pos + glm::vec3(-half.x, half.y, -half.z);
            glm::vec3 v5 = pos + glm::vec3(-half.x, -half.y, -half.z);
            glm::vec3 v6 = pos + glm::vec3(half.x, -half.y, -half.z);
            glm::vec3 v7 = pos + glm::vec3(half.x, half.y, -half.z);

            std::vector<glm::vec3> vertices =
                {
                    // 正Z轴
                    v0,
                    v1,
                    v2,

                    v0,
                    v2,
                    v3,

                    // 正X轴
                    v3,
                    v2,
                    v6,

                    v3,
                    v6,
                    v7,

                    // 正Y轴
                    v0,
                    v3,
                    v7,

                    v0,
                    v7,
                    v4,

                    // 负Z轴
                    v7,
                    v6,
                    v5,

                    v7,
                    v5,
                    v4,

                    // 负X轴
                    v4,
                    v5,
                    v1,

                    v4,
                    v1,
                    v0,

                    // 负Y轴
                    v1,
                    v5,
                    v6,

                    v1,
                    v6,
                    v2,
                };

            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.bind();
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_buffer.bind();
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_buffer.sub_data(vertices);
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        template <typename m_MaterialType>
        void CuboidSpatial<m_MaterialType>::render()
        {
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.bind();
            glDrawArrays(GL_TRIANGLES, 0, 36);
            CuboidSpatial<m_MaterialType>::m_vertices.vertex_array.unbind();
        }

        template <typename m_MaterialType>
        void CuboidSpatial<m_MaterialType>::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            BaseSpatial<m_MaterialType>::render(binder, describer);
            render();
        }
    } // namespace Graphics

} // namespace ntk

#endif
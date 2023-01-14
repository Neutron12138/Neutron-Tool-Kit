#ifndef __NEUTRON_GRAPHICS_BASESPATIAL_CPP__
#define __NEUTRON_GRAPHICS_BASESPATIAL_CPP__

#include "BaseSpatial.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::VertexData::VertexData() {}
        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::VertexData::VertexData(const BaseSpatial<m_MaterialType>::VertexData &from) { *this = from; }
        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::VertexData::~VertexData() {}

        template <typename m_MaterialType>
        typename BaseSpatial<m_MaterialType>::VertexData &BaseSpatial<m_MaterialType>::VertexData::operator=(const BaseSpatial<m_MaterialType>::VertexData &from)
        {
            vertex_array = from.vertex_array;
            vertex_buffer = from.vertex_buffer;
            normal_buffer = from.normal_buffer;
            texCoord_buffer = from.texCoord_buffer;
            material = from.material;
            return *this;
        }

        template <typename m_MaterialType>
        void BaseSpatial<m_MaterialType>::VertexData::release()
        {
            vertex_array.delete_object();
            vertex_buffer.delete_object();
            normal_buffer.delete_object();
            texCoord_buffer.delete_object();
        }

        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::BaseSpatial() : Sprite() {}
        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::BaseSpatial(const glm::vec3 &position) : Sprite(), m_spatial_position(position) {}
        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::BaseSpatial(const BaseSpatial<m_MaterialType> &from) { *this = from; }
        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType>::~BaseSpatial() {}

        template <typename m_MaterialType>
        BaseSpatial<m_MaterialType> &BaseSpatial<m_MaterialType>::operator=(const BaseSpatial<m_MaterialType> &from)
        {
            Sprite::operator=(from);
            m_spatial_position = from.m_spatial_position;
            m_vertices = from.m_vertices;
            return *this;
        }

        template <typename m_MaterialType>
        const glm::vec3 &BaseSpatial<m_MaterialType>::get_spatial_position() const
        {
            return m_spatial_position;
        }

        template <typename m_MaterialType>
        void BaseSpatial<m_MaterialType>::set_spatial_position(const glm::vec3 &position)
        {
            m_spatial_position = position;
        }

        template <typename m_MaterialType>
        const m_MaterialType &BaseSpatial<m_MaterialType>::get_material() const
        {
            return m_vertices.material;
        }

        template <typename m_MaterialType>
        void BaseSpatial<m_MaterialType>::set_material(const m_MaterialType &material)
        {
            m_vertices.material = material;
        }

        template <typename m_MaterialType>
        Sprite::PositionType BaseSpatial<m_MaterialType>::get_position()
        {
            return m_translation + m_spatial_position;
        }

        template <typename m_MaterialType>
        void BaseSpatial<m_MaterialType>::release()
        {
            m_vertices.release();
        }

        template <typename m_MaterialType>
        void BaseSpatial<m_MaterialType>::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ModelMatrix), BaseSpatial<m_MaterialType>::get_matrix());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Material_Ambient), BaseSpatial<m_MaterialType>::m_vertices.material.get_ambient());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Material_Diffuse), BaseSpatial<m_MaterialType>::m_vertices.material.get_diffuse());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Material_Specular), BaseSpatial<m_MaterialType>::m_vertices.material.get_specular());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Material_Emission), BaseSpatial<m_MaterialType>::m_vertices.material.get_emission());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Material_Shininess), BaseSpatial<m_MaterialType>::m_vertices.material.get_shininess());
        }
    } // namespace Graphics

} // namespace ntk

#endif
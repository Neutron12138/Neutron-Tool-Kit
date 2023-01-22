#ifndef __NEUTRON_GRAPHICS_MODELOBJECT_CPP__
#define __NEUTRON_GRAPHICS_MODELOBJECT_CPP__

#include "ModelObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexModelType>
        ModelObject<m_VertexModelType>::ModelObject(const typename ModelObject<m_VertexModelType>::VertexModelType &model) : ModelObject::ParentType(model) { update_VAO(); }

        template <typename m_VertexModelType>
        const VertexArrayObject &ModelObject<m_VertexModelType>::get_VAO() const
        {
            return m_VAO;
        }

        template <typename m_VertexModelType>
        const VertexBufferObject &ModelObject<m_VertexModelType>::get_VBO() const
        {
            return m_VBO;
        }

        template <typename m_VertexModelType>
        ModelInstance ModelObject<m_VertexModelType>::create_instance()
        {
            return ModelInstance(m_VAO);
        }

        template <typename m_VertexModelType>
        void ModelObject<m_VertexModelType>::update_VAO(GLenum usage)
        {
            release();
            ModelObject<m_VertexModelType>::ParentType::generate_VAO(m_VAO, m_VBO, usage);
        }

        template <typename m_VertexModelType>
        void ModelObject<m_VertexModelType>::update_VAO(const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            release();
            ModelObject<m_VertexModelType>::ParentType::generate_VAO(m_VAO, m_VBO, program, describer, usage);
        }

        template <typename m_VertexModelType>
        void ModelObject<m_VertexModelType>::release()
        {
            m_VBO.delete_object();
            m_VAO.delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif
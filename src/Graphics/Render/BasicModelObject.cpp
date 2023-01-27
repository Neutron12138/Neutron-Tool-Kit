#ifndef __NEUTRON_GRAPHICS_BASICMODELOBJECT_CPP__
#define __NEUTRON_GRAPHICS_BASICMODELOBJECT_CPP__

#include "BasicModelObject.hpp"
#include "../../Utils/Exception/NullPointerException.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexModelType>
        BasicModelObject<m_VertexModelType>::BasicModelObject(const typename BasicModelObject<m_VertexModelType>::VertexModelType &model) : BasicModelObject<m_VertexModelType>::ParentType(model) { update_VAO(); }

        template <typename m_VertexModelType>
        BasicModelObject<m_VertexModelType>::BasicModelObject(const typename BasicModelObject<m_VertexModelType>::VertexModelType &model, const DrawInfo &draw_info) : BasicModelObject<m_VertexModelType>::ParentType(model)
        {
            create();
            *m_draw_info = draw_info;
        }

        template <typename m_VertexModelType>
        void BasicModelObject<m_VertexModelType>::create()
        {
            if (m_VAO.get() == nullptr)
                m_VAO = Utils::SharedPointer<VertexArrayObject>(new VertexArrayObject(), Utils::ResourceDeleter<VertexArrayObject>());
            if (m_VBO.get() == nullptr)
                m_VBO = Utils::SharedPointer<VertexBufferObject>(new VertexBufferObject(), Utils::ResourceDeleter<VertexBufferObject>());
            if (m_draw_info.get() == nullptr)
                m_draw_info = std::make_shared<DrawInfo>(PrimitiveType::PrimitiveType::Triangles, 0, BasicModelObject<m_VertexModelType>::ParentType::ParentType::m_vertices.size());
        }

        template <typename m_VertexModelType>
        const VertexArrayObject &BasicModelObject<m_VertexModelType>::get_VAO() const
        {
            if (m_VAO.get() == nullptr)
                throw Utils::NullPointerException("template <typename m_VertexModelType> const VertexArrayObject &BasicModelObject<m_VertexModelType>::get_VAO() const");
            return *m_VAO;
        }

        template <typename m_VertexModelType>
        const VertexBufferObject &BasicModelObject<m_VertexModelType>::get_VBO() const
        {
            if (m_VBO.get() == nullptr)
                throw Utils::NullPointerException("template <typename m_VertexModelType> const VertexBufferObject &BasicModelObject<m_VertexModelType>::get_VBO() const");
            return *m_VBO;
        }

        template <typename m_VertexModelType>
        const DrawInfo &BasicModelObject<m_VertexModelType>::get_draw_info() const
        {
            return *m_draw_info;
        }

        template <typename m_VertexModelType>
        void BasicModelObject<m_VertexModelType>::set_draw_info(const DrawInfo &draw_info)
        {
            create();
            *m_draw_info = draw_info;
        }

        template <typename m_VertexModelType>
        ModelInstance BasicModelObject<m_VertexModelType>::create_instance()
        {
            create();
            return ModelInstance(m_VAO, m_draw_info);
        }
        template <typename m_VertexModelType>
        void BasicModelObject<m_VertexModelType>::update_VAO(GLenum usage)
        {
            create();
            BasicModelObject<m_VertexModelType>::ParentType::generate_VAO(*m_VAO, *m_VBO, usage);
            m_draw_info->set_count(BasicModelObject<m_VertexModelType>::ParentType::m_vertices.size());
        }

        template <typename m_VertexModelType>
        void BasicModelObject<m_VertexModelType>::update_VAO(const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            create();
            BasicModelObject<m_VertexModelType>::ParentType::generate_VAO(*m_VAO, *m_VBO, program, describer, usage);
            m_draw_info->set_count(BasicModelObject<m_VertexModelType>::ParentType::m_vertices.size());
        }

        template <typename m_VertexModelType>
        void BasicModelObject<m_VertexModelType>::release()
        {
            if (m_VBO.get() != nullptr)
                m_VBO->release();
            if (m_VAO.get() != nullptr)
                m_VAO->release();
        }
    } // namespace Graphics

} // namespace ntk

#endif
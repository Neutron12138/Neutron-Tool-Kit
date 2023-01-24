#ifndef __NEUTRON_GRAPHICS_MODELOBJECT_CPP__
#define __NEUTRON_GRAPHICS_MODELOBJECT_CPP__

#include "ModelObject.hpp"
#include "../../Utils/Exception/NullPointerException.hpp"

namespace ntk
{
    namespace Graphics
    {
        BasicModelObject<VertexModel>::BasicModelObject(const typename BasicModelObject<VertexModel>::VertexModelType &model) : BasicModelObject::ParentType(model)
        {
            create();
            update_VAO();
        }

        BasicModelObject<VertexModel>::BasicModelObject(const typename BasicModelObject<VertexModel>::VertexModelType &model, const DrawInfo &draw_info) : BasicModelObject::ParentType(model)
        {
            create();
            *m_draw_info = draw_info;
            update_VAO();
        }

        void BasicModelObject<VertexModel>::create()
        {
            if (m_VAO.get() == nullptr)
                m_VAO = std::shared_ptr<VertexArrayObject>(new VertexArrayObject(), Utils::GLObjectDeleter<VertexArrayObject>());
            if (m_VBO.get() == nullptr)
                m_VBO = std::shared_ptr<VertexBufferObject>(new VertexBufferObject(), Utils::GLObjectDeleter<VertexBufferObject>());
            if (m_draw_info.get() == nullptr)
                m_draw_info = std::make_shared<DrawInfo>(PrimitiveType::PrimitiveType::Triangles, 0, BasicModelObject<VertexModel>::ParentType::ParentType::m_vertices.size());
        }

        const VertexArrayObject &BasicModelObject<VertexModel>::get_VAO() const
        {
            if (m_VAO.get() == nullptr)
                throw Utils::NullPointerException("const VertexArrayObject &BasicModelObject<VertexModel>::get_VAO() const");
            return *m_VAO;
        }

        const VertexBufferObject &BasicModelObject<VertexModel>::get_VBO() const
        {
            if (m_VBO.get() == nullptr)
                throw Utils::NullPointerException(" const VertexBufferObject &BasicModelObject<VertexModel>::get_VBO() const");
            return *m_VBO;
        }

        const DrawInfo &BasicModelObject<VertexModel>::get_draw_info() const
        {
            return *m_draw_info;
        }

        void BasicModelObject<VertexModel>::set_draw_info(const DrawInfo &draw_info)
        {
            create();
            *m_draw_info = draw_info;
        }

        ModelInstance BasicModelObject<VertexModel>::create_instance()
        {
            create();
            return ModelInstance(m_VAO, m_draw_info);
        }

        void BasicModelObject<VertexModel>::update_VAO(GLenum usage)
        {
            create();
            release();
            BasicModelObject<VertexModel>::ParentType::generate_VAO(*m_VAO, *m_VBO, usage);
            m_draw_info->set_count(BasicModelObject<VertexModel>::ParentType::m_vertices.size());
        }

        void BasicModelObject<VertexModel>::update_VAO(const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            create();
            release();
            BasicModelObject<VertexModel>::ParentType::generate_VAO(*m_VAO, *m_VBO, program, describer, usage);
            m_draw_info->set_count(BasicModelObject<VertexModel>::ParentType::m_vertices.size());
        }

        void BasicModelObject<VertexModel>::release()
        {
            if (m_VBO.get() != nullptr)
                m_VBO->delete_object();
            if (m_VAO.get() != nullptr)
                m_VAO->delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_INSTANCEDMODELOBJECT_CPP__
#define __NEUTRON_GRAPHICS_INSTANCEDMODELOBJECT_CPP__

#include "InstancedModelObject.hpp"
#include "../../Utils/Exception/NullPointerException.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancedModelObject(const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType &model, const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancingDataArrayType &data) : Sprite(), InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType(model), m_data(data)
        {
            update_VAO();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_draw_info->set_draw_type(DrawType::DrawType::ArraysInstanced);
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancedModelObject(const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::VertexModelType &model, const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancingDataArrayType &data) : Sprite(), InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType(model), m_data(data)
        {
            update_VAO();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_draw_info->set_draw_type(DrawType::DrawType::ArraysInstanced);
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancedModelObject(const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::VertexModelType &model, const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancingDataArrayType &data, const DrawInfo &draw_info) : Sprite(), InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType(model, draw_info), m_data(data) {}

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::create()
        {
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::create();
            if (m_data_VBO.get() == nullptr)
                m_data_VBO = std::shared_ptr<VertexBufferObject>(new VertexBufferObject(), Utils::GLObjectDeleter<VertexBufferObject>());
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        const VertexBufferObject &InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::get_data_VBO() const
        {
            if (m_data_VBO.get() == nullptr)
                throw Utils::NullPointerException("template <typename m_InstancingDataArrayType, typename m_VertexModelType> const VertexBufferObject &InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::get_data_VBO() const");
            return *m_data_VBO;
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancingDataArrayType &InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::get_data() const
        {
            return m_data;
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::set_data(const typename InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::InstancingDataArrayType &data)
        {
            m_data = data;
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        ModelInstance InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::create_instance()
        {
            return ModelInstance();
        }
        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::update_VAO(GLenum usage)
        {
            create();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::update_VAO(usage);
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO->bind();
            *m_data_VBO = m_data.generate_VBO();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO->unbind();
            m_data_VBO->unbind();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_draw_info->set_instance_count(m_data.size());
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::update_VAO(const Program &program, const VertexAttribDescriber &describer, GLenum usage)
        {
            create();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::update_VAO(program, describer, usage);
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO->bind();
            *m_data_VBO = m_data.generate_VBO(program, describer);
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO->unbind();
            m_data_VBO->unbind();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_draw_info->set_instance_count(m_data.size());
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::release()
        {
            if (m_data_VBO.get() != nullptr)
                m_data_VBO->delete_object();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::release();
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::render()
        {
            if (InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO.get() == nullptr || InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_draw_info.get() == nullptr)
                throw Utils::NullPointerException("template <typename m_InstancingDataArrayType, typename m_VertexModelType> void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::render()");
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO->bind();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_draw_info->draw();
            InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::ParentType::m_VAO->unbind();
        }

        template <typename m_InstancingDataArrayType, typename m_VertexModelType>
        void InstancedModelObject<m_InstancingDataArrayType, m_VertexModelType>::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ModelMatrix), get_matrix());
            render();
        }
    } // namespace Graphics

} // namespace ntk

#endif
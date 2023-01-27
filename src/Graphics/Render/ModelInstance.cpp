#ifndef __NEUTRON_GRAPHICS_MODELINSTANCE_CPP__
#define __NEUTRON_GRAPHICS_MODELINSTANCE_CPP__

#include "ModelInstance.hpp"
#include "../../Utils/Exception/NullPointerException.hpp"

namespace ntk
{
    namespace Graphics
    {
        ModelInstance::ModelInstance(const Utils::SharedPointer<VertexArrayObject> &VAO) : Sprite(), m_VAO(VAO) {}
        ModelInstance::ModelInstance(const Utils::SharedPointer<VertexArrayObject> &VAO, const Utils::SharedPointer<DrawInfo> &draw_info) : Sprite(), m_VAO(VAO), m_draw_info(draw_info) {}

        const VertexArrayObject &ModelInstance::get_VAO() const
        {
            if (m_VAO.get() == nullptr)
                throw Utils::NullPointerException("const VertexArrayObject &ModelInstance::get_VAO() const");
            return *m_VAO;
        }

        const DrawInfo &ModelInstance::get_draw_info() const
        {
            if (m_draw_info.get() == nullptr)
                throw Utils::NullPointerException("const DrawInfo &ModelInstance::get_draw_info() const");
            return *m_draw_info;
        }

        void ModelInstance::render()
        {
            if (m_VAO.get() == nullptr || m_draw_info.get() == nullptr)
                throw Utils::NullPointerException("void ModelInstance::render()");
            m_VAO->bind();
            m_draw_info->draw();
            m_VAO->unbind();
        }

        void ModelInstance::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ModelMatrix), get_matrix());
            render();
        }
    } // namespace Graphics

} // namespace ntk

#endif
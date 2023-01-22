#ifndef __NEUTRON_GRAPHICS_MODELINSTANCE_CPP__
#define __NEUTRON_GRAPHICS_MODELINSTANCE_CPP__

#include "ModelInstance.hpp"

namespace ntk
{
    namespace Graphics
    {
        ModelInstance::ModelInstance(const VertexArrayObject &VAO) : Sprite(), m_VAO(VAO) {}

        const VertexArrayObject &ModelInstance::get_VAO() const
        {
            return m_VAO;
        }

        const DrawInfo &ModelInstance::get_draw_info() const
        {
            return m_draw_info;
        }

        void ModelInstance::set_draw_info(const DrawInfo &draw_info)
        {
            m_draw_info = draw_info;
        }

        void ModelInstance::render()
        {
            m_VAO.bind();
            m_draw_info.draw();
            m_VAO.unbind();
        }

        void ModelInstance::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ModelMatrix), get_matrix());
            render();
        }
    } // namespace Graphics

} // namespace ntk

#endif
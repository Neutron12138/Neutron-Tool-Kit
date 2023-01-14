#ifndef __NEUTRON_GRAPHICS_UNIFORMDESCRIBER_CPP__
#define __NEUTRON_GRAPHICS_UNIFORMDESCRIBER_CPP__

#include "UniformDescriber.hpp"

namespace ntk
{
    namespace Graphics
    {
        UniformDescriber::UniformDescriber()
        {
            m_names.at(UniformNameEnum::UniformName::ModelMatrix) = "u_model";
            m_names.at(UniformNameEnum::UniformName::ViewMatrix) = "u_view";
            m_names.at(UniformNameEnum::UniformName::ProjectionMatrix) = "u_projection";
            m_names.at(UniformNameEnum::UniformName::Color) = "u_color";
            m_names.at(UniformNameEnum::UniformName::ViewPosition) = "u_view_position";
            m_names.at(UniformNameEnum::UniformName::LightColor) = "u_light_color ";
            m_names.at(UniformNameEnum::UniformName::Material_Ambient) = "u_material.ambient";
            m_names.at(UniformNameEnum::UniformName::Material_Diffuse) = "u_material.diffuse";
            m_names.at(UniformNameEnum::UniformName::Material_Specular) = "u_material.specular";
            m_names.at(UniformNameEnum::UniformName::Material_Emission) = "u_material.emission";
            m_names.at(UniformNameEnum::UniformName::Material_Shininess) = "u_material.shininess";
            m_names.at(UniformNameEnum::UniformName::TextureSampler0) = "u_sampler0";
            m_names.at(UniformNameEnum::UniformName::TextureSampler1) = "u_sampler1";
        }

        UniformDescriber::UniformDescriber(const UniformDescriber &from)
        {
            *this = from;
        }
        UniformDescriber::~UniformDescriber() {}

        UniformDescriber &UniformDescriber::operator=(const UniformDescriber &from)
        {
            m_names = from.m_names;
            return *this;
        }

        const std::string &UniformDescriber::get_name(UniformNameEnum::UniformName name_enum) const
        {
            return m_names.at(static_cast<std::size_t>(name_enum));
        }

        void UniformDescriber::set_name(UniformNameEnum::UniformName name_enum, const std::string &uniform_name)
        {
            m_names.at(static_cast<std::size_t>(name_enum)) = uniform_name;
        }
    } // namespace Graphics

} // namespace ntk

#endif
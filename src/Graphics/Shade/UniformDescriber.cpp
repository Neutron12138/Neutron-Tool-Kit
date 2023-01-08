#ifndef __NEUTRON_GRAPHICS_UNIFORMDESCRIBER_CPP__
#define __NEUTRON_GRAPHICS_UNIFORMDESCRIBER_CPP__

#include "UniformDescriber.hpp"

namespace ntk
{
    namespace Graphics
    {
        UniformDescriber::UniformDescriber() {}
        UniformDescriber::UniformDescriber(const UniformDescriber &from) { *this = from; }
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
#ifndef __NEUTRON_GRAPHICS_VERTEXATTRIBDESCRIBER_CPP__
#define __NEUTRON_GRAPHICS_VERTEXATTRIBDESCRIBER_CPP__

#include "VertexAttribDescriber.hpp"

namespace ntk
{
    namespace Graphics
    {
        VertexAttribDescriber::VertexAttribDescriber()
        {
            m_names.at(VertexAttributeEnum::VertexAttributeLocation::Position) = "a_position";
            m_names.at(VertexAttributeEnum::VertexAttributeLocation::Normal) = "a_normal";
            m_names.at(VertexAttributeEnum::VertexAttributeLocation::TexCoord) = "a_texCoord";
            m_names.at(VertexAttributeEnum::VertexAttributeLocation::Color) = "a_color";
        }

        VertexAttribDescriber::VertexAttribDescriber(const VertexAttribDescriber &from) { *this = from; }
        VertexAttribDescriber::~VertexAttribDescriber() {}

        VertexAttribDescriber &VertexAttribDescriber::operator=(const VertexAttribDescriber &from)
        {
            m_names = from.m_names;
            return *this;
        }

        const std::array<std::string, VertexAttributeEnum::VertexAttributeLocation::LocationCount> &VertexAttribDescriber::get_names() const
        {
            return m_names;
        }

        const std::string &VertexAttribDescriber::get_name(VertexAttributeEnum::VertexAttributeLocation location) const
        {
            return m_names.at(location);
        }

        void VertexAttribDescriber::set_name(VertexAttributeEnum::VertexAttributeLocation location, const std::string &name)
        {
            m_names.at(location) = name;
        }
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_VERTEXATTRIBDESCRIBER_HPP__
#define __NEUTRON_GRAPHICS_VERTEXATTRIBDESCRIBER_HPP__

#include <array>
#include <string>
#include "../GL.hpp"
#include "../../Base/Object.hpp"
#include "VertexAttributeEnum.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点属性描述器
        class VertexAttribDescriber : public Object
        {
        protected:
            std::array<std::string, VertexAttributeEnum::VertexAttributeLocation::LocationCount> m_names;

        public:
            VertexAttribDescriber();
            VertexAttribDescriber(const VertexAttribDescriber &from);
            ~VertexAttribDescriber();

        public:
            VertexAttribDescriber &operator=(const VertexAttribDescriber &from);

        public:
            /// @brief 获取所有顶点属性在着色器中的名称
            /// @return 所有顶点属性在着色器中的名称
            const std::array<std::string, VertexAttributeEnum::VertexAttributeLocation::LocationCount> &get_names() const;
            
            /// @brief 获取顶点属性在着色器中的名称
            /// @param location 要获取的顶点属性
            /// @return 顶点属性在着色器中的名称
            const std::string &get_name(VertexAttributeEnum::VertexAttributeLocation location) const;
            
            /// @brief 设置顶点属性在着色器中的名称
            /// @param location 要设置的顶点属性
            /// @param name 顶点属性在着色器中的名称
            void set_name(VertexAttributeEnum::VertexAttributeLocation location, const std::string &name);
        };
    } // namespace Graphics

} // namespace ntk

#endif
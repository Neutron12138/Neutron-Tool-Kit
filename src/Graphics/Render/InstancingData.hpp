#ifndef __NEUTRON_GRAPHICS_INSTANCINGDATA_HPP__
#define __NEUTRON_GRAPHICS_INSTANCINGDATA_HPP__

#include "../../Base/BasicObject.hpp"
#include "../Buffer/VertexBufferObject.hpp"
#include "../Shade/BasicProgram.hpp"
#include "../Vertex/VertexAttribDescriber.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 实例化对象的数据
        class alignas(1) InstancingData : public BasicObject
        {
        public:
            using SelfType = InstancingData;

        public:
            InstancingData() = default;
            InstancingData(const SelfType &from) = default;
            ~InstancingData() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_MODELBUILDER_HPP__
#define __NEUTRON_GRAPHICS_MODELBUILDER_HPP__

#include "../Vertex/ModelObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 模型建造者
        class ModelBuilder : public Object
        {
        public:
            ModelBuilder() = default;
            ModelBuilder(const ModelBuilder &from) = default;
            ~ModelBuilder() = default;

        public:
            ModelBuilder &operator=(const ModelBuilder &from) = default;

        public:
            /// @brief 创建一个四边形，模型会被分割为三角面
            /// @param size 大小，如果为负值，会反转模型
            /// @return 四边形的模型
            static ModelObject create_quad_triangulated(const glm::vec2 &size = glm::vec2(1.0f, 1.0f));

            /// @brief 创建一个坐标轴
            /// @param size 坐标轴大小。每个分量也代表了是否有此轴（为0则无）
            /// @return 坐标轴的模型
            static ModelObject create_axis(const glm::vec3 &size = glm::vec3(100.0f, 100.0f, 100.0f));

            /// @brief 创建一个线框网格，此函数可能有些问题
            /// @param size 网格大小
            /// @param pieces 细分片数
            /// @return 网格的模型
            static ModelObject create_gridxy_wireframe(const glm::vec2 &size = glm::vec2(1.0f, 1.0f), const glm::uvec2 &pieces = glm::uvec2(0, 0));
        };
    } // namespace Graphics

} // namespace ntk

#endif
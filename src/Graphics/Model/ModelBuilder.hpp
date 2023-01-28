#ifndef __NEUTRON_GRAPHICS_MODELBUILDER_HPP__
#define __NEUTRON_GRAPHICS_MODELBUILDER_HPP__

#include "../Render/ModelObject.hpp"

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

            /// @brief 创建一个三角化的正多边形
            /// @param radius 半径
            /// @param sides 边数
            /// @return 正多边形的模型
            static ModelObject create_regular_polygon_triangulated(float radius, std::uint32_t sides);

            /// @brief 创建点精灵
            /// @param points 点精灵的位置
            /// @return 点精灵的模型
            static ModelObject create_points(const std::vector<glm::vec3> &points);

            /// @brief 创建线段
            /// @param lines 线段的顶点位置
            /// @return 线段的模型
            static ModelObject create_lines(const std::vector<glm::vec3> &lines);

            /// @brief 创建一个三角化的长方体
            /// @param size 长方体的尺寸
            /// @return 长方体模型
            static ModelObject create_cuboid_triangulated(const glm::vec3 &size);

            /// @brief 创建一个三角化的立方体
            /// @param size 立方体大小
            /// @return 立方体模型
            static ModelObject create_cube_triangulated(float size);

            /// @brief 创建一个三角化的球体
            /// @param radius 半径
            /// @param stacks 纵向细分数
            /// @param sectors 横向细分数
            /// @param smooth 使用更光滑的法线
            /// @return 球体模型
            static ModelObject create_sphere_triangulated(float radius, std::uint32_t stacks, std::uint32_t sectors, bool smooth = false);
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_MODEL_HPP__
#define __NEUTRON_GRAPHICS_MODEL_HPP__

#include <vector>
#include <glm/glm.hpp>
#include "../../Base/Object.hpp"
#include "../Vertex/VertexArrayObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 模型类

        template <typename m_VertexType = glm::vec3, typename m_NormalType = glm::vec3, typename m_TexCoordType = glm::vec2>
        class Model : public Object
        {
        public:
            using VertexType = m_VertexType;
            using NormalType = m_NormalType;
            using TexCoordType = m_TexCoordType;
            using SelfType = Model<VertexType, NormalType, TexCoordType>;

        protected:
            /// @brief 顶点
            std::vector<VertexType> m_vertices;
            /// @brief 法线
            std::vector<NormalType> m_normals;
            /// @brief 纹理坐标
            std::vector<TexCoordType> m_texCoords;

        public:
            Model();
            Model(const std::vector<VertexType> &vertices, const std::vector<NormalType> &normals, const std::vector<TexCoordType> &texCoords);
            Model(const SelfType &from);
            ~Model();

        public:
            SelfType &operator=(const Model &from);

        public:
            /// @brief 获取顶点
            /// @return 顶点
            const std::vector<VertexType> &get_vertices() const;

            /// @brief 获取法线
            /// @return 法线
            const std::vector<NormalType> &get_normals() const;

            /// @brief 获取纹理坐标
            /// @return 纹理坐标
            const std::vector<TexCoordType> &get_texCoords() const;

            /// @brief 设置顶点
            /// @param vertices 顶点
            void set_vertices(const std::vector<VertexType> &vertices);

            /// @brief 设置法线
            /// @param normals 法线
            void set_normals(const std::vector<NormalType> &normals);

            /// @brief 设置纹理坐标
            /// @param texCoords 纹理坐标
            void set_texCoords(const std::vector<TexCoordType> &texCoords);

            /// @brief 获取单个顶点
            /// @param index 索引
            /// @return 顶点
            const VertexType &get_vertex(size_t index) const;

            /// @brief 获取单个法线
            /// @param index 索引
            /// @return 法线
            const NormalType &get_normal(size_t index) const;

            /// @brief 获取单个纹理坐标
            /// @param index 索引
            /// @return 纹理坐标
            const TexCoordType &get_texCoord(size_t index) const;

            /// @brief 设置单个顶点
            /// @param index 索引
            /// @param vertex 顶点
            void set_vertex(size_t index, const VertexType &vertex);

            /// @brief 设置单个法线
            /// @param index 索引
            /// @param normal 法线
            void set_normal(size_t index, const NormalType &normal);

            /// @brief 设置单个纹理坐标
            /// @param index 索引
            /// @param texCoord 纹理坐标
            void set_texCoord(size_t index, const TexCoordType &texCoord);

        public:
            /// @brief 生成顶点数组对象
            /// @return 顶点数组对象
            virtual VertexArrayObject generate_VAO();
        };
    } // namespace Graphics

} // namespace ntk

#endif
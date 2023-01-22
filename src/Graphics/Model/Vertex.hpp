#ifndef __NEUTRON_GRAPHICS_VERTEX_HPP__
#define __NEUTRON_GRAPHICS_VERTEX_HPP__

#include <array>
#include <glm/glm.hpp>
#include "../GL.hpp"
#include "BasicVertex.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点
        template <>
        class alignas(1) BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform> : public Applicable<Transform>
        {
        public:
            using PositionType = glm::vec3;
            using NormalType = glm::vec3;
            using TexCoordType = glm::vec2;
            using MatrixHolderType = Transform;
            using SelfType = BasicVertex<PositionType, NormalType, TexCoordType, MatrixHolderType>;

        protected:
            /// @brief 顶点
            PositionType m_position;
            /// @brief 法线
            NormalType m_normal;
            /// @brief 纹理坐标
            TexCoordType m_texCoord;

        public:
            BasicVertex();
            BasicVertex(const PositionType &position, const NormalType &normal, const TexCoordType &texCoord);
            BasicVertex(const SelfType &from);
            ~BasicVertex();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取顶点
            /// @return 顶点
            const PositionType get_position() const;

            /// @brief 获取法线
            /// @return 法线
            const NormalType get_normal() const;

            /// @brief 获取纹理坐标
            /// @return 纹理坐标
            const TexCoordType get_texCoord() const;

            /// @brief 设置顶点
            /// @param position 顶点
            void set_position(const PositionType &position);

            /// @brief 设置法线
            /// @param normal 法线
            void set_normal(const NormalType &normal);

            /// @brief 设置纹理坐标
            /// @param texCoord 纹理坐标
            void set_texCoord(const TexCoordType &texCoord);

        public:
            /// @brief 应用变换，且只变换顶点与法线
            /// @param matrix 矩阵
            virtual void apply(const MatrixHolderType &matrix);
        };

        using Vertex = BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>;
    } // namespace Graphics

} // namespace ntk

#endif
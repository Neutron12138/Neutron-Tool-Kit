#ifndef __NEUTRON_GRAPHICS_BASICVERTEX_HPP__
#define __NEUTRON_GRAPHICS_BASICVERTEX_HPP__

#include <array>
#include <glm/glm.hpp>
#include "../GL.hpp"
#include "../Matrix/Applicable.hpp"
#include "../Matrix/Transform.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点
        /// @tparam m_PositionType 顶点类型
        /// @tparam m_NormalType 法线类型
        /// @tparam m_TexCoordType 纹理坐标类型
        /// @tparam m_MatrixHolderType 矩阵类型
        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        class alignas(1) BasicVertex : public Applicable<m_MatrixHolderType>
        {
        public:
            using PositionType = m_PositionType;
            using NormalType = m_NormalType;
            using TexCoordType = m_TexCoordType;
            using MatrixHolderType = m_MatrixHolderType;
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
            virtual void apply(const MatrixHolderType &matrix) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_TRIANGLEFACE_HPP__
#define __NEUTRON_GRAPHICS_TRIANGLEFACE_HPP__

#include <array>
#include <glm/glm.hpp>
#include "../GL.hpp"
#include "VertexArray.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 三角面
        /// @tparam m_VertexType 顶点类型
        /// @tparam m_MatrixHolderType 矩阵类型
        template <typename m_VertexType = Vertex, typename m_MatrixHolderType = Transform>
        class alignas(1) TriangleFace : public VertexArray<m_VertexType, m_MatrixHolderType, std::array<m_VertexType, 3>>
        {
        public:
            using VertexType = m_VertexType;
            using MatrixHolderType = m_MatrixHolderType;
            using ContainerType = std::array<VertexType, 3>;
            using SelfType = TriangleFace<VertexType, MatrixHolderType>;
            using ParentType = VertexArray<m_VertexType, m_MatrixHolderType, std::array<m_VertexType, 3>>;

        public:
            TriangleFace();
            TriangleFace(const ContainerType &vertices);
            TriangleFace(const VertexType &v0, const VertexType &v1, const VertexType &v2);
            TriangleFace(const SelfType &from);
            ~TriangleFace();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 计算面法线
            /// @return 面法线
            virtual typename VertexType::NormalType calculate_face_normal() const;

        public:
            virtual void clear();
        };
    } // namespace Graphics

} // namespace ntk

#endif
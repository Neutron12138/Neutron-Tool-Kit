#ifndef __NEUTRON_GRAPHICS_APPLICABLE_HPP__
#define __NEUTRON_GRAPHICS_APPLICABLE_HPP__

#include "../../Base/Object.hpp"
#include "MatrixHolder.hpp"
#include "Transform.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 可应用的对象，主要用于模型
        /// @tparam m_MatrixHolderType 矩阵类型，继承自MatrixHolder
        template <typename m_MatrixHolderType = Transform>
        class Applicable : public Object
        {
        public:
            using MatrixHolderType = m_MatrixHolderType;
            using SelfType = Applicable<MatrixHolderType>;

        public:
            Applicable() = default;
            Applicable(const SelfType &from) = default;
            ~Applicable() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 将矩阵应用至当前对象
            /// @param matrix 矩阵
            virtual void apply(const MatrixHolderType &matrix) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
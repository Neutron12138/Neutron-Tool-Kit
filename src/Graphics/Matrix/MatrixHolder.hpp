#ifndef __NEUTRON_GRAPHICS_MATRIXHOLDER_HPP__
#define __NEUTRON_GRAPHICS_MATRIXHOLDER_HPP__

#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 矩阵持有者，矩阵对象的基类
        /// @tparam m_MatrixType 矩阵类型
        template <typename m_MatrixType>
        class MatrixHolder : public Object
        {
        public:
            using MatrixType = m_MatrixType;
            using SelfType = MatrixHolder<MatrixType>;

        protected:
            MatrixType m_matrix;

        public:
            MatrixHolder();
            MatrixHolder(const MatrixType &matrix);
            MatrixHolder(const SelfType &from);
            ~MatrixHolder();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 设置矩阵
            /// @param matrix 要设置的矩阵
            /// @return 本对象
            SelfType &set_matrix(const MatrixType &matrix);

            /// @brief 获取矩阵
            /// @return 矩阵
            const MatrixType &get_matrix() const;

        public:
            /// @brief 更新矩阵
            virtual void update() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
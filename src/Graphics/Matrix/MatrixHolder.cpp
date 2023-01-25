#ifndef __NEUTRON_GRAPHICS_MATRIXHOLDER_CPP__
#define __NEUtRON_GRAPHICS_MATRIXHOLDER_CPP__

#include "MatrixHolder.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_MatrixType>
        MatrixHolder<m_MatrixType>::MatrixHolder() {}

        template <typename m_MatrixType>
        MatrixHolder<m_MatrixType>::MatrixHolder(const m_MatrixType &matrix) : m_matrix(matrix) {}

        template <typename m_MatrixType>
        MatrixHolder<m_MatrixType>::MatrixHolder(const MatrixHolder<m_MatrixType> &from) { *this = from; }

        template <typename m_MatrixType>
        MatrixHolder<m_MatrixType>::~MatrixHolder() {}

        template <typename m_MatrixType>
        MatrixHolder<m_MatrixType> &MatrixHolder<m_MatrixType>::operator=(const MatrixHolder<m_MatrixType> &from)
        {
            m_matrix = from.m_matrix;
            return *this;
        }

        template <typename m_MatrixType>
        MatrixHolder<m_MatrixType> &MatrixHolder<m_MatrixType>::set_matrix(const MatrixType &matrix)
        {
            m_matrix = matrix;
            return *this;
        }

        template <typename m_MatrixType>
        const m_MatrixType &MatrixHolder<m_MatrixType>::get_matrix() const
        {
            return m_matrix;
        }
    } // namespace Graphics

} // namespace ntk

#endif
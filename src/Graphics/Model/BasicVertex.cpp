#ifndef __NEUTRON_GRAPHICS_BASICVERTEX_CPP__
#define __NEUTRON_GRAPHICS_BASICVERTEX_CPP__

#include "BasicVertex.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::BasicVertex() {}
        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::BasicVertex(const m_PositionType &position, const m_NormalType &normal, const m_TexCoordType &texCoord) : m_position(position), m_normal(normal), m_texCoord(texCoord) {}
        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::BasicVertex(const BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::SelfType &from) { *this = from; }
        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::~BasicVertex() {}

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        typename BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::SelfType &BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::operator=(const BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::SelfType &from)
        {
            m_position = from.m_position;
            m_normal = from.m_normal;
            m_texCoord = from.m_texCoord;
            return *this;
        }

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        const m_PositionType BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::get_position() const
        {
            return m_position;
        }

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        const m_NormalType BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::get_normal() const
        {
            return m_normal;
        }

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        const m_TexCoordType BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::get_texCoord() const
        {
            return m_texCoord;
        }

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        void BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::set_position(const m_PositionType &position)
        {
            m_position = position;
        }

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        void BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::set_normal(const m_NormalType &normal)
        {
            m_normal = normal;
        }

        template <typename m_PositionType, typename m_NormalType, typename m_TexCoordType, typename m_MatrixHolderType>
        void BasicVertex<m_PositionType, m_NormalType, m_TexCoordType, m_MatrixHolderType>::set_texCoord(const m_TexCoordType &texCoord)
        {
            m_texCoord = texCoord;
        }
    } // namespace Graphics

} // namespace ntk

#endif
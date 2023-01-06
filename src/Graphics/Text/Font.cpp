#ifndef __NEUTRON_GRAPHICS_FONT_CPP__
#define __NEUTRON_GRAPHICS_FONT_CPP__

#include "Font.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_GlyphType, typename m_GlyphCollectionType>
        Font<m_GlyphType,m_GlyphCollectionType>::Font() {}
        template <typename m_GlyphType, typename m_GlyphCollectionType>
        Font<m_GlyphType,m_GlyphCollectionType>::Font(const Font<m_GlyphType,m_GlyphCollectionType> &from) { *this = from; }
        template <typename m_GlyphType, typename m_GlyphCollectionType>
        Font<m_GlyphType,m_GlyphCollectionType>::~Font() {}

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        Font<m_GlyphType,m_GlyphCollectionType> &Font<m_GlyphType,m_GlyphCollectionType>::operator=(const Font<m_GlyphType,m_GlyphCollectionType> &from)
        {
            m_glyphs = from.m_glyphs;
            return *this;
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        const std::map<std::uint32_t, m_GlyphCollectionType> &Font<m_GlyphType,m_GlyphCollectionType>::get_glyphs() const
        {
            return m_glyphs;
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        void Font<m_GlyphType,m_GlyphCollectionType>::release_all()
        {
            for (auto ptr = m_glyphs.begin(); ptr != m_glyphs.end(); ptr++)
            {
                ptr->second.release_all();
            }
            m_glyphs.clear();
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        m_GlyphCollectionType *Font<m_GlyphType,m_GlyphCollectionType>::get_glyph(std::uint32_t code)
        {
            auto ptr = m_glyphs.find(code);
            if (ptr != m_glyphs.cend())
            {
                return &ptr->second;
            }
            return nullptr;
        }
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_FONT_CPP__
#define __NEUTRON_GRAPHICS_FONT_CPP__

#include "Font.hpp"

namespace ntk
{
    namespace Graphics
    {
        Font::Font() {}
        Font::Font(const Font &from) { *this = from; }
        Font::~Font() {}

        Font &Font::operator=(const Font &from)
        {
            m_glyphs = from.m_glyphs;
            return *this;
        }

        const std::map<std::uint32_t, GlyphCollection> &Font::get_glyphs() const
        {
            return m_glyphs;
        }

        void Font::release_all()
        {
            for (auto ptr = m_glyphs.begin(); ptr != m_glyphs.end(); ptr++)
            {
                ptr->second.release_all();
            }
            m_glyphs.clear();
        }

        GlyphCollection *Font::get_glyph(std::uint32_t code)
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
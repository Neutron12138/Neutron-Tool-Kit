#ifndef __NEUTRON_GRAPHICS_GLYPHCOLLECTION_CPP__
#define __NEUTRON_GRAPHICS_GLYPHCOLLECTION_CPP__

#include "GlyphCollection.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_GlyphType>
        GlyphCollection<m_GlyphType>::GlyphCollection(std::uint32_t code) : m_code(code) {}
        template <typename m_GlyphType>
        GlyphCollection<m_GlyphType>::GlyphCollection(const GlyphCollection<m_GlyphType> &from) { *this = from; }
        template <typename m_GlyphType>
        GlyphCollection<m_GlyphType>::~GlyphCollection() {}

        template <typename m_GlyphType>
        GlyphCollection<m_GlyphType> &GlyphCollection<m_GlyphType>::operator=(const GlyphCollection<m_GlyphType> &from)
        {
            m_glyphs = from.m_glyphs;
            m_code = from.m_code;
            return *this;
        }

        template <typename m_GlyphType>
        const std::map<std::uint32_t, m_GlyphType> &GlyphCollection<m_GlyphType>::get_glyphs() const
        {
            return m_glyphs;
        }

        template <typename m_GlyphType>
        std::uint32_t GlyphCollection<m_GlyphType>::get_code() const
        {
            return m_code;
        }

        template <typename m_GlyphType>
        m_GlyphType *GlyphCollection<m_GlyphType>::get_glyph(std::uint32_t size)
        {
            auto i = m_glyphs.find(size);
            if (i != m_glyphs.end())
            {
                return &i->second;
            }
            return nullptr;
        }

        template <typename m_GlyphType>
        bool GlyphCollection<m_GlyphType>::load(FT_Face face, std::uint32_t size)
        {
            if (m_glyphs.find(size) != m_glyphs.end())
                return true;

            if (face == nullptr)
                return false;

            FT_Set_Pixel_Sizes(face, 0, size);

            if (FT_Load_Char(face, m_code, FT_LOAD_RENDER))
            {
                Instance::log.loge("Glyph Collection", Instance::string_utils.to_string("Unable to load glyph:", m_code, " with size:", size));
                return false;
            }

            Glyph glyph;
            glyph.load_data(face);
            m_glyphs.insert(std::pair<std::uint32_t, Glyph>(size, glyph));
            return true;
        }

        template <typename m_GlyphType>
        void GlyphCollection<m_GlyphType>::release()
        {
            for (auto ptr = m_glyphs.begin(); ptr != m_glyphs.end(); ptr++)
            {
                ptr->second.release();
            }
            m_glyphs.clear();
        }
    } // namespace Graphics

} // namespace ntk

#endif
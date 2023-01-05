#ifndef __NEUTRON_GRAPHICS_GLYPHCOLLECTION_CPP__
#define __NEUTRON_GRAPHICS_GLYPHCOLLECTION_CPP__

#include "GlyphCollection.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        GlyphCollection::GlyphCollection(std::uint32_t code) : m_code(code) {}
        GlyphCollection::GlyphCollection(const GlyphCollection &from) { *this = from; }
        GlyphCollection::~GlyphCollection() {}

        GlyphCollection &GlyphCollection::operator=(const GlyphCollection &from)
        {
            m_glyphs = from.m_glyphs;
            m_code = from.m_code;
            return *this;
        }

        const std::map<std::uint32_t, Glyph> &GlyphCollection::get_glyphs() const
        {
            return m_glyphs;
        }

        std::uint32_t GlyphCollection::get_code() const
        {
            return m_code;
        }

        Glyph* GlyphCollection::get_glyph(std::uint32_t size)
        {
            auto i = m_glyphs.find(size);
            if (i != m_glyphs.end())
            {
                return &i->second;
            }
            return nullptr;
        }

        bool GlyphCollection::load(FT_Face face, std::uint32_t size)
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

        void GlyphCollection::release_all()
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
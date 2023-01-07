#ifndef __NEUTRON_GRAPHICS_TRUETYPEFONT_CPP__
#define __NEUTRON_GRAPHICS_TRUETYPEFONT_CPP__

#include "TrueTypeFont.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_GlyphType, typename m_GlyphCollectionType>
        TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::TrueTypeFont() {}
        template <typename m_GlyphType, typename m_GlyphCollectionType>
        TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::TrueTypeFont(const TrueTypeFont<m_GlyphType, m_GlyphCollectionType> &from) { *this = from; }
        template <typename m_GlyphType, typename m_GlyphCollectionType>
        TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::~TrueTypeFont() {}

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        TrueTypeFont<m_GlyphType, m_GlyphCollectionType> &TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::operator=(const TrueTypeFont<m_GlyphType, m_GlyphCollectionType> &from)
        {
            Font<m_GlyphType, m_GlyphCollectionType>::operator=(from);
            return *this;
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        bool TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::load_font(const std::string &filename)
        {
            // 初始化Library
            if (FT_Init_FreeType(&m_library))
            {
                Instance::log.loge("TrueTypeFont<m_GlyphType,m_GlyphCollectionType>", "Unable to initialize FreeType");
                return false;
            }

            // 加载Face
            if (FT_New_Face(m_library, filename.data(), 0, &m_face))
            {
                Instance::log.loge("TrueTypeFont<m_GlyphType,m_GlyphCollectionType>", Instance::string_utils.to_string("Unable to load Face from file:\"", filename, "\""));
                FT_Done_FreeType(m_library);
                return false;
            }

            return true;
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        void TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::close_font()
        {
            if (m_face != nullptr)
            {
                FT_Done_Face(m_face);
                m_face = nullptr;
            }

            if (m_library != nullptr)
            {
                FT_Done_FreeType(m_library);
                m_library = nullptr;
            }
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        bool TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::load_glyph(std::uint32_t code, std::uint32_t size, GlyphType &result)
        {
            FT_Set_Pixel_Sizes(m_face, 0, size);

            if (FT_Load_Char(m_face, code, FT_LOAD_RENDER))
            {
                Instance::log.loge("TrueTypeFont<m_GlyphType,m_GlyphCollectionType>", Instance::string_utils.to_string("Unable to load glyph:", code));
                return false;
            }

            result.release();
            result.load_data(m_face);
            return true;
        }

        template <typename m_GlyphType, typename m_GlyphCollectionType>
        bool TrueTypeFont<m_GlyphType, m_GlyphCollectionType>::load_glyph(std::uint32_t code, std::uint32_t size)
        {
            auto i = Font<m_GlyphType, m_GlyphCollectionType>::m_glyphs.find(code);
            if (i != Font<m_GlyphType, m_GlyphCollectionType>::m_glyphs.end())
            {
                return i->second.load(m_face, size);
            }
            else
            {
                m_GlyphCollectionType gc(code);
                bool success = gc.load(m_face, size);
                Font<m_GlyphType, m_GlyphCollectionType>::m_glyphs.insert(std::pair<std::uint32_t, m_GlyphCollectionType>(code, gc));
                return success;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
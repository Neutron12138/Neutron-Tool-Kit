#ifndef __NEUTRON_GRAPHICS_TRUETYPEFONT_CPP__
#define __NEUTRON_GRAPHICS_TRUETYPEFONT_CPP__

#include "TrueTypeFont.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        TrueTypeFont::TrueTypeFont() {}
        TrueTypeFont::TrueTypeFont(const TrueTypeFont &from) { *this = from; }
        TrueTypeFont::~TrueTypeFont() {}

        TrueTypeFont &TrueTypeFont::operator=(const TrueTypeFont &from)
        {
            Font::operator=(from);
            return *this;
        }

        bool TrueTypeFont::load_font(const std::string &filename)
        {
            // 初始化Library
            if (FT_Init_FreeType(&m_library))
            {
                Instance::log.loge("TrueTypeFont", "Unable to initialize FreeType");
                return false;
            }

            // 加载Face
            if (FT_New_Face(m_library, filename.data(), 0, &m_face))
            {
                Instance::log.loge("TrueTypeFont", Instance::string_utils.to_string("Unable to load Face from file:\"", filename, "\""));
                FT_Done_FreeType(m_library);
                return false;
            }

            return true;
        }

        void TrueTypeFont::close_font()
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

        bool TrueTypeFont::load_glyph(std::uint32_t code, std::uint32_t size, Glyph &result)
        {
            FT_Set_Pixel_Sizes(m_face, 0, size);

            if (FT_Load_Char(m_face, code, FT_LOAD_RENDER))
            {
                Instance::log.loge("TrueTypeFont", Instance::string_utils.to_string("Unable to load glyph:", code));
                return false;
            }

            result.release();
            result.load_data(m_face);
            return true;
        }

        bool TrueTypeFont::load_glyph(std::uint32_t code, std::uint32_t size)
        {
            auto i = m_glyphs.find(code);
            if (i != m_glyphs.end())
            {
                return i->second.load(m_face, size);
            }
            else
            {
                GlyphCollection gc(code);
                bool success = gc.load(m_face, size);
                m_glyphs.insert(std::pair<std::uint32_t, GlyphCollection>(code, gc));
                return success;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
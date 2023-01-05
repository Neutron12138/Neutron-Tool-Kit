#ifndef __NEUTRON_GRAPHICS_FONT_HPP__
#define __NEUTRON_GRAPHICS_FONT_HPP__

#include <map>
#include "../../Base/Object.hpp"
#include "Glyph.hpp"
#include "GlyphCollection.hpp"

namespace ntk
{
    namespace Graphics
    {
        class Font : public Object
        {
        protected:
            /// @brief 字形数据
            std::map<std::uint32_t, GlyphCollection> m_glyphs;

        public:
            Font();
            Font(const Font &from);
            ~Font();

        public:
            Font &operator=(const Font &from);

        public:
            /// @brief 获取所有字形
            /// @return 字形数据
            const std::map<std::uint32_t, GlyphCollection> &get_glyphs() const;

            /// @brief 释放所有资源
            virtual void release_all();

            /// @brief 获取一个字形集
            /// @param code 字符编码
            /// @return 字形集
            virtual GlyphCollection *get_glyph(std::uint32_t code);

        public:
            /// @brief 从文件中加载字体
            /// @param filename 文件名
            /// @return 是否加载成功
            virtual bool load_font(const std::string &filename) = 0;

            /// @brief 关闭字体
            virtual void close_font() = 0;

            /// @brief 加载一个字形
            /// @param code 字符编码
            /// @param size 字形大小
            /// @return 字形
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size, Glyph &result) = 0;

            /// @brief 加载一个字形
            /// @param code 字符编码
            /// @param size 字形大小
            /// @return 字形
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
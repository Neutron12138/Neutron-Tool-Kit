#ifndef __NEUTRON_GRAPHICS_FONT_HPP__
#define __NEUTRON_GRAPHICS_FONT_HPP__

#include <map>
#include "Glyph.hpp"
#include "GlyphCollection.hpp"
#include "../../Utils/Resource/ResourceObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础字体类
        /// @tparam m_GlyphType 字形类型，继承自Glyph
        /// @tparam m_GlyphCollectionType 字形集类型，继承自GlyphCollection
        template <typename m_GlyphType = Glyph, typename m_GlyphCollectionType = GlyphCollection<Glyph>>
        class Font : public Utils::ResourceObject
        {
        public:
            using GlyphType = m_GlyphType;
            using GlyphCollectionType = m_GlyphCollectionType;
            using SelfType = Font<GlyphType, GlyphCollectionType>;

        protected:
            /// @brief 字形数据
            std::map<std::uint32_t, GlyphCollectionType> m_glyphs;

        public:
            Font();
            Font(const SelfType &from);
            ~Font();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取所有字形
            /// @return 字形数据
            const std::map<std::uint32_t, GlyphCollectionType> &get_glyphs() const;

            /// @brief 获取一个字形集
            /// @param code 字符编码
            /// @return 字形集
            virtual GlyphCollectionType *get_glyph(std::uint32_t code);

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
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size, GlyphType &result) = 0;

            /// @brief 加载一个字形
            /// @param code 字符编码
            /// @param size 字形大小
            /// @return 字形
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size) = 0;

        public:
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
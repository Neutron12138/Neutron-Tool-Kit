#ifndef __NEUTRON_GRAPHICS_TEXT_HPP__
#define __NEUTRON_GRAPHICS_TEXT_HPP__

#include "../../Base/Type.hpp"
#include "Shapes/RectangleShape.hpp"
#include "../Text/Font.hpp"

namespace ntk
{
    namespace Graphics
    {
        // Text渲染出的所有字都使用矩形渲染
        // 所以继承RectangleShape共用同一个VAO

        /// @brief 文本对象
        /// @tparam m_StringType 字符串类型，必须有at()和length()
        template <typename m_StringType = String, typename m_FontType = Font<Glyph, GlyphCollection<Glyph>>>
        class Text : public RectangleShape
        {
        public:
            using StringType = m_StringType;
            using FontType = m_FontType;
            using SelfType = Text<StringType, FontType>;

        protected:
            /// @brief 字符串
            StringType m_text;
            /// @brief 文本大小
            std::uint32_t m_text_size = 32;
            /// @brief 字体
            FontType *m_font = nullptr;
            /// @brief 是否启用多行
            bool m_multi_line = true;
            /// @brief 行间距
            std::uint32_t m_line_space = 32;

        public:
            Text();
            Text(const StringType &text, std::uint32_t size, FontType *font);
            Text(const SelfType &from);
            ~Text();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取文本
            /// @return 文本
            const StringType &get_text() const;

            /// @brief 获取文本尺寸
            /// @return 文本尺寸
            std::uint32_t get_text_size() const;

            /// @brief 获取字体
            /// @return 字体
            FontType *get_font() const;

            /// @brief 获取是否启用多行
            /// @return 是否启用多行
            bool enabled_multi_line() const;

            /// @brief 获取行间距
            /// @return 行间距
            std::uint32_t get_line_space() const;

            /// @brief 设置文本
            /// @param text 文本
            virtual void set_text(const StringType &text);

            /// @brief 设置文本尺寸
            /// @param size 文本尺寸
            virtual void set_text_size(std::uint32_t size);

            /// @brief 设置字体
            /// @param font 字体
            virtual void set_font(FontType *font);

            /// @brief 设置是否启用多行
            /// @param enabled 是否启用多行
            virtual void set_multi_line(bool enabled);

            /// @brief 设置行间距
            /// @param line_space 行间距
            virtual void set_line_space(std::uint32_t line_space);

        public:
            /// @brief  没有指明缩放比，无法使用
            virtual void render();

            /// @brief 渲染，不会产生字体变形
            /// @param scale 缩放比，即2与屏幕宽高的比值
            virtual void render(const glm::vec2 &scale);

            /// @brief 渲染，不会产生字体变形
            /// @param scale 缩放比，即2与屏幕宽高的比值
            /// @param binder uniform绑定器
            /// @param describer uniform描述器
            virtual void render(const glm::vec2 &scale, UniformBinder &binder, const UniformDescriber &describer);
        };

        /// @brief 测量文本宽度，不含换行
        /// @tparam StringT 字符串类型，必须有at()和length()
        /// @param text 文本
        /// @param size 文本尺寸
        /// @param font 字体，不能为空
        /// @return 文本宽度（单位：1/64像素），出错则返回-1
        template <typename StringType, typename FontType>
        int measure_text_width(const StringType &text, std::uint32_t size, FontType *font);
    } // namespace Graphics

} // namespace ntk

#endif
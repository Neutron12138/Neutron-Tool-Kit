#ifndef __NEUTRON_UTILS_IMAGE_HPP__
#define __NEUTRON_UTILS_IMAGE_HPP__

#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "../../Base/Object.hpp"
#include "../../Base/Type.hpp"
#include "ColorChannelEnum.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 图像类
        class Image : public Object
        {
        private:
            /// @brief 图像数据
            std::uint8_t *m_pixels = nullptr;
            /// @brief 图像的宽
            std::uint32_t m_width = 0;
            /// @brief 图像的高
            std::uint32_t m_height = 0;
            /// @brief 图像的色彩通道
            ColorChannel::ColorChannel m_color_channel = ColorChannel::ColorChannel::UNKNOWN;

        public:
            Image();
            Image(const Image &from);
            ~Image();

        public:
            Image &operator=(const Image &from);

        public:
            /// @brief 获取图像的数据
            /// @return 图像数据
            const std::uint8_t *get_pixels() const;

            /// @brief 获取图像宽度
            /// @return 图像的宽
            std::uint32_t get_width() const;

            /// @brief 获取图像高度
            /// @return 图像的高
            std::uint32_t get_height() const;

            /// @brief 获取图像色彩通道
            /// @return 图像的色彩通道
            ColorChannel::ColorChannel get_color_channel() const;

        public:
            /// @brief 从文件加载图像
            /// @param filename 文件名
            /// @param desired_channels 期望得到的色彩通道数，为0则不改变
            /// @return 是否加载成功
            bool load_from_file(const std::string &filename, int desired_channels = 0);

            /// @brief 从内存加载图像。注意：这会拥有source所指向的内存
            /// @param width 图像的宽度
            /// @param height 图像的高度
            /// @param color_channel 图像的色彩通道
            /// @param source 指向图像数据的指针
            /// @return 是否加载成功
            bool own_from_memory(std::uint32_t width, std::uint32_t height, ColorChannel::ColorChannel color_channel, std::uint8_t *source);

            /// @brief 从内存拷贝图像
            /// @param width 图像的宽度
            /// @param height 图像的高度
            /// @param color_channel 图像的色彩通道
            /// @param source 指向图像数据的指针
            /// @return 是否加载成功
            bool copy_from_memory(std::uint32_t width, std::uint32_t height, ColorChannel::ColorChannel color_channel, const std::uint8_t *source);

            /// @brief 从另一个Image对象加载。注意：这会让其与另一个Image对象共同拥有同一块内存
            /// @param another 另一个Image对象
            /// @return 是否成功
            bool own_from_another(Image &another);

            /// @brief 从另一个Image对象拷贝
            /// @param another 另一个Image对象
            /// @return 是否成功
            bool copy_from_another(const Image &another);

        public:
            /// @brief 保存为png文件
            /// @param filename 输出文件名
            /// @param flip 输出图像时是否将其反转
            void write_as_png(const std::string &filename, bool flip = true);

        public:
            /// @brief 手动释放图像资源，之后所有数据清零
            void release();
        };
    } // namespace Utils

} // namespace ntk

#endif
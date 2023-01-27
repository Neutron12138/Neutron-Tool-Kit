#ifndef __NEUTRON_AUDIO_BUFFER_HPP__
#define __NEUTRON_AUDIO_BUFFER_HPP__

#include <vector>
#include "AL.hpp"
#include "Bindable.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief OpenAL缓冲区对象
        class Buffer : public Bindable
        {
        public:
            Buffer();
            Buffer(ALuint objectID);
            Buffer(const Buffer &from);
            ~Buffer();

        public:
            Buffer &operator=(const Buffer &from);

        public:
            /// @brief 绑定数据
            /// @param format 数据格式
            /// @param data 数据
            /// @param size 数据大小
            /// @param freq 频率
            virtual void bind_data(ALenum format, const ALvoid *data, ALsizei size, ALsizei freq);

            /// @brief 绑定数据
            /// @tparam DataType 数据类型
            /// @param format 数据格式
            /// @param data 数据
            /// @param size 数据大小，会乘上sizeof(DataType)
            /// @param freq 频率
            template <typename DataType>
            void bind_data(ALenum format, const DataType *data, ALsizei size, ALsizei freq);

            /// @brief 绑定数据
            /// @tparam DataType 数据类型
            /// @param format 数据格式
            /// @param data 数据
            /// @param freq 频率
            template <typename DataType>
            void bind_data(ALenum format, const std::vector<DataType> &data, ALsizei freq);

        public:
            /// @brief 设置缓冲对象ID
            /// @param bufferID 缓冲对象ID
            virtual void set_bufferID(ALuint bufferID);

        public:
            virtual void generate();
            virtual bool is_correct_objectID(ALuint objectID);
            virtual void release();
        };
    } // namespace Audio

} // namespace ntk

#endif
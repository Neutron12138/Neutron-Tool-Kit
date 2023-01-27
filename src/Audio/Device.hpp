#ifndef __NEUTRON_AUDIO_DEVICE_HPP__
#define __NEUTRON_AUDIO_DEVICE_HPP__

#include "Al.hpp"
#include "ALCObject.hpp"
#include "../Base/String.hpp"
#include "Context.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief OpenAL设备类
        class Device : public ALCObject<ALCdevice>
        {
        public:
            Device();
            Device(ALCdevice *device);
            Device(const Device &from);
            ~Device();

        public:
            Device &operator=(const Device &from);

        public:
            /// @brief 打开默认设备
            /// @return 是否打开成功
            virtual bool open();

            /// @brief 打开一个设备
            /// @param devicename 设备名
            /// @return 是否打开成功
            virtual bool open(const String &devicename);

            /// @brief 关闭设备，同release()
            virtual void close();

            /// @brief 创建一个上下文，属性为空
            /// @return 上下文
            virtual Context create_context();

            /// @brief 创建一个上下文
            /// @param attrlist 属性列表
            /// @return 上下文
            virtual Context create_context(const ALCint *attrlist);

        public:
            virtual void release();
        };
    } // namespace Audio

} // namespace ntk

#endif
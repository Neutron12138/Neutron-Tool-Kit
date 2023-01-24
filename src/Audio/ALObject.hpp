#ifndef __NEUTRON_AUDIO_ALOBJECT_HPP__
#define __NEUTRON_AUDIO_ALOBJECT_HPP__

#include "AL.hpp"
#include "../Base/Object.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief OpenAL对象
        class ALObject : public Object
        {
        protected:
            ALuint m_objectID = 0;

        public:
            ALObject();
            ALObject(ALuint objectID);
            ALObject(const ALObject &from);
            // 因为有时并不需要在本对象销毁时同时销毁OpenGL对象（比如函数返回值），所以请手动管理
            ~ALObject();

        public:
            ALObject &operator=(const ALObject &from);

        public:
            /// @brief 设置对象的ID。如果本对象储存的OpenGL对象ID不是0，请自行决定是销毁还是保留，假定你会管理好的:)
            /// @param objectID 对象ID
            /// @return 本对象
            ALObject &set_objectID(ALuint objectID);

            /// @brief 获取储存的OpenGL对象的ID
            /// @return 储存的OpenGL对象的ID
            ALuint get_objectID() const;

        public:
            /// @brief 储存的OpenGL对象是否为空（即保留值0）
            /// @return 储存的OpenGL对象是否为空
            virtual bool is_null() const;

            /// @brief 为了防止误把缓冲对象用源对象管理的这种情况，需要判断对象ID是否正确。
            /// @param objectID 要判断的OpenAL对象ID
            /// @return 类型是否正确
            virtual bool is_correct_objectID(ALuint objectID) = 0;

            /// @brief 删除储存的OpenAL对象
            virtual void delete_object() = 0;
        };
    } // namespace Audio

} // namespace ntk

#endif
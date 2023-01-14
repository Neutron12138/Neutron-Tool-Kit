#ifndef __NEUTRON_AUDIO_ALCOBJECT_HPP__
#define __NEUTRON_AUDIO_ALCOBJECT_HPP__

#include "AL.hpp"
#include "../Utils/Resource/ResourceObject.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief ALC对象
        /// @tparam m_ALCObjectType ALC对象类型
        template <typename m_ALCObjectType>
        class ALCObject : public Utils::ResourceObject
        {
        public:
            using ALCObjectType = m_ALCObjectType;
            using SelfType = ALCObject<ALCObjectType>;

        protected:
            ALCObjectType *m_object = nullptr;

        public:
            ALCObject();
            ALCObject(ALCObjectType *object);
            ALCObject(const SelfType &from);
            ~ALCObject();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 设置ALC对象
            /// @param object ALC对象
            /// @return 本对象
            ALCObject &set_object(ALCObjectType *object);

            /// @brief 获取ALC对象
            /// @return ALC对象
            const ALCObjectType *get_object() const;

        public:
            /// @brief 判断ALC对象是否为空
            /// @return ALC对象是否为空
            bool is_null() const;
        };
    } // namespace Audio

} // namespace ntk

#endif
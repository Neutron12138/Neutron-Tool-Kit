#ifndef __NEUTRON_AUDIO_ALCOBJECT_HPP__
#define __NEUTRON_AUDIO_ALCOBJECT_HPP__

#include "AL.hpp"
#include "../Utils/Resource/ResourceObject.hpp"
#include "../Utils/Memory/SharedPointer.hpp"

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
            using ParentType = Utils::ResourceObject;

        protected:
            ALCObjectType *m_object = nullptr;

        public:
            ALCObject() = default;
            ALCObject(ALCObjectType *object);
            ALCObject(const SelfType &from) = default;
            ~ALCObject() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 设置ALC对象
            /// @param object ALC对象
            virtual void set_object(ALCObjectType *object);

            /// @brief 获取ALC对象
            /// @return ALC对象
            ALCObjectType *get_object() const;

        public:
            /// @brief 判断ALC对象是否为空
            /// @return ALC对象是否为空
            bool is_null() const;
        };
    } // namespace Audio

} // namespace ntk

#endif
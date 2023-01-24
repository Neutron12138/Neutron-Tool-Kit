#ifndef __NEUTRON_BASE_NAMEDOBJECT_HPP__
#define __NEUTRON_BASE_NAMEDOBJECT_HPP__

#include "Object.hpp"
#include "String.hpp"

namespace ntk
{
    /// @brief 命名的对象，可以赋予其名字
    /// @tparam m_StringType 名称字符串类型
    template <typename m_StringType = String>
    class NamedObject : public Object
    {
    public:
        using StringType = m_StringType;
        using SelfType = NamedObject<StringType>;

    protected:
        /// @brief 本对象的名称
        StringType m_name;

    public:
        NamedObject() = default;
        NamedObject(const StringType &name);
        NamedObject(const SelfType &from) = default;
        ~NamedObject() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取本对象的名称
        /// @return 本对象的名称
        const StringType &get_name() const;

        /// @brief 设置本对象的名称，如果要禁用，可以覆写为空（什么都不执行）
        /// @param name 本对象的名称
        virtual void set_name(const StringType &name);
    };
} // namespace ntk

#endif
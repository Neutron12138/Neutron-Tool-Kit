#ifndef __NEUTRON_BASE_OBJECT_HPP__
#define __NEUTRON_BASE_OBJECT_HPP__

namespace ntk
{
    /// @brief 对象类
    class Object
    {
    public:
        Object();
        Object(const Object &from);
        ~Object();

    public:
        Object &operator=(const Object &from);
    };
} // namespace ntk

#endif

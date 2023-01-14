#ifndef __NEUTRON_UTILS_GLOBJECTDELETER_HPP__
#define __NEUTRON_UTILS_GLOBJECTDELETER_HPP__

#include "../../../Base/Type.hpp"
#include "../../../Base/BasicDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        // OpenGL对象删除器没有数组特化型
        // 因为无法指明具体要删除的元素个数
        // 请使用std::vector之类的代替

        /// @brief 资源删除器
        /// @tparam m_GLObjectType 资源对象类型
        template <typename m_GLObjectType>
        class GLObjectDeleter : public BasicDeleter<m_GLObjectType>
        {
        public:
            using GLObjectType = m_GLObjectType;
            using SelfType = GLObjectDeleter<GLObjectType>;

        public:
            GLObjectDeleter();
            GLObjectDeleter(const SelfType &from);
            ~GLObjectDeleter();

        public:
            SelfType &operator=(const SelfType &from);
            void operator()(GLObjectType *ptr);
        };
    } // namespace Utils

} // namespace ntk

#endif
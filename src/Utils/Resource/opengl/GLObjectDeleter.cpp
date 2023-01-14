#ifndef __NEUTRON_UTILS_GLOBJECTDELETER_CPP__
#define __NEUTRON_UTILS_GLOBJECTDELETER_CPP__

#include "GLObjectDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_GLObjectType>
        GLObjectDeleter<m_GLObjectType>::GLObjectDeleter() {}
        template <typename m_GLObjectType>
        GLObjectDeleter<m_GLObjectType>::GLObjectDeleter(const GLObjectDeleter<m_GLObjectType> &from) {}
        template <typename m_GLObjectType>
        GLObjectDeleter<m_GLObjectType>::~GLObjectDeleter() {}
        template <typename m_GLObjectType>
        GLObjectDeleter<m_GLObjectType> &GLObjectDeleter<m_GLObjectType>::operator=(const GLObjectDeleter<m_GLObjectType> &from) { *this = from; }

        template <typename m_GLObjectType>
        void GLObjectDeleter<m_GLObjectType>::operator()(m_GLObjectType *ptr)
        {
            ptr->delete_object();
            delete ptr;
        }
    } // namespace Utils

} // namespace ntk

#endif
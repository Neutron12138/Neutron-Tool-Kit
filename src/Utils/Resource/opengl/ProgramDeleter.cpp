#ifndef __NEUTRON_UTILS_PROGRAMDELETER_CPP__
#define __NEUTRON_UTILS_PROGRAMDELETER_CPP__

#include "ProgramDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        ProgramDeleter::ProgramDeleter() {}
        ProgramDeleter::ProgramDeleter(const ProgramDeleter &from) {}
        ProgramDeleter::~ProgramDeleter() {}
        ProgramDeleter &ProgramDeleter::operator=(const ProgramDeleter &from) { return *this; }

        void ProgramDeleter::operator()(Graphics::Program *ptr)
        {
            ptr->delete_object();
            ptr->delete_shaders();
            delete ptr;
        }
    } // namespace Utils

} // namespace ntk

#endif
#ifndef __NEUTRON_UTILS_PROGRAMDELETER_HPP__
#define __NEUTRON_UTILS_PROGRAMDELETER_HPP__

#include "GLObjectDeleter.hpp"
#include "../../../Graphics/Shade/Program.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 着色程序删除器，GLObjectDeleter特化型
        class ProgramDeleter : public Utils::GLObjectDeleter<Graphics::Program>
        {
        public:
            ProgramDeleter();
            ProgramDeleter(const ProgramDeleter &from);
            ~ProgramDeleter();

        public:
            ProgramDeleter &operator=(const ProgramDeleter &from);
            void operator()(Graphics::Program *ptr);
        };
    } // namespace Utils

} // namespace ntk

#endif
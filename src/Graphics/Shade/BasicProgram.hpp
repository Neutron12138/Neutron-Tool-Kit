#ifndef __NEUTRON_GRAPHICS_BASICPROGRAM_HPP__
#define __NEUTRON_GRAPHICS_BASICPROGRAM_HPP__

#include "../GL.hpp"
#include "../GLObject.hpp"
#include "UniformBinder.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础着色程序对象
        class BasicProgram : public GLObject, public UniformBinder
        {
        public:
            /// @brief 当前正在使用的着色程序对象
            static BasicProgram *current_program;

            using SelfType = BasicProgram;

        public:
            BasicProgram() = default;
            BasicProgram(GLuint programID);
            BasicProgram(const SelfType &from) = default;
            ~BasicProgram() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 有对象检查版本的set_objectID()，建议使用这个而不是set_objectID()
            /// @param programID 要被赋予的着色程序对象
            virtual void set_programID(GLuint programID);

            virtual bool is_correct_objectID(GLuint objectID);

        public:
            /// @brief 使用本着色程序
            virtual void use_program();

        public:
            virtual GLuint get_program();

            /// @brief 注意：只会删除着色程序对象！附着的着色器对象需要用delete_shaders()手动释放！
            virtual void delete_object();

        public:
            /// @brief 删除附着的着色器对象，但是实际删除会在本着色程序被删除之后
            virtual void delete_shaders() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_SHADER_HPP__
#define __NEUTRON_GRAPHICS_SHADER_HPP__

#include <iostream>
#include "../GL.hpp"
#include "../GLObject.hpp"
#include "ShaderType.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 着色器类
        class Shader : public GLObject
        {
        public:
            using SelfType = Shader;

        private:
            /// @brief 着色器的类型，一旦指定就不可改变
            ShaderType::ShaderType m_shader_type;

        public:
            Shader(ShaderType::ShaderType shader_type);
            Shader(ShaderType::ShaderType shader_type, GLuint shaderID);
            Shader(const SelfType &from) = default;
            ~Shader() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取着色器的类型
            /// @return 着色器类型的枚举
            ShaderType::ShaderType get_shader_type() const;

        public:
            /// @brief 从字符串加载（编译）着色器。如果原来有着色器，会被替换。
            /// @param source 字符串源
            /// @return 是否加载（编译）成功
            virtual bool load_from_string(const std::string &source);

            /// @brief 从输入流加载（编译）着色器。如果原来有着色器，会被替换。
            /// @param is 输入流
            /// @return 是否加载（编译）成功
            virtual bool load_from_stream(std::istream &is);

            /// @brief 从文件加载（编译）着色器。如果原来有着色器，会被替换。
            /// @param filename 文件名
            /// @return 是否加载（编译）成功
            virtual bool load_from_file(const std::string &filename);

        public:
            /// @brief 有对象检查版本的set_objectID()，建议使用这个而不是set_objectID()
            /// @param shaderID 要被赋予的着色器对象
            virtual void set_shaderID(GLuint shaderID);

        public:
            virtual void generate();
            virtual bool is_correct_objectID(GLuint objectID);
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
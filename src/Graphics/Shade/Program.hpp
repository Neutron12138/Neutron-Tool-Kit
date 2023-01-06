#ifndef __NEUTRON_GRAPHICS_PROGRAM_HPP__
#define __NEUTRON_GRAPHICS_PROGRAM_HPP__

#include "../GL.hpp"
#include "Shader.hpp"
#include "../GLObject.hpp"
#include "UniformBinder.hpp"

namespace ntk
{
    namespace Graphics
    {
        class Program : public GLObject, public UniformBinder
        {
        public:
            /// @brief 当前正在使用的着色程序对象
            static Program *current_program;

        protected:
            /// @brief 附着的顶点着色器对象
            Shader m_vertex_shader;

            /// @brief 附着的片段着色器对象
            Shader m_fragment_shader;

        public:
            Program();
            Program(GLuint programID);
            Program(const Program &from);
            ~Program();

        public:
            Program &operator=(const Program &from);

        public:
            const Shader &get_vertex_shader() const;
            const Shader &get_fragment_shader() const;

        public:
            /// @brief 从着色器链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vshader 顶点着色器
            /// @param fshader 片段着色器
            /// @return 是否加载（链接）成功
            virtual bool load_from_shader(const Shader &vshader, const Shader &fshader);

            /// @brief 从字符串加载（编译）着色器并链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vsource 顶点着色器字符串源
            /// @param fsource 片段着色器字符串源
            /// @return 是否加载（编译并链接）成功
            virtual bool load_from_string(const std::string &vsource, const std::string &fsource);

            /// @brief 从输入流加载（编译）着色器并链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vis 顶点着色器输入流
            /// @param fis 片段着色器输入流
            /// @return 是否加载（编译并链接）成功
            virtual bool load_from_stream(std::istream &vis, std::istream &fis);

            /// @brief 从文件加载（编译）着色器并链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vfilename 顶点着色器文件名
            /// @param ffilename 片段着色器文件名
            /// @return 是否加载（编译并链接）成功
            virtual bool load_from_file(const std::string &vfilename, const std::string &ffilename);

        public:
            /// @brief 有对象检查版本的set_objectID()，建议使用这个而不是set_objectID()
            /// @param programID 要被赋予的着色程序对象
            virtual void set_programID(GLuint programID);

        public:
            virtual bool is_correct_objectID(GLuint objectID);

            /// @brief 注意：只会删除着色程序对象！内部的两个着色器对象需要用delete_shaders()手动释放！
            virtual void delete_object();

            virtual GLuint get_program();

        public:
            /// @brief 使用本着色程序
            virtual void use_program();

            /// @brief 删除内部的两个着色器对象，但是实际删除会在本着色程序被删除之后
            virtual void delete_shaders();
        };
    } // namespace Graphics

} // namespace ntk

#endif
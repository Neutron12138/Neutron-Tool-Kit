#ifndef __NEUTRON_GRAPHICS_GEOMETRYPROGRAM_HPP__
#define __NEUTRON_GRAPHICS_GEOMETRYPROGRAM_HPP__

#include "Shader.hpp"
#include "BasicProgram.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 几何着色程序对象
        class GeometryProgram : public BasicProgram
        {
        public:
            using SelfType = GeometryProgram;

        protected:
            /// @brief 附着的顶点着色器对象
            Shader m_vertex_shader;

            /// @brief 附着的顶点着色器对象
            Shader m_geometry_shader;

            /// @brief 附着的片段着色器对象
            Shader m_fragment_shader;

        public:
            GeometryProgram();
            GeometryProgram(GLuint programID);
            GeometryProgram(const SelfType &from);
            ~GeometryProgram() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取顶点着色器对象
            /// @return 顶点着色器对象
            const Shader &get_vertex_shader() const;

            /// @brief 获取几何着色器对象
            /// @return 几何着色器对象
            const Shader &get_geometry_shader() const;

            /// @brief 获取片段着色器对象
            /// @return 片段着色器对象
            const Shader &get_fragment_shader() const;

        public:
            /// @brief 从着色器链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vshader 顶点着色器
            /// @param fshader 片段着色器
            /// @return 是否加载（链接）成功
            virtual bool load_from_shader(const Shader &vshader, const Shader &gshader, const Shader &fshader);

            /// @brief 从字符串加载（编译）着色器并链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vsource 顶点着色器字符串源
            /// @param fsource 片段着色器字符串源
            /// @return 是否加载（编译并链接）成功
            virtual bool load_from_string(const std::string &vsource, const std::string &gsource, const std::string &fsource);

            /// @brief 从输入流加载（编译）着色器并链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vis 顶点着色器输入流
            /// @param fis 片段着色器输入流
            /// @return 是否加载（编译并链接）成功
            virtual bool load_from_stream(std::istream &vis, std::istream &gis, std::istream &fis);

            /// @brief 从文件加载（编译）着色器并链接为着色程序。如果原来有着色程序，会被替换。
            /// @param vfilename 顶点着色器文件名
            /// @param ffilename 片段着色器文件名
            /// @return 是否加载（编译并链接）成功
            virtual bool load_from_file(const std::string &vfilename, const std::string &gfilename, const std::string &ffilename);

        public:
            virtual void delete_shaders();
        };
    } // namespace Graphics

} // namespace ntk

#endif
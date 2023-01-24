#ifndef __NEUTRON_GRAPHICS_GEOMETRYPROGRAM_CPP__
#define __NEUTrON_GRAPHICS_GEOMETRYPROGRAM_CPP__

#include "GeometryProgram.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        GeometryProgram::GeometryProgram() : BasicProgram(), m_vertex_shader(ShaderType::ShaderType::Vertex), m_geometry_shader(ShaderType::ShaderType::Geometry), m_fragment_shader(ShaderType::ShaderType::Fragment) {}
        GeometryProgram::GeometryProgram(GLuint programID) : BasicProgram(programID), m_vertex_shader(ShaderType::ShaderType::Vertex), m_geometry_shader(ShaderType::ShaderType::Geometry), m_fragment_shader(ShaderType::ShaderType::Fragment) {}
        GeometryProgram::GeometryProgram(const GeometryProgram &from) : BasicProgram(), m_vertex_shader(ShaderType::ShaderType::Vertex), m_geometry_shader(ShaderType::ShaderType::Geometry), m_fragment_shader(ShaderType::ShaderType::Fragment) { *this = from; }

        const Shader &GeometryProgram::get_vertex_shader() const
        {
            return m_vertex_shader;
        }
        const Shader &GeometryProgram::get_geometry_shader() const
        {
            return m_geometry_shader;
        }

        const Shader &GeometryProgram::get_fragment_shader() const
        {
            return m_fragment_shader;
        }

        bool GeometryProgram::load_from_shader(const Shader &vshader, const Shader &gshader, const Shader &fshader)
        {
            // 检查着色器
            GLuint vshaderID = vshader.get_objectID();
            GLuint gshaderID = gshader.get_objectID();
            GLuint fshaderID = fshader.get_objectID();
            if (vshaderID == 0)
            {
                Instance::log.loge("Geometry Program", Utils::to_string("Invalid vertex shader to attach, value:", vshaderID));
                return false;
            }
            if (gshaderID == 0)
            {
                Instance::log.loge("Geometry Program", Utils::to_string("Invalid geometry shader to attach, value:", vshaderID));
                return false;
            }
            if (fshaderID == 0)
            {
                Instance::log.loge("Geometry Program", Utils::to_string("Invalid fragment shader to attach, value:", fshaderID));
                return false;
            }

            // 创建着色程序并链接
            GLuint programID = glCreateProgram();
            glAttachShader(programID, vshaderID);
            glAttachShader(programID, gshaderID);
            glAttachShader(programID, fshaderID);
            glLinkProgram(programID);

            // 检查是否成功
            int length;
            glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length);
            if (length == 0)
            {
                set_objectID(programID);
                m_vertex_shader = vshader;
                m_geometry_shader = gshader;
                m_fragment_shader = fshader;
            }
            else
            {
                char *info_log = new char[length];
                glGetProgramInfoLog(programID, length, nullptr, info_log);
                Instance::log.loge("Geometry Program", info_log);
                delete[] info_log;

                glDeleteProgram(programID);
            }

            return length == 0;
        }

        bool GeometryProgram::load_from_string(const std::string &vsource, const std::string &gsource, const std::string &fsource)
        {
            // 加载两个着色器
            Shader vshader(ShaderType::ShaderType::Vertex);
            Shader gshader(ShaderType::ShaderType::Geometry);
            Shader fshader(ShaderType::ShaderType::Fragment);
            bool vsuccess = vshader.load_from_string(vsource);
            bool gsuccess = gshader.load_from_string(gsource);
            bool fsuccess = fshader.load_from_string(fsource);

            // 链接为着色程序
            if (vsuccess && gsuccess && fsuccess)
            {
                return load_from_shader(vshader, gshader, fshader);
            }
            else
            {
                vshader.delete_object();
                gshader.delete_object();
                fshader.delete_object();
                return false;
            }
        }

        bool GeometryProgram::load_from_stream(std::istream &vis, std::istream &gis, std::istream &fis)
        {
            // 加载两个着色器
            Shader vshader(ShaderType::ShaderType::Vertex);
            Shader gshader(ShaderType::ShaderType::Geometry);
            Shader fshader(ShaderType::ShaderType::Fragment);
            bool vsuccess = vshader.load_from_stream(vis);
            bool gsuccess = gshader.load_from_stream(gis);
            bool fsuccess = fshader.load_from_stream(fis);

            // 链接为着色程序
            if (vsuccess && gsuccess && fsuccess)
            {
                return load_from_shader(vshader, gshader, fshader);
            }
            else
            {
                vshader.delete_object();
                gshader.delete_object();
                fshader.delete_object();
                return false;
            }
        }

        bool GeometryProgram::load_from_file(const std::string &vfilename, const std::string &gfilename, const std::string &ffilename)
        {
            // 加载两个着色器
            Shader vshader(ShaderType::ShaderType::Vertex);
            Shader gshader(ShaderType::ShaderType::Geometry);
            Shader fshader(ShaderType::ShaderType::Fragment);
            bool vsuccess = vshader.load_from_file(vfilename);
            bool gsuccess = gshader.load_from_file(gfilename);
            bool fsuccess = fshader.load_from_file(ffilename);

            // 链接为着色程序
            if (vsuccess && gsuccess && fsuccess)
            {
                return load_from_shader(vshader, gshader, fshader);
            }
            else
            {
                vshader.delete_object();
                gshader.delete_object();
                fshader.delete_object();
                return false;
            }
        }

        void GeometryProgram::delete_shaders()
        {
            m_vertex_shader.delete_object();
            m_geometry_shader.delete_object();
            m_fragment_shader.delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif
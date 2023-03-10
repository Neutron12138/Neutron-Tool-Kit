#ifndef __NEUTRON_GRAPHICS_PROGRAM_CPP__
#define __NEUTrON_GRAPHICS_PROGRAM_CPP__

#include "Program.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        Program::Program(GLuint programID) : BasicProgram(programID) {}

        const Utils::SharedPointer<Shader> &Program::get_vertex_shader() const
        {
            return m_vertex_shader;
        }

        const Utils::SharedPointer<Shader> &Program::get_fragment_shader() const
        {
            return m_fragment_shader;
        }

        bool Program::load_from_shader(const Utils::SharedPointer<Shader> &vshader, const Utils::SharedPointer<Shader> &fshader)
        {
            // 检查着色器
            if (vshader.is_nullptr())
            {
                Instance::log.loge("Program", Utils::to_string("vertex shader is a null pointer"));
                return false;
            }
            if (fshader.is_nullptr())
            {
                Instance::log.loge("Program", Utils::to_string("fragment shader is a null pointer"));
                return false;
            }
            GLuint vshaderID = vshader->get_objectID();
            GLuint fshaderID = fshader->get_objectID();
            if (vshaderID == 0)
            {
                Instance::log.loge("Program", Utils::to_string("Invalid vertex shader to attach, value:", vshaderID));
                return false;
            }
            if (fshaderID == 0)
            {
                Instance::log.loge("Program", Utils::to_string("Invalid fragment shader to attach, value:", fshaderID));
                return false;
            }

            // 创建着色程序并链接
            GLuint programID = glCreateProgram();
            glAttachShader(programID, vshaderID);
            glAttachShader(programID, fshaderID);
            glLinkProgram(programID);

            // 检查是否成功
            int length;
            glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length);
            if (length == 0)
            {
                set_objectID(programID);
                m_vertex_shader = vshader;
                m_fragment_shader = fshader;
            }
            else
            {
                char *info_log = new char[length];
                glGetProgramInfoLog(programID, length, nullptr, info_log);
                Instance::log.loge("Program", info_log);
                delete[] info_log;

                glDeleteProgram(programID);
            }

            return length == 0;
        }

        bool Program::load_from_string(const std::string &vsource, const std::string &fsource)
        {
            // 加载两个着色器
            Shader vshader(ShaderType::ShaderType::Vertex);
            Shader fshader(ShaderType::ShaderType::Fragment);
            bool vsuccess = vshader.load_from_string(vsource);
            bool fsuccess = fshader.load_from_string(fsource);

            // 链接为着色程序
            if (vsuccess && fsuccess)
            {
                bool success = load_from_shader(Utils::SharedPointer(new Shader(vshader), Utils::ResourceDeleter<Shader>()), Utils::SharedPointer(new Shader(fshader), Utils::ResourceDeleter<Shader>()));
                if (success)
                    return true;
            }
            vshader.release();
            fshader.release();
            return false;
        }

        bool Program::load_from_stream(std::istream &vis, std::istream &fis)
        {
            // 加载两个着色器
            Shader vshader(ShaderType::ShaderType::Vertex);
            Shader fshader(ShaderType::ShaderType::Fragment);
            bool vsuccess = vshader.load_from_stream(vis);
            bool fsuccess = fshader.load_from_stream(fis);

            // 链接为着色程序
            if (vsuccess && fsuccess)
            {
                bool success = load_from_shader(Utils::SharedPointer(new Shader(vshader), Utils::ResourceDeleter<Shader>()), Utils::SharedPointer(new Shader(fshader), Utils::ResourceDeleter<Shader>()));
                if (success)
                    return true;
            }
            vshader.release();
            fshader.release();
            return false;
        }

        bool Program::load_from_file(const std::string &vfilename, const std::string &ffilename)
        {
            // 加载两个着色器
            Shader vshader(ShaderType::ShaderType::Vertex);
            Shader fshader(ShaderType::ShaderType::Fragment);
            bool vsuccess = vshader.load_from_file(vfilename);
            bool fsuccess = fshader.load_from_file(ffilename);

            // 链接为着色程序
            if (vsuccess && fsuccess)
            {
                bool success = load_from_shader(Utils::SharedPointer(new Shader(vshader), Utils::ResourceDeleter<Shader>()), Utils::SharedPointer(new Shader(fshader), Utils::ResourceDeleter<Shader>()));
                if (success)
                    return true;
            }
            vshader.release();
            fshader.release();
            return false;
        }
    } // namespace Graphics

} // namespace ntk

#endif
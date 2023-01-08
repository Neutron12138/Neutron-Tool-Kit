#ifndef __NEUTRON_UTILS_STRINGUTILS_HPP__
#define __NEUTRON_UTILS_STRINGUTILS_HPP__

#include <iostream>
#include <string>
#include "../../Base/Object.hpp"
#include "Status.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 字符串的工具类
        class StringUtils : public Object
        {
        public:
            StringUtils();
            StringUtils(const StringUtils &from);
            ~StringUtils();

        public:
            StringUtils &operator=(const StringUtils &from);

        public:
            /// @brief 上一次调用load_string_from_stream()后的状态
            StringUtilsStatus::Status load_string_from_stream_status;

            /// @brief 上一次调用load_string_from_stream()后的结果
            std::string load_string_from_stream_result;

            /// @brief 从输入流加载字符串
            /// @param is 输入流
            /// @return 结果
            std::string load_string_from_stream(std::istream &is);

        public:
            /// @brief 上一次调用load_string_from_file()后的状态
            StringUtilsStatus::Status load_string_from_file_status;

            /// @brief 上一次调用load_string_from_file()后的结果
            std::string load_string_from_file_result;

            /// @brief 从文件加载字符串
            /// @param filename 文件名
            /// @return 结果
            std::string load_string_from_file(const std::string &filename);

        public:
            /// @brief 转换为字符串，重载函数之一
            /// @return 转换后的结果
            std::string to_string();

            /// @brief 转换为字符串，重载函数之一
            /// @tparam ArgT 参数类型
            /// @param arg 参数
            /// @return 转换后的结果
            template <typename ArgT>
            std::string to_string(const ArgT &arg);

            /// @brief 转换为字符串，重载函数之一
            /// @tparam ArgT 参数类型
            /// @tparam ...ArgsT 参数类型列表
            /// @param arg 参数
            /// @param ...args 参数列表
            /// @return 转换后的结果
            template <typename ArgT, typename... ArgsT>
            std::string to_string(const ArgT &arg, const ArgsT &...args);
        };
    } // namespace Utils

} // namespace ntk

#endif
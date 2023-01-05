#ifndef __NEUTRON_UTILS_STRINGUTILS_CPP__
#define __NEUTRON_UTILS_STRINGUTILS_CPP__

#include <sstream>
#include <fstream>
#include "StringUtils.hpp"

namespace ntk
{
    namespace Utils
    {
        StringUtils::StringUtils()
        {
            load_string_from_stream_status = StringUtilsStatus::Status::NOT_CALLED;
            load_string_from_stream_result = std::string();
            load_string_from_file_status = StringUtilsStatus::Status::NOT_CALLED;
            load_string_from_file_result = std::string();
        }

        StringUtils::StringUtils(const StringUtils &from) { *this = from; }
        StringUtils::~StringUtils() {}

        StringUtils &StringUtils::operator=(const StringUtils &from)
        {
            load_string_from_stream_status = from.load_string_from_stream_status;
            load_string_from_stream_result = from.load_string_from_stream_result;
            load_string_from_file_status = from.load_string_from_file_status;
            load_string_from_file_result = from.load_string_from_file_result;
            return *this;
        }

        std::string StringUtils::load_string_from_stream(std::istream &is)
        {
            try
            {
                std::stringstream sstr;
                std::string temp;
                while (std::getline(is, temp))
                {
                    sstr << temp << std::endl;
                }
                load_string_from_stream_status = StringUtilsStatus::Status::SUCCESS;
                load_string_from_stream_result = sstr.str();
                return load_string_from_stream_result;
            }
            catch (const std::exception &e)
            {
                load_string_from_stream_status = StringUtilsStatus::Status::FAILURE;
                load_string_from_stream_result = e.what();
                return std::string();
            }
        }

        std::string StringUtils::load_string_from_file(const std::string &filename)
        {
            std::ifstream fin;
            try
            {
                fin.open(filename);
                if (fin.fail())
                {
                    fin.close();
                    load_string_from_file_status = StringUtilsStatus::Status::FAILURE;
                    load_string_from_file_result = to_string("Could not open file:\"", filename, "\"");
                    return std::string();
                }
                load_string_from_file_status = StringUtilsStatus::Status::SUCCESS;
                load_string_from_file_result = load_string_from_stream(fin);

                if (load_string_from_stream_status != StringUtilsStatus::Status::SUCCESS)
                {
                    load_string_from_file_status = StringUtilsStatus::Status::FAILURE;
                    load_string_from_file_result = load_string_from_stream_result;
                }
                return load_string_from_file_result;
            }
            catch (const std::exception &e)
            {
                fin.close();
                load_string_from_file_status = StringUtilsStatus::Status::FAILURE;
                load_string_from_file_result = e.what();
                return std::string();
            }
        }

        std::string StringUtils::to_string()
        {
            return std::string();
        }

        template <typename ArgT>
        std::string StringUtils::to_string(const ArgT &arg)
        {
            std::stringstream sstr;
            sstr << arg;
            return sstr.str();
        }

        template <typename ArgT, typename... ArgsT>
        std::string StringUtils::to_string(const ArgT &arg, const ArgsT &...args)
        {
            return to_string(arg) + to_string(args...);
        }
    } // namespace Utils

} // namespace ntk

#endif
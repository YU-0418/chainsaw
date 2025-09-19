#ifndef CHAINSAW_COMMON_READWRITEFILE_H
#define CHAINSAW_COMMON_READWRITEFILE_H

#include "head.h"
#include "print.h"
#include "error_message.h"

namespace chainsaw
{
    // if it's exist, it will be return true.
    bool isFileExists(const std::string &name);

    std::vector<std::string> read_file(std::string file, bool is_null_line_save = false);

    class write_file
    {
        std::ofstream wf;

    public:
        write_file(std::string file, bool is_exist = false);

        // mode
        // [is_exist][append]
        //
        // 0b00/0b01 file isnot exists
        // 0b10 file is exists, cannot append
        // 0b11 file is exists, append
        write_file(std::string file, int mode);
        // only a std::string
        void write(std::string data, bool line = true);

        // many more std::string
        void write(std::vector<std::string> data);

        ~write_file();
    };

} // namespace chainsaw

#endif // !CHAINSAW_COMMON_READWRITEFILE_H

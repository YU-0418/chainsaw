#ifndef CHAINSAW_ARGV_ARGV_TOOL_H
#define CHAINSAW_ARGV_ARGV_TOOL_H

#include "head.h"
#include "error_message.h"
#include "common.h"

namespace chainsaw
{
    // if print=true, print all argv.
    void check_argv(int argc, char **argv, bool print = true);

    // [xx.exe,1,2] ->
    // return [1,2]
    std::vector<std::string> recognize_argv(int argc, char **argv);

    class ARGV
    {
        command cmd;
        
    public:
        // -a xx xx -b xx
        // -> node{a, xx, xx} node{b, xx}
        ARGV(std::vector<std::string> data);

        // use 'recognize_argv' first
        ARGV(int argc, char **argv);

        // 
        bool is_contain(std::string option);

        // if find option,return its arg
        // if return-val is null, it maybe null or the option is not in the argv.
        std::vector<std::string> get_argv(std::string option);

        // print all argv
        void print();

    private:
        void print_error(std::string message);
    };

} // namespace chainsaw

#endif // !CHAINSAW_ARGV_ARGV_TOOL_H
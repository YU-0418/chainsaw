#ifndef CHAINSAW_COMMON_COMMAND_H
#define CHAINSAW_COMMON_COMMAND_H

#include "head.h"
#include "error_message.h"
#include "option.h"
#include "stringtool.h"
#include "print.h"

namespace chainsaw
{
    class command
    {
        struct node
        {
            std::string value;
            std::vector<std::string> arg;

            // mode 0 -> arg
            // mode 1 -> value=arg
            int mode = 0;

            bool empty() const;

            void clear();
        };

        std::vector<node> all;

    public:
        // --word=xxx -> [word,xxx]
        // -C[space]xxx -> [C,xxx]
        // -Cxxx -> [C,xxx]
        // -c=xxx -> [c,xxx]
        command(std::string s);

        command(std::vector<std::string> arg);

        //
        bool find(std::string option);

        //
        std::vector<std::string> get_option_arg(std::string option);

        // print all command
        void print();

    private:
        void parse_string_list(std::vector<std::string> data);

        void add_data(node &buffer);

        void print_error(std::string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_COMMAND_H

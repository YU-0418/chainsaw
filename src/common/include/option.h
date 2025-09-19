#ifndef CHAINSAW_COMMON_OPTION_H
#define CHAINSAW_COMMON_OPTION_H

#include "head.h"
#include "error_message.h"

namespace chainsaw
{
    class option
    {
        std::vector<char> data;

    public:
        // -[char]
        option(std::string s);

        bool is_contain(char c);

        // Determine whether all the characters exist
        bool is_contain(std::string s);
        
    private:
        void print_error(std::string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_OPTION_H

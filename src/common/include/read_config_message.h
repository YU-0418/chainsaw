#ifndef CHAINSAW_COMMON_READ_CONFIG_MESSAGE_H
#define CHAINSAW_COMMON_READ_CONFIG_MESSAGE_H

#include "head.h"
#include "readwritefile.h"
#include "stringtool.h"
#include "error_message.h"

namespace chainsaw
{
    class ReadConfigMessage
    {
        struct kv
        {
            std::string key; // #[space]xxx
            std::vector<std::string> value;

            bool empty();

            void clear();
        };

        std::vector<kv> data;

    public:
        ReadConfigMessage(std::string config_file);

        // key=xxx
        // we will find key=#[space]xxx in data.
        std::vector<std::string> get_value(std::string key);

        // key=xxx
        // we will find key-prefix=#[space]xxx
        std::vector<std::string> get_value_prefix(std::string key);

        void print();

    private:
        void print_error(std::string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_READ_CONFIG_MESSAGE_H

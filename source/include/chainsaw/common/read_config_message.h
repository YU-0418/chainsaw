#ifndef CHAINSAW_COMMON_READ_CONFIG_MESSAGE_H
#define CHAINSAW_COMMON_READ_CONFIG_MESSAGE_H

#include "../head.h"
#include "readwritefile.h"
#include "stringtool.h"
#include "../error_message.h"

namespace chainsaw
{
    class ReadConfigMessage
    {
        struct kv
        {
            string key; // #[space]xxx
            vector<string> value;

            bool empty();

            void clear();
        };

        vector<kv> data;

    public:
        ReadConfigMessage(string config_file);

        // key=xxx
        // we will find key=#[space]xxx in data.
        vector<string> get_value(string key);

        // key=xxx
        // we will find key-prefix=#[space]xxx
        vector<string> get_value_prefix(string key);

        void print();

    private:
        void print_error(string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_READ_CONFIG_MESSAGE_H

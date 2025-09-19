#include "read_config_message.h"

bool chainsaw::ReadConfigMessage::kv::empty()
{
    return key.empty() && value.empty();
}

void chainsaw::ReadConfigMessage::kv::clear()
{
    key.clear();
    value.clear();
}

chainsaw::ReadConfigMessage::ReadConfigMessage(std::string config_file)
{
    std::vector<std::string> data = read_file(config_file, false);

    kv buffer;
    for (std::string s : data)
    {
        stringtool tool(s);
        if (tool.startsWith("# "))
        {
            if (!buffer.empty())
            {
                this->data.push_back(buffer);
                buffer.clear();
            }
            buffer.key = s;
        }
        else
        {
            if (buffer.key.empty())
            {
                print_error("the value[" + s + "] no key");
            }
            else
            {
                buffer.value.push_back(s);
            }
        }
    }
    if (!buffer.empty())
    {
        this->data.push_back(buffer);
        buffer.clear();
    }
}

std::vector<std::string> chainsaw::ReadConfigMessage::get_value(std::string key)
{
    auto buffer = std::find_if(data.begin(), data.end(), [&](kv const &buffer)
                               { return buffer.key == "# " + key; });
    std::vector<std::string> res;
    if (buffer != data.end())
    {
        res = buffer->value;
    }

    return res;
}

std::vector<std::string> chainsaw::ReadConfigMessage::get_value_prefix(std::string key)
{
    std::vector<std::string> res;
    auto buffer = std::find_if(data.begin(), data.end(), [&](kv const &buffer)
                               { return stringtool(buffer.key).startsWith("# " + key); });

    if (buffer != data.end())
        res = buffer->value;
    return res;
}

void chainsaw::ReadConfigMessage::print()
{
    for (kv t : data)
    {
        std::cout << "[ key ] [" << t.key << "]";
        if (!t.value.empty())
        {
            std::cout << " : " << std::endl;
            for (std::string s : t.value)
            {
                std::cout << "[value] " << s << std::endl;
            }
        }
    }
}

void chainsaw::ReadConfigMessage::print_error(std::string message)
{
    chainsaw::print_error(message, "read_config_message");
}

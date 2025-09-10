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

chainsaw::ReadConfigMessage::ReadConfigMessage(string config_file)
{
    vector<string> data = read_file(config_file, false);

    kv buffer;
    for (string s : data)
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

vector<string> chainsaw::ReadConfigMessage::get_value(string key)
{
    auto buffer = std::find_if(data.begin(), data.end(), [&](kv const &buffer)
                               { return buffer.key == "# " + key; });
    vector<string> res;
    if (buffer != data.end())
    {
        res = buffer->value;
    }

    return res;
}

vector<string> chainsaw::ReadConfigMessage::get_value_prefix(string key)
{
    vector<string> res;
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
        cout << "[ key ] [" << t.key << "]";
        if (!t.value.empty())
        {
            cout << " : " << endl;
            for (string s : t.value)
            {
                cout << "[value] " << s << endl;
            }
        }
    }
}

void chainsaw::ReadConfigMessage::print_error(string message)
{
    chainsaw::print_error(message, "read_config_message");
}

#include "command.h"

bool chainsaw::command::node::empty() const
{
    return value.empty() && arg.empty();
}

void chainsaw::command::node::clear()
{
    value.clear();
    arg.clear();
    mode = 0;
}

std::vector<std::string> pre(std::string const & data)
{
    int n = data.size();

    std::vector<std::string> res;
    res.reserve(n/2);

    std::string buffer;
    for (int i = 0; i < n; ++i)
    {
        if (data[i] == ' ')
        {
            if (!buffer.empty())
            {
                res.push_back(buffer);
                buffer.clear();
            }
        }
        else if (data[i] == '\\' && i + 1 < n)
        {
            buffer += data[++i];
        }
        else
        {
            buffer += data[i];
        }
    }

    if (!buffer.empty())
    {
        res.push_back(buffer);
    }

    return res;
}

chainsaw::command::command(std::string s)
{
    std::vector<std::string> pre_data = pre(s);

    parse_string_list(pre_data);
}

chainsaw::command::command(std::vector<std::string> arg)
{
    parse_string_list(arg);
}

bool chainsaw::command::find(std::string option)
{
    bool res = false;
    for (node n : all)
    {
        if (n.value == option)
        {
            res = true;
            break;
        }
    }
    return res;
}

std::vector<std::string> chainsaw::command::get_option_arg(std::string option)
{
    std::vector<std::string> res;
    for (node n : all)
    {
        if (n.value == option)
        {
            res = n.arg;
            break;
        }
    }

    return res;
}

void chainsaw::command::print()
{
    std::cout << "command print:(" << all.size() << ")" << std::endl;

    for (node t : all)
    {
        std::cout << "[" << t.mode << "]" << "[" << t.value << "]: ";
        for (std::string s : t.arg)
        {
            std::cout << "[" << s << "]";
        }
        std::cout << std::endl;
    }
}

void chainsaw::command::parse_string_list(std::vector<std::string> data)
{
    node node_buffer;

    for (std::string s : data)
    {
        stringtool tool(s);

        if (tool.startsWith("--"))
        {
            tool.remove_head(2);
            int pos = tool.find('=');

            if (~pos)
            {
                // --c=xxx
                std::string value = tool.split(pos, 0);

                if (value.empty())
                {
                    print_error("There is no data between '--' and '='!");
                    exit(0);
                }

                if (tool.tail() == '=')
                {
                    print_error("-" + value + "=?");
                    exit(0);
                }

                node_buffer.value = value;
                std::string arg = tool.split(pos, 1);
                node_buffer.arg.push_back(arg);
                node_buffer.mode = 1;
                add_data(node_buffer);
            }
            else
            {
                if (!tool.size())
                {
                    print_error("the command-input is '--'.");
                    exit(0);
                }

                node_buffer.value = tool();
            }
        }
        else if (tool.startsWith("-"))
        {
            if (!node_buffer.empty())
            {
                all.push_back(node_buffer);
                node_buffer.clear();
            }

            tool.remove_head();

            int pos = tool.find('=');

            if (~pos)
            {
                // -c=xxx
                std::string value = tool.split(pos, 0);

                if (value.empty())
                {
                    print_error("There is no data between '-' and '='!");
                    exit(0);
                }

                if (tool.tail() == '=')
                {
                    print_error("-" + value + "=?");
                    exit(0);
                }

                node_buffer.value = value;
                std::string arg = tool.split(pos, 1);
                node_buffer.arg.push_back(arg);

                node_buffer.mode = 1;
                add_data(node_buffer);
            }
            else
            {
                //
                if (!tool.size())
                {
                    print_error("the command-input is '-'.");
                    exit(0);
                }

                if (tool.size() == 1)
                {
                    // -c
                    node_buffer.value = tool();
                }
                else
                {
                    //-cxxx
                    node_buffer.value = tool.head();
                    tool.remove_head();
                    node_buffer.arg.push_back(tool());
                    add_data(node_buffer);
                }
            }
        }
        else
        {
            if (node_buffer.empty())
            {
                print_error("There is no value in a node.Why?");
                print_error("And the arg_buffer is " + tool());
                exit(0);
            }
            else
            {
                node_buffer.arg.push_back(tool());
            }
        }
    }

    if (!node_buffer.empty())
    {
        add_data(node_buffer);
    }
}

void chainsaw::command::print_error(std::string message)
{
    chainsaw::print_error(message, "command");
}

void chainsaw::command::add_data(node &buffer)
{
    all.push_back(buffer);
    buffer.clear();
}

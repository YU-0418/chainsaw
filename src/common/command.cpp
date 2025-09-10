#include "command.h"

bool chainsaw::command::node::empty()
{
    return value.empty() && arg.empty();
}

void chainsaw::command::node::clear()
{
    value.clear();
    arg.clear();
    mode = 0;
}

vector<string> pre(string data)
{
    vector<string> res;

    string buffer;
    int n = data.size();
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
        else if (data[i] == '\\')
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
        buffer.clear();
    }

    return res;
}

chainsaw::command::command(string s)
{
    vector<string> pre_data = pre(s);

    parse_string_list(pre_data);
}

chainsaw::command::command(vector<string> arg)
{
    parse_string_list(arg);
}

bool chainsaw::command::find(string option)
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

vector<string> chainsaw::command::get_option_arg(string option)
{
    vector<string> res;
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
    cout << "command print:(" << all.size() << ")" << endl;

    for (node t : all)
    {
        cout << "[" << t.mode << "]" << "[" << t.value << "]: ";
        for (string s : t.arg)
        {
            cout << "[" << s << "]";
        }
        cout << endl;
    }
}

void chainsaw::command::parse_string_list(vector<string> data)
{
    node node_buffer;

    // for (int i = 0; i < data.size(); ++i)
    for (string s : data)
    {
        stringtool tool(s);

        if (tool.startsWith("--"))
        {
            tool.remove_head(2);
            int pos = tool.find('=');

            if (~pos)
            {
                // --c=xxx
                string value = tool.split(pos, 0);

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
                string arg = tool.split(pos, 1);
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
                string value = tool.split(pos, 0);

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
                string arg = tool.split(pos, 1);
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

void chainsaw::command::print_error(string message)
{
    chainsaw::print_error(message, "command");
}

void chainsaw::command::add_data(node &buffer)
{
    all.push_back(buffer);
    buffer.clear();
}

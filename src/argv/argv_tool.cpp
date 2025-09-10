#include "include/argv_tool.h"

void chainsaw::check_argv(int argc, char **argv, bool print)
{
    if (argc == 1)
    {
        print_error("hi!(no input");
        exit(0);
    }
    else
    {
        if (!print)
            return;
        cout << "input parameter:";

        for (int i = 1; i < argc; ++i)
        {
            cout << "[" << argv[i] << "]";
            if (i != argc - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

vector<string> chainsaw::recognize_argv(int argc, char **argv)
{
    vector<string> data;
    if (argc != 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            data.push_back(argv[i]);
        }
    }

    return data;
}

chainsaw::ARGV::ARGV(vector<string> data) : cmd(data)
{
}

chainsaw::ARGV::ARGV(int argc, char **argv) : ARGV(recognize_argv(argc, argv)) {}

bool chainsaw::ARGV::is_contain(string str)
{
    return cmd.find(str);
}

vector<string> chainsaw::ARGV::get_argv(string option)
{
    return cmd.get_option_arg(option);
}

void chainsaw::ARGV::print_error(string message)
{
    chainsaw::print_error(message, "ARGV");
}

void chainsaw::ARGV::print()
{
    cmd.print();
}

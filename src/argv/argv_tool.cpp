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
        std::cout << "input parameter:";

        for (int i = 1; i < argc; ++i)
        {
            std::cout << "[" << argv[i] << "]";
            if (i != argc - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> chainsaw::recognize_argv(int argc, char **argv)
{
    std::vector<std::string> data;
    if (argc != 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            data.push_back(argv[i]);
        }
    }

    return data;
}

chainsaw::ARGV::ARGV(std::vector<std::string> data) : cmd(data)
{
}

chainsaw::ARGV::ARGV(int argc, char **argv) : ARGV(recognize_argv(argc, argv)) {}

bool chainsaw::ARGV::is_contain(std::string str)
{
    return cmd.find(str);
}

std::vector<std::string> chainsaw::ARGV::get_argv(std::string option)
{
    return cmd.get_option_arg(option);
}

void chainsaw::ARGV::print_error(std::string message)
{
    chainsaw::print_error(message, "ARGV");
}

void chainsaw::ARGV::print()
{
    cmd.print();
}

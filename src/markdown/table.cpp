#include "include/table.h"

chainsaw::markdown_table::markdown_table(std::string config_file)
{
    ReadConfigMessage rcm(config_file);

    std::vector<std::string> data;

    data = rcm.get_value_prefix("symb");
    if (data.empty())
    {
        print_error("read symbol error!");
        exit(0);
    }

    symbol = data[0][0];
}

void chainsaw::markdown_table::read_symbol(char c)
{
    symbol = c;
}

void chainsaw::markdown_table::print_error(std::string message)
{
    chainsaw::print_error(message, "markdown_table");
}

void chainsaw::markdown_table::print(std::string file, std::string save_file, bool has_tittle)
{
    write_file wf(save_file, 0b10);

    std::vector<std::string> save_data;

    std::vector<std::string> data = read_file(file);

    for (int i = 0; i < data.size(); ++i)
    {
        stringtool tool(data[i]);
        std::vector<int> pos = tool.find_all(symbol);

        if (pos.empty())
        {
            print_error("no symbol[" + std::string{symbol} + "] find!");
        }

        std::vector<std::string> tmp = tool.split(pos);

        std::string add_txt = "|";

        for (std::string s : tmp)
        {
            add_txt += " " + s + " |";
        }
        save_data.push_back(add_txt);

        if (has_tittle)
        {
            // add second line
            if (i == 0)
            {
                std::string t = "|";
                for (int i = 0; i < tmp.size(); ++i)
                {
                    t += " --- |";
                }
                save_data.push_back(t);
            }
        }
    }

    wf.write(save_data);
}

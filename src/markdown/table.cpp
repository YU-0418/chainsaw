#include "include/table.h"

chainsaw::markdown_table::markdown_table(string config_file)
{
    ReadConfigMessage rcm(config_file);

    vector<string> data;

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

void chainsaw::markdown_table::print_error(string message)
{
    chainsaw::print_error(message, "markdown_table");
}

void chainsaw::markdown_table::print(string file, string save_file, bool has_tittle)
{
    write_file wf(save_file, 0b10);

    vector<string> save_data;

    vector<string> data = read_file(file);

    for (int i = 0; i < data.size(); ++i)
    {
        stringtool tool(data[i]);
        vector<int> pos = tool.find_all(symbol);

        if (pos.empty())
        {
            print_error("no symbol[" + string{symbol} + "] find!");
        }

        vector<string> tmp = tool.split(pos);

        string add_txt = "|";

        for (string s : tmp)
        {
            add_txt += " " + s + " |";
        }
        save_data.push_back(add_txt);

        if (has_tittle)
        {
            // add second line
            if (i == 0)
            {
                string t = "|";
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

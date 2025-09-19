#include <iostream>
#include "chainsaw.h"


int main()
{
    PR(hi);

    PR(chartool);
    // chartool
    char c = 'c';
    char C = 'C';
    PRP(cns::is_upper_char(c));
    PRP(cns::is_lower_char(c));
    PRP(cns::to_upper(c));
    PRP(cns::to_lower(C));
    PRP(cns::is_letter(c));
    std::vector<int> data{1,2,3,4,5};
    PRP(data);

    // stringtool
    PR(stringtool);

    PR(ih);

    return 0;
}


void worker(int id)
{
    for (int i = 0; i < 5; ++i)
    {
        cns::SafeLogger::instance().info("Thread ", id, " iteration ", i);

        std::vector<int> vec = {id * 10 + i, id * 10 + i + 1, id * 10 + i + 2};
        cns::SafeLogger::instance().single(vec, "Numbers from thread " + std::to_string(id));

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main1()
{
    // 设置日志文件（可选）
    cns::SafeLogger::instance().setLogFile("test.log");

    // 启动 4 个线程
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i)
    {
        threads.emplace_back(worker, i);
    }

    // 等待所有线程结束
    for (auto &t : threads)
    {
        t.join();
    }

    cns::SafeLogger::instance().info("All threads finished.");
    return 0;
}

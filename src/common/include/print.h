#ifndef CHAINSAW_COMMON_PRINT_H
#define CHAINSAW_COMMON_PRINT_H

#include "head.h"
#include <mutex>

namespace chainsaw
{
    enum class HeadType
    {
        Normal,
        HI,
        IH,
        LETTER
    };

    enum class LogLevel
    {
        INFO,
        WARN,
        ERROR
    };

    class SafeLogger
    {
    public:
        static SafeLogger &instance();

        void setLogFile(std::string const &filename);

        template <typename... Args>
        void log(LogLevel level, Args &&...args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            std::ostringstream oss;
            oss << m_head
                << chainsaw_head()
                << getTimeStamp()
                << " [T" << std::this_thread::get_id() << "] "
                << "[" << levelToColorString(level) << "\033[0m] ";
            (oss << ... << args);

            std::string line = oss.str();

            // 打印到控制台
            std::cout << line << std::endl;

            // 写入文件
            if (m_log_file.is_open())
            {
                m_log_file << stripAnsiCodes(line) << std::endl;
            }
        }

        template <typename... Args>
        void info(Args &&...args) { log(LogLevel::INFO, std::forward<Args>(args)...); }

        template <typename... Args>
        void warn(Args &&...args) { log(LogLevel::WARN, std::forward<Args>(args)...); }

        template <typename... Args>
        void error(Args &&...args) { log(LogLevel::ERROR, std::forward<Args>(args)...); }

        void single(std::string vaue);

        template <typename T>
        void single(T value, std::string tip)
        {
            if(tip.empty())
            {
                log(LogLevel::INFO,value);
            }
            else
            {
                log(LogLevel::INFO, tip, m_tip_symbol, value);
            }
        }

        template <typename T>
        void single(std::vector<T> value, std::string tip)
        {
            if(!tip.empty())
            {
                m_type = HeadType::LETTER;
                m_char = 'l';
                log(LogLevel::INFO, tip, m_tip_symbol);
            }

            for(T const & t : value)
            {
                log (LogLevel::INFO, t);
            }

            reset_headtype();
        }

        //void single(std::string tip, );

    private:
        SafeLogger() = default;

        ~SafeLogger();

        SafeLogger(const SafeLogger &) = delete;
        SafeLogger &operator=(const SafeLogger &) = delete;

        std::string getTimeStamp() const;

        const char *levelToString(LogLevel level) const;

        std::string levelToColorString(LogLevel level) const;

        std::string stripAnsiCodes(const std::string &s) const;

        //
        std::string chainsaw_head() const;

        void judge_headtype(std::string value);

        void reset_headtype();
    private:
        mutable std::mutex m_mutex;
        std::ofstream m_log_file;
        HeadType m_type = HeadType::LETTER;
        std::string m_head = "[ chainsaw ]";
        char m_char = '-';
        std::string m_tip_symbol = ":";
    };

    template <>
    void chainsaw::SafeLogger::single(std::string value, std::string tip);

    template <>
    void chainsaw::SafeLogger::single(bool value, std::string tip);

    template <>
    void chainsaw::SafeLogger::single(char value, std::string tip);


    // TODO
    // void print_style();

} // namespace chainsaw

#ifndef PR
#define PR(data) chainsaw::SafeLogger::instance().single(#data)
#endif // !PR

#ifndef PRP
#define PRP(data) chainsaw::SafeLogger::instance().single(data, #data)
#endif // !PRP

#ifndef PRP2
#define PRP2(data, tips) chainsaw::SafeLogger::instance().single(data, #tips)
#endif // !PRP2

#endif // !CHAINSAW_COMMON_PRINT_H

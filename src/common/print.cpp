#include "print.h"
#include <iomanip>
#include <sstream>

chainsaw::SafeLogger &chainsaw::SafeLogger::instance()
{
    static SafeLogger inst;
    return inst;
}

void chainsaw::SafeLogger::setLogFile(std::string const &filename)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_log_file.open(filename, std::ios::out | std::ios::app);
    if (!m_log_file.is_open())
    {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

void chainsaw::SafeLogger::single(std::string s)
{
    judge_headtype(s);
    log(LogLevel::INFO, s);
    if (m_type != HeadType::Normal)
        m_type = HeadType::Normal;
}

chainsaw::SafeLogger::~SafeLogger()
{
    if (m_log_file.is_open())
        m_log_file.close();
}

std::string chainsaw::SafeLogger::getTimeStamp() const
{
    auto now = std::chrono::system_clock::now();
    auto itt = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
    localtime_r(&itt, &tm);
    std::ostringstream oss;
    // oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    oss << std::put_time(&tm, "%m-%d %H:%M:%S");
    return oss.str();
}

const char *chainsaw::SafeLogger::levelToString(LogLevel level) const
{
    switch (level)
    {
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARN:
        return "WARN";
    case LogLevel::ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

std::string chainsaw::SafeLogger::levelToColorString(LogLevel level) const
{
    switch (level)
    {
    case LogLevel::INFO:
        return "\033[32mINFO"; // 绿色
    case LogLevel::WARN:
        return "\033[33mWARN"; // 黄色
    case LogLevel::ERROR:
        return "\033[31mERR "; // 红色
    default:
        return "UNKNOWN";
    }
}

std::string chainsaw::SafeLogger::stripAnsiCodes(const std::string &s) const
{
    std::string result;
    bool inEscape = false;
    for (char c : s)
    {
        if (c == '\033')
        {
            inEscape = true;
            continue;
        }
        if (inEscape)
        {
            if (c == 'm')
            {
                inEscape = false;
            }
            continue;
        }
        result += c;
    }
    return result;
}

std::string chainsaw::SafeLogger::chainsaw_head() const
{
    std::string res = "";
    switch (m_type)
    {
    case HeadType::HI:
        res += " (= ";
        break;
    case HeadType::IH:
        res += " =) ";
        break;
    case HeadType::Normal:
        res += " -- ";
        break;
    case HeadType::LETTER:
    {
        std::string buffer(" -- ");
        buffer[2] = m_char;
        res += buffer;
    }
    break;
    default:
        std::cerr << "HeadType is error!" << std::endl;
        res += " -- ";
        break;
    }

    return res;
}

void chainsaw::SafeLogger::judge_headtype(std::string value)
{
    if (value == "hi" || value == "HI" || value == "hello" || value == "HELLO" || value == "hey" || value == "HEY")
    {
        m_type = HeadType::HI;
    }

    if (value == "ih" || value == "IH" || value == "bye" || value == "BYE" || value == "")
    {
        m_type = HeadType::IH;
    }
}

void chainsaw::SafeLogger::reset_headtype()
{
    m_type = HeadType::Normal;
    m_char = '-';
}

template <>
void chainsaw::SafeLogger::single(std::string value, std::string tip)
{
    if (tip.empty())
    {
        judge_headtype(value);
        log(LogLevel::INFO, value);
    }
    else
    {
        log(LogLevel::INFO, tip, m_tip_symbol, value);
    }
}

template <>
void chainsaw::SafeLogger::single(bool value, std::string tip)
{
    std::string data = value ? "True" : "False";
    if (tip.empty())
    {
        log(LogLevel::INFO, data);
    }
    else
    {
        log(LogLevel::INFO, tip, m_tip_symbol, data);
    }
}

template <>
void chainsaw::SafeLogger::single(char value, std::string tip)
{
    if (tip.empty())
    {
        log(LogLevel::INFO, (int)value);
    }
    else
    {
        log(LogLevel::INFO, tip, m_tip_symbol, (int)value);
    }
}

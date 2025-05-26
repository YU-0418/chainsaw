#ifndef CHAINSAW_C_CODE_C_STRING_H
#define CHAINSAW_C_CODE_C_STRING_H

#include <iostream>

namespace chainsaw
{
    using std::cout;
    using std::endl;
    
    struct char_list
    {
        char c;
        char_list *next = nullptr;

        char_list() {}
        char_list(char c) : c(c) {}
        char_list(char c, char_list *next) : c(c), next(next) {}
    };

    class c_string
    {
        char_list *head;
        char_list *tail;

    public:
        int _num = 0;
        int size = 0;

        c_string()
        {
            ++_num;
            head = nullptr;
            tail = nullptr;
        }

        c_string(char *data)
        {
            ++_num;

            head = nullptr;

            push_back(data);
        }

        // 析构函数
        ~c_string()
        {
            --_num; // 减少一次计数

            if (!_num)
                return;

            while (head)
            {
                char_list *buff = head;
                head = head->next;
                delete buff;
            }
        }

        // 在字符串最后面加入一个字符
        void push_back(char c)
        {
            if (c == '\n')
                return;
            // 如果加入的是结束字符,则size不变
            if (c)
                ++size;
            if (!head)
            {
                head = new char_list(c);
                tail = head;
            }
            else
            {
                tail->next = new char_list(c);
                tail = tail->next;
            }
        }

        // 在字符串的末尾加入一串字符
        void push_back(char *data)
        {
            while (*data++)
                push_back(data);
        }

        void push_back(c_string data)
        {
            char *buff = data.get_value();
            push_back(buff);
            delete[] buff;
        }

        // 判断这个字符串是否为空
        bool empty()
        {
            return head == nullptr;
        }

        // 判断两个字符串是否相等
        bool equal(c_string s)
        {
            bool res = true;

            if (size == s.size)
            {
                char_list *t1 = head;
                char_list *t2 = s.head;
                while (t1 && t2)
                {
                    if (t1->c != t2->c)
                    {
                        res = false;
                        break;
                    }
                    t1 = t1->next;
                    t2 = t2->next;
                }
            }
            else
            {
                res = false;
            }

            return res;
        }

        // 逐个比较每一个字符的大小
        // 若传入字符比较大，返回false
        bool compare(c_string s)
        {
            bool res = true;

            char_list *t1 = head;
            char_list *t2 = s.head;

            while (t1 && t2)
            {
                if (t1->c > t2->c)
                {
                    res = false;
                    break;
                }
                t1 = t1->next;
                t2 = t2->next;
            }

            return res;
        }

        // 输出字符串的长度
        int size()
        {
            return size;
        }

        // 用完立刻释放
        char *get_value()
        {
            char *res = new char[size + 1];
            char_list *now = head;
            int i = 0;
            while (now && now->c)
            {
                res[i++] = now->c;
                now = now->next;
            }
            res[i] = '\0';

            return res;
        }

        void print()
        {
            char *val = get_value();
            // cout << val;
            cout << "[" << val << "]";
            delete[] val;
        }

        int to_int()
        {
            int res = 0;
            char_list *now = head;
            while (now && now->c)
            {
                res = res * 10 + (now->c - '0');
                now = now->next;
            }
            return res;
        }

        char get_value(int index)
        {
            char res;
            char_list *now = head;
            while (now && now->c && index--)
            {
                now = now->next;
            }

            if (index)
            {
                // index没归零，说明传入的下标是违法的
            }

            res = now->c;
            return res;
        }

        // 清空字符串
        void clear()
        {
            size = 0;
            while (head)
            {
                char_list *buff = head;
                head = head->next;
                delete buff;
            }
            tail = nullptr;
        }
        
    };
} // namespace chainsaw

#endif // !CHAINSAW_C_CODE_C_STRING_H

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

        // ��������
        ~c_string()
        {
            --_num; // ����һ�μ���

            if (!_num)
                return;

            while (head)
            {
                char_list *buff = head;
                head = head->next;
                delete buff;
            }
        }

        // ���ַ�����������һ���ַ�
        void push_back(char c)
        {
            if (c == '\n')
                return;
            // ���������ǽ����ַ�,��size����
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

        // ���ַ�����ĩβ����һ���ַ�
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

        // �ж�����ַ����Ƿ�Ϊ��
        bool empty()
        {
            return head == nullptr;
        }

        // �ж������ַ����Ƿ����
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

        // ����Ƚ�ÿһ���ַ��Ĵ�С
        // �������ַ��Ƚϴ󣬷���false
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

        // ����ַ����ĳ���
        int size()
        {
            return size;
        }

        // ���������ͷ�
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
                // indexû���㣬˵��������±���Υ����
            }

            res = now->c;
            return res;
        }

        // ����ַ���
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

#include <codech/codech_def.h>
#include <cstring>

namespace c11
{
    class String
    {
    public:
        String():m_data(new char[1])
        {
            m_data[0]='\0';
        }
        String(const String &rhs)
        {
            m_data = new char[rhs.size() + 1];
            strcpy(m_data, rhs.c_str());
        }
        String(const char* raw) // 需要判断是否为null?
        {
            m_data = new char[strlen(raw)+1];
            strcpy(m_data, raw);
        }

        ~String()
        {
            delete []m_data;
        }

        // why not copy rhs.data to this?
        // = itself?
        String& operator=(const String& rhs)
        {
            String tmp(rhs);
            swap(tmp);
            return *this;
        }

        // C++11 move ctor
        String(String&& rhs)
                :m_data(rhs.m_data)
        {
            rhs.m_data = nullptr;
        }

        String& operator=(String&& rhs)
        {
            swap(rhs);
            return *this;
        }
        // accessor
        size_t size() const
        {
            return strlen(m_data);
        }

        const char* c_str() const
        {
            return m_data;
        }

        void swap(String&rhs)
        {
            std::swap(m_data, rhs.m_data);
        }


    private:
        char *m_data;
    };
}



DEFINE_CODE_TEST(string_impl)
{

}

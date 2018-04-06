#ifndef CODECH_UTIL_H_
#define CODECH_UTIL_H_

#include <string>
#include <algorithm>


namespace CODECH
{
    inline bool isspace(char ch)
    {
        return ch == ' ';
    }
    inline void trim(std::string &s) {
        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](char c){ return CODECH::isspace(c); }));
        s.erase(std::find_if_not(s.rbegin(), s.rend(), [](char c){ return CODECH::isspace(c); }).base(), s.end());
    }

    inline std::string& trim(std::string &&s) {
        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](char c){ return CODECH::isspace(c); }));
        s.erase(std::find_if_not(s.rbegin(), s.rend(), [](char c){ return CODECH::isspace(c); }).base(), s.end());
        return s;
    }
}

#endif


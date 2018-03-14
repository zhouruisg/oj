#include <string>
#include <algorithm>

namespace CODECH
{
    static bool isspace(char ch)
    {
        return ch == ' ';
    }
    static void trim(std::string &s) {
        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](char c){ return CODECH::isspace(c); }));
        s.erase(std::find_if_not(s.rbegin(), s.rend(), [](char c){ return CODECH::isspace(c); }).base(), s.end());
    }
}

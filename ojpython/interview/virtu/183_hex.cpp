// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <sstream>
using namespace std;

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    std::stringstream stream;
    stream << std::hex << 257;
    std::string result( stream.str() );
    return result;
}

int main()
{
    string s=string("257");
    cout<<solution(s);
}
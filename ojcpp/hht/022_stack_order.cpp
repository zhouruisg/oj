//
// Created by rui.zhou on 5/9/2019.
//
#include <codech/codech_def.h>
using namespace std;

// 两个整数序列，第一个是压栈顺序，判断第二个是否为出栈顺序
// {1,2,3,4,5} -> {4,5,3,2,1}, 即先pop 4后再push 5 {4,3,5,1,2}就不行
namespace {
    class Solution {
    public:
        bool isPopOrder(const vector<int> &p,const vector<int>&o) {
            stack<int> st;
            for (auto&it :p) {
                st.push(it);
            }
            int pos=0;
            while (pos<o.size()) {
                auto oel = o[pos++];
                deque<int> dq;
                bool found = false;
                while (!st.empty()) {
                    auto pel = st.top();
                    if (pel==oel) {
                        st.pop();found=true;break;
                    } else {
                        dq.push_front(pel);st.pop();
                    }
                }
                if (!found) {
                    return false;
                } else {
                    while (!dq.empty()) {
                        st.push(dq.front());
                        dq.pop_front();
                    }
                }
            }
            return true;
        }
    };
}

DEFINE_CODE_TEST(hht_022_stack_order)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isPopOrder({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}),false);
        VERIFY_CASE(obj.isPopOrder({1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}),true);

    }
}
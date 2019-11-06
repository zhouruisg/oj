//
// Created by rui zhou on 2019-11-06.
//

#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;
vector<int> findMaxsumArr(vector<int> &&arr) {
    int maxsum = INT_MIN;
    // 0, -1 = -1,discard
    // please explain the logic before code
    int cursum = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i< arr.size(); i++) {
        if (cursum <= 0) {
            cursum = arr[i];
            start = i;
            end = i;
        } else {
            cursum+=arr[i];
        }
        if (cursum>maxsum) {
            maxsum = cursum;
            end = i;
        }
    }
    vector<int> ans;
    if (end>=start) {
        copy(arr.begin()+start,arr.begin()+end+1,back_inserter(ans));
    }
    return ans;
}

//[7, 9, 5, 6, 3, 2]
//7, 9 -> 2
//[2, 3, 10, 6, 4, 8, 1]
//10, 2 -> 8
//
//
//[2, 3, 10, 16, 4, 8, 1]
//
//
//[22, 3, 10, 16, 4, 8, 1]
//->16 , 3
//
//
//
//int diff(vector<int> &arr) {
//    int mi = INT_MAX;
//    int mm = INT_MAX;
//    int maxdiff = INT_MIN;
//
//    for (int i=0;i<arr.size();i++) {
////       mi = min(mi,arr[i]);
//
//        if (arr[i] > mi) {
//            mm = min(arr[i],mi);
//        }
//    }
//}

DEFINE_CODE_TEST(autodesk_maxsumarr)
{
//    {
//        vector<int> ans = findMaxsumArr({0,-1,6,7,8,-3,7,9});
//        cout << PRINT_VEC(move(ans));
//    }
    {
        vector<int> ans = findMaxsumArr({-2,-3,-4,0,-1,-6,-7,-8,-3,-7,-9});
        cout << PRINT_VEC(move(ans));
    }

}
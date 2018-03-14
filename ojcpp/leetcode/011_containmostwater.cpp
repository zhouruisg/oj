//
// Created by Rui Zhou on 10/3/18.
//

/*
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the t
 * wo endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such that the container
 * contains the most water.

Note: You may not slant the container and n is at least 2.
12:41

 2 8 4 6 2 -> 8 4 6 is the container have most water.

 assume the widest is the most water one, then iterate and find
 ->
 */

#include <codech/codech_def.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /*int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = height.size();
        for (int i =0 ; i < l - 1; i++) {
            int cur = height[i];
            for (int j = i+1; j < l; j++) {
                int next = height[j];
                if (next >= cur) {
                    maxArea = max(maxArea, cur*())
                }
            }
        }
    }*/
    int maxArea0(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }


    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i=0,j=height.size()-1;
        while (i < j) {
            int h = min(height[i],height[j]);
            maxArea = max(maxArea, (j-i)*h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return maxArea;
    }
};



DEFINE_CODE_TEST(mostwater)
{
    Solution obj;
    vector<int> h = {2,8,4,6,2};
    cout << obj.maxArea(h);

    vector<int> h1 = {2,2,3};
    cout << obj.maxArea(h1);



}
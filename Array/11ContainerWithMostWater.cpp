class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int res=0;
        while(i<j){
            int h = min(height[i],height[j]);
            res = max(res,(j-i)*h);
            while(i < j && height[j] <= h) j--;
            while(i < j && height[i] <= h) i++;
        }
        return res;
    }
};
/**
刚开始理解错题意，以为是找最长的两个相邻的数字，后来才有容器的概念。
讨论中的中文分析很有道理，非常收益，其实就是对可能情况的归纳，然后得出一个有用的结论
***
设置两个指针i, j, 一头一尾, 相向而行. 不妨设i指向的挡板较低, j指向的挡板较高(height[i] < height[j]).
下一步移动哪个指针?
-- 若移动j, 无论height[j-1]是何种高度, 形成的面积都小于之前的面积.
-- 若移动i, 若height[i+1] <= height[i], 面积一定缩小; 但若height[i+1] > height[i], 面积则有可能增大.
综上, 应该移动指向较低挡板的那个指针.
***

具体实现的时候，没必要判断哪个小，因为我们都是判断哪个会比较小的小，才会移动指针，较大的那个并不会移动指针，
直接让他们两者都循环好了。
**/

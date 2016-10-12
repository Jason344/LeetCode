class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                res[0] = hash[target - nums[i]], res[1] = i;
                return res;
                }
            hash[nums[i]] = i;
        }
        return res;
    }
};

/**
我本来想先把num排序，遍历每一个数字，用二分搜索查找可能的另一个数字，
但由于不熟悉STL，我先看了看评论区，结果发现，大家都用map就可以实现O（n）
的算法了，学习了unordered_map和vector的初始化。
**/

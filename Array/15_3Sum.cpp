class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;

        if(len<2) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            int lo = i+1;
            int hi = len-1;
            if(i>0&&nums[i]==nums[i-1]) continue;
            while(lo<hi){
                int equal = nums[i]+nums[lo]+nums[hi];
                if(equal==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);
                    while(nums[lo+1]==nums[lo])lo++;
                    while(nums[hi-1]==nums[hi])hi--;
                    lo++;
                    hi--;
                }else if(equal<0){
//额外的循环导致超时                    while(nums[lo+1]==nums[lo])lo++;
                    lo++;
                }else{
//额外的循环导致超时                    while(nums[hi-1]==nums[hi])hi++;
                    hi--;
                }
            }
        }
        return res;
    }
};

/**
a+b+c=0
本想先排序，再用两个指针两两匹配数组中的元素，在用二分搜索在数组中寻找-c，但是二分搜索的时候，可能会导致同一个元素重复使用，
后来参考了评论区的建议，用i遍历数组，用两个指针lo和hi一前一后去搜索能和i够成3sum的元素。尽量使3者之和能接近0，
时间复杂度为O（n^2）。
**/

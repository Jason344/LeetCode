class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i,cnt;

        if(n<2) return n;
        for(i=1,cnt=0;i<n;i++){
            if(nums[i]!=nums[cnt]){
                nums[++cnt] = nums[i];
            }
        }
        return cnt+1;
    }
};
/**
我的代码
两个指针i,cnt， i负责遍数组，找出第一个不相同的数字，cnt负责指向当前最后一个不重元素
**/

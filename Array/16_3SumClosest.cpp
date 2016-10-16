class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        int offset = abs(closest-target);
        if(len == 3) return closest;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            int lo = i+1;
            int hi = len-1;
            while(lo<hi){
                int equal = nums[i]+nums[lo]+nums[hi]-target;
                if(equal==0){
                    return target;
                }else if(equal<0){
                    lo++;
                }else hi--;
                if(abs(equal)<offset){
                    offset = abs(equal);
                    closest = equal + target;
                }
            }
        }
        return closest;
    }
};
/**
题型与3sum相似，遍历的方式都是相同的，就是多设置两个观察变量，offset和closest。
**/

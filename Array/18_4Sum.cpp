class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<len-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int lo = j+1;
                int hi = len-1;
                while(lo<hi){
                    int equal = nums[i]+nums[j]+nums[lo]+nums[hi]-target;
                    if(equal==0){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        ans.push_back(temp);
                        while(nums[lo+1]==nums[lo])lo++;
                        while(nums[hi-1]==nums[hi])hi--;
                        lo++;
                        hi--;
                    }else if(equal<0){
                        lo++;
                    }else hi--;
                }
            }
        }
        return ans;
    }
};
/**
和3sum相似，i和j负责去遍历数组中不同的的两两组合，lo和hi负责为每一对组合寻找可能的4sum，
注意temp的声明要写在equal==0的语句内，不然会超时。
**/

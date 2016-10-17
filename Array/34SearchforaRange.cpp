class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo,mid,hi;
        int l,h;
        vector<int> ans;
        lo = 0;
        hi = nums.size()-1;
        if(hi==0&&target==nums[0]) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(nums[mid]==target){
                for(l=mid;nums[l]==target&&l>=lo;l--);
                l++;
                for(h=mid;nums[h]==target&&h<=hi;h++);
                h--;
                ans.push_back(l);
                ans.push_back(h);
                return ans;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else hi = mid-1;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};
//简单的二分查找，并向两边扩展，主义边界情况

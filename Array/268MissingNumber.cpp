/*
我用求和的方法，先求出1-n的和，再减去实际的和，剩下的就是缺少的数字，
但别人用位运算的方法，每个数字和自己异或后为0，于是1-n的数字和数组逐个异或，剩下的就是
只异或了一次的数字，也就是缺少的数字。
*/
//我的代码
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,x=0,n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        x = n*(n+1)/2-sum;
        return x;
    }
};
//别人的代码
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};

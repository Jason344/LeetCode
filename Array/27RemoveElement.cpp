class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,cnt;
        int n = nums.size();

        for(i=0,cnt=0;i<n;i++){
            if(nums[i]!=val){
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};
/**
我的代码
两个指针i和cnt，i负责遍历整个数组，当发现不一样的数字便将其写到cnt所在的位置，cnt指向下一个可写的位置，也就是去除元素后的数组的长度。
**/

/*
简单地先非零数字前置，再把剩下的数字置零既可
但我在for循环中修改了循环的变量，使问题变得更加麻烦，
参考讨论区的内容后，给出了更优雅的解法
*/
//我的解法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fill=0,find=0,n=nums.size();

        for(find=0;find<n;find++){
            while(nums[find]==0&&find<n){
                find++;
            }
            if(find<n){
                nums[fill]=nums[find];
                fill++;
            }
        }
        while(fill<n){
            nums[fill] = 0;
            fill++;
        }
    }
};
//别人的解法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),index=0;


        for(int i=0;i<n;i++){
            if(nums[i]!=0) nums[index++] = nums[i];
        }
        while(index<n){
            nums[index] = 0;
            index++;
        }
    }
};

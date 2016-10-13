public class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        int i=1;
        int cnt = 0;

        if(len<2) return len;
        for(i=1;i<len;i++){
            if(nums[cnt]!=nums[i]){
                cnt++;
                nums[cnt]=nums[i];
            }
        }
        return cnt;
    }
}

/**
我的代码，但不能通过，不知道问题所在
**/

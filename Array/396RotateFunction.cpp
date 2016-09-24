
/**
可以用作差法找出F（k）的递推公式，然后就可以在O（n）的时间内解决问题
F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]
F(k-1) = 0 * Bk-1[0] + 1 * Bk-1[1] + ... + (n-1) * Bk-1[n-1]
       = 0 * Bk[1] + 1 * Bk[2] + ... + (n-2) * Bk[n-1] + (n-1) * Bk[0]

F(k) - F(k-1) = Bk[1] + Bk[2] + ... + Bk[n-1] + (1-n)Bk[0]
              = (Bk[0] + ... + Bk[n-1]) - nBk[0]
              = sum - nBk[0]

所以 F（k）=F（k-1）+sum-nBk[0]
k=0;Bk[0]==A[0];
k=1;Bk[0]==A[n-1];
k=2;Bk[0]==A[n-2];
所以Bk[0]==A[n-k];
**/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int F=0,sum=0,max=0,n=A.size();

        for(int i=0;i<n;i++){
            F += A[i];
            sum += i*A[i];
        }
        max = sum;
        for(int k=1;k<n+1;k++){
            sum +=F;
            sum -= n*A[n-k];
            if(sum>max)
                max = sum;
        }
        return max;
    }
};

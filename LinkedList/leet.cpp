class Solution {

    #define inte long long inte

public:
    long long maxStrength(vector<inte>& nums) {

        inte n= nums.size();
        inte m= 0;
        inte maxi= INT_MIN;
        inte tm= 0;
        inte final= 1;
        inte zm= 0;
        if(n==1)
            return nums[0];
        inte i=0;
         while(i<=n-1){

            if(nums[i]==0){
               zm++;
                continue;
            }

            if(nums[i]<0){
               m++;
                maxi= max(maxi,i);
            } else {
               tm++;
            }

            final*=abs(i);
            i++;
        }

        if(zm==n)
            return 0;

        if(m+zm==n &&m==1)
            return 0;

        if(m%2==0){
            return final;
        } else {
            return (final/abs(maxi));
        }
    }
};
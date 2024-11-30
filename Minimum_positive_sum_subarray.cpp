class Solution {
public:
    int minimumSubarray(vector<int>& nums,int k,int n){
        int i=0,j=0;
        int mini=INT_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(j-i+1 > k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1 == k){
                if(sum>0){
                    mini = min(mini,sum);
                }
            }
            j++;
        }
        return (mini==INT_MAX)?-1:mini;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=l;i<=r;i++){
            int ans = minimumSubarray(nums,i,n);
            if(ans!=-1){
            mini = min(mini,ans);
            }
        }
        return (mini==INT_MAX)?-1:mini; 
    }
};

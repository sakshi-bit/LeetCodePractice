class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,0);

      //  prefix[0]=nums[0];
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(nums[i-1] == 0){
                int leftSum = prefix[i-1];
                int rightsum = prefix[n] - prefix[i-1];
                int diff = abs(leftSum-rightsum);
                if(diff==0){
                    ans+=2;
                }else if(diff==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

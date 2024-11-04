class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longestLength=0;
        unordered_map<int,bool>mpp;

        for(int num:nums){
            mpp[num]=false;
        }

        for(int num:nums){
            int currentLength=1;
            int nextNum=num+1;
            while(mpp.find(nextNum)!=mpp.end() && mpp[nextNum]==false){
                currentLength++;
                mpp[nextNum]=true;
                nextNum++;
            }
            int prevNum=num-1;
            while(mpp.find(prevNum)!=mpp.end() && mpp[prevNum]==false){
                currentLength++;
                mpp[prevNum] = true;
                prevNum--;
            }
            longestLength = max(longestLength,currentLength);
        }
        return longestLength;
        
    }
};

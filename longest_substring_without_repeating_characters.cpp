class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int>mpp;
        int i=0,j=0;
        int n = s.length();

        int maxi = INT_MIN;
        if(s.length() == 0){
            return 0;
        }
        while(j<n){
            mpp[s[j]]++;

            if(mpp.size() == j-i+1){
                maxi = max(maxi,j-i+1);
                j++;
            }else if(mpp.size() < j-i+1){
                while(mpp.size()<j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
            }
            
            
        }
        return maxi;
    }
};

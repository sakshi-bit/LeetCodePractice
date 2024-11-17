class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int i=0,j=0;
        int n = s.length();
        int maxfreq=0;
        int maxwindowsize=0;

        while(j<n){
            freq[s[j]-'A']++;
            maxfreq = max(maxfreq,freq[s[j]-'A']);
            int windowLength = j-i+1;

            if(windowLength - maxfreq > k){
                freq[s[i]-'A']--;
                i++;
            }

            windowLength = j-i+1;
            maxwindowsize = max(maxwindowsize,windowLength);
            j++;
        }
        return maxwindowsize;
    }
};

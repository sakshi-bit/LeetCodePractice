class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>results;
        unordered_map<string,vector<string>>mpp;

        int n = strs.size();

        for(int i=0;i<n;i++){
            string temps = strs[i];
            sort(temps.begin(),temps.end());
            mpp[temps].push_back(strs[i]);
        }

        for(auto it:mpp){
            results.push_back(it.second);
        }

        return results;
        
    }
};

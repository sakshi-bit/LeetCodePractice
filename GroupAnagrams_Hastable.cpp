class Solution {
public:

    string generate(string &word){
        int arr[26]={0};

        for(char& ch: word){
            arr[ch-'a']++;
        }

        string new_word="";

        for(int i=0;i<26;i++){
            int freq=arr[i];
            if(freq>0){
                for(int j=0;j<freq;j++){
                    new_word+= i+'a';
                }
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mpp;
        int n = strs.size();

        for(int i=0;i<n;i++){
            string word = strs[i];
            string new_word = generate(word);
            mpp[new_word].push_back(word);
        }

        for(auto &it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        vector<vector<int>>bucket(n+1);

        for(auto it: mpp){
            int element= it.first;
            int freq=it.second;

            bucket[freq].push_back(element);
        }

        vector<int>ans;

        for(int i=n;i>=0;i--){

            if(bucket[i].size()==0){
                continue;
            }
            while(bucket[i].size()>0 && k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return ans;

        
    }
};

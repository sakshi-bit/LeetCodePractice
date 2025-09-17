class Solution {
public:
    typedef pair<int,pair<int,int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P,vector<P>>pq; // max-heap storing {sum, {i, j}}

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum = nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }else{
                    break; // since nums2 is sorted, later sums will only be larger
                }
            }
        }

        vector<vector<int>>result;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i],nums2[j]});
        }
        return result;
    }
};

/*
 Time Complexity:
- Outer loop runs nums1.size() times (n1).
- Inner loop runs nums2.size() times (n2), but often breaks early when sums exceed heap top.
- In worst case → O(n1 * min(n2, k) * log k) because:
   - Heap operations (push/pop) take O(log k).
   - At most k elements are kept in the heap.

 Space Complexity:
- Heap stores at most k elements → O(k).
- Result stores k pairs → O(k).
- So, total space = O(k).
*/

class Solution {
public:
    int M = 1e9+7;
    typedef pair<int,int>P;
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Min-heap storing {subarray_sum, end_index}
        priority_queue<P,vector<P>,greater<P>>pq;
        
        // Push initial subarrays (each element as a starting subarray)
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        int result=0;

        // Extract subarray sums in increasing order
        for(int count=1;count<=right;count++){
            auto p = pq.top(); // smallest subarray sum
            pq.pop();
            int sum = p.first;
            int idx = p.second;

            if(count >= left){
                result = (result+sum)%M;
            }

            int new_idx = idx+1;
            P new_pair;
            if(new_idx<n){
                // Extend subarray by including nums[new_idx]
                new_pair.first = sum+nums[new_idx];
                new_pair.second = new_idx;
                pq.push(new_pair);
            }
        }

        return result;
    }
};

/*
Time Complexity (TC):
- Each of the "right" smallest subarray sums is extracted from the heap.
- Heap operations (push/pop) take O(log n).
- We may push at most n * log(right) times.
- Overall: O((right) * log n).

 Space Complexity (SC):
- Heap stores at most O(n) elements at a time.
- Extra variables are O(1).
- Overall: O(n).
*/

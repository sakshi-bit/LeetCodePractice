class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int,vector<int>>pq;  

        // Push all elements into the max heap
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        // Repeat k times: take the max, add to ans, then push ceil(max/3)
        while(k--){
            int maxEl = pq.top();
            pq.pop();
            ans+=maxEl;
            maxEl = ceil(maxEl/3.0);
            pq.push(maxEl);
        }

        return ans;
    }
};

// Time Complexity: O(n log n + k log n)
//   - O(n log n) for building the heap with n elements
//   - O(k log n) for k iterations (each pop + push takes O(log n))
// Space Complexity: O(n)
//   - Priority queue stores up to n elements

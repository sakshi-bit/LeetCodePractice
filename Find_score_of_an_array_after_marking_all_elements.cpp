class Solution {
public:
    typedef pair<int,int>P;

    // Time Complexity: O(n log n) 
    //   -> pushing all elements into priority_queue: O(n log n)
    //   -> popping all elements from priority_queue: O(n log n)
    //   -> each index visited at most once
    //
    // Space Complexity: O(n)
    //   -> priority_queue stores n elements
    //   -> visited vector of size n

    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();

        // min-heap based on element value (pair<value, index>)
        priority_queue<P, vector<P>, greater<P>> pq;

        // visited[i] = true means index i is already "used"
        vector<bool> visited(n, false);

        // Push all elements with their index into pq -> O(n log n)
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i}); // GitHub comment: pushing {value, index}
        }

        // Process the heap until empty
        while(!pq.empty()){
            P temp = pq.top(); 
            pq.pop(); // GitHub comment: always pop the smallest element

            int elem = temp.first;   // current value
            int idx = temp.second;   // current index

            if(!visited[idx]){ // GitHub comment: only process if not visited yet
                visited[idx] = true;
                score += elem; // GitHub comment: add value to score

                // Mark left neighbor as visited if valid
                if(idx - 1 >= 0 && !visited[idx - 1]){
                    visited[idx - 1] = true;
                }

                // Mark right neighbor as visited if valid
                if(idx + 1 < n && !visited[idx + 1]){
                    visited[idx + 1] = true;
                }
            }
        }
        return score;
    }
};

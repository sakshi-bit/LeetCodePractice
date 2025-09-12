class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap (priority queue) to always get the two heaviest stones
        priority_queue<int> pq(begin(stones), end(stones));

        // Keep smashing the two heaviest stones until at most one stone remains
        while(pq.size() > 1) {
            int a = pq.top(); // heaviest stone
            pq.pop();
            int b = pq.top(); // second heaviest stone
            pq.pop();

            // If stones are unequal, push the remaining weight back
            pq.push(abs(a - b));
        }

        // The last stone (or 0 if no stones remain)
        return pq.empty() ? 0 : pq.top();
    }
};

/*
Time Complexity:  
- Building heap: O(n)  
- Each smash operation: O(log n) (pop twice, push once)  
- Up to n-1 smashes → O(n log n) overall  

Space Complexity:  
- O(n) for the priority queue  
*/

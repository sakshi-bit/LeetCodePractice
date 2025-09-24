class Solution {
public:
    typedef vector<int>V;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // k = number of lists

        // {element, listIdx, idx}
        // vector<int>(a,b,c)

        // Priority queue (min-heap) storing smallest element among lists
        // SC: O(k) → heap stores at most one element from each list
        priority_queue<V,vector<V>,greater<V>>pq;

        int maxEl = INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0}); // TC: O(log k) per push
            maxEl = max(maxEl,nums[i][0]);
        }

        vector<int>resultRange = {-1000000,1000000}; // SC: O(1)

        // The loop runs at most N times (N = total elements across all lists)
        while(!pq.empty()){
            vector<int>curr = pq.top(); // O(1)
            pq.pop(); // TC: O(log k)

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx = curr[2];

            // Update best range if found smaller
            if(maxEl - minEl < resultRange[1]-resultRange[0]){
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            // Move pointer in the list where min element came from
            if(idx+1 < nums[listIdx].size()){
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement,listIdx,idx+1}); // TC: O(log k)
                maxEl = max(maxEl,nextElement); // O(1)
            }else{
                // If one list is exhausted → stop, because we can’t form range covering all lists
                break;
            }
        }
        return resultRange;
    }
};

/*
Overall Time Complexity: O(N log k)
 - N = total number of elements across all lists
 - log k = heap operations (push/pop)

Overall Space Complexity: O(k)
 - heap stores at most one element from each of the k lists
*/

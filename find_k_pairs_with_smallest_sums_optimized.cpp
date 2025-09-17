class Solution {
public:
    typedef pair<int,pair<int,int>> P; // {sum, {i, j}}

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        // Min-heap to always fetch the smallest sum pair
        priority_queue<P,vector<P>,greater<P>> pq;

        // To avoid pushing duplicate pairs into the heap
        set<pair<int,int>> visited;

        // Start with the smallest possible pair (0,0)
        visited.insert({0,0});
        int sum = nums1[0] + nums2[0];
        pq.push({sum,{0,0}});

        vector<vector<int>> result;

        while(k-- && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            // Add the current pair to the result
            result.push_back({nums1[i], nums2[j]});

            // Push neighbor (i, j+1) if inside bounds and not visited
            if(j+1 < n && visited.find({i, j+1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }

            // Push neighbor (i+1, j) if inside bounds and not visited
            if(i+1 < m && visited.find({i+1, j}) == visited.end()) {
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
        }
        return result;
    }
};

/*
Time Complexity:
- Each heap operation takes O(log k).
- At most k pairs are extracted, and up to 2 neighbors are pushed for each.
- Total complexity: O(k log k).

Space Complexity:
- Heap can hold up to O(k) elements.
- Visited set also stores up to O(k) pairs.
- Result stores k pairs.
- Total space: O(k).
*/

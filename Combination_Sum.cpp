class Solution {
public:
    // Recursive function to find combinations that sum up to the target
    void find_combination(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int> &ds) {
        
        // Base condition: if we reach the end of the array
        if(index == candidates.size()) {
            // If the target becomes 0, current combination is valid
            if(target == 0){
                ans.push_back(ds); // store a copy of current combination
            }
            return;
        }

        // Pick the current element if it's less than or equal to target
        if(candidates[index] <= target){
            ds.push_back(candidates[index]); // choose the element
            // Recurse with the same index (as we can pick the same number again)
            find_combination(index, target - candidates[index], candidates, ans, ds);
            ds.pop_back(); // backtrack: remove the last picked element
        }

        // Do not pick the current element, move to next index
        find_combination(index + 1, target, candidates, ans, ds);
    }

    // Main function to return all combinations that sum to target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // to store all valid combinations
        vector<int> ds; // temporary list to store current combination
        find_combination(0, target, candidates, ans, ds); // start recursion from index 0
        return ans; // return all combinations
    }
};


                         (index=0, target=7, ds=[])
                         /                      \
            pick 2      /                        \ not pick 2
                       /                          \
        (index=0, target=5, ds=[2])            (index=1, target=7, ds=[])
               /       \                            /      \
       pick 2 /         \ not pick 2        pick 3 /        \ not pick 3
             /           \                        /          \
(index=0, t=3, ds=[2,2])  (index=1, t=5, ds=[2]) ...          ...
     /      \
pick 2     not pick 2
   |            |
(index=0,t=1,ds=[2,2,2])   (index=1,t=3,ds=[2,2])
     |
pick 2 → rejected (2 > 1) → backtrack
     |
not pick 2 → index=1 → pick 3 → index=1, t=0, ds=[2,2,3] → ✅ valid, add to answer

Backtrack... explore other paths like picking 3 initially...

---

### ✅ Valid combinations discovered:

1. `[2, 2, 3]`  
2. `[7]`

---


| Complexity Type  | Value        | Explanation                                      |
| ---------------- | ------------ | ------------------------------------------------ |
| Time Complexity  | `O(2^T * N)` | Each step has 2 choices, repeated till target    |
| Space Complexity | `O(T + K*M)` | Recursion depth + space for storing combinations |




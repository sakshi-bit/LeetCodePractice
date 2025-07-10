class Solution {
public:

    // Helper function to find unique combinations that sum up to the target
    void find_combination_sum(int index, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates) {

        // Base Case: if target is zero, we found a valid combination
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Prune the search space if current candidate is greater than target
            if (candidates[i] > target) break;

            // Include the current candidate
            ds.push_back(candidates[i]);

            // Recursive call with i+1 (each number can be used only once)
            find_combination_sum(i + 1, target - candidates[i], ds, ans, candidates);

            // Backtrack
            ds.pop_back();
        }
    }

    // Main function to return all unique combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort to handle duplicates and enable pruning
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;  // Stores all valid combinations
        vector<int> ds;           // Temporary list for current combination

        // Start the backtracking
        find_combination_sum(0, target, ds, ans, candidates);

        return ans;
    }
};


/*
Time Complexity: O(2^n + n log n)
- O(n log n) for sorting
- O(2^n) for generating all subsets (in the worst case)

Space Complexity: O(n)
- O(n) recursion stack in the worst case
- O(k) for the temp combination list 'ds'
- Result vector 'ans' can take up to O(2^n * k), typically excluded from SC
*/

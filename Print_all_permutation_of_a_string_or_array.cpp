class Solution {
public:
    // Recursive function to generate permutations
    void recur_permute(vector<int>& ds, vector<vector<int>>& ans, int freq[], vector<int>& nums) {
        // Base case: if the current permutation is complete
        if(ds.size() == nums.size()) {
            ans.push_back(ds); // store the current permutation
            return;
        }

        // Try every unused element in the current position
        for(int i = 0; i < nums.size(); i++) {
            if(!freq[i]) { // if element is not used yet
                ds.push_back(nums[i]);  // choose it
                freq[i] = 1;            // mark as used
                recur_permute(ds, ans, freq, nums); // recurse
                ds.pop_back();          // backtrack
                freq[i] = 0;            // mark as unused
            }
        }
    }

    // Main function to initiate permutation generation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // stores all permutations
        vector<int> ds;          // stores current permutation
        int n = nums.size();
        int freq[n];             // to track used elements
        for(int i = 0; i < n; i++) {
            freq[i] = 0;         // initialize all as unused
        }
        recur_permute(ds, ans, freq, nums);
        return ans;
    }
};


/*
    Time Complexity: O(n! * n)
    ----------------------------------
    - There are n! permutations of n distinct elements.
    - For each permutation, we copy the current sequence (O(n) operation).
    - So total time = O(n! * n)

    Space Complexity: O(n) + O(n! * n)
    ----------------------------------
    - O(n) for:
        - recursion call stack (depth = n)
        - frequency array freq[]
        - current permutation vector ds
    - O(n! * n) to store all n! permutations of length n in ans
    */

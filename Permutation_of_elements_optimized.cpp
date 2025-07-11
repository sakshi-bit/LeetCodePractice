class Solution {
public:
    /*
    Time Complexity: O(n! * n)
    -------------------------------------
    - There are n! permutations of a list with n elements.
    - For each permutation, we copy the array (O(n)) to ans.
    - So total time = O(n! * n)

    Space Complexity: O(n! * n) + O(n) (stack space)
    ------------------------------------------------
    - O(n! * n): for storing the result in 'ans'
    - O(n): recursion stack depth in worst case (n recursive calls)
    - No extra space like 'freq' or 'ds' is used, so it's more space-efficient.
    */

    void recur_permute(int index, vector<vector<int>>& ans, vector<int>& nums) {
        // Base case: if we fixed all positions
        if(index == nums.size()) {
            ans.push_back(nums); // store current permutation
            return;
        }

        // Try all possibilities for current index
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);              // fix i-th element at index
            recur_permute(index + 1, ans, nums);     // recurse for next index
            swap(nums[index], nums[i]);              // backtrack to restore array
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // store all permutations
        recur_permute(0, ans, nums); // start with index 0
        return ans;
    }
};

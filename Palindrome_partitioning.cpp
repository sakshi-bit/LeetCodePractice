class Solution {
public:
    /*
    Time Complexity: O(2^n * n)
    ---------------------------
    - In the worst case, you may partition at every character: 2^(n-1) ~ O(2^n) combinations
    - For each substring, you check if it's a palindrome, which takes O(n)
    - So total time = O(2^n * n)

    Space Complexity: O(n) + O(n * 2^n)
    -----------------------------------
    - O(n) for the recursion call stack (depth up to n)
    - O(n * 2^n) for storing the final result (each path stores substrings totaling n characters, and there are 2^n such paths)
    */

    // Utility to check if a substring is a palindrome
    bool isPalindrome(int start, int end, string s){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    // Recursive backtracking function to explore partitions
    void func(int index, string s, vector<string>& path, vector<vector<string>>& res){
        // Base case: if index reaches the end of string
        if(index == s.size()){
            res.push_back(path); // store current partition
            return;
        }

        for(int i = index; i < s.size(); i++){
            // Check if substring s[index...i] is a palindrome
            if(isPalindrome(index, i, s)){
                path.push_back(s.substr(index, i - index + 1)); // choose
                func(i + 1, s, path, res); // explore
                path.pop_back(); // backtrack
            }
        }
    }

    // Main function to return all possible palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; // to store all results
        vector<string> path;        // to store current path
        func(0, s, path, res);      // begin recursion from index 0
        return res;
    }
};

class Solution {
public:
    /**
     * @brief Returns the k-th permutation of numbers from 1 to n.
     * 
     * Time Complexity: 
     *   - O(n^2): For each digit, we erase from the vector (O(n)), repeated n times.
     * 
     * Space Complexity:
     *   - O(n): For storing the `numbers` list and output `ans` string.
     * 
     * @param n The number of digits (1 to n)
     * @param k The k-th permutation sequence to return
     * @return string The k-th permutation in lexicographic order
     */
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;

        // Step 1: Calculate (n-1)! and fill the numbers list
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // include 'n' in the list

        k = k - 1; // converting to 0-based indexing
        string ans = "";

        // Step 2: Find each digit of the k-th permutation
        while (!numbers.empty()) {
            int index = k / fact;
            ans += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            // Update k and fact for remaining digits
            if (!numbers.empty()) {
                k %= fact;
                fact /= numbers.size();
            }
        }

        return ans;
    }
};

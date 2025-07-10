class Solution {
public:

    // Recursive function to calculate all subset sums
    void find_subset(int index, int sum, vector<int>& ds, vector<int>& arr) {
        // Base case: if we've considered all elements
        if (index == arr.size()) {
            ds.push_back(sum); // store the current subset sum
            return;
        }

        // Include the current element in the sum
        find_subset(index + 1, sum + arr[index], ds, arr);

        // Exclude the current element from the sum
        find_subset(index + 1, sum, ds, arr);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ds;  // stores all subset sums
        find_subset(0, 0, ds, arr);

        sort(ds.begin(), ds.end()); //sort the results
        return ds;
    }
};

/*
Time Complexity: O(2^n)
- For each of the n elements, there are two choices: pick or not pick
- So total recursive calls = 2^n
- Sorting the result takes O(2^n * log(2^n)) = O(2^n * n), but often ignored in basic TC

Space Complexity: O(2^n)
- To store all subset sums (total 2^n sums)
- Recursion stack space = O(n) at most
*/


class Solution {
public:
    typedef pair<int,char> P; // pair of <frequency, character>

    string reorganizeString(string s) {
        priority_queue<P, vector<P>> pq;  // max-heap to store <frequency, char>
        int n = s.length();
        vector<int> count(26, 0);         // frequency array for characters

        // Step 1: Count frequency of each character
        for (char &ch : s) {
            count[ch - 'a']++;

            // If any character count exceeds (n+1)/2, impossible to rearrange
            if (count[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        // Step 2: Push all characters with nonzero frequency into max-heap
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] > 0) {
                pq.push({count[ch - 'a'], ch});
            }
        }

        string result = "";

        // Step 3: Build the result string
        // Always pick the top 2 most frequent chars to avoid duplicates
        while (pq.size() >= 2) {
            auto P1 = pq.top(); pq.pop();
            auto P2 = pq.top(); pq.pop();

            // Append both characters
            result.push_back(P1.second);
            result.push_back(P2.second);

            // Decrease frequency and push back if still available
            if (--P1.first > 0) pq.push(P1);
            if (--P2.first > 0) pq.push(P2);
        }

        // Step 4: If one character left, just append it
        if (!pq.empty()) {
            result.push_back(pq.top().second);
        }

        return result;
    }
};

/*
Time Complexity (TC):
- Counting frequencies: O(n)
- Building heap: O(26 log 26) ≈ O(1) since alphabet size is fixed
- While loop processes each of n characters, each push/pop takes O(log 26) ≈ O(1)
=> Total: O(n)

Space Complexity (SC):
- Frequency array: O(26) = O(1)
- Priority queue stores at most 26 chars = O(1)
- Result string uses O(n)
=> Total: O(n) (dominated by result string)
*/

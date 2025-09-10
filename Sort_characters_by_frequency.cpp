class Solution {
public:
    // Define a pair type for character and its frequency
    typedef pair<char, int> P;

    // Custom comparator for max-heap based on frequency
    struct lambda {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second; // higher frequency comes first
        }
    };

    string frequencySort(string s) {
        // Max-heap to store characters by frequency
        priority_queue<P, vector<P>, lambda> pq;

        // Map to count frequency of each character
        unordered_map<char, int> mpp;
        for(auto &ch: s) {
            mpp[ch]++;
        }

        // Push all character-frequency pairs into max-heap
        for(auto &it: mpp) {
            pq.push({it.first, it.second});
        }

        // Build the result string
        string res = "";
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            // Append the character 'temp.second' times
            res += string(temp.second, temp.first);
        }

        return res;
    }
};

/**
 * Time Complexity (TC):
 * - Counting frequencies: O(n) where n = s.length()
 * - Building heap: O(k log k), k = number of unique characters
 * - Constructing result: O(n)
 * => Overall: O(n + k log k)
 *
 * Space Complexity (SC):
 * - Hash map: O(k)
 * - Heap: O(k)
 * - Result string: O(n)
 * => Overall: O(n + k)
 */

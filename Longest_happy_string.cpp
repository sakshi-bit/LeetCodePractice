class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        priority_queue<P, vector<P>> pq;  // Max-heap storing (count, char)

        // Push available characters with their frequencies
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        // Build the result string greedily
        while (!pq.empty()) {
            int curr_count = pq.top().first;
            char curr_char = pq.top().second;
            pq.pop();

            // If adding curr_char causes 3 consecutive same letters
            if (result.length() >= 2 &&
                result[result.length() - 1] == curr_char &&
                result[result.length() - 2] == curr_char) {
                
                if (pq.empty()) {  // No alternative left
                    break;
                }
                int next_count = pq.top().first;
                char next_char = pq.top().second;
                pq.pop();

                result.push_back(next_char);
                next_count--;

                if (next_count > 0) {
                    pq.push({next_count, next_char});
                }

                // Push back curr_char because it’s still usable
                pq.push({curr_count, curr_char});

            } else {
                // Safe to use curr_char
                curr_count--;
                result.push_back(curr_char);

                if (curr_count > 0) {
                    pq.push({curr_count, curr_char});
                }
            }
        }
        return result;
    }
};

// Time Complexity: O((a + b + c) log 3) 
//   - Each push/pop operation takes O(log 3) = O(1), since heap size ≤ 3
//   - Total iterations = a + b + c (each char added once)
//   - Overall: O(a + b + c)

// Space Complexity: O(1)
//   - Heap size is bounded by 3 (for 'a', 'b', 'c')
//   - Result string uses O(a + b + c) extra space, but that’s the output itself

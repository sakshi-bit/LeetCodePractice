class Solution {
public:
    typedef pair<char,int>P; // pair to store {character, index}

    // Custom comparator for priority_queue (min-heap behavior)
    struct comp {
        bool operator()(P &p1, P &p2){
            if(p1.first == p2.first){
                // If characters are the same, prefer the one with larger index
                return p1.second < p2.second;
            }
            // Otherwise, prefer smaller character alphabetically
            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        int n = s.length();
        
        // Priority queue (min-heap based on comp) → stores smallest char first,
        // and if tie, the rightmost one among equals
        priority_queue<P,vector<P>,comp>pq;

        for(int i=0;i<n;i++){ // O(n log n)
            if(s[i]!='*'){
                pq.push({s[i],i}); // Push character with index into heap → O(log n)
            }else{
                // When '*' is found, remove the smallest lexicographic char,
                // if tie → remove rightmost among them
                int idx = pq.top().second;
                pq.pop();
                s[idx]='*'; // Mark removed character as '*'
            }
        }

        string result="";
        for(int i=0;i<n;i++){ // O(n)
            if(s[i]!='*'){ // Collect only non-removed characters
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

/*
 Time Complexity:
- Heap push/pop takes O(log n) per operation.
- For each character (n characters total), we might push/pop → O(n log n).
- Final traversal to build result → O(n).
Overall: O(n log n)

 Space Complexity:
- Priority queue can hold up to O(n) elements.
- Result string also uses O(n).
 Overall: O(n)
*/

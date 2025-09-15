class KthLargest {
public:
    int K;  
    // Min-heap to keep track of the k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Constructor: initialize with nums and maintain only k largest elements
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto &num: nums) {
            pq.push(num);        // push element into heap
            if(pq.size() > k) {  // if heap grows beyond k, remove smallest
                pq.pop();
            }
        }
    }
    
    // Add a new value and return the kth largest element
    int add(int val) {
        pq.push(val);            // insert new element
        if(pq.size() > K) {      // maintain only k elements in the heap
            pq.pop();
        }
        return pq.top();         // top is the kth largest element
    }
};

/**
 * Time Complexity:
 * - Constructor: O(n log k), where n = nums.size() (each insertion O(log k))
 * - add(): O(log k) for heap push/pop
 * 
 * Space Complexity:
 * - O(k), heap stores at most k elements
 */

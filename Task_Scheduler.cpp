class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Time Complexity: O(T log 26) ≈ O(T), where T = number of tasks
        //   - Counting tasks: O(T)
        //   - Each push/pop into max heap: O(log 26) = O(1), since only 26 letters
        // Space Complexity: O(26) = O(1), for hashmap + heap

        int size = tasks.size();
        unordered_map<char,int> mpp; // frequency map to count each task

        // Count frequency of each task
        for(char &ch : tasks){
            mpp[ch]++;
        }

        // Max heap to always schedule the task with the highest remaining frequency
        priority_queue<int,vector<int>> pq;

        // Push all frequencies into max heap
        for(auto &it : mpp){
            pq.push(it.second);
        }

        int time = 0; // total time taken to execute all tasks with cooldowns

        // Process tasks in cycles of (n+1)
        while(!pq.empty()){
            vector<int> temp; // stores remaining counts for this cycle

            // Execute up to (n+1) tasks in this cycle
            for(int i = 1; i <= n+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top() - 1); // decrement frequency of executed task
                    pq.pop();
                }
            }

            // Push remaining (still pending) tasks back into heap
            for(int &freq : temp){
                if(freq > 0){
                    pq.push(freq);
                }
            }

            // If heap is empty, then all tasks are completed → add only actual executed tasks
            if(pq.empty()){
                time += temp.size();
            } 
            // Otherwise, full (n+1) cycle was used including idle slots
            else {
                time += n+1;
            }
        }
        return time;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Store tasks as {enqueue_time, processing_time, index}
        vector<array<int,3>> sorted_tasks;
        for(int i = 0; i < n; i++) {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];
            sorted_tasks.push_back({start_time, processing_time, i});
        }

        // Sort tasks by enqueue_time (and by processing_time + index implicitly if ties occur)
        sort(begin(sorted_tasks), end(sorted_tasks));

        vector<int> result;
        long long curr_time = 0; // Current time of the CPU
        int idx = 0;             // Index to track which task to push into pq

        // Min-heap (priority_queue) that stores {processing_time, index}
        // Comparator ensures smallest processing_time first, and if tie → smallest index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        // Process until all tasks are handled
        while(idx < n || !pq.empty()) {
            // If no task available, jump CPU time to next task's enqueue_time
            if(pq.empty() && curr_time < sorted_tasks[idx][0]) {
                curr_time = sorted_tasks[idx][0];
            }

            // Push all tasks that are available at or before curr_time into pq
            while(idx < n && sorted_tasks[idx][0] <= curr_time) {
                pq.push({sorted_tasks[idx][1], sorted_tasks[idx][2]});
                idx++;
            }

            // Pick the task with the smallest processing_time (and lowest index if tie)
            pair<int,int> curr_task = pq.top();
            pq.pop();

            // Execute task
            curr_time += curr_task.first;
            result.push_back(curr_task.second);
        }

        return result;
    }
};

/*
Time Complexity:
- Sorting tasks: O(n log n)
- Each task pushed + popped from priority_queue: O(n log n)
=> Overall: O(n log n)

Space Complexity:
- sorted_tasks stores n tasks: O(n)
- priority_queue stores at most n tasks: O(n)
- result stores n tasks: O(n)
=> Overall: O(n)
*/

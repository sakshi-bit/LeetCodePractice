class Solution {
public:
    vector<int> NSL(vector<int> heights) {
        vector<int> left;
        int n = heights.size();
        int pseudoindex = -1;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
           while(s.size() > 0 && s.top().first >= heights[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                left.push_back(pseudoindex);
            } else{
                left.push_back(s.top().second);
            
            }
            s.push({heights[i], i});
        }
        return left;
    }

    vector<int> NSR(vector<int> heights) {
        vector<int> right;
        int n = heights.size();
        int pseudoindex = n;
        stack<pair<int, int>> s;
        for (int i = n-1; i >= 0; i--) {
           while(s.size() > 0 && s.top().first >= heights[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                right.push_back(pseudoindex);
            } else{
                right.push_back(s.top().second);
            
            }
            s.push({heights[i], i});
        }
   
        reverse(right.begin(),right.end());
        return right;
    } 

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> width(n);
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
       // int ans = 0;

        for(int i=0;i<n;i++){
            width[i] = right[i]-left[i]-1;
        }

        for(int i=0;i<n;i++){
           heights[i] = heights[i]*width[i];
        }

       return *max_element(heights.begin(), heights.end());
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>cars(n);
        stack<double>st;

        for(int i=0;i<n;i++){
            cars[i] = {position[i],(double)(target-position[i])/speed[i]};
        }

        sort(cars.rbegin(),cars.rend());
        for(int i=0;i<n;i++){
            if(st.size()==0 || st.top()<cars[i].second){
                st.push(cars[i].second);
            }
        }
        return st.size();
    }
};

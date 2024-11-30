class Solution {
public:
    bool canAliceWin(int n) {
        int stoneRemoved = 10;
        int count=0;
        while(n>=stoneRemoved){
             n = n - stoneRemoved;
             stoneRemoved--;
            count++;
        }
        //odd - Alice //even - Bob
       return count%2!=0;
    }
};

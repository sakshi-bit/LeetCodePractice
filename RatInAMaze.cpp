 vector<string>result;
    bool isSafe(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    void solve(int i,int j,vector<vector<int>> &mat,int n,string& temp){
        if(!isSafe(i,j,n) || mat[i][j]==0){
            return;
        }
        if(i==n-1 && j==n-1){
            result.push_back(temp);
            return;
        }
        mat[i][j]=0;
        //D,R,U,L
        
        temp.push_back('D');
        solve(i+1,j,mat,n,temp);
        temp.pop_back();
        
        temp.push_back('R');
        solve(i,j+1,mat,n,temp);
        temp.pop_back();
        
        temp.push_back('U');
        solve(i-1,j,mat,n,temp);
        temp.pop_back();
        
        temp.push_back('L');
        solve(i,j-1,mat,n,temp);
        temp.pop_back();
        
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
       string temp="";
       int n = mat.size();
       int m = mat[0].size();
       solve(0,0,mat,n,temp);
       return result;
    }

TC=O(3^n^2)
SC=O(N^2)  Worst Case Stack Space
O(1) Auxillary Space

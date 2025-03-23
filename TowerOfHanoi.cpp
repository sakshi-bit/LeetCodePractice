int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        if(n==0){
            return 0;
        }
        if(n==1){
           // cout<<"move disk "<<n<<" from "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        
        int count=0;
        count= towerOfHanoi(n-1,from,aux,to);
       // cout<<"move disk "<<n<<" from "<<from<<" to rod "<<to<<endl;
        count+=1;
        
        count+=towerOfHanoi(n-1,aux,to,from);
        return count;
    }

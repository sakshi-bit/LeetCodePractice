class Solution {

    public char recursiveSearch(int k,int len,char currChar){

        if(k==1){
            return currChar;
        }

        int halfLength = len/2;

        if(k <= halfLength){
            return recursiveSearch(k,halfLength,currChar);
        }

        char nextChar = (currChar == 'z')?'a':(char)(currChar+1);
        return recursiveSearch(k-halfLength,halfLength,nextChar);

    }

    public char kthCharacter(int k) {

        char currChar='a';
        int len=1;

        while(len<k){
            len*=2;
        }

        return recursiveSearch(k,len,currChar);
    }
}

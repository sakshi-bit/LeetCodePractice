    //TC = O(NlogN)
//SC = O(logn)

void merge(vector<int>& arr, int l, int m,int r){
        int k = l;
        int n1 = m-l+1;
        int n2= r-m;
        int L[n1];
        int R[n2];
        
        for(int i=0;i<n1;i++){
            L[i]=arr[k];
            k++;
        }
        
        for(int i=0;i<n2;i++){
            R[i] = arr[k];
            k++;
        }
        
        //merge
        int i=0,j=0;
        k=l;
        
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r){
            return;
        }
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

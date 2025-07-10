#include <iostream>

using namespace std;

int cnt=0;
void print(){
    if (cnt==3) return;
    cout<<cnt<<endl;
    cnt++;
    print();
}

void Print_name_n_times(int i,int n){
    if(i>n) return;

    cout<<"Sakshi"<<endl;

    Print_name_n_times(i+1,n);
    
}

void Print_lineraly_from_1_to_n(int i,int n){
    if(i>n) return;
    cout<<i<<endl;
    Print_lineraly_from_1_to_n(i+1,n);
}

void Print_In_Terms_of_N_to_1(int i,int n){
    if(i<1) return;
    cout<<i<<endl;
    Print_In_Terms_of_N_to_1(i-1,n);
}

void Print_1_to_N_by_Backtracking(int i,int n){
    if(i<1) return;
    Print_1_to_N_by_Backtracking(i-1,n);
    cout<<i<<endl;
}

void Print_N_to_1_by_Backtracking(int i,int n){
    if(i>n) return;
    Print_N_to_1_by_Backtracking(i+1,n);
    cout<<i<<endl;
}

int functional_sum_of_n_nos(int n){
    if(n==0){
        return 0;
    }
    return n+functional_sum_of_n_nos(n-1);
}

void parameterized_sum_of_n_nos(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    parameterized_sum_of_n_nos(i-1,sum+i);
}

int functional_factorial_of_n(int n){
    if(n==0) return 1;
    return n*functional_factorial_of_n(n-1);
}

void paramerterized_factorial_of_n(int i,int fact){
    if(i==1){
        cout<<fact;
        return;
    }
    paramerterized_factorial_of_n(i-1,fact*i);
}

void reverse_array_using_two_variables(int l,int r, vector<int> &arr){
    if(l>=r) return;
    swap(arr[l],arr[r]);
    reverse_array_using_two_variables(l+1,r-1,arr);
}

void reverse_array_using_single_variable(int i, int n, vector<int>& arr){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverse_array_using_single_variable(i+1,n,arr);
}

bool check_palindrome_of_string(int i, string &s){
    if(i>=s.length()/2){
        return true;
    }
    if(s[i]!=s[s.length()-i-1]){
        return false;
    }
    return check_palindrome_of_string(i+1,s);
    
}

int nth_fibonacci_number(int n){
    if(n<=1){
        return n;
    }
    return nth_fibonacci_number(n-1)+nth_fibonacci_number(n-2);
}

void Print_All_Subsequences(int index, vector<int>&ds, vector<int>arr, int n){
    //base condition
    if(index>=n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }

    //pick or take the particular index into the subsequence
    ds.push_back(arr[index]);
    Print_All_Subsequences(index+1, ds, arr, n);

    //not pick or take the particular index into the subsequence
    ds.pop_back();
    Print_All_Subsequences(index+1,ds,arr,n);

    
}

void Print_All_Subsequence_with_sum(int index,vector<int>&ds,int s, int sum, vector<int>arr,int n){

    if(index==n){
        if(s == sum){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
           
        }
         return;
    }
    //pick the condition
    ds.push_back(arr[index]);
    s+=arr[index];
    Print_All_Subsequence_with_sum(index+1,ds,s,sum,arr,n);
    s-=arr[index];
    ds.pop_back();
    //not pick the condition
    Print_All_Subsequence_with_sum(index+1,ds,s,sum,arr,n);

}

bool Print_Ony_One_Subsequence_With_Sum(int index, vector<int>&ds, int s, int sum, vector<int>arr,int n){
    if(index==n){
        //condition satisfied
        if(s==sum){
            for(auto it: ds){
                cout<<it<<" ";
            }
            return true;
        }
        return false;
    }

    //Pick the condition
    s+=arr[index];
    ds.push_back(arr[index]);
     if (Print_Ony_One_Subsequence_With_Sum(index+1,ds,s,sum,arr,n) == true) return true;

    s-=arr[index];
    ds.pop_back();

    //Not pick the condition
    if(Print_Ony_One_Subsequence_With_Sum(index+1, ds, s, sum, arr, n) == true) return true;
    return false;
}

int count_the_subsequence_with_sum_s(int index, int s, int sum, vector<int>arr,int n){
    if(s>sum){
        return 0;
    }
    if(index == n){
        //condition satisfied
        if(s==sum){
            return 1;
        }
        //condition not satisfied
        return 0;
    }

    s+=arr[index];
    int left =count_the_subsequence_with_sum_s(index+1,s,sum,arr,n);
    s-=arr[index];
    int right= count_the_subsequence_with_sum_s(index+1,s,sum,arr,n);
    return left+right;

}

int main(){
    int n;
    cin>>n;
   vector<int> arr(n);

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   //int sum;
   //cin>>sum;
 
   // vector<int> ds;

   //Print_All_Subsequence_with_sum(0,ds,0,sum,arr,n);
   //Print_Ony_One_Subsequence_With_Sum(0,ds,0,sum,arr,n);
   //cout<<count_the_subsequence_with_sum_s(0,0,sum,arr,n);

    return 0;
}

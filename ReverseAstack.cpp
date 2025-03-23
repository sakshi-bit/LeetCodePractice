 
//TC = O(n^2)
//SC = Auxillary Space = o(n)
void Reverse(stack<int> &st){
        
        if(st.empty()){
            return;
        }
        
        int top = st.top();
        st.pop();
        
        //[2,1,7,6]
        Reverse(st);
        //[6,7,1,2]
        
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        //temp[2,1,7,6]
        st.push(top);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        
    }

//Optimized without Auxillary Space

 void insertAtTheBottom(stack<int> &st,int element){
        if(st.empty()){
            st.push(element);
            return;
        }
        int top= st.top();
        //[7,1,2]
        st.pop();
        insertAtTheBottom(st,element);
        
        //[7,1,2,3]
        st.push(top);
        //[6,7,1,2,3]
    }
    void Reverse(stack<int> &st){
        
        if(st.empty()){
            return;
        }
        
        int top = st.top();
        st.pop();
        
        //[2,1,7,6]
        Reverse(st);
        //[6,7,1,2]
        
       insertAtTheBottom(st,top);
        
    }

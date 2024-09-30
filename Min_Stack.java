//Approach 1
//Using 2 stacks: 1 for storing elements and another for staoring min elements
//Time: O(1) space: O(2n)

//Cons: Extra O(n) space

class MinStack {
Stack<Integer> s1 = new Stack<Integer>();
Stack<Integer> s2 = new Stack<Integer>();

    public MinStack() {
       
        
    }
    
    public void push(int val) {
       
        if(s2.empty() || s2.peek()>=val){
            s2.push(val);
        }
         s1.push(val);
    }
    
    public void pop() {
   
       if (s1.peek().equals(s2.peek())) {
            s2.pop();
        }
        s1.pop();
    }
    
    public int top() {
        return s1.peek();
    }
    
    public int getMin() {
        return s2.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */



//Approach -2
//Using duynamic linked list 
//Time: O(1) space: O(2n)

//Cons: O(2n) space since each node has two integer variable and there will be n such nodes

class MinStack {

    private class Node {
        int val;
        int min;
        Node next;

        private Node(int val,int min,Node next){
            this.val=val;
            this.min=min;
            this.next=next;
        }
       
    }
    private Node head;

    // public MinStack() {
        
    // }
    
    public void push(int x) {

        if(head==null){
            head=new Node(x,x,null);
        }else{
            head=new Node(x,Math.min(x,head.min),head);
        }
    }
    
    public void pop() {
        head=head.next;
    }
    
    public int top() {
        return head.val;
    }
    
    public int getMin() {
        return head.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


//Approach-3
//O(1) space
//Time: O(1) space: O(n)

//Cons: Integer overflow


class MinStack {
    Stack < Long > st = new Stack < Long > ();
    Long mini;

    /** initialize your data structure here. */
    public MinStack() {
        mini = Long.MAX_VALUE;
    }

    public void push(int value) {
        Long val = Long.valueOf(value);
        if (st.isEmpty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2 * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    public void pop() {
        if (st.isEmpty()) return;

        Long val = st.pop();
        if (val < mini) {
            mini = 2 * mini - val;
        }
    }

    public int top() {
        Long val = st.peek();
        if (val < mini) {
            return mini.intValue();
        }
        return val.intValue();
    }

    public int getMin() {
        return mini.intValue();
    }
}

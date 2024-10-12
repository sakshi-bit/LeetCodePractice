package com.example.demo;

import java.util.Stack;

public class DeleteMiddleElementOfStack {
	
	Stack<Integer> midDel(Stack<Integer>s,int size){
		if(s.size()==0) {
			return s;
		}
		
		int k = size/2+1;
		
		solve(s,k);
		return s;
		
	}

	private void solve(Stack<Integer> s, int k) {
		// TODO Auto-generated method stub
		
		if(k==1) {
			s.pop();
			return;
		}
		
		int temp = s.peek();
		s.pop();
		solve(s,k-1);
		s.push(temp);
		return;
	}

}

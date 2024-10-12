package com.example.demo;

import java.util.Stack;

public class SortStack {
	
	public static void sort(Stack<Integer> s) {
		
		if(s.size()==1) {
			return;
		}
		
		int temp = s.peek();
		s.pop();
		sort(s);
		insert(s,temp);
	}

	private static void insert(Stack<Integer> s, int temp) {
		// TODO Auto-generated method stub
		
		if(s.size()==0 || s.peek()<=temp) {
			s.push(temp);
			return;
		}
		
		int value = s.peek();
		s.pop();
		insert(s,temp);
		s.push(value);
		
	}

}

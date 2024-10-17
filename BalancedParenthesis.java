package com.example.demo;

import java.util.List;

public class BalancedParenthesis {

	public static void solve(int open, int close, String output, List<String> l) {
		// TODO Auto-generated method stub
		if(open==0 && close==0) {
			l.add(output);
			return;
		}
		
		if(open!=0) {
			String output1=output;
			output1+='(';
			solve(open-1,close,output1,l);
		}
		if(close>open) {
			String output2=output;
			output2+=')';
			solve(open,close-1,output2,l);
		}
		return;		
	}
	
	


}

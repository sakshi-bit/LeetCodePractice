package com.example.demo;

public class printNthBinaryNumbers {

	void solve(int one,int zero,int n, String output) {
		
		if(n == 0) {
			System.out.println(output);
			return;
		}
		
		String output1 = output;
		output1+='1';
		solve(one+1,zero,n-1,output1);
		
		if(one > zero) {
			
			String output2= output;
			output2+='0';
			solve(one,zero+1,n-1,output2);
		}
		return;
		
	}
	
	
}

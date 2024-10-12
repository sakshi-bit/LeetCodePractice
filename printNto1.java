package com.example.demo;

public class printNto1 {
	
	public static void solveA(int n){
	if(n==0) {
		return;
	}
	
	System.out.println(n);
	solveA(n-1);
	}


}

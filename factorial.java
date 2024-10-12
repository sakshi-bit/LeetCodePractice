package com.example.demo;

public class factorial {
	
	public static int fact(int n) {
		
		//5
		
		int fact = 1;
		
		if(n == 1) {
			return 1;
		}
		
		fact = n*fact(n-1);
		
		return fact;
		
	}

}

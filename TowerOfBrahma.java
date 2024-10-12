package com.example.demo;

public class TowerOfHanoi {
	
	void solve(int source,int destination,int helper,int n) {
		
		//base condition
		if(n==1) {
			System.out.println("moving plate "+ n+ " from " + source + " to "+ destination);
			return;
		}
		
		//hypothesis
		
		solve(source,helper,destination,n-1);
		
		//smaller input
		
		System.out.println("moving plate "+n+" from "+source+" to "+ destination);
		
		//Induction
		
		solve(helper,destination,source,n-1);
		
		
	}

}

package com.example.demo;

public class PermutationWithSpaces {
	
	public static void solve(String input,String output) {
		
		if(input.length()==0) {
			
			System.out.println(output);
			return;
		}
		
		String output1 = output;
		String output2 = output;
		
		output1+=" ";
		output2+=input.charAt(0);
		input=input.substring(1);
		
		solve(input,output1);
		solve(input,output2);
		return;
		
	}

}

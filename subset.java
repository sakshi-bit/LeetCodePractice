package com.example.demo;

public class subset {

	
	void permutation(String input,String output) {
		
		if(input.length()==0) {
			System.out.println(output);
			return;
		}
		
		String output1 = output;
		String output2=output;
		
		output2+=input.charAt(0);
		input=input.substring(1);
		
		permutation(input,output1);
		permutation(input,output2);
		
		
	}
	
}

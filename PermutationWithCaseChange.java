package com.example.demo;

import java.util.List;

public class PermutationWithCaseChange {
	
	public static void solve(String input,String output, List<String> list){
		
		if(input.length()==0) {
			list.add(output);
			return;
		}
		
		if(Character.isDigit(input.charAt(0))) {
			String output1 = output;
			output1+=input.charAt(0);
			input=input.substring(1);
			solve(input,output1,list);
		}else {
			String output1= output;
			String output2=output;
			
			output1+=Character.toLowerCase(input.charAt(0));
			output2+=Character.toUpperCase(input.charAt(0));
			input=input.substring(1);
			
			solve(input,output1,list);
			solve(input,output2,list);
		}
		
		
	}

}

package com.example.demo;

import java.util.Map;

public class uniqueSubset {
	
	public void subset(String input,String output,Map<String,Integer> m) {
		
		//base condition
		
		if(input.length()==0) {
			
			if(m.containsKey(output)) {
				m.put(output, m.get(output)+1);
			}else {
				m.put(output, 1);
			}
			
			if(m.get(output)==1) {
				System.out.println(output);
			}
			return;
		}
		
		String output1=output;
		String output2=output;
		
		output2+=input.charAt(0);
		input=input.substring(1);
		
		subset(input,output1,m);
		subset(input,output2,m);
		return;
		
	}

}

package com.example.demo;

import java.util.List;

public class JosephusProblem {

	void solve(List<Integer> l,int k, int []ans,int index) {
		
		if(l.size() == 1) {
			ans[0] = l.get(0);
			return;
		}
		
		index = (k+index)%(l.size());
		l.remove(index);
		solve(l,k,ans,index);
		
	}
	
}

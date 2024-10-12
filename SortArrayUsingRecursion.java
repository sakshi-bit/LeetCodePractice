package com.example.demo;

import java.util.List;

public class SortUsingRecursion {

	public static void sort(List<Integer> list) {
		// TODO Auto-generated method stub
		
		if(list.size()==1) {
			return;
		}
		
		int temp = list.get(list.size()-1);
		list.remove(list.size()-1);
		sort(list);
		insert(list,temp);
		
	}

	private static void insert(List<Integer> list, int temp) {
		// TODO Auto-generated method stub
		
		if(list.size()==0 || list.get(list.size()-1)<=temp) {
			list.add(temp);
			return;
		}
		
		int value = list.get(list.size()-1);
		list.remove(list.size()-1);
		insert(list,temp);
		list.add(value);
		
	}
	
	

}

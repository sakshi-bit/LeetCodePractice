// Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "Taking input as a list" << endl;
	int n, m;
	cin >> n >> m;
	//O(2E)
	//graph here
	//int adj[n + 1][m + 1];
	vector<vector<int>>adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
}


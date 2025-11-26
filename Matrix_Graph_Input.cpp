// Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "Taking input as a matrix" << endl;
	int n, m;
	cin >> n >> m;
	//graph here
	//int adj[n + 1][m + 1];
	//O(2E)
	vector<vector<int>>adj(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u < 0 || u > n || v < 0 || v > n) {
			cout << "Invalid edge (" << u << ", " << v << ") — node out of range!" << endl;
			return 1;
		}
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	return 0;
}


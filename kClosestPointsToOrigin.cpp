#include "closestPointsToOrigin.h"
#include <queue>

vector<vector<int>> kClosestPoints(vector<vector<int>>& points, int K)
{
	priority_queue<pair<int,pair<int,int>>>maxh;

	//arr[n][2]
	int n = points.size();
	for (int i = 0; i < n; i++) {
		maxh.push({ points[i][0] * points[i][0] + points[i][1] * points[i][1],{points[i][0],points[i][1]}});
		if (maxh.size() > K) {
			maxh.pop();
		}
	}

	vector<vector<int>>res;

	while (maxh.size() > 0) {
		pair<int, int>p = maxh.top().second;
		res.push_back({ p.first,p.second });
		maxh.pop();
	}
	return res;

}

//The problem is from https://www.acmicpc.net/problem/1967
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, u ,v, weight;
int node, ans;
int visit[100001];
vector<pair<int, int>> graph[100001];

void DFS(int x, int dist)
{
	visit[x] = 1;

	if(dist > ans){
		ans = dist;
		node = x;
	}

	for(int i = 0; i < graph[x].size(); i++)
	{
		int next_node = graph[x][i].first;
		int next_dist = graph[x][i].second + dist;
		if(visit[next_node] == 0)
		{
			visit[next_node] = 1;
			DFS(next_node, next_dist);
			visit[next_node] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		cin >> u >> v >> weight;
		graph[u].push_back({ v,weight });
		graph[v].push_back({ u,weight });
	}

	DFS(1, 0);
	ans = 0;
	for(int i = 1; i <= n; i++)
		visit[i] = 0;
	DFS(node, 0);
	cout << ans << '\n';
}
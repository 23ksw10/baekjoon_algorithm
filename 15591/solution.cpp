#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
long long n;
long long q;
long long k;
long long v;
vector<pair<int, int>>node[50001];
void bfs(int start,int k) {
	queue<int>q;
	q.push(start);
	int ans = 0;
	vector<bool>visit(5001, false);
	visit[start] = 1;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int i = 0; i < node[from].size(); i++) {
			int d = node[from][i].first;
			int w = node[from][i].second;
			if (!visit[d] && w >= k) {
				visit[d] = 1;
				q.push(d);
				ans++;
			}
		}
	}
	cout << ans << '\n';

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>>q;
	for (int i = 1; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		node[x].push_back({ y,w });
		node[y].push_back({ x,w });
	}
	for (int i = 0; i < q; i++) {
		cin >> k >> v;
		bfs(v, k);
	}

	
	


	return 0;
}
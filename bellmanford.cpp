vector<pair<int,int> > adj[MAXN];
vector<int> dist(100,INF);

void bellman_ford(int n, int s){
	dist[s]=0;
	for(int i=0; i< n-1; i++)
		for(int u=0; u<n; u++)
			for(int j=0; j< (int)adj[u].size(); j++){
				pair<int,int> v = adj[u][j];
				dist[v.first] = min(dist[v.first], dist[u] + v.second);
			}
}

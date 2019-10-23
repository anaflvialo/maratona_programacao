vector<int> adj[MAXN];
vector<bool> vis(1000,false);
queue<int> fila;

void bfs(int u){
	fila.push(u);
	vis[u]=true;

	while(!fila.empty()){
		int v = fila.front();
		fila.pop();

		for(int v:adj[u]){
			if(!vis[v]){
				fila.push(v);
				vis[v]=true;
			}
		}
	}
}

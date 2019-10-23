vector <int> adj[MAXN];
vector <bool> vis(MAXN,false);

void dfs(int u){
	if(vis[u])
		return;

	vis[u]=true;

	for(int v:adj[u])
		dfs(v);
}

dfs_explore(){
	for(int i=0; i<VERT; i++)
		if(!vis[i]) dfs(i);
}

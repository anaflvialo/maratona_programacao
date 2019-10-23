vector<pair<int,int> > adj[VERT];
vector<int> custo(VERT,INF);
vector<int> anterior(VERT,-1);

void dijkstra(int s){
	custo[s]=0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0,s));

	while(!pq.empty()){
		pair <int,int> front = pq.top();
		pq.pop();
		int c = front.first; //custo
		int u = front.second; //anterior
		if(c>custo[u]) continue;
		for(pair<int,int> v: adj[u]){
			if(custo[u] + v.second < custo[v.first]){
				custo[v.first] = custo[u] + v.second;
				pq.push(make_pair(custo[v.first],v.first));
				anterior[v.first]=u;
			}
		}

	}
}

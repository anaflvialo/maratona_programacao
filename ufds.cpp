#include<bits/stdc++.h>
using namespace std;

#define MAXN 10

int parents[MAXN];

void makeSet(){
	for(int i=0;i<MAXN; i++)
		parents[i]=i;
}

int find(int elem){
	if(elem == parents[elem]) return elem;
	return parents[elem] = find(parents[elem]);
}

void unite(int x, int y){
	parents[find(y)] = find(x);
}

bool isSameSet(int x, int y){
	return find(x) == find(y);
}


int main(){
	int x, y;
	makeSet();
	
	while(true){ //fazendo conexoes
		cin >> x >> y;
		if(x==-1 || y==-1) break;
		unite(x,y);
	}
	
	while(true){ //fazendo consultas
		cin >> x >> y;
		if(x==-1 || y==-1) break;
		if(isSameSet(x,y))
			cout << "Connected" << endl;
		else
			cout << "Disconnected" << endl;
	}
}
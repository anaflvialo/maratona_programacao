int v[MAXN];

void build(int no, int l, int r){ //O(nlogn)
	if(l==r){
		seg[no]=v[l];
		return;
	}
	int mid = (l+r)/2;
	int noL=no*2;
	int noR=no*2+1;
	build(noL, l, mid);
	build(noR, mid+1, r);
	seg[no] = seg[noL] + seg[noR];
}

void update(int no, int l, int r, int p, int x){ //O(logn)
	if(l>p || r<p)
		return;
	if(l==r){
			seg[no]=x;
			return;
	}
	int mid = (l+r)/2;
	int noL=no*2;
	int noR=no*2+1;
	update(noL, l, mid,p,x);
	update(noR, mid+1, r,p,x);
	seg[no] = seg[noL] + seg[noR];
}

int query(int no, int l, int r, int i, int j){
	if(l>j || r<i)
		return;
	if(l>=i && r<=j)
		return seg[no];
	int mid = (l+r)/2;
	int noL=no*2;
	int noR=no*2+1;
	int x1=query(noL,l,mid,i,j);
	int x2=query(noR,mid+1,r,i,j);
	return x1+x2
}

int main(){
	build(1,0,MAXN-1); //começa sempre em -1
	return 0;
}

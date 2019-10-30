int maximum_weight_set(int *vet, int siz){
	int memo[siz+1];
	memset(memo, 0, sizeof memo);
	
	memo[0]=0;
	memo[1]=vet[0];
	
	for(int i=2; i<=siz; i++){
		if(memo[i-1] > memo[i-2]+vet[i-1])
			memo[i] = memo[i-1];
		else
			memo[i] = memo[i-2]+vet[i-1];
	}
	return memo[siz];
}
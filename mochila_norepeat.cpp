int mochila_norepeat(int* pesos, int* valores){
	int k[PESO_MAX+1][QUANT_ITENS+1];
	
	for(int w=0; w<= PESO_MAX; w++)
		k[w][0]=0;
	for(int j=0; j<=QUANT_ITENS; j++)
		k[0][j]=0;
	
	for(int j=1; j<= QUANT_ITENS; j++){
		for(int w=1; w<= PESO_MAX; w++){
			if(pesos[j-1] > w)
				k[w][j] = k[w][j-1];
			else{
				if((k[w-pesos[j-1]][j-1] + valores[j-1]) > k[w][j-1])
					k[w][j] = k[w - pesos[j-1]][j-1] + valores[j-1];
				else
					k[w][j] = k[w][j-1];
			}
		}
	}
	
	return k[PESO_MAX][QUANT_ITENS];
}
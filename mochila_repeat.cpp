int mochila_repeat(int* pesos, int* valores){
	int k[PESO_MAX + 1];
	
	for(int i=0; i<PESO_MAX+1; i++)
		k[i]=0;
	
	for(int w=1; w<PESO_MAX+1; w++){
		for(int j=0; j<QUANT_ITENS; j++){
			if(pesos[j] <= w){
				if(k[w - pesos[j]] + valores[j] > k[w])
					k[w] = k[w-pesos[j]]+valores[j];
			}
		}
	}
	
	cout << "Matriz de PD" << endl;
	for(int i=0; i<PESO_MAX+1; i++)
		cout << k[i] << " ";
	cout << endl;
	
	return k[PESO_MAX];
}
int encontrar_byte(NODE *p, unsigned char c){
	NODE *aux = p;

	while(aux){
		if(aux->byte == c)
			break;
		aux=aux->prev;
	}

	if(aux){
		aux->freq++;		

		while(aux->prev && (aux->freq > aux->prev->freq)){
			int troca = aux->freq;
			aux->freq = aux->prev->freq;
			aux->prev->freq = troca;

			unsigned char bTroca = aux->byte;
			aux->byte = aux->prev->byte;
			aux->prev->byte = bTroca;
		}

		return 1;
	}
	return 0;
}

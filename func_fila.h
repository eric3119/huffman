void print_fila(FILA *fila);

FILA* create_fila(){
	FILA *novo = (FILA*) malloc(sizeof(FILA));

	novo->head = NULL;

	return novo;
}

int empty_queue(FILA *fila){
	return (fila->head)? 0:1;
}

NODE* dequeue(FILA *fila){
	
	if(empty_queue(fila)) return NULL;
	
	NODE *aux = fila->head;

	fila->head = fila->head->next;
	
	aux->next = NULL;
	
	return aux;
}

void enqueue(FILA *fila, NODE *n){

	NODE *atual = fila->head,
	     *ant = NULL;
	while((atual!= NULL)&&(atual->freq < n->freq))	{
		ant = atual;
		atual = atual->next;
	}
	if(ant== NULL){
		n->next = fila->head;
		fila->head = n;
	}else{
		ant->next = n;
		n->next = atual;
	}
}

void print_fila(FILA *fila){
	NODE *aux = fila->head;

	while(aux){
		if(aux->byte != '\n') printf("%c, %d\n", aux->byte, aux->freq);		
		else printf("\\n, %d\n", aux->freq);
		aux = aux->next;
	}
}

NODE* create_node(int freq, unsigned char c){
	NODE *novo = (NODE*) malloc(sizeof(NODE));

		novo->byte = c;
		novo->freq = freq;
		novo->left = novo->right = novo->next = NULL;
		if(c == 42 || c == 92)
		{
			novo->caractere_controle = 1;
		}
		else
		{
			novo->caractere_controle = 0;
		}
	return novo;
}

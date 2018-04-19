NODE* criar_arvore(NODE *n1, NODE *n2){
	NODE *novo = (NODE*) malloc(sizeof(NODE));
	
	novo->byte = '*';
	if(n1 && n2)
		novo->freq = n1->freq + n2->freq;
	else if(n1)
		novo->freq = n1->freq;
	else if(n2)
		novo->freq = n2->freq;
	novo->left = n1;
	novo->right = n2;

	//printf("%c %c\n", novo->left->byte, novo->right->byte);

	return novo;
}

void enqueue_arvore(FILA *fila, NODE *n1, NODE *n2){
	NODE *novo = criar_arvore(n1, n2), 
		 *aux  = fila->head;

	if(empty_queue(fila)){
		fila->head = novo;
	}
	
}

FILA* inserir_arvore(FILA *f, NODE *n){
	
	NODE *ant = NULL, *atual = f->head;
	
	while(atual!= NULL && atual->freq < n->freq){
		ant = atual;
		atual = atual->next;
	}
	if(ant  == NULL){
		n->next = f->head;
		f->head = n;
	}else if(atual == NULL){
		ant->next = n;
	}else{
		n->next = atual;
		ant->next = n;
	}

	return f;
}

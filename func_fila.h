FILA* create_fila(){
	FILA *novo = (FILA*) malloc(sizeof(FILA));

	novo->head = novo->tail = NULL;

	return novo;
}

int size_fila(FILA *f){
	NODE *aux = f->head;
	int cont = 0;
	while(aux){
		cont++;
		aux = aux->next;
	}
	return cont;
}

int empty_queue(FILA *f){
	return (f->head)? 0:1;
}

NODE* dequeue(FILA *f){
	if(empty_queue(f)) return NULL;

	NODE *aux = f->head;

	f->head = f->head->next;

	return aux;
}

void enqueue(FILA *fila, unsigned char c){
	if(!encontrar_byte(fila->head, c)){

		NODE *novo = (NODE*) malloc(sizeof(NODE));

			novo->byte = c;
			novo->freq = 1;
			novo->next = novo->prev = NULL;
			novo->left = novo->right = NULL;
			novo->next = novo->prev = NULL;

		if(empty_queue(fila)){
			fila->head = fila->tail = novo;
		}else{
			novo->prev = fila->head;
			fila->head->next = novo;
			fila->head = novo;
		}
	}
}

void print_fila

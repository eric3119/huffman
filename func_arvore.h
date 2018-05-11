NODE* criar_arvore(NODE *n1, NODE *n2){
	NODE *novo = (NODE*) malloc(sizeof(NODE));
	
	novo->byte = '*';

	if(n1 && n2)
		novo->freq = n1->freq + n2->freq;
	else if(n1)
		novo->freq = n1->freq;
	else
		novo->freq = 0;

	novo->left = n1;
	novo->right = n2;
	novo->next = NULL;

	return novo;
}

void mostrar_arvore(NODE *raiz){//printa na saída padrão
	if(raiz != NULL){
		if(raiz->caracter_controle == 1)
			printf("\\%c", raiz->byte);
		else
			printf("%c", raiz->byte);
		mostrar_arvore(raiz->left);
		mostrar_arvore(raiz->right);
	}
}

void print_arvore(NODE *raiz, FILE* tmp){//printa no arquivo
	if(raiz != NULL)
	{
		unsigned char c = raiz->byte;
		if(raiz->caracter_controle == 1)
		{
			unsigned char d = 92;
			fwrite(&d, sizeof(d), 1, tmp);
			fwrite(&c, sizeof(c), 1, tmp);
		}else
		{
			fwrite(&c, sizeof(c), 1, tmp);
		}
		print_arvore(raiz->left, tmp);
		print_arvore(raiz->right, tmp);
	}
}

int is_empty(NODE *bt){
	return (bt)? 0:1;
}

int height(NODE* bt){
	
	if(is_empty(bt->left) || is_empty(bt->right))
	{
		return 0;
	}
	int height_left, height_right;
	height_left = height(bt->left);
	height_right= height(bt->right);

	if(height_left > height_right)
	{
		return 1 + height_left;
	}
	else
	{
		return 1 + height_right;
	}
}

int calc_tam_arvore(NODE* arvore){

	if(!arvore) return 0;
	//O tamanho da arvore eh 1 + o tamanho da arvore da esuqerda + o tamanho da subarvore da direita
	if((arvore->left == NULL)  && (arvore->right == NULL))
	{
		//o tamanho d euma folha eh 2, se a folha for '*' ou '\' , ou 1. 
		if(arvore->caracter_controle == 1)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	int tamanho;
	tamanho = 1 + calc_tam_arvore(arvore->left);
	tamanho+= calc_tam_arvore(arvore->right);
	return tamanho;
}

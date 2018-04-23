NODE* criar_arvore(NODE *n1, NODE *n2){
	NODE *novo = (NODE*) malloc(sizeof(NODE));
	
	novo->byte = '*';
	novo->freq = n1->freq + n2->freq;
	novo->left = n1;
	novo->right = n2;
	novo->next = NULL;

	return novo;
}

void print_arvore(NODE *raiz){
	if(raiz != NULL)
	{
		if(raiz->byte!='\n')
		{
			if(raiz->caracter_controle == 1)
			{
				printf("\\%c", raiz->byte);
			}else
			{
				printf("%c", raiz->byte);
			}
		} 
		else printf("\\n");
		print_arvore(raiz->left);
		print_arvore(raiz->right);
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

grafo* algoritmo_prim(grafo* g, int partida)
{
	grafo* ACM = criar_grafo(g->tamanho);
	heap* hp;//heap mínima
	adj_lista* arestas;//As arestas que vão ser colocadas na heap
	adj_lista* min_aresta;
	int adicionados = 1;//O vértice de partida já está na árvore

	arestas = g->vertices[partida];//Pega as arestas do vertice de partida da árvore
								   //Esse é o primeiro vértice a ser colocado na árvore
	hp = criar_heap(100);			

	while(adicionados < g->tamanho)//Esse while não se repete g->tamanho vezes por que 
	{							   //nem sempre uma aresta vai ser colocada na árvore
								   //Pode-se dizer que no máximo ele se repete E(arestas) vezes
		while(arestas != NULL)
		{//enfileira as arestas(do grafo g) do vértice que acabou de ser colocado na árvore
			enqueue(hp, arestas);
			arestas = arestas->prox;
		}
		min_aresta = dequeue(hp);//Pega a aresta que tem custo mínimo atual

		if(ACM->vertices[min_aresta->vertice] == NULL)//Verifica se a aresta é segura, ou seja,
		{											   //se ela não vai formar ciclos na árvore
			adicionado+=1;							  //mas nem todas arestas são seguras, esse é o motivo do while não se repetir g->tamanho vezes
			
			adicionar_vertice(ACM, min_aresta->origem,//min_aresta->origem e min_aresta->vertice são os
			 min_aresta->vertice, min_aresta->custo); //vértices que essa aresta conecta
													  //min_aresta->origem já está na árvore
													  //min_aresta->vertice acabou de ser colocado na árvore
													  //min_aresta->origem seria como o vértice que teve de ser
													  //colocado na árvore para se chegar a min_aresta->vertice
			]
			arestas = g->vertices[min_aresta->vertice];//Pega as arestas do vértice que acabou de ser colocado na árvore
		}

	}
	return ACM;
}

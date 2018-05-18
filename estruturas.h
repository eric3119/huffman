/*
*Modulo das estruturas
*/

typedef struct binario binario;

typedef struct configuracoes configuracoes;

typedef struct NO NO;

typedef struct FILA FILA;

struct binario{
	char* byte;
}; 

struct configuracoes{
	binario* bytes[256];
};

struct NO{
	unsigned char byte;
	int freq;
	short caracter_controle;
	NO *proximo;
	NO *esquerda, *direita;
};

struct FILA{
	NO *cabeca;
};
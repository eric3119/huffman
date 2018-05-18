/*
*Modulo das estruturas
*/

typedef struct binario binario;

typedef struct dicionario dicionario;

typedef struct NO NO;

typedef struct FILA FILA;

struct binario{
	char* byte;
}; 

struct dicionario{
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
	void *cabeca;
};
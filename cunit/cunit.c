#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"

#include "../cabecalhos/estruturas.h"
#include "../cabecalhos/func_fila.h"
#include "../cabecalhos/func_arvore.h"
#include "../cabecalhos/dicionario.h"
#include "../cabecalhos/comprimir.h"

void pqueue_test() {
	
	FILA* teste = criar_fila();

	enqueue(teste, criar_no(6, 'A'));
	enqueue(teste, criar_no(5, 'B'));
	enqueue(teste, criar_no(4, 'C'));
	enqueue(teste, criar_no(3, 'D'));
	enqueue(teste, criar_no(2, 'E'));
	enqueue(teste, criar_no(1, 'F'));

	// Check if first param matches with second[2]
	NO* fila = dequeue(teste);
	CU_ASSERT_EQUAL(fila->freq, 1);
	CU_ASSERT_EQUAL(fila->byte, 'F');

	fila = dequeue(teste);
	CU_ASSERT_EQUAL(fila->freq, 2);
	CU_ASSERT_EQUAL(fila->byte, 'E');

	fila = dequeue(teste);
	CU_ASSERT_EQUAL(fila->freq, 3);
	CU_ASSERT_EQUAL(fila->byte, 'D');

	fila = dequeue(teste);
	CU_ASSERT_EQUAL(fila->freq, 4);
	CU_ASSERT_EQUAL(fila->byte, 'C');

	fila = dequeue(teste);
	CU_ASSERT_EQUAL(fila->freq, 5);
	CU_ASSERT_EQUAL(fila->byte, 'B');

	fila = dequeue(teste);
	CU_ASSERT_EQUAL(fila->freq, 6);
	CU_ASSERT_EQUAL(fila->byte, 'A');
}

/*teste arvore*/
void pre_ordem(NO* raiz, unsigned char* arvore, int *i){
	if(!raiz) return;

	arvore[(*i)] = raiz->byte;

	(*i)++;

	if(raiz->esquerda == NULL && raiz->direita == NULL) return;

	pre_ordem(raiz->esquerda, arvore, i);
	pre_ordem(raiz->direita, arvore, i);
}

void arv_test() {
	
	FILA* fila = criar_fila();

	enqueue(fila, criar_no(6, 'A'));
	enqueue(fila, criar_no(5, 'B'));
	enqueue(fila, criar_no(4, 'C'));
	enqueue(fila, criar_no(3, 'D'));
	enqueue(fila, criar_no(2, 'E'));
	enqueue(fila, criar_no(1, 'F'));

	while(!fila_vazia(fila)){
		NO *n1   = dequeue(fila),
		   *n2   = dequeue(fila);
		NO *novo = criar_arvore(n1, n2);
		
		if(fila_vazia(fila)){
		
			enqueue(fila, novo);
			break;
		}
		enqueue(fila, novo);		
	}
	int* i;
	unsigned char *arvore;

	int tam  = calc_tam_arvore((NO*)fila->cabeca);

	arvore = (unsigned char*) malloc((tam+1)*sizeof(unsigned char));

	strcpy(arvore, "");

	(*i) = 0;
	pre_ordem((NO*)fila->cabeca, arvore, i);

	CU_ASSERT_STRING_EQUAL(arvore, "**CB***FEDA");
}

void dicio_test() {
	
	FILA* fila = criar_fila();

	enqueue(fila, criar_no(6, 'A'));
	enqueue(fila, criar_no(5, 'B'));
	enqueue(fila, criar_no(4, 'C'));
	enqueue(fila, criar_no(3, 'D'));
	enqueue(fila, criar_no(2, 'E'));
	enqueue(fila, criar_no(1, 'F'));

	while(!fila_vazia(fila)){
		NO *n1   = dequeue(fila),
		   *n2   = dequeue(fila);
		NO *novo = criar_arvore(n1, n2);
		
		if(fila_vazia(fila)){
		
			enqueue(fila, novo);
			break;
		}
		enqueue(fila, novo);		
	}

	dicionario* ht = criar_dicionario();

	int tam  = altura((NO*)fila->cabeca);

	char* byte = (char*)malloc((tam+1)*sizeof(char));
		
	buscar((NO*)fila->cabeca,byte,ht, 0);

	// Check if first param matches with second[2]

	CU_ASSERT_STRING_EQUAL( ( (binario*) ht->bytes['A'] )->byte, "11");
	CU_ASSERT_STRING_EQUAL( ( (binario*) ht->bytes['B'] )->byte, "01");
	CU_ASSERT_STRING_EQUAL( ( (binario*) ht->bytes['C'] )->byte, "00");
	CU_ASSERT_STRING_EQUAL( ( (binario*) ht->bytes['D'] )->byte, "101");
	CU_ASSERT_STRING_EQUAL( ( (binario*) ht->bytes['E'] )->byte, "1001");
	CU_ASSERT_STRING_EQUAL( ( (binario*) ht->bytes['F'] )->byte, "1000");
	
}

int main() {

   // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);


   CU_pSuite pSuite = NULL;

	// Add a suite to the registry
	pSuite = CU_add_suite("Teste Fila", 0, 0);
   // Run the tests and show the run summary

	// Always check if add was successful
	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	// Add the test to the suite
	if (NULL == CU_add_test(pSuite, "pqueue_test", pqueue_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	pSuite = CU_add_suite("Teste Arvore", 0, 0);
   // Run the tests and show the run summary

	// Always check if add was successful
	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	// Add the test to the suite
	if (NULL == CU_add_test(pSuite, "arv_test", arv_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	pSuite = CU_add_suite("Teste Dicionario", 0, 0);
   // Run the tests and show the run summary

	// Always check if add was successful
	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	// Add the test to the suite
	if (NULL == CU_add_test(pSuite, "dicio_test", dicio_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

   CU_basic_run_tests();
   //return CU_get_error();
}

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	unsigned char byte;
	int freq;
	short caracter_controle;
	struct NODE *next;
	struct NODE *left, *right;
}NODE;

typedef struct FILA{
	NODE *head;
}FILA;

#include "CUnit/Basic.h"
#include "func_fila.h"

int sum(int a, int b){
  return a + b;
}

void sum_test() {

	FILA* teste = create_fila();

	enqueue(teste, create_node(5, '0'));
	enqueue(teste, create_node(2, '0'));
	enqueue(teste, create_node(4, '0'));
	enqueue(teste, create_node(10, '0'));

	// Check if first param matches with second[2]
  CU_ASSERT_EQUAL(dequeue(teste)->freq, 2);
  CU_ASSERT_EQUAL(dequeue(teste)->freq,4);
  CU_ASSERT_EQUAL(dequeue(teste)->freq, 5);
  CU_ASSERT_EQUAL(dequeue(teste)->freq, 10);  
 /* CU_ASSERT_EQUAL(sum(0, 0), 0);
  CU_ASSERT_EQUAL(sum(-1 ,6), 5);*/
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
	pSuite = CU_add_suite("sum_test_suite", 0, 0);
   // Run the tests and show the run summary

	// Always check if add was successful
	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	// Add the test to the suite
	if (NULL == CU_add_test(pSuite, "sum_test", sum_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

   CU_basic_run_tests();
   //return CU_get_error();
}
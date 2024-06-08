#include "unity.h"
#include "list.h"
#include <string.h>

void tearDown(void) {}

void setUp(void)
{
    //   nombreAppelOperation = 0;  
}

void test_tri_bulle_return_nul_si_tableau_vide_ou_longueur_vide(void)
{
    int *t;

    int res = tri_bulle(NULL, 0);
    TEST_ASSERT_EQUAL(0, res);
}

void test_tri_bulle_ne_fait_rien_si_longueur_tableau_égale_1(void)
{
    int t[1] = {1};

    int res = tri_bulle(t, 1);
    TEST_ASSERT_EQUAL(t[0], 1);
}

void test_tri_bulle_trie_tableau_à_2_elements(void)
{
    int t[2] = {2, 1};

    tri_bulle(t, 2);

    TEST_ASSERT_EQUAL(t[0], 1);
    TEST_ASSERT_EQUAL(t[1], 2);
}

void test_tri_bulle_trie_tableau_3_elements(void)
{
    int t[3] = {4, 2, 1};

    tri_bulle(t, 3);

    TEST_ASSERT_EQUAL(t[0], 1);
    TEST_ASSERT_EQUAL(t[1], 2);
    TEST_ASSERT_EQUAL(t[2], 4);
}

void test_tri_bulle_ne_fait_rien_si_tableau_trié(void)
{
    int t[3] = {1, 2, 4};

    tri_bulle(t, 3);

    TEST_ASSERT_EQUAL(t[0], 1);
    TEST_ASSERT_EQUAL(t[1], 2);
    TEST_ASSERT_EQUAL(t[2], 4);
}

void test_tri_bulle_retourne_1_si_tableau_trié(void)
{
  int t[4] = {2, 1, 3, 6};
  int res = tri_bulle(t, 4);

   TEST_ASSERT_EQUAL(res, 1);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_tri_bulle_return_nul_si_tableau_vide_ou_longueur_vide);
    RUN_TEST(test_tri_bulle_ne_fait_rien_si_longueur_tableau_égale_1);
    RUN_TEST(test_tri_bulle_trie_tableau_à_2_elements);
    RUN_TEST(test_tri_bulle_trie_tableau_3_elements);
    RUN_TEST(test_tri_bulle_ne_fait_rien_si_tableau_trié);
    RUN_TEST(test_tri_bulle_retourne_1_si_tableau_trié);

    return UNITY_END();
}

/*

int nombreAppelOperation;
Node *addressNode;

int setNodeOperation(Node **list, void *data)
{
  if (list == 0)
    addressNode = 0;
  else
    addressNode = *list;
  return 1;
}

int test_operation(Node **list, void *data)
{
  nombreAppelOperation += 1;
  return 1;
}

int test_stopOperation(Node **list, void *data)
{
  nombreAppelOperation += 1;
  return 0;
}

int test_setDataOperation(Node **list, void *data)
{
  nombreAppelOperation = (int)data;
  return 1;
}


void test_parcoursRetourneUneValeurNonNullSiListVide(void)
{
  int retour = list_parcours(0, 0, 0);
  TEST_ASSERT_EQUAL(100, retour);
}

void test_parcoursRetourneUneValeurNonNullSiOperationNull(void)
{
  Node *list = 0;
  int retour = list_parcours(&list, 0, 0);
  TEST_ASSERT_EQUAL(200, retour);
}

void test_parcoursAppelOperationUneFoisQuandListVide(void)
{
  Node *list = 0;
  list_parcours(&list, test_operation, 0);
  TEST_ASSERT_EQUAL(1, nombreAppelOperation);
}

void test_parcoursAppelOperationUneFoisQuandListAUnSeulElement(void)
{
  Node *list = 0, elt;
  list = &elt;
  memset(&elt, 0, sizeof(Node));
  list_parcours(&list, test_operation, 0);
  TEST_ASSERT_EQUAL(1, nombreAppelOperation);
}

void test_parcoursAppelOperationDeuxFoisQuandListADeuxElements(void)
{
  Node *list = 0, elt1, elt2;
  list = &elt1;
  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  elt1.next = &elt2;
  elt2.previous = &elt1;
  list_parcours(&list, test_operation, 0);
  TEST_ASSERT_EQUAL(2, nombreAppelOperation);
}

void test_parcoursArreteQuandOperationRetourFaux(void)
{
  nombreAppelOperation = 0;
  Node *list = 0, elt1, elt2;
  list = &elt1;
  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  elt1.next = &elt2;
  elt2.previous = &elt1;
  list_parcours(&list, test_stopOperation, 0);
  TEST_ASSERT_EQUAL(1, nombreAppelOperation);
}

void test_parcoursPasseLaDonneeUtilisateurALaFonctionOperation(void)
{
  Node *list = 0;
  list_parcours(&list, test_setDataOperation, (void *)3);
  TEST_ASSERT_EQUAL(3, nombreAppelOperation);
}

void test_parcoursRetourneZeroSiToutLesParametresSontCorrects(void)
{
  Node *list = 0;
  TEST_ASSERT_EQUAL(0, list_parcours(&list, test_operation, 0));
}

void test_parcoursPasseLePremierElementAOperationQuantLaListeContientUnSeulElement(void)
{
  Node *list = 0, elt;
  list = &elt;
  memset(&elt, 0, sizeof(Node));
  list_parcours(&list, setNodeOperation, 0);
  TEST_ASSERT_EQUAL(&elt, addressNode);
}

void test_parcoursPasseLeDeuxiemeElementAOperationCommeDernierElementQuantLaListeContientUnSeulElement(void)
{
  Node *list = 0, elt1, elt2;
  list = &elt1;
  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  elt1.next = &elt2;
  elt2.previous = &elt1;
  list_parcours(&list, setNodeOperation, 0);
  TEST_ASSERT_EQUAL(&elt2, addressNode);
}



/* Create list element tests
____________________________________________________________*/
/*
void test_insertElementOperation_retourne_moins1_tête_de_liste_si_liste_vide(void)
{
  int res;
  Node *list = 0;
  res = insertElementOperation(&list, 0);
  TEST_ASSERT_EQUAL(res, -1);
}

void test_insertElementOperation_insère_en_tête_de_liste_si_liste_vide(void)
{
  Node *list = 0, elt; Data data;

  memset(&elt, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));
  data.data1 = &elt;

  insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(&elt, list);
}

void test_insertElementOperation_insère_en_fin_de_liste_si_referencence_null(void)
{
  Node *list = 0, elt1, elt2;
  Data data;
  list = &elt1;

  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));

  data.data1 = &elt2;

  insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(elt1.next, &elt2);
}

void test_insertElementOperation_ne_fait_rien_si_reference_non_trouvé(void)
{
  Node *list = 0, elt1, elt2;
  Data data;
  list = &elt1;

  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));

  data.data1 = &elt2;
  data.data2 = &elt2;

  insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(elt1.next, 0);
  TEST_ASSERT_EQUAL(elt1.previous, 0);
}

void test_insertElementOperation_suivant_de_reference_est_element_inséré(void)
{
  Node *list = 0, elt1, elt2;
  Data data;
  list = &elt1;

  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));

  data.data1 = &elt2;
  data.data2 = &elt1;

  insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(elt1.next, &elt2);
}

void test_insertElementOperation_prev_de_element_insere_est_element_de_reference(void)
{
  Node *list = 0, elt1, elt2;
  Data data;
  list = &elt1;

  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));

  data.data1 = &elt2;
  data.data2 = &elt1;

  insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(&elt1, elt2.previous);
}

void test_insertElementOperation_si_next_de_reference_est_definie_son_precedent_devient_nouvel_element(void)
{
  Node *list = 0, elt1, elt2, elt3;
  Data data;

  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  memset(&elt3, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));

  data.data1 = &elt3;
  data.data2 = &elt1;
  list = &elt1;
  elt1.next = &elt2;

  insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(elt2.previous, &elt3);
}


void test_insertElementOperation_retourne_0_si_element_inséré(void)
{
  int result;
  Node *list = 0, elt1, elt2;
  Data data;
  list = &elt1;

  memset(&elt1, 0, sizeof(Node));
  memset(&elt2, 0, sizeof(Node));
  memset(&data, 0, sizeof(Data));

  data.data1 = &elt2;
  data.data2 = &elt1;

  result = insertElementOperation(&list, &data);
  TEST_ASSERT_EQUAL(result, 0);
}
*/

// Tests pour la fonction operation pour déterminer la taille d'une liste

/*void test_listLengthOperation_incrémente_la_longueur_de_la_liste(void){
  int len = 0;
  Node *list = 0, elt1;
  list = &elt1;

  listLengthOperation(&list, &len);
  TEST_ASSERT_EQUAL(len, 1);
}*/

// Tests pour la algorithme de bulle

/*void test_tri_bulle_return_nul_si_tableau_vide_ou_longueur_vide(void)
{
  int *t;

  int res = tri_bulle(NULL, 0);
  TEST_ASSERT_EQUAL(0, res);
}

int main(void)
{
  UNITY_BEGIN();

  // RUN_TEST(test_parcoursRetourneUneValeurNonNullSiListVide);
  // RUN_TEST(test_parcoursRetourneUneValeurNonNullSiOperationNull);
  // RUN_TEST(test_parcoursAppelOperationUneFoisQuandListVide);
  // RUN_TEST(test_parcoursAppelOperationUneFoisQuandListAUnSeulElement);
  // RUN_TEST(test_parcoursAppelOperationDeuxFoisQuandListADeuxElements);
  // RUN_TEST(test_parcoursArreteQuandOperationRetourFaux);
  // RUN_TEST(test_parcoursPasseLaDonneeUtilisateurALaFonctionOperation);
  // RUN_TEST(test_parcoursRetourneZeroSiToutLesParametresSontCorrects);
  // RUN_TEST(test_parcoursPasseLePremierElementAOperationQuantLaListeContientUnSeulElement);
  // RUN_TEST(test_parcoursPasseLeDeuxiemeElementAOperationCommeDernierElementQuantLaListeContientUnSeulElement);
  // RUN_TEST(test_insertElementOperation_insère_en_tête_de_liste_si_liste_vide);
  // RUN_TEST(test_insertElementOperation_retourne_moins1_tête_de_liste_si_liste_vide);
  // RUN_TEST(test_insertElementOperation_insère_en_fin_de_liste_si_referencence_null);
  // RUN_TEST(test_insertElementOperation_suivant_de_reference_est_element_inséré);
  // RUN_TEST(test_insertElementOperation_prev_de_element_insere_est_element_de_reference);
  // RUN_TEST(test_insertElementOperation_si_next_de_reference_est_definie_son_precedent_devient_nouvel_element);
  // RUN_TEST(test_insertElementOperation_retourne_0_si_element_inséré);
  // RUN_TEST(test_listLengthOperation_incrémente_la_longueur_de_la_liste);


  RUN_TEST(test_tri_bulle_return_nul_si_tableau_vide_ou_longueur_vide);
  // RUN_TEST(test_tri_bulle_ne_fait_rien_si_longueur_tableau_égale_1);
  // RUN_TEST(test_tri_bulle_ne_fait_rien_si_deux_elements_succesifs_tableau_triés);
  // RUN_TEST(test_tri_bulle_permute_si_2_elements_successifs_tableau_non_trié);
  // RUN_TEST(test_tri_bulle_permute_si_2_elements_successifs_tableau_non_trié);
  return UNITY_END();
}
*/
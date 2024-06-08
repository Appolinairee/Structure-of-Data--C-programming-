#include "unity.h"
#include "tree.h"
#include <string.h>

int nombreAppelOperation;

void setUp(void)
{
    nombreAppelOperation = 0;
}

void tearDown(void)
{
    nombreAppelOperation = 0;
}

int test_operation(TREE **t, void *data)
{
    nombreAppelOperation += 1;
    return 1;
}

void test_parcours_largueur_return_200_when_tree_is_null()
{
    int res = parcours_largueur(0, 0, 0);
    TEST_ASSERT_EQUAL(100, res);
}

void test_parcours_largueur_retourne_une_valeur_non_null_si_operation_null(void)
{
    TREE *tree = 0;
    int retour = parcours_largueur(&tree, 0, 0);
    TEST_ASSERT_EQUAL(200, retour);
}

void test_parcours_largueur_call_operation_once_when_tree_has_one_element(void)
{
    TREE *tree = 0, elt;
    tree = &elt;
    memset(&elt, 0, sizeof(TREE));

    parcours_largueur(&tree, test_operation, 0);

    TEST_ASSERT_EQUAL(1, nombreAppelOperation);
}

void test_parcours_largueur_call_operation_twice_when_tree_has_DeuxElements(void)
{
    TREE *tree = 0, elt1, elt2;
    tree = &elt1;

    memset(&elt1, 0, sizeof(TREE));
    memset(&elt2, 0, sizeof(TREE));

    elt1.child1 = &elt2;
    parcours_largueur(&tree, test_operation, 0);

    TEST_ASSERT_EQUAL(2, nombreAppelOperation);
}

void test_parcours_largueur_call_operation_treeth_when_tree_root_has_two_children(void)
{
    TREE *tree = 0, elt1, elt2, elt3;
    tree = &elt1;

    memset(&elt1, 0, sizeof(TREE));
    memset(&elt2, 0, sizeof(TREE));
    memset(&elt3, 0, sizeof(TREE));

    // printf("\nadresses a %d  %d  %d", &elt1, &elt2, &elt3);

    elt1.child1 = &elt2;
    elt1.child2 = &elt3;

    parcours_largueur(&tree, test_operation, 0);

    TEST_ASSERT_EQUAL(3, nombreAppelOperation);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_parcours_largueur_return_200_when_tree_is_null);
    RUN_TEST(test_parcours_largueur_retourne_une_valeur_non_null_si_operation_null);
    RUN_TEST(test_parcours_largueur_call_operation_once_when_tree_has_one_element);
    RUN_TEST(test_parcours_largueur_call_operation_twice_when_tree_has_DeuxElements);
    RUN_TEST(test_parcours_largueur_call_operation_treeth_when_tree_root_has_two_children);

    return UNITY_END();
}
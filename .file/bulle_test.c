#include "unity.h"
#include "bulle.h"
#include <string.h>

void tearDown(void) {}

void setUp(void) {}

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
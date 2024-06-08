#include "unity.h"
#include "file.h"
#include <string.h>

void tearDown(void) {}

void setUp(void) {}

void test_enfiler_file_return_0_when_element_null(void)
{
    LFILE *f;
    int res = _enfiler(&f, 0);
    TEST_ASSERT_EQUAL(res, 0);
}

void test_enfiler_enfile_element_si_file_vide(void)
{
    LFILE *f = 0, elt;
    memset(&elt, 0, sizeof(LFILE));

    _enfiler(&f, &elt);
    TEST_ASSERT_EQUAL(0, 0);
}

void test_enfiler_enfile_element_en_fin_de_file_si_file_non_vide(void)
{
    LFILE *f = 0, elt1, elt2;
    memset(&elt1, 0, sizeof(LFILE));
    memset(&elt2, 0, sizeof(LFILE));
    f = &elt1;

    _enfiler(&f, &elt2);
    TEST_ASSERT_EQUAL(elt1.next, &elt2);
}

void test_defiler_return_0_when_file_empty(void)
{
    LFILE *f = 0;

    int res = _defiler(&f);
    TEST_ASSERT_EQUAL(res, 0);
}

void test_defiler_when_file_have_one_element_it_s_become_empty(void)
{
    LFILE *f = 0, elt;
    memset(&elt, 0, sizeof(LFILE));
    f = &elt;

    _defiler(&f);
    TEST_ASSERT_EQUAL(f, 0);
}

void test_defiler_the_second_elemnt_become_the_top(void)
{
    LFILE *f = 0, elt1, elt2;
    memset(&elt1, 0, sizeof(LFILE));
    memset(&elt2, 0, sizeof(LFILE));

    f = &elt1;
    elt1.next = &elt2;

    _defiler(&f);
    TEST_ASSERT_EQUAL(f, &elt2);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_enfiler_file_return_0_when_element_null);
    RUN_TEST(test_enfiler_enfile_element_si_file_vide);
    RUN_TEST(test_enfiler_enfile_element_en_fin_de_file_si_file_non_vide);

    RUN_TEST(test_defiler_return_0_when_file_empty);
    RUN_TEST(test_defiler_when_file_have_one_element_it_s_become_empty);
    RUN_TEST(test_defiler_the_second_elemnt_become_the_top);

    return UNITY_END();
}
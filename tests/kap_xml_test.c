/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_xml_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "kapparser.h"

Test(kap_xml_test, xml_open_test)
{
    xml_f *xml = xml_open("./tests/configs/test_xml.xml");

    cr_assert_not_null(xml);
    cr_assert_str_eq(xml->path, "./tests/configs/test_xml.xml");
    cr_assert_str_eq(xml->version, "1.5");
    cr_assert_str_eq(xml->encoding, "UTF-9");
    xml_close(xml);
}

Test(kap_xml_test, xml_parse1) {
    xml_f *xml = xml_open("./tests/configs/test_xml.xml");
    list_t *elems = xml_get_element_tag(xml, "config");

    cr_assert_not_null(elems);
    cr_assert_eq(elems->size, 1);
    list_destroy(elems);
    xml_close(xml);
}

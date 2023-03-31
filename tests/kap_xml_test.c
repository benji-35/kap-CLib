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

Test(kap_xml_test, xml_parse_attribute) {
    xml_f *xml = xml_open("./tests/configs/test_xml.xml");
    list_t *elems = xml_get_element_attribute(xml, "test", "toto");

    cr_assert_not_null(elems);
    cr_assert_eq(elems->size, 1);
    foreach_l(elems, elem) {
        xml_node_t *node = elem->data;
        cr_assert_str_eq(node->tag_name, "config", "Expected tag name to be 'config' but got '%s'", node->tag_name);
    }
    list_destroy(elems);
    xml_close(xml);
}

Test(kap_xml_test, xml_save_without_changes) {
    xml_f *xml = xml_open("./tests/configs/test_xml.xml");
    xml_save(xml);

    
    list_t *elems = xml_get_element_tag(xml, "config");

    cr_assert_not_null(elems);
    cr_assert_eq(elems->size, 1);
    list_destroy(elems);

    xml_close(xml);
}

Test(kap_xml_test, xml_add_new_element) {
    xml_f *xml = xml_open("./tests/configs/test_xml.xml");
    map_t *attrs = map_create();
    map_insert(attrs, "toto_test", NULL, true);
    xml_add_element(xml, "config3", "test", attrs);

    list_t *attrs_got = xml_get_element_tag(xml, "config3");

    xml_node_t *got = list_get(attrs_got, 0);
    cr_assert_not_null(got);
    cr_assert_str_eq(got->tag_name, "config3");
    xml_close(xml);
}

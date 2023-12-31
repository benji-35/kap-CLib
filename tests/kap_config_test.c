/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kap_config_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <kapparser.h>

Test(kap_config, open_yml_config) {
    config_f *config = config_open("./tests/configs/test_yaml.yml");

    cr_assert_not_null(config);
    cr_assert_not_null(config->file);
    cr_assert_eq(config->type, YAML);

    config_close(config);
}

Test(kap_config, open_json_config) {
    config_f *config = config_open("./tests/configs/test_json.json");

    cr_assert_not_null(config);
    //cr_assert_not_null(config->file);
    cr_assert_eq(config->type, JSON);

    config_close(config);
}

Test(kap_config, open_toml_config) {
    config_f *config = config_open("./tests/configs/test_toml.toml");

    cr_assert_not_null(config);
    //cr_assert_not_null(config->file);
    cr_assert_eq(config->type, TOML);

    config_close(config);
}

Test(kap_config, open_ini_config) {
    config_f *config = config_open("./tests/configs/test_ini.ini");

    cr_assert_not_null(config);
    //cr_assert_not_null(config->file);
    cr_assert_eq(config->type, INI);

    config_close(config);
}

Test(kap_config, open_xml_config) {
    config_f *config = config_open("./tests/configs/test_xml.xml");

    cr_assert_not_null(config);
    cr_assert_not_null(config->file);
    cr_assert_eq(config->type, XML);

    config_close(config);
}

Test(kap_config, open_invalid_config) {
    config_f *config = config_open("./tests/configs/test_invalid.toto");

    cr_assert_not_null(config);
    //cr_assert_not_null(config->file);
    cr_assert_eq(config->type, CONFIG_TYPE_MAX, "Invalid config type expected: %d, got: %d", CONFIG_TYPE_MAX, config->type);
    config_close(config);
}

Test(kap_config, open_null_config) {
    config_f *config = config_open(NULL);

    cr_assert_null(config);
    config_close(config);
}

Test(kap_config, open_empty_config) {
    config_f *config = config_open("");

    cr_assert_eq(config->type, CONFIG_TYPE_MAX, "Invalid config type expected: %d, got: %d", CONFIG_TYPE_MAX, config->type);
    config_close(config);
}

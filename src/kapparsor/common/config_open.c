/*
** KAP PROJECT, 2023
** C Lib
** File description:
** config_open
*/

#include "kapparser.h"
#include <stdio.h>

private void open_config_type(config_f *config, cstring path) {
    switch (config->type) {
        case YAML:
            config->file = yaml_open(path);
            break;
        case JSON:
            break;
        case XML:
            config->file = xml_open(path);
            break;
        case INI:
            break;
        case TOML:
            break;
        default:
            break;
    }
}

config_f *config_open(cstring path) {
    config_f *config = malloc(sizeof(config_f));
    text_t pathes = str_split(path, '.');
    string extension = text_get_line(pathes, pathes->size - 1);
    
    if (config == NULL || pathes->size == 0)
        return NULL;
    if (str_is_equal(extension, "yaml", true) || str_is_equal(extension, "yml", true))
        config->type = YAML;
    else if (str_is_equal(extension, "json", true))
        config->type = JSON;
    else if (str_is_equal(extension, "xml", true))
        config->type = XML;
    else if (str_is_equal(extension, "ini", true))
        config->type = INI;
    else if (str_is_equal(extension, "toml", true))
        config->type = TOML;
    else
        config->type = CONFIG_TYPE_MAX;
    text_destroy(pathes);
    open_config_type(config, path);
    return config;
}

void config_save(config_f *config) {
    switch (config->type) {
        case YAML:
            yaml_save(config->file);
            break;
        case JSON:
            break;
        case XML:
            break;
        case INI:
            break;
        case TOML:
            break;
        default:
            break;
    }
}

void config_close(config_f *config) {
    if (config == NULL)
        return;
    switch (config->type) {
        case YAML:
            yaml_close(config->file);
            break;
        case JSON:
            break;
        case XML:
            xml_close(config->file);
            break;
        case INI:
            break;
        case TOML:
            break;
        default:
            break;
    }
    kfree(config);
}

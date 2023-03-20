/*
** KAP PROJECT, 2023
** C Lib
** File description:
** yaml_init
*/

#include "kapparser.h"

yaml_f *yaml_open(cstring path) {
    yaml_f *yaml = calloc(1, sizeof(yaml_f));
    yaml->path = str_copy(path);
    yaml->file_content = text_read(path);
    yaml->yaml = list_create();
    yaml->line_read = 0;
    yaml->last_added = NULL;
    return yaml;
}

void yaml_close(yaml_f *yaml) {
    if (yaml == NULL)
        return;
    kfree(yaml->path);
    text_destroy(yaml->file_content);
    list_destroy(yaml->yaml);
    yaml->path = NULL;
    yaml->file_content = NULL;
    kfree(yaml);
}

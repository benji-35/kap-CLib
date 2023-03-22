/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kprint_init
*/

#include "kapprintf.h"

kprint_tool_t kprint_init(void) {
    kprint_tool_t kprint_tool = {
        .functions = map_create()
    };

    map_insert(kprint_tool.functions, "d", &kap_put_int, false);
    map_insert(kprint_tool.functions, "s", &kap_put_string, false);
    map_insert(kprint_tool.functions, "c", &kap_put_char, false);
    map_insert(kprint_tool.functions, "x", &kap_put_hex_low, false);
    map_insert(kprint_tool.functions, "X", &kap_put_hex, false);
    map_insert(kprint_tool.functions, "b", &kap_put_bin, false);

    return kprint_tool;
}

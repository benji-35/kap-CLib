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

    map_insert(kprint_tool.functions, KEYS_KPRINTF[0], &kap_put_long_long_int, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[1], &kap_put_long_int, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[2], &kap_put_ulong_int, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[3], &kap_put_char, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[4], &kap_put_int, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[5], &kap_put_string, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[6], &kap_put_hex_low, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[7], &kap_put_hex, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[8], &kap_put_bin, false);
    map_insert(kprint_tool.functions, KEYS_KPRINTF[9], &kap_put_percent, false);

    return kprint_tool;
}

/*
** KAP PROJECT, 2023
** C Lib
** File description:
** string_io
*/

#include "kapstring.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool str_write(cstring str, cstring path, bool append) {
    int fd = -1;
    if (append) {
        fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    } else {
        fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    }

    if (fd < 0)
        return false;
    int r = write(fd, str, str_len(str));
    close(fd);
    return (r >= 0)? true : false;
}

string str_read(cstring path) {
    string res = NULL;
    struct stat st;
    ssize_t rd;
    int fd = open(path, O_RDONLY, stat);

    if (path == NULL) {
        close(fd);
        return (NULL);
    }
    if (fd < 0)
        return (res);
    stat(path, &st);
    res = kapmalloc(sizeof(char) * (st.st_size + 1));
    rd = read(fd, res, st.st_size);
    close(fd);
    if (rd < 0) {
        kfree(res);
        return (NULL);
    }
    res[st.st_size] = 0;
    return (res);
}

/**
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to 
 * the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double 
 * period .. moves the directory up a level. For more information, see: Absolute path vs relative 
 * path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and there must be only 
 * a single slash / between two directory names. The last directory name (if it exists) must not 
 * end with a trailing /. Also, the canonical path must be the shortest string representing the 
 * absolute path.
 */

#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int prev, start, i, j;
    res[0] = '\0';
    for (i = 0; i < len; ++i) {
        if (path[i] == '/') continue;
        start = i;
        for (; i < len; ++i) {
            if (path[i] == '/') break;
        }
        if (i - start == 1 && path[start] == '.')
            continue;
        else if (i - start == 2 && path[start + 1] == '.') {
            if (strlen(res) > 0) {
                for (j = strlen(res) - 1; j >= 0; --j) {
                    if (res[j] == '/') break;
                }
                res[j] = '\0';
            }
        } else {
            prev = strlen(res);
            res[prev] = '/';
            for (j = 0; j < i - start; ++j) {
                res[prev + j + 1] = path[start + j];
            }
            res[prev + j + 1] = '\0';
        }
    }
    if (strlen(res) == 0) {
        res[0] = '/';
        res[1] = '\0';
    }
    return res;
}
#include "framework.h"

#include <string.h>

int fw_strcpy_s(char* dest, size_t destsz, const char* src)
{
    if (src == NULL)
        src = "";
    dest[destsz - 1] = '\0';
    strncpy(dest, src, destsz);

    if (dest[destsz - 1] != '\0') {
        dest[destsz - 1] = '\0';
        return -1;
    }
    return 0;
}

int fw_strcat_s(char* dest, size_t destsz, const char* src)
{
    size_t len;

    if (src == NULL)
        src = "";
    len = strlen(dest);
    if (len >= destsz)
        return -1;

    dest[destsz - 1] = '\0';
    strncat(dest, src, destsz - len - 1);

    if (strlen(src) + len >= destsz)
        return -1;
    return 0;
}

int fw_strncpy_s(char* dest, size_t destsz, const char* src, size_t len)
{
    if (src == NULL)
        src = "";
    dest[destsz - 1] = '\0';

    len = (destsz < len + 1) ? destsz : len + 1;
    strncpy(dest, src, len);
    if (dest[len - 1] != '\0') {
        dest[len - 1] = '\0';
        return -1;
    }
    return 0;
}

int fw_strncat_s(char* dest, size_t destsz, const char* src, size_t len)
{
    size_t min;
    int ret;

    if (src == NULL)
        src = "";
    if (destsz < (strlen(dest) + len + 1)) {
        min = destsz;
        ret = -1;
    } else {
        min = strlen(dest) + len + 1;
        ret = 0;
    }
    fw_strcat_s(dest, min, src);
    return ret;
}

char* fw_stracpy(char* dest, const char* src, size_t destsz)
{
    fw_strcpy_s(dest, destsz, src);
    return dest;
}

char* fw_stracat(char* dest, const char* src, size_t destsz)
{
    fw_strcat_s(dest, destsz, src);
    return dest;
}

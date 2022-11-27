#ifndef FW_STRING_H
#define FW_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

int fw_strcpy_s(char *dest, size_t destsz, const char *src);
int fw_strcat_s(char *dest, size_t destsz, const char *src);
int fw_strncpy_s(char *dest, size_t destsz, const char *src, size_t len);
int fw_strncat_s(char *dest, size_t destsz, const char *src, size_t len);
char *fw_stracpy(char *dest, const char *src, size_t destsz);
char *fw_stracat(char *dest, const char *src, size_t destsz);
char *fw_strdup(const char *src);

#ifdef __cplusplus
}
#endif

#endif // FW_STRING_H
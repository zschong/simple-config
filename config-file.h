#ifndef __CONFIG_FILE_H__
#define __CONFIG_FILE_H__
#include <stdio.h>

FILE* config_open(const char *filename);
int config_readline(FILE *fp, char *buf, int len);
int config_writeline(FILE *fp, const char *data, int len);
int config_close(FILE *fp);

#endif//__CONFIG_FILE_H__

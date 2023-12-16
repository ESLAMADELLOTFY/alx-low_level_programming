#endif#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pUTch(char c);
ssize_t TEXTFILEREAD(const char *name_of_file, size_t l_etters);
int FileCreater(const char *filenNAmeame, char *content_text);
int Text_file_append(const char *Name_of_file, char *ContentTheText);
ssize_t Strlen(const char *string);


#endif

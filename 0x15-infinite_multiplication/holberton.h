#ifndef _MUL_H_
#define _MUL_H_

#include <stddef.h>

int _putchar(char c);
unsigned int *makespace(size_t size);
void domult(unsigned int *resp, char *a_int, size_t a_len,
			char *b_int, size_t b_len);
int valid(char *c);
void error(int status);

#endif /* _MUL_H_ */

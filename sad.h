#ifndef SAD_H 
#define SAD_H 

#include <stdlib.h>
#include <string.h>

#define NULL  (void *)0

#define SADT_INT   sizeof(int)
#define SADT_FLOAT sizeof(float)
#define SADT_CHAR  sizeof(char)

#define SAD_MAX_SZ 1024
#define SAD_MAX_BT sizeof(long double)

#define SADE_RNG -1
#define SADE_MEM -2
#define SADE_NON  1

struct sadarr {
        void  *dat;
        size_t sz;
        int    t;
};

int sadres(void **ptr, size_t nsz);

int sadini(struct sadarr *arr, size_t sz, size_t t);

void sadset(struct sadarr *arr, void *n, int i);

int sadapp(struct sadarr *arr, void *n);

int sadrem(struct sadarr *arr);

int sadins(struct sadarr *arr, void *n, int i);
// int sadins(void **arr, size_t *sz, size_t t, void *n, int i);

#endif

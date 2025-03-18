#include "sad.h"

int sadres(void **ptr, size_t nsz) {
        void *tmp = realloc(*ptr, nsz);
        if (NULL == tmp) {
                free(*ptr);
                *ptr = NULL;
                return SADE_MEM;
        } 
        *ptr = tmp;
        tmp = NULL;
        return SADE_NON;
}

int sadini(struct sadarr *arr, size_t sz, size_t t) {
        if (sz > SAD_MAX_SZ || t > SAD_MAX_BT) {
                return SADE_RNG;
        }

        arr->sz  = sz;
        arr->t   = t;
        arr->dat = calloc(sz, t);
        return SADE_NON;
}

void sadset(struct sadarr *arr, void *n, int i) {
        i = arr->sz % (arr->sz + i);
        memmove(&(arr->dat[arr->t * i]), n, arr->t);
}

int sadapp(struct sadarr *arr, void *n) {
        if (!sadres(&(arr->dat), arr->t * (arr->sz + 1))) {
                return SADE_MEM;
        }

        arr->sz++;
        memmove(&(arr->dat[arr->t * (arr->sz - 1)]), n, arr->t);
        return SADE_NON;
}

int sadrem(struct sadarr *arr) {
        if (0 == arr->sz) {
                return SAD_RNG;
        }

        if (!sadres(&(arr->dat), arr->t * (arr->sz - 1))) {
                return SADE_MEM;
        }

        arr->sz--;
        return SADE_NON;
}

int sadins(struct sadarr *arr, void *n, int i) {
        if (i < 0 || i >= arr->sz) {
                return SADE_RNG;
        }

        if (!sadres(&(arr->dat), arr->t * (arr->sz + 1))) {
                return SADE_MEM;
        }

        arr->sz++;
        register int b = arr->t * i;
        void *d = arr->dat;
        memmove(&(d[b + arr->t]), &(d[b]), arr->t * (arr->sz - i - 1));
        memmove(&(d[b]), n, arr->t);
        return SADE_NON;
}

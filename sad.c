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
        i = (arr->sz + i) % arr->sz;
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
                return SADE_RNG;
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

int sadgeti(struct sadarr arr, int *got, int i) {
        if (arr.t != SADT_INT) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((int *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetli(struct sadarr arr, long int *got, int i) {
        if (arr.t != SADT_LINT) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((long int *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetlli(struct sadarr arr, long long int *got, int i) {
        if (arr.t != SADT_LLINT) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((long long int *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetsi(struct sadarr arr, short int *got, int i) {
        if (arr.t != SADT_SINT) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((short int *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetf(struct sadarr arr, float *got, int i) {
        if (arr.t != SADT_FLOAT) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((float *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetd(struct sadarr arr, double *got, int i) {
        if (arr.t != SADT_DOUBLE) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((double *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetld(struct sadarr arr, long double *got, int i) {
        if (arr.t != SADT_LDOUBLE) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((long double *)(arr.dat))[i];
        return SADE_NON;
}

int sadgetc(struct sadarr arr, char *got, int i) {
        if (arr.t != SADT_CHAR) {
                return SADE_MEM;
        }

        i = (arr.sz + i) % arr.sz;
        *got = ((char *)(arr.dat))[i];
        return SADE_NON;
}

#ifndef SAD_H 
#define SAD_H 

#include <stdlib.h>
#include <string.h>

#define NULL  (void *)0

/*
 *   Sizes of different common datatypes.
 */
#define SADT_INT     sizeof(int)
#define SADT_LINT    sizeof(long int)
#define SADT_LLINT   sizeof(long long int)
#define SADT_SINT    sizeof(short int)
#define SADT_FLOAT   sizeof(float)
#define SADT_DOUBLE  sizeof(double)
#define SADT_LDOUBLE sizeof(long double)
#define SADT_CHAR    sizeof(char)

/*
 *   Limits
 *
 *   Maximum sizes allowed for array.
 *   `SAD_MAX_SZ` - Maximum length of array.
 *   `SAD_MAX_BT` - Maximum size of each array element (in bytes).
 */
#define SAD_MAX_SZ 1024
#define SAD_MAX_BT SADT_LDOUBLE 

/*
 *   Errors
 *
 *   Error codes returned by all sad functions. All errors are less than 0, any
 *   success is greater than 0.
 *   `SADE_RNG` - Error to do with data being on or over boundaries.
 *   `SADE_MEM` - Error to do with memory allocation.
 *   `SADE_NON` - No error.
 */
#define SADE_RNG -1
#define SADE_MEM -2
#define SADE_NON  1

/*
 *   Array
 *
 *   Array used by sad to enable dynamics.
 *   `void   *dat` - Memory block containing data.
 *   `size_t  sz ` - Number of elements currently in array.
 *   `size_t  t  ` - Size of each element in array (in bytes).
 */
struct sadarr {
        void  *dat;
        size_t sz;
        size_t t;
};

/*
 *   Resize
 *
 *   INPUT  : Pointer to a void pointer - array to resize. New size.
 *   OUTPUT : `SADE_MEM` - Reallocation failed.
 *            `SADE_NON` - Resizing successful.
 *
 *   DESC.  : Resizes the array by changing how much memory is allocated for
 *            it.
 */
int sadres(void **ptr, size_t nsz);

/*
 *   Initialise
 *
 *   INPUT  : Pointer to sad array structure. Size to initialise at. Size of
 *            element type.
 *   OUTPUT : `SADE_RNG` - `sz` is greater than `SAD_MAX_SZ` or `t` is greater
 *                         than `SAD_MAX_BT`.
 *            `SADE_NON` - Initialisation successful.
 *
 *   DESC.  : Initialises the array by setting given parameters and allocating
 *            room for the data.
 */
int sadini(struct sadarr *arr, size_t sz, size_t t);

/*
 *   Set
 *
 *   INPUT  : Pointer to sad array structure. Void pointer to new data. Index
 *            at which to place new data in the array.
 *   OUTPUT : -
 *
 *   DESC.  : Sets given data at given index in array. If the index is outside
 *            bounds of the array, it will be scaled to fit.
 */
void sadset(struct sadarr *arr, void *n, int i);

/*
 *   Append
 *
 *   INPUT  : Pointer to sad array structure. Void pointer to new data.
 *   OUTPUT : `SADE_MEM` - Array could not be resize to make room for new
 *                         element.
 *            `SADE_NON` - Successful appending.
 *
 *   DESC.  : Appends given entity to array.
 */
int sadapp(struct sadarr *arr, void *n);

/*
 *   Remove
 *
 *   INPUT  : Pointer to sad array structure.
 *   OUTPUT : `SADE_RNG` - Array is empty and so no element can be removed.
 *            `SADE_MEM` - Array could not be resized to allow removal of last
 *                         element.
 *            `SADE_NON` - Successful removal.
 *
 *   DESC.  : Removes element at the end of the array.
 */
int sadrem(struct sadarr *arr);

/*
 *   Insert 
 *
 *   INPUT  : Pointer to sad array structure. Void pointer to new data. Index
 *            at which to place new data.
 *   OUTPUT : `SADE_RNG` - Given index is out of bounds.
 *            `SADE_MEM` - Array could not be resized to make room for new
 *                         element.
 *            `SADE_NON` - Insertion removal.
 *
 *   DESC.  : Inserts given element into array at given index.
 */
int sadins(struct sadarr *arr, void *n, int i);

#endif

#include "Nori.h"

void recalculate_sparse(sparse_set *pSs)
{
    for (u32 *ptr = pSs->dense; ptr != pSs->dense + pSs->denseCount; ptr++)
    {
        if (*ptr > pSs->maxVal)
        {
            pSs->maxVal = *ptr;
            u32 *newSparse = REALLOC(pSs->sparse, (pSs->maxVal + 1) * sizeof(u32));
            if (newSparse)
                pSs->sparse = newSparse;
        }
        pSs->sparse[*ptr] = ptr - pSs->dense;
    }
}
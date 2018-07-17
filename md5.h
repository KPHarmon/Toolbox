#include <stdlib.h>
#include <stdio.h>

#ifndef MD5_H
#define MD5_H

typedef unsigned DigestArray[4];

int crackHash(FILE *, char *);

typedef unsigned(*DgstFctn)(unsigned a[]);

#endif /*  MD5_H  */
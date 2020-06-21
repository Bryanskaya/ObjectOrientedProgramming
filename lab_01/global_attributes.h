#ifndef GLOBAL_ATTRIBUTES_H
#define GLOBAL_ATTRIBUTES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI     3.1415
#define EPS               1e-5
#define TRANSF_CONST      10e5
#define MAX_XYZ            900

typedef enum
{
    CORRECT_WORK = 0,
    OPEN_FILE_ERROR,
    EMPTY_FILE,
    INCORRECT_INPUT,
    MEMORY_ERROR,
    INCORRECT_COMMAND,
    INCORRECT_DATA,
    ERROR_SCAN_EDGES
}code_t;

#endif // GLOBAL_ATTRIBUTES_H

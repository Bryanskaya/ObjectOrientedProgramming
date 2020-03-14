#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct
{
    const char *filename;
}read_file_t;

typedef struct
{
    double dx, dy, dz;
}move_t;

typedef struct
{
    double ax, ay, az;
}rotate_t;

typedef struct
{
    double kx, ky, kz;
}scale_t;

#endif // OPERATIONS_H

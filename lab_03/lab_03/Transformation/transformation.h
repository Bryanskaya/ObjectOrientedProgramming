#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <memory>
#include <math.h>

#define PI  3.1415


using namespace std;

class Transformation
{
public:
    Transformation();
    virtual ~Transformation() = 0;

    virtual void execute(double& x, double& y, double& z) = 0;
};

class Move : public Transformation
{
public:
    Move(double dx, double dy, double dz);
    virtual ~Move(){}

    virtual void execute(double& x, double& y, double& z);

private:
    double _dx, _dy, _dz;
};

class Rotate : public Transformation
{
public:
    Rotate(double ax, double ay, double az);
    virtual ~Rotate() {}

    virtual void execute(double& x, double& y, double& z);

private:
    double _ax, _ay, _az;

    void rotate_x(double&, double& y, double& z);
    void rotate_y(double& x, double& y, double& z);
    void rotate_z(double& x, double& y, double& z);
};

class Scale : public Transformation
{
public:
    Scale(double kx, double ky, double kz);
    virtual ~Scale() {}

    virtual void execute(double& x, double& y, double& z);

private:
    double _kx, _ky, _kz;
};

#endif // TRANSFORMATION_H

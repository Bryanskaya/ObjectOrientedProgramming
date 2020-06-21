#ifndef BASEPOINT_H
#define BASEPOINT_H

#include "Objects/simpleobject.h"

class BasePoint : public VisibleObject
{
public:
    BasePoint();
    BasePoint(double x, double y, double z);
    explicit BasePoint(const BasePoint& other);
    virtual ~BasePoint();

    double& get_x();
    double& get_y();
    double& get_z();

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double elem);
    void set_y(double elem);
    void set_z(double elem);


private:
    double _x, _y, _z;
};

#endif // BASEPOINT_H

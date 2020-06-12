#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "Objects/simpleobject.h"

class BaseCamera : public InvisibleObject
{
public:
    BaseCamera();
    BaseCamera(double x, double y, double z);
    explicit BaseCamera(const BaseCamera& other);
    virtual ~BaseCamera() = default;

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

#endif // BASECAMERA_H

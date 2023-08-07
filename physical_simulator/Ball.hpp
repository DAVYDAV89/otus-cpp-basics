#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {

    double      m_radius;
    double      PI{3.14};
    Velocity    m_velocity;
    Point       m_center;
    Color       m_color;
public:
    Ball(double _radius, double _x, double _y, double _vx, double _vy, double _red, double _green, double _blue);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;

    void draw(Painter& painter) const;

    void setCenter(const Point& center);
    Point getCenter() const;

    double getRadius() const;
    double getMass() const;
};

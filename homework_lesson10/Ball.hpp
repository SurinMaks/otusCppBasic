#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(double radius, double x, double y, double vx, double vy, double red, double green, double blue, bool isCollidable);
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

private:
    // Velocity velocity;
    Point center;
    Point velocity;
    // Color color;
    // double x;
    // double y;
    double vx;
    double vy;
    double radius;

    double red;
    double green;
    double blue;
    

    bool isCollidable;
};

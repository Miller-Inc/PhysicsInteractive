//
// Created by James Miller on 10/8/2024.
//

#ifndef QUATERNION_H
#define QUATERNION_H

#pragma once

class Quaternion
{
public:
    float x, y, z, w;

    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Quaternion operator*(const Quaternion& other) const
    {
        return {
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y + y * other.w + z * other.x - x * other.z,
            w * other.z + z * other.w + x * other.y - y * other.x,
            w * other.w - x * other.x - y * other.y - z * other.z
        };
    }

    Quaternion operator*(const float& scalar) const
    {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    Quaternion operator+(const Quaternion& other) const
    {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    Quaternion operator-(const Quaternion& other) const
    {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }

    Quaternion operator/(const float& scalar) const
    {
        return {x / scalar, y / scalar, z / scalar, w / scalar};
    }

    Quaternion operator-() const
    {
        return {-x, -y, -z, -w};
    }

    [[nodiscard]] Quaternion conjugate() const
    {
        return {-x, -y, -z, w};
    }

    [[nodiscard]] Quaternion inverse() const
    {
        return conjugate() / (x * x + y * y + z * z + w * w);
    }

    Quaternion operator+=(const Quaternion& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }



};


#endif //QUATERNION_H

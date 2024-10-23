//
// Created by James Miller on 10/8/2024.
//

#ifndef QUATERNION_H
#define QUATERNION_H

#pragma once
#include <complex>

#include "Vector3.h"

class Quaternion
{
public:
    float x, y, z, w;

    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    explicit Quaternion(Quaternion* other) : x(other->x), y(other->y), z(other->z), w(other->w) {}

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

    Quaternion* operator*=(const Quaternion& other)
    {
        *this = *this * other;
        return this;
    }

    Quaternion* operator* (const Quaternion* other)
    {
        x = w * other->x + x * other->w + y * other->z - z * other->y,
        y = w * other->y + y * other->w + z * other->x - x * other->z,
        z = w * other->z + z * other->w + x * other->y - y * other->x,
        w = w * other->w - x * other->x - y * other->y - z * other->z;

        return this;
    }

    Quaternion operator+=(const Quaternion& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }



    [[nodiscard]] Quaternion getConjugate() const;

    Quaternion* normalizeP();

    [[nodiscard]] float magnitude() const
    {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    [[nodiscard]] float magnitudeSquared() const
    {
        return x * x + y * y + z * z + w * w;
    }

    [[nodiscard]] Quaternion normalize() const
    {
        return *this / magnitude();
    }

    [[nodiscard]] float dot(const Quaternion& other) const
    {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    [[nodiscard]] Quaternion getNormalVector() const;

    [[nodiscard]] Quaternion* getNormalVectorP() const;

    // SLERP
    [[nodiscard]] Quaternion slerp(const Quaternion& other, float t) const;
    [[nodiscard]] Quaternion* slerp(const Quaternion* other, float t) const;

    // Rotation
    [[nodiscard]] Vector3 rotate(const Vector3& v) const;
    [[nodiscard]] Vector3* rotate(const Vector3* v) const;

    bool operator==(const Quaternion& quaternion) const
    {
        return std::fabs(x - quaternion.x) < 0.0000001f && std::fabs(y - quaternion.y) < 0.0000001f && std::fabs(z - quaternion.z) < 0.0000001f && std::fabs(w - quaternion.w) < 0.0000001f;
    };

    bool operator==(const Quaternion* quaternion) const
    {
        return std::fabs(x - quaternion->x) < 0.0000001f && std::fabs(y - quaternion->y) < 0.0000001f && std::fabs(z - quaternion->z) < 0.0000001f && std::fabs(w - quaternion->w) < 0.0000001f;
    };

    // Create a quaternion from an axis and an angle
    static Quaternion fromAxisAngle(const Vector3& axis, float angle);

    // To Axis Angle
    void toAxisAngle(Vector3& axis, float& angle);

    [[nodiscard]] Vector3 getNormalVector3() const;

    [[nodiscard]] std::string toString() const;

};


#endif //QUATERNION_H

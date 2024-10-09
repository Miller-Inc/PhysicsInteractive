//
// Created by James Miller on 10/8/2024.
//

#ifndef VECTOR3_H
#define VECTOR3_H

#pragma once
#include <string>

class Vector3
{
public:
    // Fields Section
    float x;

    float y;

    float z;

    // Constructors Section
    Vector3(float x, float y, float z);

    Vector3(); // Default constructor

    // Operators Section
    Vector3 operator+(const Vector3& other) const;

    Vector3 operator-(const Vector3& other) const;

    Vector3 operator*(float scalar) const;

    Vector3 operator/(float scalar) const;

    Vector3& operator+=(const Vector3& other);

    Vector3& operator-=(const Vector3& other);

    Vector3& operator*=(float scalar);

    bool operator==(const Vector3& other) const;

    [[nodiscard]] Vector3 cross(const Vector3& other) const;

    [[nodiscard]] float magnitude() const;

    [[nodiscard]] float distance(const Vector3& other) const;

    static Vector3 cross(const Vector3& a, const Vector3& b);

    [[nodiscard]] float dot(const Vector3& other) const;

    static float dot(const Vector3& a, const Vector3& b);

    [[nodiscard]] std::string toString() const;
};


#endif //VECTOR3_H

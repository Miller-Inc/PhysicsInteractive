//
// Created by James Miller on 10/8/2024.
//

#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include <string>

#include "../CollisionObject.h"

class Sphere : public CollisionObject
{
public:

    // Properties
    bool useFriction;
    float friction;
    float radius;
    std::string name = "Sphere";
    static int sphereCount();

    static void incrementSpheres();
    static int sphereCounter;

    // Constructors
    Sphere();
    explicit Sphere(float radius);
    Sphere(float radius, float mass);
    Sphere(float radius, float mass, const Vector3& position);
    Sphere(float radius, float mass, const Vector3& position, const Vector3& velocity);
    Sphere(float radius, float mass, float friction, const Vector3& position);


    // Methods
    void ApplyImpulse(const Vector3& impulse) override;
    void ApplyImpulse(const Vector3& impulse, const Vector3& position) override;
    void ApplyAngularImpulse(const Quaternion& impulse) override;
    void ApplyTorqueImpulse(const Vector3& impulse) override;
    void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position) override;
    void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position, const Vector3& axis) override;
    void OnCollision(CollisionObject* other) override;
    void OnSeparation(CollisionObject* other) override;
    void OnContact(CollisionObject* other) override;

    bool isColliding(CollisionObject* other) override;
    bool isTouching(CollisionObject* other) override;

    Vector3 getClosestPoint(const Vector3& point) override;


    std::string toString() override;
};

#endif //SPHERE_H

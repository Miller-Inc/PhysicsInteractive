//
// Created by James Miller on 10/8/2024.
//

#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#pragma once
#include "ImpulseObject.h"
#include <functional>
#include <vector>

#include "../../FieldTypes/ComplexTypes/Force.h"

class CollisionObject: public ImpulseObject
{
public:

    CollisionObject();

    std::vector<CollisionObject*> overlappingObjects;

    virtual void OnCollision(CollisionObject* other);
    virtual void OnSeparation(CollisionObject* other);
    virtual void OnContact(CollisionObject* other);

    virtual bool isColliding(CollisionObject* other);
    virtual bool isTouching(CollisionObject* other);
    virtual Vector3 getClosestPoint(const Vector3& point);

    void ApplyImpulse(const Vector3& impulse, const Vector3& position) override;
    void ApplyAngularImpulse(const Quaternion& impulse) override;
    void ApplyImpulse(const Vector3& impulse) override;
    void ApplyTorqueImpulse(const Vector3& impulse) override;
    void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position) override;
    void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position, const Vector3& axis) override;
    void step(float timeStep) override;

    void AddForce(const Force& force)
    {
        forces.push_back(force);
    }

    std::vector<Force> forces;

};

#endif //COLLISIONOBJECT_H

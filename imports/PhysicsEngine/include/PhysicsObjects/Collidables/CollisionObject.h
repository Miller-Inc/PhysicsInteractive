//
// Created by James Miller on 10/8/2024.
//

#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#pragma once
#include "ImpulseObject.h"
#include <functional>
#include <iostream>
#include <vector>

#include "../../FieldTypes/ComplexTypes/Force.h"

class CollisionObject: public ImpulseObject
{
public:

    CollisionObject();

    std::string name = "Collision Object ";
    static int collObjCount();

    static void incrementCollisionObjs();
    static int objCounter;

    std::vector<CollisionObject*> overlappingObjects;

    virtual void OnCollision(CollisionObject* other);
    virtual void OnSeparation(CollisionObject* other);
    virtual void OnContact(CollisionObject* other);

    virtual bool isColliding(CollisionObject* other);
    virtual bool isTouching(CollisionObject* other);
    virtual Vector3 getClosestPoint(const Vector3& point);
    virtual Vector3* getClosestPoint(const Vector3* point);

    bool isCollidable() override
    {
        return true;
    }

    bool operator==(const CollisionObject& collision_object) const {
        return velocity == collision_object.velocity && position == collision_object.position && rotation == collision_object.rotation && angularVelocity == collision_object.angularVelocity && mass == collision_object.mass;
    }

    void ApplyImpulse(const Vector3& impulse, const Vector3& position) override;
    void ApplyImpulse(const Vector3* impulse) override;
    void ApplyImpulse(CollisionObject* other);

    void ApplyAngularImpulse(const Quaternion& impulse) override;
    void ApplyImpulse(const Vector3& impulse) override;
    void ApplyTorqueImpulse(const Vector3& impulse) override;
    void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position) override;
    void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position, const Vector3& axis) override;

    void step(float timeStep) override;

    void rotate(Quaternion rotation) override;

    void rotate(float degrees, Vector3 axis) override;

    std::string toString() override;

    void AddForce(const Force& force)
    {
        forces.push_back(new Force(force));
    }

    void AddForce(const Force* force)
    {
        std::cout << force->force->toString() << std::endl;
        forces.push_back(new Force(*force));
    }

    std::vector<Force*> forces;

    bool equals(BaseObject* other) override;

    ~CollisionObject() override;
};

#endif //COLLISIONOBJECT_H

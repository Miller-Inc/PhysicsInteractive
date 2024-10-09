//
// Created by James Miller on 10/8/2024.
//

#ifndef IMPULSEOBJECT_H
#define IMPULSEOBJECT_H

#pragma once
#include "../BaseObject.h"

class ImpulseObject : public BaseObject
{
public:

    Vector3 currentMomentum;

    virtual void ApplyImpulse(const Vector3& impulse) = 0;
    virtual void ApplyImpulse(const Vector3& impulse, const Vector3& position) = 0;
    virtual void ApplyAngularImpulse(const Quaternion& impulse) = 0;
    virtual void ApplyTorqueImpulse(const Vector3& impulse) = 0;
    virtual void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position) = 0;
    virtual void ApplyTorqueImpulse(const Vector3& impulse, const Vector3& position, const Vector3& axis) = 0;

};


#endif //IMPULSEOBJECT_H

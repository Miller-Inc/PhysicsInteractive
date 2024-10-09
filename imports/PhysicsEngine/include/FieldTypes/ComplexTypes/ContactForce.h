//
// Created by James Miller on 10/8/2024.
//

#ifndef CONTACTFORCE_H
#define CONTACTFORCE_H
#pragma once
#include "Force.h"

class ContactForce : Force
{
    Vector3 contactPoint;

    explicit ContactForce(const Vector3 force) : ContactForce(force, Vector3(0, 0, 0))
    {

    }

    ContactForce(const Vector3 force, const Vector3 contactPoint) : ContactForce(force, contactPoint, 0)
    {
        this->contactPoint = contactPoint;
        this->force = force;
    }

    ContactForce(const Vector3 force, const Vector3 contactPoint, const float timeApplied) : Force(force, timeApplied)
    {
        this->contactPoint = contactPoint;
        this->force = force;
        this->timeRemaining = timeApplied;
    }

    [[nodiscard]] Vector3 torque() const
    {
        return Vector3::cross(contactPoint, force);
    }

    [[nodiscard]] Vector3 get_force() const override;
};

#endif //CONTACTFORCE_H

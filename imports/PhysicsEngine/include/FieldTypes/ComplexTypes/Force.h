//
// Created by James Miller on 10/8/2024.
//

#ifndef FORCE_H
#define FORCE_H
#pragma once
#include "../BaseTypes/Vector3.h"

class Force
{
public:
    virtual ~Force() = default;
    Vector3 force;

    float timeRemaining;

    explicit Force(Vector3 force) : Force(force, 0.0f)
    {
        this->force = force;
    }

    /// <summary>
    ///     Main Constructor, creates a force with a given force and time applied,
    ///     if time applied is negative, the force is applied indefinitely
    /// </summary>
    Force(const Vector3 force, const float timeApplied)
    {
        this->force = force;
        this->timeRemaining = timeApplied;
        if (timeApplied < 0.0f)
        {
            continuous = true;
        }
    }

    [[nodiscard]] virtual Vector3 get_force() const;

    /// <summary>
    ///     Steps the force by a given timestep
    /// </summary>
    void step(float timeStep)
    {
        if (continuous)
        {
            return;
        }
        timeRemaining -= timeStep;
    }

    bool continuous;
};

#endif //FORCE_H

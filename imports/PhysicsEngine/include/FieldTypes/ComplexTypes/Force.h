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

    // Constants:
    static Vector3 EARTHGRAVITY()
    {
        return {0.0f, -9.81f, 0.0f};
    }

    static Vector3 GRAVITATIONALCONSTANT()
    {
        return {0.0f, -6.67430e-11f, 0.0f};
    }

    static Force* Gravity(const float mass1, const float mass2, const float distance)
    {
        const Vector3 g = GRAVITATIONALCONSTANT();
        auto* force = new Vector3(g.x * (mass1 * mass2) / (distance * distance), g.y * (mass1 * mass2) / (distance * distance), g.z * (mass1 * mass2) / (distance * distance));
        return new Force(force, -1.0f);
    }

    static Force* Gravity(const float mass)
    {
        const Vector3 g = EARTHGRAVITY();
        auto* force = new Vector3(g.x * mass, g.y * mass, g.z * mass);
        return new Force(force, -1.0f );
    }

    virtual ~Force() = default;
    Vector3* force;

    float timeRemaining;

    explicit Force(Vector3* force) : Force(force, 0.0f)
    {
        this->force = force;
    }

    /// <summary>
    ///     Main Constructor, creates a force with a given force and time applied,
    ///     if time applied is negative, the force is applied indefinitely
    /// </summary>
    Force(Vector3* force, const float timeApplied)
    {
        this->force = force;
        this->timeRemaining = timeApplied;
        if (timeApplied < 0.0f)
        {
            continuous = true;
        }
    }

    [[nodiscard]] virtual Vector3* get_force() const;

    /// <summary>
    ///     Steps the force by a given timestep
    /// </summary>
    virtual void step(float timeStep)
    {
        if (continuous)
        {
            return;
        }
        timeRemaining -= timeStep;
    }

    bool continuous;

    [[nodiscard]] virtual bool isVariableForce() const
    {
        return variable;
    }

    const bool variable = false;
};

#endif //FORCE_H

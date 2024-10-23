//
// Created by James Miller on 10/21/2024.
//

#ifndef POSVARIABLEFORCE_H
#define POSVARIABLEFORCE_H

#include "Force.h"

class PosVariableForce : public Force
{
public:
    Vector3* position;

    const bool variable = true;

    PosVariableForce(Vector3* force, Vector3* positionPointer) : Force(force)
    {
        this->position = positionPointer;
    }

    // Method to update the force based on the position
    virtual void updateForce() = 0;

    /// <summary>
    ///    Step function for the force
    /// </summary>
    void step(float timeStep) override
    {
        updateForce(); // Update the force
        if (continuous)
        {
            return;
        }
        timeRemaining -= timeStep;
    }
	
	[[nodiscard]] bool isVariableForce() const override
    {
        return variable;
    }
};

#endif //POSVARIABLEFORCE_H

//
// Created by jwmil on 10/8/2024.
//

#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#pragma once
#include <string>

#include "../FieldTypes/BaseTypes/Vector3.h"
#include "../FieldTypes/BaseTypes/Quaternion.h"

class BaseObject
{
public:
    BaseObject(); // Constructor for the object

    // Constructor for the object with a position, velocity, rotation, and mass
    BaseObject(Vector3 position, Vector3 velocity, Quaternion rotation, float mass);

    virtual ~BaseObject() = default;
    Vector3 position;

    Vector3 velocity;

    Quaternion rotation;

    Quaternion angularVelocity;

    float mass{}; // Mass of the object

    void step()
    {
        step(0.01f);
    } // Step function for the object

    virtual void step(float timeStep); // Step function for the object with a time step

    virtual std::string toString() = 0; // Function to return a string representation of the object
};

#endif //BASEOBJECT_H

//
// Created by James Miller on 10/22/2024.
//

#ifndef DRAGFORCE_H
#define DRAGFORCE_H

#include "../PosVariableForce.h"

class DragForce final : public PosVariableForce
{
public:
    float dragCoefficient;

    DragForce(Vector3* velocityPointer, float dragCoefficient)
        : PosVariableForce(new Vector3(0, 0, 0), velocityPointer), dragCoefficient(dragCoefficient) {}

    void updateForce() override;
};

#endif //DRAGFORCE_H

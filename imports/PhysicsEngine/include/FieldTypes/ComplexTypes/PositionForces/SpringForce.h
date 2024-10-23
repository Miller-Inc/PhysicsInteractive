//
// Created by James Miller on 10/22/2024.
//

#ifndef SPRINGFORCE_H
#define SPRINGFORCE_H

#include "../PosVariableForce.h"

class SpringForce final : public PosVariableForce
{
public:
    Vector3* anchorPoint;
    float springConstant;
    float restLength;

    SpringForce(Vector3* positionPointer, Vector3* anchorPoint, float springConstant, float restLength)
        : PosVariableForce(new Vector3(0, 0, 0), positionPointer), anchorPoint(anchorPoint), springConstant(springConstant), restLength(restLength) {}

    void updateForce() override;
};

#endif //SPRINGFORCE_H

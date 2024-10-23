//
// Created by James Miller on 10/21/2024.
//

#ifndef GRAVITYFORCE_H
#define GRAVITYFORCE_H

#include "../PosVariableForce.h"

class GravityForce final : public PosVariableForce
{
private:
    float mass1;
    float mass2;

public:
    GravityForce(Vector3* positionPointer, const float mass1, const float mass2)
        : PosVariableForce(new Vector3(0, 0, 0), positionPointer), mass1(mass1), mass2(mass2) {}

    void updateForce() override;
};

#endif //GRAVITYFORCE_H
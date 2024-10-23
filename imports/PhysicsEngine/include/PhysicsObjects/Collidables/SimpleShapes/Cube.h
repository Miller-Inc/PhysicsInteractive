//
// Created by James Miller on 10/9/2024.
//

#ifndef CUBE_H
#define CUBE_H

#pragma once

#include "FlatSheet.h"
#include "../CollisionObject.h"


class Cube : public CollisionObject
{

public:
    // Constructors
    Cube();
    explicit Cube(float sideLength);

    std::string name = "Cube ";
    static int cubeCount();

    static void incrementCube();
    static int cubeCounter;

    // Cube faces
    FlatSheet* top;
    FlatSheet* bottom;
    FlatSheet* left;
    FlatSheet* right;
    FlatSheet* front;
    FlatSheet* back;

    // Destructors
    ~Cube() override;

    // Variables
    float sideLength;

    // Override Functions
    bool isColliding(CollisionObject* other) override;

    bool isTouching(CollisionObject* other) override;

    Vector3 getClosestPoint(const Vector3& point) override;

    [[nodiscard]] Quaternion getRotation() const;

    void rotate(Quaternion rotation) override;

    void rotate(float degrees, Vector3 axis) override;

    std::string toString() override;

    void step(float timeStep) override;

private:
    [[nodiscard]] FlatSheet* getClosestPlane(const Vector3& point) const;
};

#endif //CUBE_H

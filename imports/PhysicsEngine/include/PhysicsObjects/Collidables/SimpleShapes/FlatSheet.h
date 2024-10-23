//
// Created by James Miller on 10/9/2024.
//

#ifndef FLATSHEET_H
#define FLATSHEET_H

#include "../CollisionObject.h"

class FlatSheet : public CollisionObject
{
public:
    // Constructors
    FlatSheet();
    explicit FlatSheet(float sideLength);
    explicit FlatSheet(float height, float width);
    explicit FlatSheet(float height, float width, Vector3* position, float mass);

    // Destructor
    ~FlatSheet() override;

    // Name
    std::string name = "Flat Sheet ";
    static int fSCount();

    static void incrementFS();
    static int fSCounter;

    // Variables
    float height;
    float width;
    Vector3* normalVector;

private:
    // Variables:
    Vector3* topRight;
    Vector3* topLeft;
    Vector3* bottomRight;
    Vector3* bottomLeft;


public:
    // Override Functions
    bool isColliding(CollisionObject* other) override;

    bool isTouching(CollisionObject* other) override;

    Vector3 getClosestPoint(const Vector3& point) override;

    Vector3* getClosestPoint(const Vector3* point) override;

    [[nodiscard]] Vector3 getNormalVector() const;

    void setNormalVector(Vector3* normalVector);

    void rotate(Quaternion rotation) override;

    void rotate(float degrees, Vector3 axis) override;

    std::string toString() override;
};

#endif //FLATSHEET_H

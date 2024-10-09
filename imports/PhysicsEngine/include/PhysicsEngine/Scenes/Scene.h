//
// Created by James Miller on 10/8/2024.
//

#ifndef SCENE_H
#define SCENE_H
#pragma once
#include <chrono>
#include <vector>

#include "../../PhysicsObjects/BaseObject.h"
#include "../../PhysicsObjects/Collidables/CollisionObject.h"

class Scene
{
public:

    Scene() = default;

    std::vector<BaseObject*> sceneObjects;

    bool sceneRunning = true;

    void main();

    void main(float time);

    void main(float time, bool print);

    std::vector<CollisionObject> collisionObjects;

    std::vector<CollisionObject> collidedObjects;

    std::vector<CollisionObject*> getCollisions(CollisionObject* object);

    void AddObject(BaseObject* object)
    {
        sceneObjects.push_back(object);
    }

    void step(float timestep);

    void stopSimulation();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
    float getDeltaTime();

};

#endif //SCENE_H

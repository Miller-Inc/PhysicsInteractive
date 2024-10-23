#include <iostream>
#include "imports/PhysicsEngine/include/FullEngineIncludes.h"

int main()
{
    Scene scene = Scene();

    auto* sphere = new Sphere(1.5f, 10.0f, Vector3(0, 0, 0));

    auto* sphere2 = new Sphere(1.5f, 15.0f, Vector3(0, 0, 0));

    auto* plane = new FlatSheet(10.0f, 10.0f, new Vector3(0, 1, 0), 10.0);

    const auto gravity = Force::Gravity(10.0f);

    const auto gravity2 = Force::Gravity(15.0f);

    const auto gravity3 = Force::Gravity(10.0f);

    const auto springForce = SpringForce(plane->position, new Vector3(0.0f, 0.0f, 0.0f), 10000.0f, 0.1f);

    sphere2->AddForce(gravity2);

    sphere->AddForce(gravity);

    plane->AddForce(gravity3);

    plane->AddForce(springForce);

    scene.AddObject(sphere);

    scene.AddObject(sphere2);

    scene.AddObject(plane);

    scene.main(20.0f, true);

    std::vector<CollisionObject*> objs = scene.getCollisions(scene.collisionObjects[2]);

    std::cout << "Objects: \n";
    for (const auto obj : scene.sceneObjects)
    {
        std::cout << obj->toString() << "\n";
    }

    std::cout << "Collisions: \n";
    for (const auto obj : objs)
    {
        std::cout << obj->toString() << " " << obj->mass << " kg" << "\n";
    }

    return 0;
}

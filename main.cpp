#include <iostream>
#include "imports/PhysicsEngine/include/library.h"
#include "imports/PhysicsEngine/include/FullEngineIncludes.h"


int main()
{
    Scene scene = Scene();

    auto* sphere = new Sphere(1.5f, 10.0f, Vector3(0, 0, 0));

    auto* sphere2 = new Sphere(1.5f, 15.0f, Vector3(0, 0, 0));

    auto gravity = Force(Vector3(0, -98.0f, 0), -1.0);

    auto gravity2 = Force(gravity.force * 1.5f, -1.0f);

    sphere2->AddForce(gravity2);

    sphere->AddForce(gravity);

    scene.AddObject(sphere);

    scene.AddObject(sphere2);

    scene.main(10.0f, true);


    return 0;
}

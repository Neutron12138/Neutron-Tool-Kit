#include <iostream>
#include <btBulletDynamicsCommon.h>
#include <memory>

int main()
{
	std::unique_ptr<btDiscreteDynamicsWorld> world;
	std::unique_ptr<btStaticPlaneShape> ground_shape;
	std::unique_ptr<btBoxShape> cube_shape;
	std::unique_ptr<btRigidBody> ground;
	std::unique_ptr<btRigidBody> cube;

	btVector3 min = btVector3(-100, -100, -100);
	btVector3 max = btVector3(100, 100, 100);
	std::unique_ptr<btAxisSweep3> as = std::make_unique<btAxisSweep3>(min, max, 1024);

	std::unique_ptr<btDefaultCollisionConfiguration> dcc = std::make_unique<btDefaultCollisionConfiguration>();
	std::unique_ptr<btCollisionDispatcher> cd = std::make_unique<btCollisionDispatcher>(dcc.get());
	std::unique_ptr<btSequentialImpulseConstraintSolver> sics = std::make_unique<btSequentialImpulseConstraintSolver>();

	world = std::make_unique<btDiscreteDynamicsWorld>(cd.get(), as.get(), sics.get(), dcc.get());
	world->setGravity(btVector3(0, -10, 0));

	ground_shape = std::make_unique<btStaticPlaneShape>(btVector3(0, 1, 0), 0);
	cube_shape = std::make_unique<btBoxShape>(btVector3(0.5f, 0.5f, 0.5f));

	std::unique_ptr<btDefaultMotionState> ground_dms = std::make_unique<btDefaultMotionState>(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	btRigidBody::btRigidBodyConstructionInfo ground_rbci(0, ground_dms.get(), ground_shape.get());
	ground = std::make_unique<btRigidBody>(ground_rbci);
	world->addRigidBody(ground.get());

	std::unique_ptr<btDefaultMotionState> cube_dms = std::make_unique<btDefaultMotionState>(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 10, 0)));
	btVector3 cube_inertia = btVector3(0, 0, 0);
	cube_shape->calculateLocalInertia(1, cube_inertia);
	btRigidBody::btRigidBodyConstructionInfo cube_rbci(1, cube_dms.get(), cube_shape.get(), cube_inertia);
	cube = std::make_unique<btRigidBody>(cube_rbci);
	cube->setRestitution(0.9f);
	cube->setFriction(0.1f);
	world->addRigidBody(cube.get());
	
	float stepsPerSeconds = 1000.0f;
	
	for (int i = 0; i < 2 * stepsPerSeconds; i++)
	{
		world->stepSimulation(1.0f / stepsPerSeconds);

		btTransform trans;
		cube->getMotionState()->getWorldTransform(trans);
		float y = trans.getOrigin().getY();
		const btVector3& vel = cube->getLinearVelocity();
		float time = float(i) / stepsPerSeconds;
		std::cout << "time: " << time << "\t\theight: " << y << "\t\tvelocity: " << vel.getY() << std::endl;
	}
	return 0;
}

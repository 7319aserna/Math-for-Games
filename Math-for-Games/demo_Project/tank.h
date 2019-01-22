#include "raylib.h"
#include "vec3.h"
#pragma once

class tank {
public:
	/*transform2d tank;
	transform2d tankTurrent;
	tankTurrent.setParent(&tank);*/
	tank();
	~tank();

	transform2d tankBody;
	transform2d tankTurret;
	Texture2D tankBodyTexture;
	Texture2D tankTurretTexture;
	Vector2 tankBodyPosition;
	Vector2 tankTurretPosition;

	Rectangle tankBodyRectangle;
	Rectangle tankTurrentRectangle;

	void update(float deltaTime);
	void draw();
};
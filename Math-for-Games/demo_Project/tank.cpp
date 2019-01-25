#include <iostream>
#include "tank.h"

tank::tank() {
	tankTurret.setParent(&tankBody);
	
	// Tank body
	tankBody.localPos = { 0.0f, 0.0f };
	tankBody.localScale = { 1.0f, 1.0f };
	// Tank turret
	// Offset for tank's turret
	tankTurret.localPos = { 29.5f, 29.5f };
	tankTurret.localScale = { 1.0f, 1.0f };
	tankBodyPosition = tankBody.localPos;
	tankTurretPosition = tankTurret.worldPosition();
	// Offset for tank's turret
	tankTurretPosition.x += 29.5f;
	tankTurretPosition.y += 29.5f;
	// Set rotation
	tankTurret.localRot = 0.0f;
	tankBodyTexture = LoadTexture("C:/Users/7319a/source/repos/Math-for-Games/Math-for-Games/Assets/Tanks/tankRed_outline.png");
	tankTurretTexture = LoadTexture("C:/Users/7319a/source/repos/Math-for-Games/Math-for-Games/Assets/Tanks/barrelRed_outline.png");
}

tank::~tank() {
}

void tank::update(float deltaTime) {
	// Get tank body's matrix
	if (IsKeyPressed(KEY_Q)) {
		tankBody.getTRSMatix();
		std::cout << std::endl;
	}

	if (IsKeyDown(KEY_W)) {
		tankBody.translate(0.0f, -1.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
	}

	if (IsKeyDown(KEY_A)) {
		tankBody.translate(-1.0f, 0.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
	}

	if (IsKeyDown(KEY_S)) {
		tankBody.translate(0.0f, 1.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
	}

	if (IsKeyDown(KEY_D)) {
		tankBody.translate(1.0f, 0.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
	}

	if (IsKeyDown(KEY_Q)) {
		tankBody.rotate(-1.0f);
		//tankTurret.rotate(-1.0f);
	}

	if (IsKeyDown(KEY_E)) {
		tankBody.rotate(1.0f);
	}
}

void tank::draw() {
	DrawTextureEx(tankBodyTexture, tankBody.worldPosition(), tankBody.worldRotation(), 1.0f, WHITE);
	DrawTextureEx(tankTurretTexture, tankTurret.worldPosition(), tankTurret.worldRotation(), 1.0f, WHITE);
	// Get tank body's position
	DrawText(FormatText("X: %i", (int)tankBodyPosition.x), 750, 25, 50, BLACK);
	DrawText(FormatText("Y: %i", (int)tankBodyPosition.y), 750, 87, 50, BLACK);
}
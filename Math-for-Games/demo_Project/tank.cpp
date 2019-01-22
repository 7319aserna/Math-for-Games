#include <iostream>
#include "tank.h"

tank::tank() {
	tankTurret.setParent(&tankBody);

	tankBody.localPos = { 0.0f, 0.0f };
	// Offset for tank's turret
	tankTurret.localPos = { 29.5f, 29.5f };
	tankBodyPosition = tankBody.localPos;
	tankTurretPosition = tankTurret.worldPosition();
	// Offset for tank's turret
	tankTurretPosition.x += 29.5f;
	tankTurretPosition.y += 29.5f;
	//tankTurretPosition = { tankBodyPosition.x + 29.5f, tankBodyPosition.y + 29.5f };
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
		//tankTurretPosition = { tankBodyPosition.x + 29.5f, tankBodyPosition.y + 29.5f };
	}

	if (IsKeyDown(KEY_A)) {
		tankBody.translate(-1.0f, 0.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
		//tankTurretPosition = { tankBodyPosition.x + 29.5f, tankBodyPosition.y + 29.5f };
	}

	if (IsKeyDown(KEY_S)) {
		tankBody.translate(0.0f, 1.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
		//tankTurretPosition = { tankBodyPosition.x + 29.5f, tankBodyPosition.y + 29.5f };
	}

	if (IsKeyDown(KEY_D)) {
		tankBody.translate(1.0f, 0.0f);
		tankBodyPosition = tankBody.localPos;
		tankTurretPosition = tankTurret.worldPosition();
		// Offset for tank's turret
		tankTurretPosition.x += 29.5f;
		tankTurretPosition.y += 29.5f;
		//tankTurretPosition = { tankBodyPosition.x + 29.5f, tankBodyPosition.y + 29.5f };
	}

	// Tank turret rotation
	// Ask Terry how to rotate tank on wednsday
	//tankTurret.rotate
}

void tank::draw() {
	DrawTexture(tankBodyTexture, tankBodyPosition.x, tankBodyPosition.y, WHITE);
	DrawTexture(tankTurretTexture, tankTurretPosition.x, tankTurretPosition.y, WHITE);
	// Get tank body's position
	DrawText(FormatText("X: %i", (int)tankBodyPosition.x), 750, 25, 50, BLACK);
	DrawText(FormatText("Y: %i", (int)tankBodyPosition.y), 750, 87, 50, BLACK);
}
#pragma once
#include <iostream>

class Vector2D
{
public:
	int x;
	int y;

	int spriteLocationInPNGWidth;
	int spriteLocationInPNGHeight;
	Vector2D();
	Vector2D(int x, int y);

	Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);
};
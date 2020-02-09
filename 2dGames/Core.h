#pragma once


struct Vector2d
{
	int x = 0;
	int y = 0;

	static Vector2d Up;
	static Vector2d Down;
	static Vector2d Left;
	static Vector2d Right;


	Vector2d() {
		x = 0;
		y = 0;
	}

	Vector2d(int _x, int _y)
	{
		x = _x;
		y = _y;
	}


	bool operator != (const Vector2d other)
	{
		return !(this->x == other.x && this->y == other.y);
	}


	Vector2d operator += (const Vector2d np)
	{
		x += np.x;
		y += np.y;

		return *this;
	}

	Vector2d operator * (float a)
	{
		this->x *= a;
		this->y *= a;

		return *this;
	}


	bool isNull()
	{
		return x == 0 && y == 0;
	}
};


/*

Vector2d Vector2d::Up = { 0, -1 };
Vector2d Vector2d::Down = { 0, 1 };
Vector2d Vector2d::Left = { -1, 0 };
Vector2d Vector2d::Right = { 1, 0 };

*/
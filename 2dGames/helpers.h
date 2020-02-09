#pragma once

#include <cmath>



inline float Clamp2(float min, float max, float value)
{
	value = value < min ? min : value;
	value = value > max ? max : value;

	return value;
}


inline float Lerp2(float a, float b, float f)
{
	return a + (0, 1, f) * (b - a);
}




struct V2 {
	float x, y;

	V2()
	{
		x = 0;
		y = 0;
	}


	V2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}


	V2& operator=(const V2& a)
	{
		x = a.x;
		y = a.y;
		return *this;
	}


	V2 operator *(float a) const
	{
		return V2(x*a, y*a);
	}


	V2 operator +(const V2& a) const
	{
		return V2(x + a.x, y + a.y);
	}


	V2 operator -(const V2& a) const
	{
		return V2(x - a.x, y - a.y);
	}


	bool operator==(const V2& a) const
	{
		return (x == a.x && y == a.y);
	}


	float length()
	{
		return sqrt(x*x + y * y);
	}

};


struct CellCoords {
	int i, j;


	CellCoords()
	{
		i = 0;
		j = 0;
	}

	CellCoords(int _i, int _j)
	{
		i = _i;
		j = _j;
	}

	CellCoords operator +(const CellCoords& a) const
	{
		return CellCoords(i + a.i, j + a.j);
	}


	CellCoords operator -(const CellCoords& a) const
	{
		return CellCoords(i - a.i, j - a.j);
	}


	V2 NormalAsV2()
	{
		float ni = i != 0 ? i / abs(i) : 0;
		float nj = j != 0 ? j / abs(j) : 0;

		return V2(ni, nj);
	}


	float length()
	{
		return sqrt(i*i + j*j);
	}

};



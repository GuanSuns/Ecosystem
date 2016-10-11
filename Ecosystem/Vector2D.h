#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include "Location.h"
#include "MapItem.h"
#include <cmath>

class Vector2D
{
public:
	Vector2D();
	Vector2D(double, double);
	Vector2D(Location&, Location&);
	~Vector2D();

public:
	Vector2D operator + (Vector2D);
	Vector2D operator - (Vector2D);
	Vector2D operator * (double);
	Vector2D operator / (double);
	void getNormalization();

	double dot(Vector2D);
	double det(Vector2D);
	double getLength();

	double getY() const { return y; }
	void setY(double val) { y = val; }
	double getX() const { return x; }
	void setX(double val) { x = val; }

private:
	double x, y;
	double add(double a, double b) { return a + b; }
	inline int getXDirection(int, int);
	inline int getYDirection(int, int);
};

#endif

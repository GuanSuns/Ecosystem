#include "Vector2D.h"


Vector2D::Vector2D()
{
}

Vector2D::Vector2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(Location& from, Location& to)
{
	this->x = (double)(to.x - from.x)* (double)getXDirection(from.x,to.x);
	this->y = (double)(to.y - from.y)*(double)getYDirection(from.y,to.y);
}

int Vector2D::getXDirection(int from, int to)
{
	int maxX, minX, tempDistance, directDistance;
	if (from > to)
	{
		maxX = from;
		minX = to;
	}
	else
	{
		maxX = to;
		minX = from;
	}
	tempDistance = minX + MapParameters::maxMapHeight - maxX;
	directDistance = maxX - minX;

	if (tempDistance < directDistance) return -1;
	else return 1;
}

int Vector2D::getYDirection(int from, int to)
{
	int maxY, minY, tempDistance, directDistance;
	if (from > to)
	{
		maxY = from;
		minY = to;
	}
	else
	{
		maxY = to;
		minY = from;
	}
	tempDistance = minY + MapParameters::maxMapHeight - maxY;
	directDistance = maxY - minY;

	if (tempDistance < directDistance) return -1;
	else return 1;
}


Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator + (Vector2D p)
{
	return Vector2D(add(x, p.getX()), add(y, p.getY()));
}

Vector2D Vector2D::operator - (Vector2D p)
{
	return Vector2D(add(x, -p.getX()), add(y, -p.getY()));
}

Vector2D Vector2D::operator * (double n)
{
	return Vector2D(n*x, n*y);
}

Vector2D Vector2D::operator / (double n)
{
	return Vector2D(x / n, y / n);
}

void Vector2D::getNormalization()
{
	double l = this->getLength();
	this->x = (this->x) / l;
	this->y = (this->y) / l;
}

double Vector2D::dot(Vector2D p)
{
	return add(p.getX()*x, p.getY()*y);
}

double Vector2D::det(Vector2D p)
{
	return add(p.getY()*x, -p.getX()*y);
}

double Vector2D::getLength()
{
	return (double)sqrt(x*x + y*y);
}




#include "stdafx.h"
#include "Vector2D.h"


CVector2D::CVector2D(void)
{
	_x = 0;
	_y = 0;
}

CVector2D::CVector2D(float x, float y)
{
	_x = x;
	_y = y;
}

CVector2D::~CVector2D(void)
{
}

const CVector2D CVector2D::operator+(const CVector2D &other) const
{
	return CVector2D(_x + other.GetX(), _y + other.GetY());
}

const CVector2D CVector2D::operator-(const CVector2D &other) const
{
	return CVector2D(_x - other.GetX(), _y - other.GetY());
}

void CVector2D::SetPosition(float x, float y)
{
	_x = x;
	_y = y;
}

void CVector2D::SetX(float x)
{
	_x = x;
}

void CVector2D::SetY(float y)
{
	_y = y;
}

float CVector2D::GetX(void) const
{
	return _x;
}

float CVector2D::GetY(void) const
{
	return _y;
}

float CVector2D::Length(void) const
{
	return sqrt((_x * _x) + (_y * _y));
}

float CVector2D::ScalarDistanceBetween(const CVector2D &other) const
{
	return (other - *this).Length();
}

CVector2D CVector2D::VectorDistanceBetween(const CVector2D& other) const
{
	//TODO: Implement VectorDistanceBetween
	return CVector2D();
}

float CVector2D::DotProduct(const CVector2D &other) const
{
	return (_x * other.GetX()) + (_y * other.GetY());
}

CVector2D CVector2D::CrossProduct(const CVector2D &other) const
{
	//TODO: Implement CrossProduct
	return CVector2D();
}
#pragma once
class CVector2D
{
public:
	CVector2D(void);
	CVector2D(float x, float y);
	~CVector2D(void);

	const CVector2D operator+(const CVector2D &other) const;
	const CVector2D operator-(const CVector2D &other) const;

	void SetPosition(float x, float y);
	void SetX(float x);
	void SetY(float y);

	float GetX(void) const;
	float GetY(void) const;

	float Length(void) const;
	float ScalarDistanceBetween(const CVector2D &other) const;
	CVector2D VectorDistanceBetween(const CVector2D &other) const;
	float DotProduct(const CVector2D &other) const;
	float CrossProduct(const CVector2D &other) const;

private:
	float _x;
	float _y;
};


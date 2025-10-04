#pragma once
#include "Utils.h"

namespace MathClasses
{
	struct Vector2
	{
		union
		{
			struct
			{
				float x, y;
			};

			float v[2];
		};

		Vector2() { x = y = 0; }
		Vector2(float inX, float inY) { x = inX; y = inY; }

#ifdef RAYLIB_CPP_INCLUDE_RAYLIB_CPP_HPP_

		Vector2(const raylib::Vector2& RVector2) { x = RVector2.x; y = RVector2.y; }
		operator raylib::Vector2() const { return{ x,y }; }

#endif

#ifdef RAYLIB_H
		Vector2(const ::Vector2& RVector2) { x = RVector2.x; y = RVector2.y; }
		operator::Vector2()const { return { x,y }; }
#endif
		float Magnitude() const { return sqrtf((x * x) + (y * y)); }
		float Dot(const Vector2& rhs) const { return ((x * rhs.x) + (y * rhs.y)); }
		static float Dot(const Vector2& first, const Vector2& second) { return first.Dot(second); }
		Vector2 Perp() const { return { -y,x }; }

		void Normalise() { float mag = this->Magnitude(); x /= mag; y /= mag; }
		void SafeNormalise() { if (this->Magnitude() != 0) { Normalise(); } return; }
		Vector2 Normalised() const { Vector2 copy = *this; copy.Normalise(); return copy; }
		Vector2 SafeNormalised() const { if (this->Magnitude() != 0) { Vector2 copy = *this; copy.SafeNormalise(); return copy; }


	//	Vector2 operator +(const Vector2& rhs) const;
	//	Vector2& operator +=(const Vector2& rhs);
	//	Vector2 operator -(const Vector2& rhs) const;
	//	Vector2& operator -=(const Vector2& rhs);
	//	Vector2 operator *(float rhs) const;
	//	Vector2& operator *=(float rhs);
	//	Vector2 operator /(float rhs) const;
	//	Vector2& operator /=(float rhs);
	//	bool operator == (const Vector2& rhs) const;
	//	bool operator != (const Vector2& rhs) const;
		bool Equals(const Vector2 & rhs, float Tolerance = MAX_FLOAT_DELTA) const { Vector2 distance =  }
	//	std::string ToString() const;
	//	operator float* ();
	//	operator const float* () const;
	//	Vector2 operator *(const Vector2& rhs) const; rhs.y);
	//	Vector2& operator *=(const Vector2& rhs);
	//	Vector2 operator /(const Vector2& rhs) const;
	//	Vector2& operator /=(const Vector2& rhs);
	//	Vector2 operator -() const;
	//	float& operator [](int dim);
	//	const float& operator [](int dim) const;
		float MagnitudeSqr() const { return ((x * x) + (y * y)); }
	//	float Distance(const Vector2& other) const;
	//	float DistanceSqr(const Vector2& other) const;
	//	static float Distance(const Vector2& start, const Vector2& end);
	//	static float DistanceSqr(const Vector2& start, const Vector2& end);
	//	float AngleBetween(const Vector2& other) const;
	//	inline Vector2 operator*(float scalar, const Vector2& vector);


	};
}
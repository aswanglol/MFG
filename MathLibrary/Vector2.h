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
		float Magnitude() const { 
			return sqrtf((x * x) + (y * y)); 
		}
		float Dot(const Vector2& rhs) const { 
			return ((x * rhs.x) + (y * rhs.y)); 
		}
		static float Dot(const Vector2& first, const Vector2& second) { 
			return first.Dot(second); 
		}
		Vector2 Perp() const { 
			return { -y,x }; 
		}

		void Normalise() { 
			float mag = this->Magnitude(); x /= mag; y /= mag; 
		}
		void SafeNormalise() { 
			if (this->Magnitude() != 0) { Normalise(); } return; 
		}
		Vector2 Normalised() const { 
			Vector2 copy = *this; copy.Normalise(); return copy; 
		}
		Vector2 SafeNormalised() const {
			if (this->Magnitude() != 0) { Vector2 copy = *this; copy.SafeNormalise(); return copy; }
		}
		Vector2 operator +(const Vector2& rhs) const {
			Vector2 vector = { x, y };
			vector.x += rhs.x;
			vector.y += rhs.y;
			return vector;
		}
		Vector2& operator +=(const Vector2& rhs) {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
		Vector2 operator -(const Vector2& rhs) const {
			Vector2 vector = { x, y };
			vector.x -= rhs.x;
			vector.y -= rhs.y;
			return vector;
		}
		Vector2& operator -=(const Vector2& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}
		Vector2 operator *(float rhs) const {
			Vector2 vector = { x, y };
			vector.x *= rhs;
			vector.y *= rhs;
			return vector;
		}
		Vector2& operator *=(float rhs) {
			x *= rhs; y *= rhs; return *this;
		}

		Vector2 operator /(float rhs) const {
			Vector2 vector = { x, y };
			vector.x /= rhs;
			vector.y /= rhs;
			return vector;
		}
		Vector2& operator /=(float rhs) {
			x /= rhs; y /= rhs; return *this;
		}
		bool operator == (const Vector2& rhs) const {
			return Equals(rhs);
		}
		bool operator != (const Vector2 & rhs) const {
			return !(Equals(rhs));
		}
		bool Equals(const Vector2 & rhs, float Tolerance = MAX_FLOAT_DELTA) const { 
			Vector2 distance = { x - rhs.x, y - rhs.y };
			distance.Absolute();
		}
		std::string ToString() const {
			return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
		}
		operator float* () {
			return data;
		}
		operator const float* () const {
			return data;
		}
	//	Vector2 operator *(const Vector2& rhs) const; rhs.y);
	//	Vector2& operator *=(const Vector2& rhs);
	//	Vector2 operator /(const Vector2& rhs) const;
	//	Vector2& operator /=(const Vector2& rhs);
	//	Vector2 operator -() const;
		float& operator [](int dim) {
			return data[dim];
		}
		const float& operator [](int dim) const {
			return data[dim];
		}
		float MagnitudeSqr() const { 
			return ((x * x) + (y * y)); 
		}
		float Distance(const Vector2& other) const {
			return (*this - other).Magnitude();
		}
		float DistanceSqr(const Vector2& other) const {
			return (*this - other).MagnitudeSqr();
		}
		static float Distance(const Vector2& start, const Vector2& end) {
			return start.Distance(end);
		}
		static float DistanceSqr(const Vector2& start, const Vector2& end) {
			return start.DistanceSqr(end);
		}
		float AngleBetween(const Vector2& other) const {
			return std::atan2f(y - other.y, x - other.x);
		}


	};
	
	inline Vector2 operator*(float scalar, const Vector2 & vector) {
		return vector * scalar;
	}

}
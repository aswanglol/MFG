#pragma once
#include "Vector2.h"
#include "Utils.h"
#include <string>

namespace MathClasses
{
	struct Vector3
	{
		union
		{
			struct
			{
				float x, y, z;
			};

			float v[3];
		};

		Vector3() {
			x = y = z = 0;
		}

		Vector3(float inX, float inY, float inZ) {
			x = inX;
			y = inY;
			z = inZ;
		}

		Vector3(const Vector2& Vec2, float InZ = 0) : x(Vec2.x), y(Vec2.y), z(InZ) {}

		float Magnitude() const {
			return sqrtf((x * x) + (y * y) + (z * z));
		}

		float Dot(const Vector3& rhs) const {
			return((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
		}
		static float Dot(const Vector3& first, const Vector3& second) {
			return first.Dot(second);
		}

		Vector3 Cross(const Vector3& rhs) const {
			Vector3 vector3 = *this;
			vector3.x = (y * rhs.z) - (z * rhs.y);
			vector3.y = (z * rhs.x) - (x * rhs.z);
			vector3.z = (x * rhs.y) - (y * rhs.x);
			return vector3;
		}

		static Vector3 Cross(const Vector3& first, const Vector3& second) {
			return first.Cross(second);
		}

		void Normalise() {
			float mag = this->Magnitude();
			x /= mag; y /= mag; z /= mag; return;
		}

		void SafeNormalise() {
			if (this->Magnitude() != 0) {
				Normalise();
			}
			return;
		}

		Vector3 Normalised() const {
			Vector3 vector3 = *this;
			vector3.Normalise();
			return vector3;
		}

		Vector3 SafeNormalised() const {
			Vector3 vector3 = *this;
			vector3.SafeNormalise();
			return vector3;
		}

		Vector3 Absolute() {
			if (x < 0) { x *= -1; }
			if (y < 0) { y *= -1; }
			if (z < 0) { z *= -1; }
			return *this;
		}

		Vector3 operator +(const Vector3& rhs) const;
		//	Vector3& operator +=(const Vector3& rhs);
		//	Vector3 operator -(const Vector3& rhs) const;
		//	Vector3& operator -=(const Vector3& rhs);
		//	Vector3 operator *(float rhs) const;
		//	Vector3& operator *=(float rhs);
		//	Vector3 operator /(float rhs) const;
		//	Vector3 operator /=(float rhs);
		//	bool operator == (const Vector3& rhs) const;
		//	bool operator != (const Vector3& rhs) const;

		bool Equals(const Vector3& rhs, float Tolerance = MAX_FLOAT_DELTA) const {
			Vector3 distance = { x - rhs.x, y - rhs.y, z - rhs.z };
			distance.Absolute();
			return ((distance.x < Tolerance) && (distance.y < Tolerance) && (distance.z < Tolerance));
		}

		std::string ToString() const {
			return "x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z);
		}

		operator Vector2() const { return Vector2(x, y); }

		// optional
		operator float* ();
		operator const float* () const;
		Vector3 operator *(const Vector3& rhs) const;
		Vector3& operator *=(const Vector3& rhs);
		Vector3 operator /(const Vector3& rhs) const;
		Vector3& operator /=(const Vector3& rhs);
		Vector3 operator -() const;

		float& operator [](int dim) {

		}
		const float& operator [](int dim) const {

		}
		
		float MagnitudeSqr() const {
			return ((x * x) + (y * y) + (z * z));
		}
		float Distance(const Vector3& other) const {
			return (*this - other).Magnitude();
		}
		float DistanceSqr(const Vector3& other) const {
			return (*this - other).Magnitude();
		}
		static float Distance(const Vector3& start, const Vector3& end) {
			return start.Distance(end);
		}
		static float DistanceSqr(const Vector3& start, const Vector3& end) {
			return start.DistanceSqr(end);
		}
		float AngleBetween(const Vector3& other) const {
			return std::acosf(Dot(other) / (Magnitude() * other.Magnitude()));
		}

	};


	inline Vector3 operator*(float scalar, const Vector3& vector) {
		Vector3 temp = vector * scalar;
		return temp;
	}
}



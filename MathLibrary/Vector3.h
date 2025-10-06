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

		Vector3& operator +=(const Vector3& rhs);

		Vector3 operator -(const Vector3& rhs) const;

		Vector3& operator -=(const Vector3& rhs);

		Vector3 operator *(float rhs) const;

		Vector3& operator *=(float rhs);

		Vector3 operator /(float rhs) const;

		Vector3 operator /=(float rhs);

		bool operator == (const Vector3& rhs) const;

		bool operator != (const Vector3& rhs) const;

		bool Equals(const Vector3& rhs, float Tolerance = MAX_FLOAT_DELTA) const {
			Vector3 distance = { x - rhs.x, y - rhs.y, z - rhs.z };
			distance.Absolute();
			return ((distance.x < Tolerance) && (distance.y < Tolerance) && (distance.z < Tolerance));
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

		std::string ToString() const {
			return "x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z);
		}

		operator Vector2() const { return Vector2(x, y); }

		/**
		 * OPTIONAL
		 */

		 /**
		 * Treats this Vector as an array of floats containing its components.
		 */
		operator float* ();

		/**
		 * Treats this Vector as an const array of floats containing its components.
		 */
		operator const float* () const;

		/**
		 * Returns a new Vector where each component is multiplied by the component from the other vector
		 *
		 * @param rhs The other vector.
		 * @return The Vector with each components multiplied by the component from the other vector.
		 */
		Vector3 operator *(const Vector3& rhs) const;

		/**
		 * Assigns and returns this Vector where each component is multiplied by
		 * the component from the other vector
		 *
		 * @param rhs The other Vector.
		 * @return Reference to this Vector's components multiplied by the component from the other vector.
		 */
		Vector3& operator *=(const Vector3& rhs);

		/**
		 * Returns a new Vector where each component is divided by the component from the other vector
		 *
		 * @param The other Vector.
		 * @return A copy of this Vector's components divided by the component from the other vector.
		 */
		Vector3 operator /(const Vector3& rhs) const;

		/**
		 * Assigns and returns this Vector after dividing it by the other vector
		 *
		 * @param rhs The other vector.
		 * @return Reference to this Vector's components divided by the component from the other vector.
		 */
		Vector3& operator /=(const Vector3& rhs);

		/**
		 * Returns a copy of this Vector after negating its components.
		 *
		 * @param rhs The other vector.
		 * @return A copy of this Vector after negating its components.
		 */
		Vector3 operator -() const;

		/**
		 * Returns a reference to one of the components of this Vector when
		 * accessed as though it were an array of floats.
		 *
		 * @param dim The index or dimension (X would be 0, Y would be 1...)
		 * @return Reference to the specified element.
		 */
		float& operator [](int dim);rn v[dim];
	}

	/**
	 * Returns a constant reference to one of the components of this Vector when
	 * accessed as though it were an array of floats.
	 *
	 * @param dim The index or dimension (X would be 0, Y would be 1...)
	 * @return Constant reference to the specified element.
	 */
	const float& operator [](int dim) const;

	/**
	 * Returns the Squared Magnitude of this Vector.
	 *
	 * This is used to avoid or skip a potentially expensive square-root
	 * function call.
	 *
	 * @return The squared magnitude of this Vector.
	 */
	float MagnitudeSqr() const;

};

/**
 * Returns a new Vector where each component is scaled by the scalar value
 * @param scalar The scalar.
 * @param vector The Vector.
 * @return The scaled Vector.
 */
inline Vector3 operator*(float scalar, const Vector3& vector);


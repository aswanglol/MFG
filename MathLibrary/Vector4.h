#pragma once
#include "Vector3.h"
#include "Utils.h"


namespace MathClasses
{
	struct Vector4
	{
		union
		{
			struct
			{
				float x, y, z, w;
			};

			float v[4];
		};

		Vector4() { x = y = z = w = 0; }

		Vector4(float inX, float inY, float inZ, float inW) 
		{ x = inX; y = inY; z = inZ; w = inW; }

		/* @todo Allow construction from Vector3 */

		/**
		 * @brief Returns the magnitude of this Vector
		 * @return The magnitude of this Vector.
		 */
		float Magnitude() const {
			if (w == 0) {
				return sqrtf((x * x) + (y * y) + (z * z));
			}
			return (w * sqrtf((x * x) + (y * y) + (z * z)));
		}
		
		float Dot(const Vector4& rhs) const {
			return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w));
		}

		Vector4 Cross(const Vector4& rhs) const {
			Vector4 temp = *this;
			temp.x = (y * temp.z) - (z * temp.y);
			temp.y = (z * temp.x) - (x * temp.z);
			temp.z = (x * temp.y) - (y * temp.x);
		}

		/* @todo static Vector3 Cross(const Vector4& first, const Vector4& second) */

		void Normalise() {
			float mag = this->Magnitude();
			x = (x / mag) * w; y = (y / mag) * w; z = (z / mag) * w; w = (w / mag) * w;
		}

		void SafeNormalise() {
			if (this->Magnitude() != 0) {
				Normalise();
			}
			return;
		}

		Vector4 Normalised() const {
			Vector4 temp = *this;
			temp.Normalise();
			return temp;
		}

		Vector4 SafeNormalised() const {
			Vector4 temp = *this;
			temp.SafeNormalise();
			return temp;
		}

		/**
		 * Returns a Vector containing the sum of each component added to
		 * the other vector's component.
		 *
		 * @param rhs The other component.
		 * @return The Vector containing the sums of the components.
		 */
		Vector4 operator +(const Vector4& rhs) const;

		/**
		 * Assigns and returns the result of this Vector added to the other
		 * Vector.
		 *
		 * @param rhs The other Vector.
		 * @return The reference to this Vector after addition.
		 */
		Vector4& operator +=(const Vector4& rhs);

		/**
		 * Returns a Vector containing the difference of each component when
		 * subtracted from the other vector's component.
		 *
		 * @param rhs The other component.
		 * @return The Vector containing the differences of the components.
		 */
		Vector4 operator -(const Vector4& rhs) const;

		/**
		 * Returns a Vector containing the difference of each component when
		 * subtracted from the other vector's component.
		 *
		 * @param rhs The other component.
		 * @return The Vector containing the differences of the components.
		 */
		Vector4& operator -=(const Vector4& rhs);

		/**
		 * Assigns and returns this Vector scaled by the scalar value.
		 *
		 * @param rhs The scalar.
		 * @return Reference to this Vector after scaling.
		 */
		Vector4 operator *(float rhs) const;

		/* @note (float * Vector4) implemented as a free-function below */


		/**
		 * Returns true if every component is equal to the other in the other vector
		 *
		 * See also: Equals() for approximate equality.
		 * @param rhs The other Vector.
		 * @return True if equal, otherwise false.
		 */
		Vector4& operator *=(float rhs);

		// @note (float * Vector4) implemented as a free-function below

		/**
		 * Returns a new Vector where each component is divided by the value
		 *
		 * @param rhs The divisor.
		 * @return The Vector after division.
		 */
		Vector4 operator /(float rhs) const;

		/**
		 * Assigns and returns this Vector after dividing its components.
		 *
		 * @param rhs The divisor.
		 * @return Reference to this Vector after division.
		 */
		Vector4 operator /=(float rhs);

		/**
		 * Returns true if every component is equal to the other in the other vector
		 *
		 * See also: Equals() for approximate equality.
		 * @param rhs The other Vector.
		 * @return True if equal, otherwise false.
		 */
		bool operator == (const Vector4& rhs) const;

		/**
		 * Returns true if any component is NOT equal to the other in the other vector
		 *
		 * @param rhs The other Vector.
		 * @return True if inequal, otherwise false.
		 */
		bool operator != (const Vector4& rhs) const;

		/**
		 * Returns true if every component is approximately equal to the other in the other vector
		 *
		 * @param rhs The other Vector.
		 * @param Tolerence The maximum difference between any component being compared.
		 * @return True if approximately equal, otherwise false.
		 */
		bool Equals(const Vector4& rhs, float Tolerance = MAX_FLOAT_DELTA) const {
			Vector4 distance = { x - rhs.x,y - rhs.y,z - rhs.z,w - rhs.w };
			distance.Absolute();
			return((distance.x < Tolerance) && (distance.y < Tolerance) && (distance.z < Tolerance) && (distance.w < Tolerance));
		}

		/**
		 * Returns this Vector as a formatted string.
		 *
		 * @return A comma separated Vector with its components.
		 */
		std::string ToString() const {
			return "x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z) + ", w: " + std::to_string(w);
		}

		//
		// OPTIONAL
		//

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
		Vector4 operator *(const Vector4& rhs) const;

		/**
		 * Assigns and returns this Vector where each component is multiplied by
		 * the component from the other vector
		 *
		 * @param rhs The other Vector.
		 * @return Reference to this Vector's components multiplied by the component from the other vector.
		 */
		Vector4& operator *=(const Vector4& rhs);

		/**
		 * Returns a new Vector where each component is divided by the component from the other vector
		 *
		 * @param The other Vector.
		 * @return A copy of this Vector's components divided by the component from the other vector.
		 */
		Vector4 operator /(const Vector4& rhs) const;

		/**
		 * Assigns and returns this Vector after dividing it by the other vector
		 *
		 * @param rhs The other vector.
		 * @return Reference to this Vector's components divided by the component from the other vector.
		 */
		Vector4& operator /=(const Vector4& rhs);

		/**
		 * Returns a copy of this Vector after negating its components.
		 *
		 * @param rhs The other vector.
		 * @return A copy of this Vector after negating its components.
		 */
		Vector4 operator -() const;

		/**
		 * Returns a reference to one of the components of this Vector when
		 * accessed as though it were an array of floats.
		 *
		 * @param dim The index or dimension (X would be 0, Y would be 1...)
		 * @return Reference to the specified element.
		 */
		float& operator [](int dim);

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
	inline Vector4 operator*(float scalar, const Vector4& vector);
}
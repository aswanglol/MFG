#pragma once


//
// 1. System Includes (i.e., in your compiler, or OS)
// 2. Libraries
// 3. Your Libraries
// 4. Your Project
//

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

		/**
		 * Initializes all members to zero
		 */
		Vector3()
		{
			x = y = z = 0;
		}

		/**
		 * Initializes members to the given values
		 *
		 * @param inX Value for x
		 * @param inY Value for y
		 * @param inZ Value for z
		 */
		Vector3(float inX, float inY, float inZ)
		{
			x = inX;
			y = inY;
			z = inZ;
		}

		/**
		 * Initializes a Vector3, copying the X and Y elements from the given
		 * Vector2 object.
		 *
		 * The Z value will be zero by default or as specified.
		 *
		 * @param Vec2 The Vector2 whose X and Y will be copied.
		 */
		Vector3(const Vector2& Vec2, float InZ = 0) : x(Vec2.x), y(Vec2.y), z(InZ) {}

		/**
		 * Returns the magnitude of this Vector
		 *
		 * @return The magnitude of this Vector.
		 */
		float Magnitude() const;

		/**
		 * Returns the dot product of these vectors.
		 *
		 * @param rhs The other Vector.
		 * @return The dot product of this Vector and the other.
		 */
		float Dot(const Vector3& rhs) const;
		/**
		 * Returns the dot product of these vectors.
		 *
		 * @param first The first operand.
		 * @param second The second operand.
		 * @return  The dot product of these Vectors.
		 */
		static float Dot(const Vector3& first, const Vector3& second);

		/**
		 * Returns a Vector that is perpendicular to both this Vector and the other.
		 *
		 * @param rhs The other Vector.
		 * @details A Vector that is perpendicular to both this Vector and the other.
		 */
		Vector3 Cross(const Vector3& rhs) const;

		/**
		 * Returns a Vector that is perpendicular to both Vectors.
		 *
		 * @param rhs The first Vector.
		 * @param rhs The second Vector.
		 * @details A Vector that is perpendicular to both Vectors.
		 */
		static Vector3 Cross(const Vector3& first, const Vector3& second);

		/**
		 * Normalises this vector, modifying its length to be 1 while retaining the same direction.
		 *
		 * @details Does NOT check for zero-length vectors, which are invalid to normalise.
		 *
		 * See also: SafeNormalise().
		 */
		void Normalise();

		/**
		 * Safely normalises this vector, modifying its length to be 1 while retaining the same direction
		 * unless its length is zero, in which case its members will be set to zero.
		 *
		 * @details Does NOT check for zero-length vectors, which are invalid to normalise.
		 *
		 * See also: SafeNormalise().
		 */
		void SafeNormalise();

		/**
		 * Returns a normalized copy of this vector.
		 *
		 * See also: SafeNormalised()
		 * @return A normalized copy.
		 */
		Vector3 Normalised() const;

		/**
		 * Returns a normalized copy of this vector or returns it as-is if too small to n
		 *
		 * @return A normalized copy if possible.
		 */
		Vector3 SafeNormalised() const;

		/**
		 * Returns a Vector containing the sum of each component added to
		 * the other vector's component.
		 *
		 * @param rhs The other component.
		 * @return The Vector containing the sums of the components.
		 */
		Vector3 operator +(const Vector3& rhs) const;

		/**
		 * Assigns and returns the result of this Vector added to the other
		 * Vector.
		 *
		 * @param rhs The other Vector.
		 * @return The reference to this Vector after addition.
		 */
		Vector3& operator +=(const Vector3& rhs);

		/**
		 * Returns a Vector containing the difference of each component when
		 * subtracted from the other vector's component.
		 *
		 * @param rhs The other component.
		 * @return The Vector containing the differences of the components.
		 */
		Vector3 operator -(const Vector3& rhs) const;

		/**
		 * Returns a Vector containing the difference of each component when
		 * subtracted from the other vector's component.
		 *
		 * @param rhs The other component.
		 * @return The Vector containing the differences of the components.
		 */
		Vector3& operator -=(const Vector3& rhs);

		/**
		 * Returns a new Vector where each component is scaled by the scalar value
		 *
		 * @param rhs The scalar.
		 * @return The scaled Vector.
		 */
		Vector3 operator *(float rhs) const;

		/**
		 * Assigns and returns this Vector scaled by the scalar value.
		 *
		 * @param rhs The scalar.
		 * @return Reference to this Vector after scaling.
		 */
		Vector3& operator *=(float rhs);

		/* @note: (float * Vector3) implemented as a free-function below */

		/**
		 * Returns a new Vector where each component is divided by the value
		 *
		 * @param rhs The divisor.
		 * @return The Vector after division.
		 */
		Vector3 operator /(float rhs) const;

		/**
		 * Assigns and returns this Vector after dividing its components.
		 *
		 * @param rhs The divisor.
		 * @return Reference to this Vector after division.
		 */
		Vector3 operator /=(float rhs);

		/**
		 * Returns true if every component is equal to the other in the other vector
		 *
		 * See also: Equals() for approximate equality.
		 * @param rhs The other Vector.
		 * @return True if equal, otherwise false.
		 */
		bool operator == (const Vector3& rhs) const;

		/**
		 * Returns true if any component is NOT equal to the other in the other vector
		 *
		 * @param rhs The other Vector.
		 * @return True if inequal, otherwise false.
		 */
		bool operator != (const Vector3& rhs) const;

		/**
		 * Returns true if every component is approximately equal to the other in the other vector
		 *
		 * @param rhs The other Vector.
		 * @param Tolerence The maximum difference between any component being compared.
		 * @return True if approximately equal, otherwise false.
		 */
		bool Equals(const Vector3& rhs, float Tolerance = MAX_FLOAT_DELTA) const;

		/**
		 * Returns this Vector as a formatted string.
		 *
		 * @return A comma separated Vector with its components.
		 */
		std::string ToString() const;

		/**
		 * Implicit conversion to Vector2, truncating the Z value entirely.
		 */
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

	/**
	 * Returns the distance between two Points.
	 *
	 * @details This Vector is one of those Points.
	 * @param other The other Point.
	 * @return The distance between those points.
	 */
	float Distance(const Vector3& other) const;

	/**
	 * Returns the squared distance between two Points.
	 *
	 * @details This Vector is one of those Points.
	 * @param other The other Point.
	 * @return The squared distance between those points.
	 */
	float DistanceSqr(const Vector3& other) const;

	/**
	 * Returns the distance between two Points.
	 *
	 * @param other A Point.
	 * @param other The other Point.
	 * @return The distance between those points.
	 */
	static float Distance(const Vector3& start, const Vector3& end);

	/**
	 * Returns the squared distance between two Points.
	 *
	 * @param other A Point.
	 * @param other The other Point.
	 * @return The distance between those points.
	 */
	static float DistanceSqr(const Vector3& start, const Vector3& end);

	/**
	 * Returns the acute angle between two Points expressed in Radians.
	 *
	 * @param other The other Point.
	 * @return The acute angle between those points.
	 */
	float AngleBetween(const Vector3& other) const;
};

/**
 * Returns a new Vector where each component is scaled by the scalar value
 * @param scalar The scalar.
 * @param vector The Vector.
 * @return The scaled Vector.
 */
inline Vector3 operator*(float scalar, const Vector3& vector);
}
Vector4
#pragma once

//
// 1. System Includes (i.e., in your compiler, or OS)
// 2. Libraries
// 3. Your Libraries
// 4. Your Project
//

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

		/**
		 * Initializes all members to zero
		 */
		Vector4()
		{
			x = y = z = w = 0;
		}

		/**
		 * Initializes members to the given values
		 *
		 * @param inX Value for x
		 * @param inY Value for y
		 * @param inZ Value for z
		 * @param inW Value for W
		 */
		Vector4(float inX, float inY, float inZ, float inW)
		{
			x = inX;
			y = inY;
			z = inZ;
			w = inW;
		}

		/* @todo Allow construction from Vector3 */

		/**
		 * @brief Returns the magnitude of this Vector
		 * @return The magnitude of this Vector.
		 */
		float Magnitude() const;

		/**
		 * @brief Returns the dot product of these vectors.
		 * @param rhs The other Vector.
		 * @return The dot product of this Vector and the other.
		 */
		float Dot(const Vector4& rhs) const;

		/* @todo static float Dot(const Vector4& first, const Vector4& second) */

		/**
		 * Returns a Vector that is perpendicular to both this Vector and the other.
		 *
		 * This is the implementation for Vector3 objects. The W component is
		 * not considered and will be set to 0.
		 *
		 * @param rhs The other Vector.
		 * @details A Vector that is perpendicular to both this Vector and the other.
		 */
		Vector4 Cross(const Vector4& rhs) const;

		/* @todo static Vector3 Cross(const Vector4& first, const Vector4& second) */

		/**
		 * Normalises this vector, modifying its length to be 1 while retaining the same direction.
		 *
		 * @details Does NOT check for zero-length vectors, which are invalid to normalise.
		 *
		 * See also: SafeNormalise().
		 */
		void Normalise();

		/**
		 * Safely normalises this vector, modifying its length to be 1 while retaining the same direction
		 * unless its length is zero, in which case its members will be set to zero.
		 *
		 * @details Does NOT check for zero-length vectors, which are invalid to normalise.
		 *
		 * See also: SafeNormalise().
		 */
		void SafeNormalise();

		/**
		 * Returns a normalized copy of this vector.
		 *
		 * See also: SafeNormalised()
		 * @return A normalized copy.
		 */
		Vector4 Normalised() const;

		/**
		 * Returns a normalized copy of this vector or returns it as-is if too small to n
		 *
		 * @return A normalized copy if possible.
		 */
		Vector4 SafeNormalised() const;

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
		bool Equals(const Vector4& rhs, float Tolerance = MAX_FLOAT_DELTA) const;

		/**
		 * Returns this Vector as a formatted string.
		 *
		 * @return A comma separated Vector with its components.
		 */
		std::string ToString() const;

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
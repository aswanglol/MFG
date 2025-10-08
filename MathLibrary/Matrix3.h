#pragma once
#include "Vector2.h"
#include "Vector3.h"

namespace MathClasses
{
	struct Matrix3
	{
		union
		{
			struct
			{
				float m1, m2, m3, m4, m5, m6, m7, m8, m9;
			};

			float v[9];
			float mm[3][3];
			Vector3 axis[3];
		};

		/**
		 * Initializes all members to zero
		 */
		Matrix3();

		Matrix3(float inM1, float inM2, float inM3, float inM4, float inM5, float inM6, float inM7, float inM8, float inM9) {
			m1 = inM1; m2 = inM2; m3 = inM3; m4 = inM4; m5 = inM5; m6 = inM6; m7 = inM7; m8 = inM8; m9 = inM9;
		}

		Matrix3(float* inArr) {
			for (int i = 0; i < 9; i++) {
				v[i] = inArr[i];
			}
		}

		static Matrix3 MakeIdentity() {
			return { 1.0f,0,0,0,1.0f,0,0,0,1.0f };
		}

		Matrix3 operator *(Matrix3 rhs) const {
			Matrix3 temp = *this;
			Vector3 r1 = { m1,m4,m7 };
			Vector3 r2 = { m2,m5,m8 };
			Vector3 r3 = { m3,m6,m9 };
			Vector3 c1 = { rhs.m1,rhs.m2,rhs.m3 };
			Vector3 c2 = { rhs.m4,rhs.m5,rhs.m6 };
			Vector3 c3 = { rhs.m7,rhs.m8,rhs.m9 };

			temp.m1 = r1.Dot(c1); temp.m4 = r1.Dot(c2); temp.m7 = r1.Dot(c3);
			temp.m2 = r2.Dot(c1); temp.m5 = r2.Dot(c2); temp.m8 = r2.Dot(c3);
			temp.m3 = r3.Dot(c1); temp.m6 = r3.Dot(c2); temp.m9 = r3.Dot(c3);

			return temp;
		}

		/**
		 * Assigns and returns the result of this Matrix multiplied against the
		 * other Matrix.
		 *
		 * @param rhs The other Matrix.
		 * @return The reference to this Matrix after multiplication.
		 */
		Matrix3& operator *=(Matrix3 rhs);

		/**
		 * Multiplies this matrix against the given Vector3, treating it like
		 * a 3x1 matrix.
		 *
		 * @param rhs The vector
		 * @return The product of multiplying the 3x3 by a 3x1
		 */
		Vector3 operator *(Vector3 rhs) const;

		/**
		 * Multiplies this matrix against the given Vector2, treating it like
		 * a 3x1 matrix where its third element, normally Vector3.z, is 1.0.
		 *
		 * @param rhs The vector
		 * @return The product of multiplying the 3x3 by a 3x1, then truncating
		 *		   it to a 2x1.
		 */
		Vector2 operator *(Vector2 rhs) const;

		/**
		 * Returns true if every component is exactly equal to the other.
		 *
		 * See also: Equals() for approximate equality.
		 *
		 * @param rhs The other Matrix.
		 * @return True if equal, otherwise false.
		 */
		bool operator == (const Matrix3& rhs) const;

		/**
		 * Returns true if any component is not exactly equal to the other.
		 *
		 * @param rhs The other Matrix.
		 * @return True if equal, otherwise false.
		 */
		bool operator != (const Matrix3& rhs) const;

		/**
		 * Returns true if every component is approximately equal to the other.
		 *
		 * @param rhs The other Matrix.
		 * @return True if equal, otherwise false.
		 */
		bool Equals(const Matrix3& rhs, float Tolerance = MAX_FLOAT_DELTA) const;

		/**
		 * Returns this as a formatted string.
		 *
		 * @return A comma separated Vector with its components.
		 */
		std::string ToString() const;

		/**
		 * Transform Factory Functions
		 */

		 // Raylib 2D utilizes a left-handed coordinate system where:
		 // - x+ is RIGHT
		 // - y+ is DOWN

		 /**
		  * Creates a translation matrix that translates on the given X and Y
		  * axis.
		  *
		  * For use with 2-D math.
		  *
		  * @param x Amount to translate by on the X-axis.
		  * @param y Amount to translate by on the Y-axis.

		  * @return The translation matrix.
		  */
		static Matrix3 MakeTranslation(float x, float y);

		/**
		 * Creates a translation matrix that translates on the given X and Y
		 * axes. No translation on the Z-axis.
		 *
		 * For use with 2-D math.
		 *
		 * @param vec A Vector containing the amount to translate by on the X, Y, and Z axes.
		 * @return The translation matrix.
		 */
		static Matrix3 MakeTranslation(Vector2 vec);

		/**
		 * Creates a translation matrix that translates on the given X, Y, and
		 * Z-axes.
		 *
		 * For use with 3-D math.
		 *
		 * @param x Amount to translate by on the X-axis.
		 * @param y Amount to translate by on the Y-axis.
		 * @param z Amount to translate by on the Z-axis.
		 * @return The translation matrix.
		 */
		static Matrix3 MakeTranslation(float x, float y, float z);

		/**
		 * Creates a translation matrix that translates on the given X, Y, and
		 * Z-axes.
		 *
		 * For use with 3-D math.
		 *
		 * @param vec A Vector containing the amount to translate by on the X, Y, and Z axes.
		 * @return The translation matrix.
		 */
		static Matrix3 MakeTranslation(Vector3 vec);

		/**
		 * Creates a rotation matrix that rotates around the X-axis
		 *
		 * @param Rotation around the X-axis, expressed in radians.
		 * @return The rotation matrix.
		 */
		static Matrix3 MakeRotateX(float a);

		/**
		 * Creates a rotation matrix that rotates around the Y-axis
		 *
		 * @param Rotation around the Y-axis, expressed in radians.
		 * @return The rotation matrix.
		 */
		static Matrix3 MakeRotateY(float a);

		/**
		 * Creates a rotation matrix that rotates around the Z-axis
		 *
		 * @param Rotation around the Z-axis, expressed in radians.
		 * @return The rotation matrix.
		 */
		static Matrix3 MakeRotateZ(float a);

		/**
		 * Creates a rotation matrix that applies a pitch, yaw, roll rotation
		 *
		 * Combined in a pitch, then yaw, then roll.
		 *
		 * @param pitch Amount to pitch, expressed in radians.
		 * @param yaw	Amount to yaw, expressed in radians.
		 * @param roll	Amount to roll, expressed in radians.
		 * @return The rotation matrix.
		 */
		static Matrix3 MakeEuler(float pitch, float yaw, float roll);

		/**
		 * Creates a rotation matrix that applies a pitch, yaw, roll rotation
		 * expressed as the X, Y, and Z components of a Vector.
		 *
		 * @param rot Vector containing how much to pitch (X), yaw (Y), and roll (Z)
		 * @return The rotation matrix.
		 */
		static Matrix3 MakeEuler(Vector3 rot);

		/**
		 * Creates a scaling matrix that applies to the X and Y axes.
		 *
		 * The third column is reserved for translation.
		 *
		 * For use with 2D-maths.
		 *
		 * @param xScale Scalar for the X-axis.
		 * @param yScale Scalar for the Y-axis.
		 * @return The scaling matrix.
		 */
		static Matrix3 MakeScale(float xScale, float yScale);

		/**
		 * Creates a scaling matrix that applies to the X, Y, and Z axis with
		 * no homogeneous coordinates, not allowing for any translation.
		 *
		 * For use with 3D-maths.
		 *
		 * @param xScale Scalar for the X-axis.
		 * @param yScale Scalar for the Y-axis.
		 * @return The scaling matrix.
		 */
		static Matrix3 MakeScale(float xScale, float yScale, float zScale);

		/**
		 * Creates a scaling matrix that applies to the X, Y, and Z axis with
		 * no homogeneous coordinates, not allowing for any translation. The
		 * amount to scale by on each axis is expressed as the components of
		 * a Vector's X, Y, and Z.
		 *
		 * For use with 3D-maths.
		 *
		 * @param scale Scale factor expressed as a Vector.
		 * @return The scaling matrix.
		 */
		static Matrix3 MakeScale(Vector3 scale);

		/*
		 * OPTIONAL
		 */

		 /**
		  * Transposes the matrix, swapping the values along the diagonal defined
		  * as m1, m5, m9.
		  *
		  * In other words, it turns its columns into rows.
		  *
		  * @return The transposed matrix.
		  */
		Matrix3 Transposed() const;

		/**
		 * Accesses the matrix as though it were an array of floats in columns.
		 *
		 * @param dim The index (accessed by "columns").
		 * @return Returns a reference to the element at the requested index.
		 */
		float& operator [](int dim);

		/**
		 * Accesses the matrix as though it were an array of floats in columns.
		 *
		 * @param dim The index (accessed by "columns").
		 * @return Returns a const reference to the element at the requested index.
		 */
		const float& operator [](int dim) const;

		/**
		 * Casts the matrix as though it were an array of floats in columns.
		 *
		 * @return Returns a float* pointing to the first element of the "array".
		 */
		operator float* ();

		/**
		 * Casts the matrix as though it were an array of floats in columns.
		 *
		 * @return Returns a const float* pointing to the first element of the "array".
		 */
		operator const float* () const;
	};
}
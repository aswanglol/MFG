#pragma once

#include <cmath>

namespace MathClasses
{
	/* Maximum tolerance for comparing floats
	 *
	 * @details Alternatively written as "1.e-4f" or read as "1 times 10 to the
	 * power of -4".
	 */
	constexpr float MAX_FLOAT_DELTA = 0.0001f;
	/* The former is a constant equivalent to Unreal Engine's default threshold.
	 *
	 * We can ensure this is applicable to our environment by using a
	 * static_assert, which is checked at compile time.
	 */
	static_assert((1.e-4f) == MAX_FLOAT_DELTA);

	template<typename T>
	inline float ApproximatelyEquals(const T& a, const T& b, const T& Threshold = MAX_FLOAT_DELTA)
	{
		return std::abs(a - b) < Threshold;
	}

	inline float AngleFrom2D(float x, float y)
	{
		return atan2(y, x);
	}

	template<typename T, typename A>
	T Lerp(const T& Start, const T& End, const A& Alpha)
	{
		T Dist = End - Start;
		return Start + Dist * Alpha;
	}

	/* Constant for Pi
	 *
	 * @details Prefer C++ STDLIB
	 */
	[[deprecated]]
	constexpr float Pi = 3.14159265358979323846264338327950288f;

	// Deg2Rad
	constexpr float Deg2Rad = Pi * 2.0f / 360.0f;

	// Rad2Deg
	constexpr float Rad2Deg = 1.0f / Deg2Rad;
}
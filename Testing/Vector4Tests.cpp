#include "CppUnitTest.h"

#include "MathLibraryTests.h"
#include "MathUnitTestAssert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using aie::test::CustomAssert;
using MathClasses::Vector4;
using MathClasses::ApproximatelyEquals;
using MathClasses::MAX_FLOAT_DELTA;

namespace MathLibraryTests
{
	TEST_CLASS(Vector4Tests)
	{
	public:
		TEST_METHOD(Equality)
		{
			Vector4 vecA;
			vecA.x = 1;
			vecA.y = 2;
			vecA.z = 3;
			vecA.w = 4;

			Vector4 vecB;
			vecB.x = 1;
			vecB.y = 2;
			vecB.z = 3;
			vecB.w = 4;

			Vector4 vecC;
			vecC.x = 3;
			vecC.y = 2;
			vecC.z = 1;
			vecC.w = 0;

			Assert::AreEqual(vecA, vecB);
			Assert::AreEqual(vecB, vecA);
			Assert::AreNotEqual(vecA, vecC);
			Assert::AreNotEqual(vecC, vecA);
		}

		TEST_METHOD(InequalityOperator)
		{
			Vector4 vecA(1, 2, 3, 4);
			Vector4 vecB(5, 6, 7, 8);

			Vector4 vecA_duplicate(1, 2, 3, 4);

			CustomAssert::AreInequal(vecA, vecB);
			CustomAssert::AreInequal(vecB, vecA); // (symmetric)

			CustomAssert::AreNotInequal(vecA, vecA_duplicate);
		}

		TEST_METHOD(EqualsFunction)
		{
			Vector4 vecA;
			vecA.x = 1;
			vecA.y = 2;
			vecA.z = 3;
			vecA.w = 4;

			Vector4 vecB;
			vecB.x = 1;
			vecB.y = 2;
			vecB.z = 3;
			vecB.w = 4;

			Vector4 vecC;
			vecC.x = 5;
			vecC.y = 6;
			vecC.z = 7;
			vecC.w = 8;

			CustomAssert::AreEqualsMember(vecA, vecB);		// TRUE, two equivalent values
			CustomAssert::AreEqualsMember(vecB, vecA);		// TRUE, symmetric
			CustomAssert::AreNotEqualsMember(vecA, vecC);
			CustomAssert::AreNotEqualsMember(vecC, vecA);
		}
		TEST_METHOD(ConstructorDefault)
		{
			Vector4 vec;
			Assert::AreEqual(0.f, vec.x);
			Assert::AreEqual(0.f, vec.y);
			Assert::AreEqual(0.f, vec.z);
			Assert::AreEqual(0.f, vec.w);
		}

		TEST_METHOD(ConstructorFloat)
		{
			Vector4 vec(1.f, 2.f, 3.f, 4.f);
			Assert::AreEqual(1.f, vec.x);
			Assert::AreEqual(2.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
			Assert::AreEqual(4.f, vec.w);
		}

		TEST_METHOD(Magnitude)
		{
			{
				Vector4 v4a(13.5f, -48.23f, 862, 0);
				float mag4 = v4a.Magnitude();
				Assert::AreEqual(863.453735352f, mag4, MAX_FLOAT_DELTA);
			}
			{
				Vector4 v4a(0, 0, 0, 0);
				float mag4 = v4a.Magnitude();
				Assert::AreEqual(0.0f, mag4, MAX_FLOAT_DELTA);
			}
		}

		TEST_METHOD(Normalised)
		{
			Vector4 v4a(243, -48.23f, 862, 22.2f);
			Vector4 v4b = v4a.Normalised();
			CustomAssert::AreEqualsMember(Vector4(0.270852f, -0.053758f, 0.960800f, 0.024745f), v4b);
		}

		TEST_METHOD(Normalise)
		{
			Vector4 v4a(243, -48.23f, 862, 22.2f);
			v4a.Normalise();
			CustomAssert::AreEqualsMember(Vector4(0.270852f, -0.053758f, 0.960800f, 0.024745f), v4a);
		}

		TEST_METHOD(Dot)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			float dot4 = v4a.Dot(v4b);

			Assert::AreEqual(-10468.9375f, dot4, 0.0001f);
		}

		TEST_METHOD(Cross)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			Vector4 v4c = v4a.Cross(v4b);

			CustomAssert::AreEqualsMember(Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0), v4c);
		}
	};

	TEST_CLASS(Vector4Tests_Operator)
	{
		TEST_METHOD(Add)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			Vector4 v4c = v4a + v4b;

			CustomAssert::AreEqualsMember(Vector4(18.5f, -44.24f, 850, 1), v4c);
		}

		TEST_METHOD(Subtract)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			Vector4 v4c = v4a - v4b;

			CustomAssert::AreEqualsMember(Vector4(8.5f, -52.22f, 874, -1), v4c);
		}

		TEST_METHOD(SubtractAssign)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4b(5, 3.99f, -12, 1);
			v4a -= v4b;

			CustomAssert::AreEqualsMember(Vector4(8.5f, -52.22f, 874, -1), v4a);
		}
		TEST_METHOD(MultiplyScalarPost)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4c = v4a * 4.89f;

			CustomAssert::AreEqualsMember(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4c);
		}

		TEST_METHOD(MultiplyScalarPostAssign)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			v4a *= 4.89f;

			CustomAssert::AreEqualsMember(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4a);
		}

		TEST_METHOD(MultiplyScalarPre)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 0);
			Vector4 v4c = 4.89f * v4a;

			CustomAssert::AreEqualsMember(Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0), v4c);
		}

		TEST_METHOD(ScalarDivide)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 344.2f);
			Vector4 v4c = v4a / 0.256f;

			CustomAssert::AreEqualsMember(Vector4(52.734371f, -188.398422f, 3367.187256f, 1344.531250f), v4c);
		}

		TEST_METHOD(ScalarDivideAssign)
		{
			Vector4 v4a(13.5f, -48.23f, 862, 344.2f);
			v4a /= 0.256f;

			CustomAssert::AreEqualsMember(Vector4(52.734371f, -188.398422f, 3367.187256f, 1344.531250f), v4a);
		}
	};
}

namespace MathLibraryTests_OPTIONAL
{
	TEST_CLASS(Vector4Tests_Optional)
	{
		TEST_METHOD(SafeNormalised)
		{
			Vector4 v4a(0, 0, 0, 0);
			Vector4 v4b = v4a.SafeNormalised();
			CustomAssert::AreEqualsMember(Vector4(0, 0, 0, 0), v4b);
		}

		TEST_METHOD(SafeNormalise)
		{
			Vector4 v4a(0, 0, 0, 0);
			v4a.SafeNormalise();
			CustomAssert::AreEqualsMember(Vector4(0, 0, 0, 0), v4a);
		}
	};

	TEST_CLASS(Vector4Tests_Optional_Operator)
	{
		TEST_METHOD(Subscript)
		{
			Vector4 v4a(0, 0, 0, 0);
			v4a[0] = 3;
			Assert::AreEqual(v4a[0], 3.f);
			v4a[1] = 4;
			Assert::AreEqual(v4a[1], 4.f);
			v4a[2] = 6;
			Assert::AreEqual(v4a[2], 6.f);
			v4a[3] = 9;
			Assert::AreEqual(v4a[3], 9.f);
		}

		TEST_METHOD(SubscriptReference)
		{
			const Vector4 v4a(13.5f, -48.23f, 862, 1.f);

			Assert::AreEqual(v4a[0], 13.5f);
			Assert::AreEqual(v4a[1], -48.23f);
			Assert::AreEqual(v4a[2], 862.f);
			Assert::AreEqual(v4a[3], 1.f);
		}

		TEST_METHOD(Cast)
		{
			Vector4 v4a(10, 2, 6, 12);

			float* ptrMutable = (float*)v4a;
			Assert::AreEqual(ptrMutable[0], 10.f);
			Assert::AreEqual(ptrMutable[1], 2.f);
			Assert::AreEqual(ptrMutable[2], 6.f);
			Assert::AreEqual(ptrMutable[3], 12.f);

			const float* ptrConst = (float*)v4a;
			Assert::AreEqual(ptrConst[0], 10.f);
			Assert::AreEqual(ptrConst[1], 2.f);
			Assert::AreEqual(ptrConst[2], 6.f);
			Assert::AreEqual(ptrConst[3], 12.f);
		}
	};
}

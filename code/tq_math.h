#pragma once

#include <math.h>

/*************
* Datatypes *
*************/

union tqVec2
{
	float values[2];
	struct
	{
		float x;
		float y;
	};
	struct
	{
		float u;
		float v;
	};
};

union tqVec3
{
	float values[3];
	struct
	{
		tqVec2 xy;
		float z;
	};
	struct
	{
		float x;
		float y;
		float z;
	};
	struct
	{
		float r;
		float g;
		float b;
	};
};

union tqVec4
{
	float values[4];
	struct
	{
		tqVec2 xy;
		float z;
		float w;
	};
	struct
	{
		tqVec3 xyz;
		float w;
	};
	struct
	{
		float x;
		float y;
		float z;
		float w;
	};
	struct
	{
		float r;
		float g;
		float b;
		float a;
	};
	struct
	{
		tqVec3 rgb;
		float a;
	};
};

union tqMatrix2x2
{
	float values[4];
	struct
	{
		float a11;
		float a12;
		float a21;
		float a22;
	};
};

union tqMatrix3x3
{
	float values[9];
	struct
	{
		float a11;
		float a12;
		float a13;
		float a21;
		float a22;
		float a23;
		float a31;
		float a32;
		float a33;
	};
};

union tqMatrix4x4
{
	float values[16];
	struct
	{
		float a11;
		float a12;
		float a13;
		float a14;
		float a21;
		float a22;
		float a23;
		float a24;
		float a31;
		float a32;
		float a33;
		float a34;
		float a41;
		float a42;
		float a43;
		float a44;
	};
};

union tqQuaternion
{
	float values[4];
	struct
	{
		float x;
		float y;
		float z;
		float w;
	};
};

/************
* Constants *
*************/

const float TQ_PI = 3.14159265358979323846f;

const tqVec2 TQ_VEC2_RIGHT = { 1.0f, 0.0f };
const tqVec2 TQ_VEC2_LEFT = { -1.0f, 0.0f };
const tqVec2 TQ_VEC2_UP = { 0.0f, 1.0f };
const tqVec2 TQ_VEC2_DOWN = { 0.0f, -1.0f };
const tqVec2 TQ_VEC2_ZERO = { 0.0f, 0.0f };

const tqVec3 TQ_VEC3_RIGHT = { 1.0f, 0.0f, 0.0f };
const tqVec3 TQ_VEC3_LEFT = { -1.0f, 0.0f, 0.0f };
const tqVec3 TQ_VEC3_UP = { 0.0f, 1.0f, 0.0f };
const tqVec3 TQ_VEC3_DOWN = { 0.0f, -1.0f, 0.0f };
const tqVec3 TQ_VEC3_BACK = { 0.0f, 0.0f, 1.0f };
const tqVec3 TQ_VEC3_FORWARD = { 0.0f, 0.0f, -1.0f };
const tqVec3 TQ_VEC3_ZERO = { 0.0f, 0.0f, 0.0f };

/**************************
* Operations & Functions *
**************************/

/* Float */

inline float
tqSin(float angle)
{
	return sin(angle);
}

inline float
tqCos(float angle)
{
	return cos(angle);
}

inline float
tqTan(float angle)
{
	return tan(angle);
}

inline float
tqSqrt(float angle)
{
	return sqrt(angle);
}

inline float
tqDegreesToRadians(float degrees)
{
	return degrees * TQ_PI / 180;
}

inline float
tqRadiansToDegrees(float radians)
{
	return radians * 180 / TQ_PI;
}

/* tqVec2 */

inline tqVec2
operator+(const tqVec2& lhs, const tqVec2& rhs)
{
	const tqVec2 result = { lhs.x + rhs.x, lhs.y + rhs.y };
	return result;
}

inline tqVec2
operator-(const tqVec2& lhs, const tqVec2& rhs)
{
	const tqVec2 result = { lhs.x - rhs.x, lhs.y - rhs.y };
	return result;
}

inline tqVec2
operator-(const tqVec2& v)
{
	const tqVec2 result = { -v.x, -v.y };
	return result;
}

inline tqVec2
operator*(const tqVec2& lhs, const tqVec2& rhs)
{
	const tqVec2 result =
	{
		lhs.x * rhs.x,
		lhs.y * rhs.y,
	};

	return result;
}

inline tqVec2
operator*(const tqMatrix2x2& lhs, const tqVec2& rhs)
{
	const tqVec2 result =
	{
		lhs.a11 * rhs.x + lhs.a12 * rhs.y,
		lhs.a21 * rhs.x + lhs.a22 * rhs.y
	};

	return result;
}

/* tqVec3 */

inline tqVec3
operator+(const tqVec3& lhs, const tqVec3& rhs)
{
	const tqVec3 result = { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
	return result;
}

inline tqVec3
operator-(const tqVec3& lhs, const tqVec3& rhs)
{
	const tqVec3 result = { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
	return result;
}

inline tqVec3
operator-(const tqVec3& v)
{
	const tqVec3 result = { -v.x, -v.y, -v.z };
	return result;
}

inline tqVec3
operator*(const tqVec3& lhs, const tqVec3& rhs)
{
	const tqVec3 result =
	{
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	};

	return result;
}

inline tqVec3
operator*(const tqMatrix3x3& lhs, const tqVec3& rhs)
{
	const tqVec3 result =
	{
		lhs.a11 * rhs.x + lhs.a12 * rhs.y + lhs.a13 * rhs.z,
		lhs.a21 * rhs.x + lhs.a22 * rhs.y + lhs.a23 * rhs.z,
		lhs.a31 * rhs.x + lhs.a32 * rhs.y + lhs.a33 * rhs.z
	};

	return result;
}

inline tqVec3
operator*(const tqMatrix4x4& lhs, const tqVec3& rhs)
{
	const tqVec3 result =
	{
		lhs.a11 * rhs.x + lhs.a12 * rhs.y + lhs.a13 * rhs.z + lhs.a14,
		lhs.a21 * rhs.x + lhs.a22 * rhs.y + lhs.a23 * rhs.z + lhs.a24,
		lhs.a31 * rhs.x + lhs.a32 * rhs.y + lhs.a33 * rhs.z + lhs.a34
	};

	return result;
}

inline tqVec3
operator*(const tqVec3& lhs, const float rhs)
{
	const tqVec3 result = { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
	return result;
}

inline tqVec3
operator*(const float lhs, const tqVec3& rhs)
{
	return rhs * lhs;
}

inline tqVec3
operator/(const tqVec3& lhs, const float& rhs)
{
	const tqVec3 result = { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
	return result;
}

inline float
tqDot(const tqVec3& lhs, const tqVec3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline tqVec3
tqCross(const tqVec3& lhs, const tqVec3& rhs)
{
	const tqVec3 result =
	{
		(lhs.y * rhs.z) - (lhs.z * rhs.y),
		(lhs.z * rhs.x) - (lhs.x * rhs.z),
		(lhs.x * rhs.y) - (lhs.y * rhs.x)
	};

	return result;
}

inline float
tqLengthVec3(const tqVec3& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline float
tqLengthSquaredVec3(const tqVec3& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline tqVec3
tqNormalizeVec3(tqVec3* v)
{
	const float invLength = 1.0 / tqLengthVec3(*v);

	v->x *= invLength;
	v->y *= invLength;
	v->z *= invLength;

	return *v;
}

inline tqVec3
tqNormalizedVec3(const tqVec3& v)
{
	const float invLength = 1.0 / tqLengthVec3(v);

	const tqVec3 result =
	{
		v.x * invLength,
		v.y * invLength,
		v.z * invLength,
	};

	return result;
}

inline float
tqDistanceVec3(const tqVec3& v1, const tqVec3& v2)
{
	return tqLengthVec3(v1 - v2);
}

inline float
tqDistanceSquaredVec3(const tqVec3& v1, const tqVec3& v2)
{
	return tqLengthSquaredVec3(v1 - v2);
}

inline tqVec3
tqLerpVec3(const tqVec3& v1, const tqVec3& v2, const float amount)
{
	const float diff = 1.0f - amount;

	const tqVec3 result =
	{
		diff * v1.x + amount * v2.x,
		diff * v1.y + amount * v2.y,
		diff * v1.z + amount * v2.z
	};

	return result;
}

/* tqQuaternion */

inline tqQuaternion
operator+(const tqQuaternion& lhs, const tqQuaternion& rhs)
{
	const tqQuaternion result =
	{
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z,
		lhs.w + rhs.w
	};

	return result;
}

inline tqQuaternion
operator-(const tqQuaternion& lhs, const tqQuaternion& rhs)
{
	const tqQuaternion result =
	{
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z,
		lhs.w - rhs.w
	};

	return result;
}

inline tqQuaternion
operator*(const tqQuaternion& lhs, const tqQuaternion& rhs)
{
	const tqQuaternion result =
	{
		lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x,
		lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z
	};

	return result;
}

inline tqQuaternion
operator*(const tqQuaternion& lhs, const float rhs)
{
	const tqQuaternion result =
	{
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs,
		lhs.w * rhs
	};

	return result;
}

inline tqQuaternion
operator*(const float lhs, const tqQuaternion& rhs)
{
	const tqQuaternion result =
	{
		rhs.x * lhs,
		rhs.y * lhs,
		rhs.z * lhs,
		rhs.w * lhs
	};

	return result;
}

inline float
tqLengthQuaternion(const tqQuaternion& q)
{
	return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

inline float
tqLengthSquaredQuaternion(const tqQuaternion& q)
{
	return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

inline tqQuaternion
tqNormalizedQuaternion(const tqQuaternion& q)
{
	const float invLength = 1.0 / tqLengthQuaternion(q);
	const tqQuaternion result =
	{
		q.x * invLength,
		q.y * invLength,
		q.z * invLength,
		q.w * invLength
	};

	return result;
}

inline tqQuaternion
tqQuaternionFromAxis(const float ax, const float ay, const float az, const float angle)
{
	const float halfRad = angle * TQ_PI / 360;
	const float halfSin = tqSin(halfRad);
	const float halfCos = tqCos(halfRad);
	const tqQuaternion result =
	{
		-ax * halfSin,
		-ay * halfSin,
		-az * halfSin,
		halfCos
	};

	return tqNormalizedQuaternion(result);
}

inline tqQuaternion
tqQuaternionFromAxis(const tqVec3& axis, const float angle)
{
	return tqQuaternionFromAxis(axis.x, axis.y, axis.z, angle);
}

inline tqQuaternion
tqQuaternionFromEuler(const float x, const float y, const float z)
{
	const float rx = x * TQ_PI / 360;
	const float ry = y * TQ_PI / 360;
	const float rz = z * TQ_PI / 360;

	const float sinX = -tqSin(rx);
	const float sinY = -tqSin(ry);
	const float sinZ = -tqSin(rz);

	const float cosX = tqCos(rx);
	const float cosY = tqCos(ry);
	const float cosZ = tqCos(rz);

	const float sinXsinY = sinX * sinY;
	const float sinXcosY = sinX * cosY;
	const float cosXcosY = cosX * cosY;
	const float cosXsinY = cosX * sinY;

	const tqQuaternion result =
	{
		cosXsinY * sinZ + sinXcosY * cosZ,
		cosXsinY * cosZ + sinXcosY * sinZ,
		cosXcosY * sinZ - sinXsinY * cosZ,
		cosXcosY * cosZ - sinXsinY * sinZ
	};

	return tqNormalizedQuaternion(result);
}

inline tqQuaternion
tqQuaternionFromEuler(const tqVec3& v)
{
	return tqQuaternionFromEuler(v.x, v.y, v.z);
}

inline tqQuaternion tqRotatedQuaternion(const tqQuaternion& q,
	const tqVec3& axis, const float angle)
{
	return tqNormalizedQuaternion(tqQuaternionFromAxis(axis, angle) * q);
}

inline float
tqDot(const tqQuaternion& lhs, const tqQuaternion& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

inline tqQuaternion
tqConjugateQuaternion(const tqQuaternion& q)
{
	const tqQuaternion result = { -q.x, -q.y, -q.z, q.w };

	return result;
}

inline tqQuaternion
tqInverseQuaternion(const tqQuaternion& q)
{
	const float invLengthSquared = 1.0 / tqLengthSquaredQuaternion(q);
	const tqQuaternion result =
	{
		-q.x * invLengthSquared,
		-q.y * invLengthSquared,
		-q.z * invLengthSquared,
		q.w * invLengthSquared
	};

	return result;
}


inline tqVec3
tqRotatedVec3(const tqVec3& v, const tqQuaternion& q)
{
    const tqVec3 u = { q.x, q.y, q.z };
	const float s = q.w;

    return 2.0f * tqDot(u, v) * u
          + (s*s - tqDot(u, u)) * v
          + 2.0f * s * tqCross(u, v);
}

inline tqVec3
tqForwardFromQuaternion(const tqQuaternion& q)
{
	return tqRotatedVec3(TQ_VEC3_BACK, q);
}

inline tqVec3
tqBackwardFromQuaternion(const tqQuaternion& q)
{
	return tqRotatedVec3(TQ_VEC3_FORWARD, q);
}

inline tqVec3
tqUpFromQuaternion(const tqQuaternion& q)
{
	return tqRotatedVec3(TQ_VEC3_UP, q);
}

inline tqVec3
tqDownFromQuaternion(const tqQuaternion& q)
{
	return tqRotatedVec3(TQ_VEC3_DOWN, q);
}

inline tqVec3
tqLeftFromQuaternion(const tqQuaternion& q)
{
	return tqRotatedVec3(TQ_VEC3_RIGHT, q);
}

inline tqVec3
tqRightFromQuaternion(const tqQuaternion& q)
{
	return tqRotatedVec3(TQ_VEC3_LEFT, q);
}

/* tqMatrix2x2 */

inline tqMatrix2x2
operator*(const tqMatrix2x2& lhs, const tqMatrix2x2& rhs)
{
	tqMatrix2x2 result;
	result.a11 = lhs.a11 * rhs.a11 + lhs.a12 * rhs.a21;
	result.a12 = lhs.a11 * rhs.a12 + lhs.a12 * rhs.a22;
	result.a21 = lhs.a21 * rhs.a11 + lhs.a22 * rhs.a21;
	result.a22 = lhs.a21 * rhs.a12 + lhs.a22 * rhs.a22;
	
	return result;
}

/* tqMatrix3x3 */

inline tqMatrix3x3
operator*(const tqMatrix3x3& lhs, const tqMatrix3x3& rhs)
{
	tqMatrix3x3 result;
	result.a11 = lhs.a11 * rhs.a11 + lhs.a12 * rhs.a21 + lhs.a13 * rhs.a31;
	result.a12 = lhs.a11 * rhs.a12 + lhs.a12 * rhs.a22 + lhs.a13 * rhs.a32;
	result.a13 = lhs.a11 * rhs.a13 + lhs.a12 * rhs.a23 + lhs.a13 * rhs.a33;
	result.a21 = lhs.a21 * rhs.a11 + lhs.a22 * rhs.a21 + lhs.a23 * rhs.a31;
	result.a22 = lhs.a21 * rhs.a12 + lhs.a22 * rhs.a22 + lhs.a23 * rhs.a32;
	result.a23 = lhs.a21 * rhs.a13 + lhs.a22 * rhs.a23 + lhs.a23 * rhs.a33;
	result.a31 = lhs.a31 * rhs.a11 + lhs.a32 * rhs.a21 + lhs.a33 * rhs.a31;
	result.a32 = lhs.a31 * rhs.a12 + lhs.a32 * rhs.a22 + lhs.a33 * rhs.a32;
	result.a33 = lhs.a31 * rhs.a13 + lhs.a32 * rhs.a23 + lhs.a33 * rhs.a33;
	
	return result;
}

/* tqMatrix4x4 */

inline tqMatrix4x4
operator*(const tqMatrix4x4& lhs, const tqMatrix4x4& rhs)
{
	tqMatrix4x4 result;

	/* First row */
	result.a11 = lhs.a11 * rhs.a11 + lhs.a12 * rhs.a21 + lhs.a13 * rhs.a31 + lhs.a14 * rhs.a41;
	result.a12 = lhs.a11 * rhs.a12 + lhs.a12 * rhs.a22 + lhs.a13 * rhs.a32 + lhs.a14 * rhs.a42;
	result.a13 = lhs.a11 * rhs.a13 + lhs.a12 * rhs.a23 + lhs.a13 * rhs.a33 + lhs.a14 * rhs.a43;
	result.a14 = lhs.a11 * rhs.a14 + lhs.a12 * rhs.a24 + lhs.a13 * rhs.a34 + lhs.a14 * rhs.a44;

	/* Second row */
	result.a21 = lhs.a21 * rhs.a11 + lhs.a22 * rhs.a21 + lhs.a23 * rhs.a31 + lhs.a24 * rhs.a41;
	result.a22 = lhs.a21 * rhs.a12 + lhs.a22 * rhs.a22 + lhs.a23 * rhs.a32 + lhs.a24 * rhs.a42;
	result.a23 = lhs.a21 * rhs.a13 + lhs.a22 * rhs.a23 + lhs.a23 * rhs.a33 + lhs.a24 * rhs.a43;
	result.a24 = lhs.a21 * rhs.a14 + lhs.a22 * rhs.a24 + lhs.a23 * rhs.a34 + lhs.a24 * rhs.a44;

	/* Third row */
	result.a31 = lhs.a31 * rhs.a11 + lhs.a32 * rhs.a21 + lhs.a33 * rhs.a31 + lhs.a34 * rhs.a41;
	result.a32 = lhs.a31 * rhs.a12 + lhs.a32 * rhs.a22 + lhs.a33 * rhs.a32 + lhs.a34 * rhs.a42;
	result.a33 = lhs.a31 * rhs.a13 + lhs.a32 * rhs.a23 + lhs.a33 * rhs.a33 + lhs.a34 * rhs.a43;
	result.a34 = lhs.a31 * rhs.a14 + lhs.a32 * rhs.a24 + lhs.a33 * rhs.a34 + lhs.a34 * rhs.a44;

	/* Fourth row */
	result.a41 = lhs.a41 * rhs.a11 + lhs.a42 * rhs.a21 + lhs.a43 * rhs.a31 + lhs.a44 * rhs.a41;
	result.a42 = lhs.a41 * rhs.a12 + lhs.a42 * rhs.a22 + lhs.a43 * rhs.a32 + lhs.a44 * rhs.a42;
	result.a43 = lhs.a41 * rhs.a13 + lhs.a42 * rhs.a23 + lhs.a43 * rhs.a33 + lhs.a44 * rhs.a43;
	result.a44 = lhs.a41 * rhs.a14 + lhs.a42 * rhs.a24 + lhs.a43 * rhs.a34 + lhs.a44 * rhs.a44;

	return result;
}

inline tqVec4
operator*(const tqMatrix4x4& lhs, const tqVec4& rhs)
{
	const tqVec4 result =
	{
		lhs.a11 * rhs.x + lhs.a12 * rhs.y + lhs.a13 * rhs.z + lhs.a14 * rhs.w,
		lhs.a21 * rhs.x + lhs.a22 * rhs.y + lhs.a23 * rhs.z + lhs.a24 * rhs.w,
		lhs.a31 * rhs.x + lhs.a32 * rhs.y + lhs.a33 * rhs.z + lhs.a34 * rhs.w,
		lhs.a41 * rhs.x + lhs.a42 * rhs.y + lhs.a43 * rhs.z + lhs.a44 * rhs.w
	};
	return result;
}

inline tqMatrix4x4
tqCreateMatrix4x4(void)
{
	const tqMatrix4x4 result =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	return result;
}

inline tqMatrix4x4
tqCreateMatrix4x4(const float d)
{
	const tqMatrix4x4 result =
	{
		d, 0, 0, 0,
		0, d, 0, 0,
		0, 0, d, 0,
		0, 0, 0, d
	};

	return result;
}

inline tqMatrix4x4
tqCreateMatrix4x4(const tqQuaternion& q)
{
	const float xx2 = 2.0f * q.x * q.x;
	const float xy2 = 2.0f * q.x * q.y;
	const float xz2 = 2.0f * q.x * q.z;
	const float xw2 = 2.0f * q.x * q.w;
	const float yy2 = 2.0f * q.y * q.y;
	const float yz2 = 2.0f * q.y * q.z;
	const float yw2 = 2.0f * q.y * q.w;
	const float zz2 = 2.0f * q.z * q.z;
	const float zw2 = 2.0f * q.z * q.w;

	const tqMatrix4x4 result =
	{
		1.0f - (yy2 + zz2), xy2 + zw2, xz2 - yw2, 0.0f,
		xy2 - zw2, 1.0f - (xx2 + zz2), yz2 + xw2, 0.0f,
		xz2 + yw2, yz2 - xw2, 1.0f - (xx2 + yy2), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return result;
}

inline tqMatrix4x4
tqTransposeMatrix4x4(const tqMatrix4x4& m)
{
	const tqMatrix4x4 result =
	{
		m.a11, m.a21, m.a31, m.a41,
		m.a12, m.a22, m.a32, m.a42,
		m.a13, m.a23, m.a33, m.a43,
		m.a14, m.a24, m.a34, m.a44
	};

	return result;
}

inline tqMatrix4x4
tqTranslateMatrix4x4(const tqMatrix4x4& m, const tqVec3& v)
{
	const tqMatrix4x4 translate =
	{
		1, 0, 0, v.x,
		0, 1, 0, v.y,
		0, 0, 1, v.z,
		0, 0, 0, 1
	};

	return translate * m;
}

inline tqMatrix4x4
tqTranslateMatrix4x4(const tqVec3& v)
{
	const tqMatrix4x4 result =
	{
		1, 0, 0, v.x,
		0, 1, 0, v.y,
		0, 0, 1, v.z,
		0, 0, 0, 1
	};

	return result;
}

inline tqMatrix4x4
tqScaleMatrix4x4(const tqMatrix4x4& m, const tqVec3& v)
{
	const tqMatrix4x4 scale =
	{
		v.x, 0, 0, 0,
		0, v.y, 0, 0,
		0, 0, v.z, 0,
		0, 0, 0, 1
	};

	return scale * m;
}

inline tqMatrix4x4
tqScaleMatrix4x4(const tqVec3& v)
{
	const tqMatrix4x4 result =
	{
		v.x, 0, 0, 0,
		0, v.y, 0, 0,
		0, 0, v.z, 0,
		0, 0, 0, 1
	};

	return result;
}

inline tqMatrix4x4
tqMirrorMatrix4x4(const tqMatrix4x4& m)
{
	const tqMatrix4x4 scale =
	{
		-1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, -1, 0,
		0, 0, 0, 1
	};

	return scale * m;
}

inline tqMatrix4x4
tqMirrorMatrix4x4(void)
{
	const tqMatrix4x4 result =
	{
		-1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, -1, 0,
		0, 0, 0, 1
	};

	return result;
}

inline tqMatrix4x4 
tqOrthoMatrix4x4(const float left, const float right, const float bottom, const float top, const float zNear, const float zFar)
{
	const float width = right - left;
	const float height = top - bottom;
	const float depth = zFar - zNear;

	const tqMatrix4x4 result =
	{
		2.0f/width, 0, 0, -(right + left) / width,
		0, 2.0f/height, 0, -(top + bottom) / height,
		0, 0, -2.0f/depth, -(zFar + zNear) / depth,
		0, 0, 0, 0
	};

	return result;
}

inline tqMatrix4x4 
tqPerspectiveMatrix4x4(const float fovy, const float aspect, const float zNear, const float zFar)
{
	const float angle = (fovy / 2.0f) * TQ_PI / 180.0f;
	const float yScale = 1.0f / tqTan(angle);
	const float xScale = yScale / aspect;
	const float depth = zFar - zNear;

	const tqMatrix4x4 result =
	{
		xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, (zNear + zFar) / depth, -2.0f * zNear * zFar / depth,
		0, 0, 1, 0
	};

	return result;
}

inline tqVec4
tqPerspectiveDivideVec4(const tqVec4& v)
{
	const tqVec4 result = 
	{
		v.x / v.w,
		v.y / v.w,
		v.z / v.w,
		v.w		
	};
	
	return v; 
}

inline tqMatrix4x4 
tqLookAtMatrix4x4(const tqVec3& eye, const tqVec3& look, const tqVec3& up)
{
	const tqVec3 l = tqNormalizedVec3(look);
	const tqVec3 r = tqCross(look, up);
	const tqVec3 u = tqNormalizedVec3(tqCross(r, l));

	const tqMatrix4x4 result =
	{
		r.x, u.x, -l.x, -r.x * eye.x - u.x * eye.y + l.x * eye.z,
		r.y, u.y, -l.y, -r.y * eye.x - u.y * eye.y + l.y * eye.z,
		r.z, u.z, -l.z, -r.z * eye.x - u.z * eye.y + l.z * eye.z,
		0, 0, 0, 1,
	};

	return result;
}

inline tqMatrix4x4 
tqViewMatrix4x4(const tqVec3& position, const tqQuaternion& orientation)
{
	const tqVec3 r = tqRightFromQuaternion(orientation);
	const tqVec3 u = tqUpFromQuaternion(orientation);
	const tqVec3 f = tqForwardFromQuaternion(orientation);

	const tqMatrix4x4 result =
	{
		r.x, r.y, r.z, -r.x * position.x - r.y * position.y - r.z * position.z,
		u.x, u.y, u.z, -u.x * position.x - u.y * position.y - u.z * position.z,
		f.x, f.y, f.z, -f.x * position.x - f.y * position.y - f.z * position.z,
		0, 0, 0, 1
	};

	return result;
}

/* From normalized coordinates to screen space */
inline tqMatrix4x4 
tqViewportMatrix4x4(int x, int y, int width, int height)
{
	const float halfWidth = (float) width / 2;
	const float halfHeight = (float) height / 2;
	
	const tqMatrix4x4 result =
	{
		halfWidth,	0,				0,		x + halfWidth,
		0,			-halfHeight,	0,		y + halfHeight,
		0, 			0, 				1,		0,
		0,			0,				0,		1
	};

	return result;
}
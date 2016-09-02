#pragma once

#include <stdint.h>

#include "tq_math.h"

enum tqShapeType
{
	TQ_SHAPE_TYPE_UNDEFINED = 0,	
	TQ_SHAPE_TYPE_SPHERE = 1,
	TQ_SHAPE_TYPE_AABB = 2,
	TQ_SHAPE_TYPE_RAY = 3,
	
	TQ_SHAPE_TYPE_BEGIN_RANGE = TQ_SHAPE_TYPE_SPHERE,
	TQ_SHAPE_TYPE_END_RANGE = TQ_SHAPE_TYPE_AABB,
	TQ_SHAPE_TYPE_RANGE_SIZE = (TQ_SHAPE_TYPE_AABB - TQ_SHAPE_TYPE_SPHERE + 1),	
	TQ_SHAPE_TYPE_MAX_ENUM = 0x7FFFFFFF	
};

union tqShape
{	
	struct tqSphere
	{
		tqShapeType type;		
		tqVec3 origin;
		float radius;
		float __padding[2];
	};
	
	struct tqRay
	{
		tqShapeType type;
		tqVec3 origin;
		tqVec3 direction;	
	};	
};

struct tqIntersectionData
{
	tqVec3 point;
	tqVec3 normal;
	float distance;
	bool intersects;
};

inline tqIntersectionData
tqIntersectRaySphere(const tqRay* const* r, const tqSphere const* s)
{
	tqIntersectionData result = {};
	tqVec3 m = p - s.c;
	float b = tqDot(m, d);
	float c = tqDot(m, m) - s.r * s.r;
	if (c > 0.0f && b > 0.0f) {
		return result;
	}
	
	float discr = b*b - c;
	if (discr < 0.0f) {
		return result;
	}
	
	t = -b - tqSqrt(discr);
	
	if (t < 0.0f) {
		t = 0.0f;
	}
	
	q = p + t * d;
	
	return result;	
}

inline IntersectionData
tqIntersectSphereRay(const tqSphere const* s, const tqRay* const* r)
{
	return tqIntersectRaySphere(r, s);
}

inline tqIntersectionData 
tqIntersect(const tqShape* const* s1, const* tqShape const* s2)
{
	tqIntersectionData result = {};
	
	switch(s1->type)
	{
		case TQ_SHAPE_TYPE_RAY: 
		{
			switch(s2->type)
			{
				case TQ_SHAPE_TYPE_SPHERE: return tqIntersectRaySphere(s1, s2);
				default: return result;
			}
		}
		
		case TQ_SHAPE_TYPE_SPHERE:
		{
			switch(s2->type)
			{
				case TQ_SHAPE_TYPE_RAY: return tqIntersectSphereRay(s1, s2);
				default: return result;				
			}
		}
	}
	
	return result;
}
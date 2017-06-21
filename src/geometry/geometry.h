#pragma once

# include "../core/vec.h"
# include <iostream>

namespace yuki {
	/* all basic classes */
	class Vector;
	class Normal;
	class Point;

	class Vector : public vec3<Float> {
	private:
	public:
		// constructors
		Vector() {}
		Vector(Float a, Float b, Float c) : vec3(a, b, c) {}
		Vector(const vec3<Float> &v) : vec3(v.x, v.y, v.z) {}
		Vector(const Vector &v) : vec3(v.x, v.y, v.z) {}
		explicit Vector(const Normal &n);
		explicit Vector(const Point &p);
		// de-constructor
		~Vector() {}
	};


	class Point : public vec3<Float> {
	private:
	public:
		// constructors
		Point() {}
		Point(Float a, Float b, Float c) : vec3(a, b, c) {}
		Point(const vec3<Float> &v) : vec3(v) {}
		Point(const Point &p) : vec3(p.x, p.y, p.z) {}
		// de-constructor
		~Point() {}
	};
	inline Float distance(const Point &p1, const Point &p2) {
		return (p1 - p2).length();
	}
	inline Float distance_squared(const Point &p1, const Point &p2) {
		return (p1 - p2).length_squared();
	}


	class Normal : public vec3<Float> {
	public:
		// constructors
		Normal() {}
		Normal(Float a, Float b, Float c) : vec3(a, b, c) {}
		Normal(const vec3 &v) : vec3(v) {}
		Normal(const Normal &n) : vec3(n.x, n.y, n.z) {}
		explicit Normal(const Vector& v) : vec3(v.x, v.y, v.z) {}
		// de-constructor
		~Normal() {}
	};
	inline Normal face_forward(const Normal &n, const Vector &v) {
		if ((n * v) < 0.f) return -n; else return n;
	}



}
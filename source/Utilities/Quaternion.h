#pragma once

#include "VMath.h"

namespace util {
	struct Quaternion {
		float x, y, z, w;
		Quaternion();
		Quaternion(const float nx, const float ny, const float nz, const float nw);
		const Quaternion operator * (const float f) const;
		const Quaternion operator / (const float f) const;
		const Quaternion operator + (const Quaternion q) const;
		const Quaternion operator - (const Quaternion q) const;
		const Quaternion operator * (const Quaternion q) const;
		const Quaternion operator / (const Quaternion q) const;
		const void operator *= (const float f);
		const void operator /= (const float f);
		const void operator += (const Quaternion q);
		const void operator -= (const Quaternion q);
		const void operator *= (const Quaternion q);
		const void operator /= (const Quaternion q);
		const float Normal() const;
		const Quaternion Conjugate() const;
		const Quaternion Inverse() const;
		const Quaternion operator () (const Quaternion q) const;
	};

	const Quaternion rotation(const Vec3f v, const float a);
};

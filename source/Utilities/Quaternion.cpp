#include "Quaternion.h"

namespace util {
	Quaternion::Quaternion() {
	}

	Quaternion::Quaternion(const float nx, const float ny, const float nz, const float nw) {
		x = nx;
		y = ny;
		z = nz;
		w = nw;
	}

	const Quaternion Quaternion::operator * (const float f) const {
		return(Quaternion(
			x * f,
			y * f,
			z * f,
			w * f
		));
	}

	const Quaternion Quaternion::operator / (const float f) const {
		return(Quaternion(
			x / f,
			y / f,
			z / f,
			w / f
		));
	}

	const Quaternion Quaternion::operator + (const Quaternion q) const {
		return(Quaternion(
			x + q.x,
			y + q.y,
			z + q.z,
			w + q.w
		));
	}

	const Quaternion Quaternion::operator - (const Quaternion q) const {
		return(Quaternion(
			x - q.x,
			y - q.y,
			z - q.z,
			w - q.w
		));
	}

	const Quaternion Quaternion::operator * (const Quaternion q) const {
		return(Quaternion(
			w * q.x + x * q.w + y * q.z - z * q.y,
			w * q.y + y * q.w + z * q.x - x * q.z,
			w * q.z + z * q.w + x * q.y - y * q.x,
			w * q.w - x * q.x - y * q.y - z * q.z
		));
	}

	const Quaternion Quaternion::operator / (const Quaternion q) const {
		return(*this * q.Inverse());
	}

	const void Quaternion::operator *= (const float f) {
		*this = *this * f;
	}

	const void Quaternion::operator /= (const float f) {
		*this = *this / f;
	}

	const void Quaternion::operator += (const Quaternion q) {
		*this = *this + q;
	}

	const void Quaternion::operator -= (const Quaternion q) {
		*this = *this - q;
	}

	const void Quaternion::operator *= (const Quaternion q) {
		*this = *this * q;
	}

	const void Quaternion::operator /= (const Quaternion q) {
		*this = *this / q;
	}

	const float Quaternion::Normal() const {
		return(x * x + y * y + z * z + w * w);
	}

	const Quaternion Quaternion::Conjugate() const {
		return(Quaternion(
			-x,
			-y,
			-z,
			w
		));
	}

	const Quaternion Quaternion::Inverse() const {
		return(Conjugate() / Normal());
	}

	const Quaternion Quaternion::operator () (const Quaternion q) const {
		return(*this * q * Conjugate());
	}

	const Quaternion rotation(const Vec3f v, const float a) {
		float s = sin(a);
		float c = cos(a);
		return(Quaternion(
			s * v.x,
			s * v.y,
			s * v.z,
			c
		));
	}
};

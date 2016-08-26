#pragma once

#include <cmath>

namespace util {
	const float inf = 1.0 / 0.0;
	const float e = 2.7182818284f;
	const float pi = 3.1415926535f;
	const float fi = pi / 180;

	template <typename Type>
	const Type Abs(const Type a) {
		return(a < 0 ? -a : a);
	}

	template <typename Type>
	const Type Min(const Type a, const Type b) {
		return(a < b ? a : b);
	}

	template <typename Type>
	const Type Max(const Type a, const Type b) {
		return(a > b ? a : b);
	}

	template <typename Type>
	const void Clamp(Type & value, const Type min, const Type max) {
		value = Min(Max(value, min), max);
	}

	template <typename Type, typename Scalar>
	const Type Mix(const Type a, const Type b, const Scalar f) {
		return(a + (b - a) * f);
	}

	struct Vec2f;
	struct Vec3f;
	struct Vec4f;
	struct Mat2f;
	struct Mat3f;
	struct Mat4f;

	struct Vec2f {
		float x, y;
		Vec2f();
		Vec2f(float nx, float ny);
		Vec2f(Vec3f v);
		Vec2f(Vec4f v);
		Vec2f operator - () const;
		Vec2f operator + (Vec2f v) const;
		Vec2f operator - (Vec2f v) const;
		Vec2f operator * (float f) const;
		Vec2f operator / (float f) const;
		void operator += (Vec2f v);
		void operator -= (Vec2f v);
		void operator *= (float f);
		void operator /= (float f);
		float * operator & ();
	};

	struct Vec3f {
		float x, y, z;
		Vec3f();
		Vec3f(float nx, float ny, float nz);
		Vec3f(Vec2f v);
		Vec3f(Vec4f v);
		Vec3f operator - () const;
		Vec3f operator + (Vec3f v) const;
		Vec3f operator - (Vec3f v) const;
		Vec3f operator * (float f) const;
		Vec3f operator / (float f) const;
		void operator += (Vec3f v);
		void operator -= (Vec3f v);
		void operator *= (float f);
		void operator /= (float f);
		float * operator & ();
	};

	struct Vec4f {
		float x, y, z, w;
		Vec4f();
		Vec4f(float nx, float ny, float nz, float nw);
		Vec4f(Vec2f v);
		Vec4f(Vec3f v);
		Vec4f operator - () const;
		Vec4f operator + (Vec4f v) const;
		Vec4f operator - (Vec4f v) const;
		Vec4f operator * (float f) const;
		Vec4f operator / (float f) const;
		void operator += (Vec4f v);
		void operator -= (Vec4f v);
		void operator *= (float f);
		void operator /= (float f);
		float * operator & ();
	};

	struct Mat2f {
		Vec2f x, y;
		Mat2f();
		Mat2f(Vec2f nx, Vec2f ny);
		Mat2f(Mat3f m);
		Mat2f(Mat4f m);
		Mat2f operator - ();
		Mat2f operator + (Mat2f m);
		Mat2f operator - (Mat2f m);
		Mat2f operator * (float f);
		Mat2f operator / (float f);
		void operator += (Mat2f m);
		void operator -= (Mat2f m);
		void operator *= (float f);
		void operator /= (float f);
		Mat2f operator * (Mat2f m);
		Vec2f operator * (Vec2f v);
		float * operator & ();
	};

	struct Mat3f {
		Vec3f x, y, z;
		Mat3f();
		Mat3f(Vec3f nx, Vec3f ny, Vec3f nz);
		Mat3f(Mat2f m);
		Mat3f(Mat4f m);
		Mat3f operator - ();
		Mat3f operator + (Mat3f m);
		Mat3f operator - (Mat3f m);
		Mat3f operator * (float f);
		Mat3f operator / (float f);
		void operator += (Mat3f m);
		void operator -= (Mat3f m);
		void operator *= (float f);
		void operator /= (float f);
		Mat3f operator * (Mat3f m);
		Vec2f operator * (Vec2f v);
		Vec3f operator * (Vec3f v);
		float * operator & ();
	};

	struct Mat4f {
		Vec4f x, y, z, w;
		Mat4f();
		Mat4f(Vec4f nx, Vec4f ny, Vec4f nz, Vec4f nw);
		Mat4f(Mat2f m);
		Mat4f(Mat3f m);
		Mat4f operator - ();
		Mat4f operator + (Mat4f m);
		Mat4f operator - (Mat4f m);
		Mat4f operator * (float f);
		Mat4f operator / (float f);
		void operator += (Mat4f m);
		void operator -= (Mat4f m);
		void operator *= (float f);
		void operator /= (float f);
		Mat4f operator * (Mat4f m);
		Vec2f operator * (Vec2f v);
		Vec3f operator * (Vec3f v);
		Vec4f operator * (Vec4f v);
		float * operator & ();
	};

	float vsqr(Vec2f v);
	float vsqr(Vec3f v);
	float vsqr(Vec4f v);

	float vlength(Vec2f v);
	float vlength(Vec3f v);
	float vlength(Vec4f v);

	Vec2f vnormal(Vec2f v);
	Vec3f vnormal(Vec3f v);
	Vec4f vnormal(Vec4f v);

	float vdot(Vec2f a, Vec2f b);
	float vdot(Vec3f a, Vec3f b);
	float vdot(Vec4f a, Vec4f b);

	float vcos(Vec2f a, Vec2f b);
	float vcos(Vec3f a, Vec3f b);
	float vcos(Vec4f a, Vec4f b);

	float vangle(Vec2f a, Vec2f b);
	float vangle(Vec3f a, Vec3f b);
	float vangle(Vec4f a, Vec4f b);

	float vdistance(Vec2f a, Vec2f b);
	float vdistance(Vec3f a, Vec3f b);
	float vdistance(Vec4f a, Vec4f b);

	float vdet(Vec2f a, Vec2f b);

	Vec3f vcross(Vec3f a, Vec3f b);

	float mdet(Mat2f m);
	float mdet(Mat3f m);
	float mdet(Mat4f m);

	Mat2f mtrans(Mat2f m);
	Mat3f mtrans(Mat3f m);
	Mat4f mtrans(Mat4f m);

	Mat2f mstar(Mat2f m);
	Mat3f mstar(Mat3f m);
	Mat4f mstar(Mat4f m);

	Mat2f minverse(Mat2f m);
	Mat3f minverse(Mat3f m);
	Mat4f minverse(Mat4f m);
};

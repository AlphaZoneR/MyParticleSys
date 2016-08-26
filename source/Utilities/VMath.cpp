#include "VMath.h"
namespace util {
	Vec2f::Vec2f() {
	}

	Vec2f::Vec2f(float nx, float ny) {
		x = nx; y = ny;
	}

	Vec2f::Vec2f(Vec3f v) {
		x = v.x;
		y = v.y;
	}

	Vec2f::Vec2f(Vec4f v) {
		x = v.x;
		y = v.y;
	}

	Vec2f Vec2f::operator - () const {
		return(Vec2f(-x, -y));
	}

	Vec2f Vec2f::operator + (Vec2f v) const {
		return(Vec2f(x + v.x, y + v.y));
	}

	Vec2f Vec2f::operator - (Vec2f v) const {
		return(Vec2f(x - v.x, y - v.y));
	}

	Vec2f Vec2f::operator * (float f) const {
		return(Vec2f(x * f, y * f));
	}

	Vec2f Vec2f::operator / (float f) const {
		return(Vec2f(x / f, y / f));
	}

	void Vec2f::operator += (Vec2f v) {
		*this = *this + v;
	}

	void Vec2f::operator -= (Vec2f v) {
		*this = *this - v;
	}

	void Vec2f::operator *= (float f) {
		*this = *this * f;
	}

	void Vec2f::operator /= (float f) {
		*this = *this / f;
	}

	float * Vec2f::operator & () {
		return((float *)this);
	}

	Vec3f::Vec3f() {
	}

	Vec3f::Vec3f(float nx, float ny, float nz) {
		x = nx; y = ny; z = nz;
	}

	Vec3f::Vec3f(Vec2f v) {
		x = v.x;
		y = v.y;
		z = 0;
	}

	Vec3f::Vec3f(Vec4f v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vec3f Vec3f::operator - () const {
		return(Vec3f(-x, -y, -z));
	}

	Vec3f Vec3f::operator + (Vec3f v) const {
		return(Vec3f(x + v.x, y + v.y, z + v.z));
	}

	Vec3f Vec3f::operator - (Vec3f v) const {
		return(Vec3f(x - v.x, y - v.y, z - v.z));
	}

	Vec3f Vec3f::operator * (float f) const {
		return(Vec3f(x * f, y * f, z * f));
	}

	Vec3f Vec3f::operator / (float f) const {
		return(Vec3f(x / f, y / f, z / f));
	}

	void Vec3f::operator += (Vec3f v) {
		*this = *this + v;
	}

	void Vec3f::operator -= (Vec3f v) {
		*this = *this - v;
	}

	void Vec3f::operator *= (float f) {
		*this = *this * f;
	}

	void Vec3f::operator /= (float f) {
		*this = *this / f;
	}

	float * Vec3f::operator & () {
		return((float *)this);
	}

	Vec4f::Vec4f() {
	}

	Vec4f::Vec4f(float nx, float ny, float nz, float nw) {
		x = nx; y = ny; z = nz; w = nw;
	}

	Vec4f::Vec4f(Vec2f v) {
		x = v.x;
		y = v.y;
		z = 0;
		w = 0;
	}

	Vec4f::Vec4f(Vec3f v) {
		x = v.x;
		y = v.y;
		z = v.z;
		w = 0;
	}

	Vec4f Vec4f::operator - () const {
		return(Vec4f(-x, -y, -z, -w));
	}

	Vec4f Vec4f::operator + (Vec4f v) const {
		return(Vec4f(x + v.x, y + v.y, z + v.z, w + v.w));
	}

	Vec4f Vec4f::operator - (Vec4f v) const {
		return(Vec4f(x - v.x, y - v.y, z - v.z, w - v.w));
	}

	Vec4f Vec4f::operator * (float f) const {
		return(Vec4f(x * f, y * f, z * f, w * f));
	}

	Vec4f Vec4f::operator / (float f) const {
		return(Vec4f(x / f, y / f, z / f, w / f));
	}

	void Vec4f::operator += (Vec4f v) {
		*this = *this + v;
	}

	void Vec4f::operator -= (Vec4f v) {
		*this = *this - v;
	}

	void Vec4f::operator *= (float f) {
		*this = *this * f;
	}

	void Vec4f::operator /= (float f) {
		*this = *this / f;
	}

	float * Vec4f::operator & () {
		return((float *)this);
	}

	Mat2f::Mat2f() {
	}

	Mat2f::Mat2f(Vec2f nx, Vec2f ny) {
		x = nx; y = ny;
	}

	Mat2f::Mat2f(Mat3f m) {
		x = Vec2f(m.x);
		y = Vec2f(m.y);
	}

	Mat2f::Mat2f(Mat4f m) {
		x = Vec2f(m.x);
		y = Vec2f(m.y);
	}

	Mat2f Mat2f::operator - () {
		return(Mat2f(-x, -y));
	}

	Mat2f Mat2f::operator + (Mat2f m) {
		return(Mat2f(x + m.x, y + m.y));
	}

	Mat2f Mat2f::operator - (Mat2f m) {
		return(Mat2f(x - m.x, y - m.y));
	}

	Mat2f Mat2f::operator * (float f) {
		return(Mat2f(x * f, y * f));
	}

	Mat2f Mat2f::operator / (float f) {
		return(Mat2f(x / f, y / f));
	}

	void Mat2f::operator += (Mat2f m) {
		*this = *this + m;
	}

	void Mat2f::operator -= (Mat2f m) {
		*this = *this - m;
	}

	void Mat2f::operator *= (float f) {
		*this = *this * f;
	}

	void Mat2f::operator /= (float f) {
		*this = *this / f;
	}

	Mat2f Mat2f::operator * (Mat2f m) {
		return(Mat2f(Vec2f(x.x * m.x.x + y.x * m.x.y,
						   x.y * m.x.x + y.y * m.x.y),
					 Vec2f(x.x * m.y.x + y.x * m.y.y,
						   x.y * m.y.x + y.y * m.y.y)));
	}

	Vec2f Mat2f::operator * (Vec2f v) {
		return(Vec2f(x.x * v.x + y.x * v.y,
					 x.y * v.x + y.y * v.y));
	}

	float * Mat2f::operator & () {
		return((float *)this);
	}

	Mat3f::Mat3f() {
	}

	Mat3f::Mat3f(Vec3f nx, Vec3f ny, Vec3f nz) {
		x = nx; y = ny; z = nz;
	}

	Mat3f::Mat3f(Mat2f m) {
		x = Vec3f(m.x);
		y = Vec3f(m.y);
		z = Vec3f(0, 0, 1);
	}

	Mat3f::Mat3f(Mat4f m) {
		x = Vec3f(m.x);
		y = Vec3f(m.y);
		z = Vec3f(m.z);
	}

	Mat3f Mat3f::operator - () {
		return(Mat3f(-x, -y, -z));
	}

	Mat3f Mat3f::operator + (Mat3f m) {
		return(Mat3f(x + m.x, y + m.y, z + m.z));
	}

	Mat3f Mat3f::operator - (Mat3f m) {
		return(Mat3f(x - m.x, y - m.y, z - m.z));
	}

	Mat3f Mat3f::operator * (float f) {
		return(Mat3f(x * f, y * f, z * f));
	}

	Mat3f Mat3f::operator / (float f) {
		return(Mat3f(x / f, y / f, z / f));
	}

	void Mat3f::operator += (Mat3f m) {
		*this = *this + m;
	}

	void Mat3f::operator -= (Mat3f m) {
		*this = *this - m;
	}

	void Mat3f::operator *= (float f) {
		*this = *this * f;
	}

	void Mat3f::operator /= (float f) {
		*this = *this / f;
	}

	Mat3f Mat3f::operator * (Mat3f m) {
		return(Mat3f(Vec3f(x.x * m.x.x + y.x * m.x.y + z.x * m.x.z,
						   x.y * m.x.x + y.y * m.x.y + z.y * m.x.z,
						   x.z * m.x.x + y.z * m.x.y + z.z * m.x.z),
					 Vec3f(x.x * m.y.x + y.x * m.y.y + z.x * m.y.z,
						   x.y * m.y.x + y.y * m.y.y + z.y * m.y.z,
						   x.z * m.y.x + y.z * m.y.y + z.z * m.y.z),
					 Vec3f(x.x * m.z.x + y.x * m.z.y + z.x * m.z.z,
						   x.y * m.z.x + y.y * m.z.y + z.y * m.z.z,
						   x.z * m.z.x + y.z * m.z.y + z.z * m.z.z)));
	}

	Vec2f Mat3f::operator * (Vec2f v) {
		return(Vec2f(x.x * v.x + y.x * v.y + z.x,
					 x.y * v.x + y.y * v.y + z.y));
	}

	Vec3f Mat3f::operator * (Vec3f v) {
		return(Vec3f(x.x * v.x + y.x * v.y + z.x * v.z,
					 x.y * v.x + y.y * v.y + z.y * v.z,
					 x.z * v.x + y.z * v.y + z.z * v.z));
	}

	float * Mat3f::operator & () {
		return((float *)this);
	}

	Mat4f::Mat4f() {
	}

	Mat4f::Mat4f(Vec4f nx, Vec4f ny, Vec4f nz, Vec4f nw) {
		x = nx; y = ny; z = nz; w = nw;
	}

	Mat4f::Mat4f(Mat2f m) {
		x = Vec4f(m.x);
		y = Vec4f(m.y);
		z = Vec4f(0, 0, 1, 0);
		w = Vec4f(0, 0, 0, 1);
	}

	Mat4f::Mat4f(Mat3f m) {
		x = Vec4f(m.x);
		y = Vec4f(m.y);
		z = Vec4f(m.z);
		w = Vec4f(0, 0, 0, 1);
	}

	Mat4f Mat4f::operator - () {
		return(Mat4f(-x, -y, -z, -w));
	}

	Mat4f Mat4f::operator + (Mat4f m) {
		return(Mat4f(x + m.x, y + m.y, z + m.z, w + m.w));
	}

	Mat4f Mat4f::operator - (Mat4f m) {
		return(Mat4f(x - m.x, y - m.y, z - m.z, w - m.w));
	}

	Mat4f Mat4f::operator * (float f) {
		return(Mat4f(x * f, y * f, z * f, w * f));
	}

	Mat4f Mat4f::operator / (float f) {
		return(Mat4f(x / f, y / f, z / f, w / f));
	}

	void Mat4f::operator += (Mat4f m) {
		*this = *this + m;
	}

	void Mat4f::operator -= (Mat4f m) {
		*this = *this - m;
	}

	void Mat4f::operator *= (float f) {
		*this = *this * f;
	}

	void Mat4f::operator /= (float f) {
		*this = *this / f;
	}

	Mat4f Mat4f::operator * (Mat4f m) {
		return(Mat4f(Vec4f(x.x * m.x.x + y.x * m.x.y + z.x * m.x.z + w.x * m.x.w,
						   x.y * m.x.x + y.y * m.x.y + z.y * m.x.z + w.y * m.x.w,
						   x.z * m.x.x + y.z * m.x.y + z.z * m.x.z + w.z * m.x.w,
						   x.w * m.x.x + y.w * m.x.y + z.w * m.x.z + w.w * m.x.w),
					 Vec4f(x.x * m.y.x + y.x * m.y.y + z.x * m.y.z + w.x * m.y.w,
						   x.y * m.y.x + y.y * m.y.y + z.y * m.y.z + w.y * m.y.w,
						   x.z * m.y.x + y.z * m.y.y + z.z * m.y.z + w.z * m.y.w,
						   x.w * m.y.x + y.w * m.y.y + z.w * m.y.z + w.w * m.y.w),
					 Vec4f(x.x * m.z.x + y.x * m.z.y + z.x * m.z.z + w.x * m.z.w,
						   x.y * m.z.x + y.y * m.z.y + z.y * m.z.z + w.y * m.z.w,
						   x.z * m.z.x + y.z * m.z.y + z.z * m.z.z + w.z * m.z.w,
						   x.w * m.z.x + y.w * m.z.y + z.w * m.z.z + w.w * m.z.w),
					 Vec4f(x.x * m.w.x + y.x * m.w.y + z.x * m.w.z + w.x * m.w.w,
						   x.y * m.w.x + y.y * m.w.y + z.y * m.w.z + w.y * m.w.w,
						   x.z * m.w.x + y.z * m.w.y + z.z * m.w.z + w.z * m.w.w,
						   x.w * m.w.x + y.w * m.w.y + z.w * m.w.z + w.w * m.w.w)));
	}

	Vec2f Mat4f::operator * (Vec2f v) {
		return(Vec2f(x.x * v.x + y.x * v.y + z.x + w.x,
					 x.y * v.x + y.y * v.y + z.y + w.y));
	}

	Vec3f Mat4f::operator * (Vec3f v) {
		return(Vec3f(x.x * v.x + y.x * v.y + z.x * v.z + w.x,
					 x.y * v.x + y.y * v.y + z.y * v.z + w.y,
					 x.z * v.x + y.z * v.y + z.z * v.z + w.z));
	}

	Vec4f Mat4f::operator * (Vec4f v) {
		return(Vec4f(x.x * v.x + y.x * v.y + z.x * v.z + w.x * v.w,
					 x.y * v.x + y.y * v.y + z.y * v.z + w.y * v.w,
					 x.z * v.x + y.z * v.y + z.z * v.z + w.z * v.w,
					 x.w * v.x + y.w * v.y + z.w * v.z + w.w * v.w));
	}

	float * Mat4f::operator & () {
		return((float *)this);
	}

	float vsqr(Vec2f v) {
		return(v.x * v.x + v.y * v.y);
	}

	float vsqr(Vec3f v) {
		return(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	float vsqr(Vec4f v) {
		return(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	float vlength(Vec2f v) {
		return(sqrt(vsqr(v)));
	}

	float vlength(Vec3f v) {
		return(sqrt(vsqr(v)));
	}

	float vlength(Vec4f v) {
		return(sqrt(vsqr(v)));
	}

	Vec2f vnormal(Vec2f v) {
		float l = vlength(v);
		if (l) return(v / l);
		return(v);
	}

	Vec3f vnormal(Vec3f v) {
		float l = vlength(v);
		if (l) return(v / l);
		return(v);
	}

	Vec4f vnormal(Vec4f v) {
		float l = vlength(v);
		if (l) return(v / l);
		return(v);
	}

	float vdot(Vec2f a, Vec2f b) {
		return(a.x * b.x + a.y * b.y);
	}

	float vdot(Vec3f a, Vec3f b) {
		return(a.x * b.x + a.y * b.y + a.z * b.z);
	}

	float vdot(Vec4f a, Vec4f b) {
		return(a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	}

	float vcos(Vec2f a, Vec2f b) {
		return(vdot(vnormal(a), vnormal(b)));
	}

	float vcos(Vec3f a, Vec3f b) {
		return(vdot(vnormal(a), vnormal(b)));
	}

	float vcos(Vec4f a, Vec4f b) {
		return(vdot(vnormal(a), vnormal(b)));
	}

	float vangle(Vec2f a, Vec2f b) {
		return(acos(vcos(a, b)));
	}

	float vangle(Vec3f a, Vec3f b) {
		return(acos(vcos(a, b)));
	}

	float vangle(Vec4f a, Vec4f b) {
		return(acos(vcos(a, b)));
	}

	float vdistance(Vec2f a, Vec2f b) {
		return(vlength(a - b));
	}

	float vdistance(Vec3f a, Vec3f b) {
		return(vlength(a - b));
	}

	float vdistance(Vec4f a, Vec4f b) {
		return(vlength(a - b));
	}

	float vdet(Vec2f a, Vec2f b) {
		return(a.x * b.y - a.y * b.x);
	}

	Vec3f vcross(Vec3f a, Vec3f b) {
		return(Vec3f(a.y * b.z - b.y * a.z,
					 a.z * b.x - b.z * a.x,
					 a.x * b.y - b.x * a.y));
	}

	float mdet(Mat2f m) {
		return(m.x.x * m.y.y -
			   m.x.y * m.y.x);
	}

	float mdet(Mat3f m) {
		return(m.x.x * m.y.y * m.z.z +
			   m.x.y * m.y.z * m.z.x +
			   m.x.z * m.y.x * m.z.y -
			   m.x.x * m.y.y * m.z.z -
			   m.x.y * m.y.z * m.z.x);
	}

	float mdet(Mat4f m) {
		return(m.x.x * m.y.y * m.z.z * m.w.w +
			   m.x.x * m.y.z * m.z.w * m.w.y +
			   m.x.x * m.y.w * m.z.y * m.w.z -
			   m.x.x * m.y.y * m.z.w * m.w.z -
			   m.x.x * m.y.z * m.z.y * m.w.w -
			   m.x.x * m.y.w * m.z.z * m.w.y -
			   m.y.x * m.x.y * m.z.z * m.w.w -
			   m.y.x * m.x.z * m.z.w * m.w.y -
			   m.y.x * m.x.w * m.z.y * m.w.z +
			   m.y.x * m.x.y * m.z.w * m.w.z +
			   m.y.x * m.x.z * m.z.y * m.w.w +
			   m.y.x * m.x.w * m.z.z * m.w.y +
			   m.z.x * m.x.y * m.y.z * m.w.w +
			   m.z.x * m.x.z * m.y.w * m.w.y +
			   m.z.x * m.x.w * m.y.y * m.w.z -
			   m.z.x * m.x.y * m.y.w * m.w.z -
			   m.z.x * m.x.z * m.y.y * m.w.w -
			   m.z.x * m.x.w * m.y.z * m.w.y -
			   m.w.x * m.x.y * m.y.z * m.z.w -
			   m.w.x * m.x.z * m.y.w * m.z.y -
			   m.w.x * m.x.w * m.y.y * m.z.z +
			   m.w.x * m.x.y * m.y.w * m.z.z +
			   m.w.x * m.x.z * m.y.y * m.z.w +
			   m.w.x * m.x.w * m.y.z * m.z.y);
	}

	Mat2f mtrans(Mat2f m) {
		return(Mat2f(Vec2f(m.x.x, m.y.x),
					 Vec2f(m.x.y, m.y.y)));
	}

	Mat3f mtrans(Mat3f m) {
		return(Mat3f(Vec3f(m.x.x, m.y.x, m.z.x),
					 Vec3f(m.x.y, m.y.y, m.z.y),
					 Vec3f(m.x.z, m.y.z, m.z.z)));
	}

	Mat4f mtrans(Mat4f m) {
		return(Mat4f(Vec4f(m.x.x, m.y.x, m.z.x, m.w.x),
					 Vec4f(m.x.y, m.y.y, m.z.y, m.w.y),
					 Vec4f(m.x.z, m.y.z, m.z.z, m.w.z),
					 Vec4f(m.x.w, m.y.w, m.z.w, m.w.w)));
	}

	Mat2f mstar(Mat2f m) {
		return(Mat2f(Vec2f(m.y.y, m.x.y),
					 Vec2f(m.y.x, m.x.x)));
	}

	Mat3f mstar(Mat3f m) {
		return(Mat3f(Vec3f(m.y.y * m.z.z - m.y.z * m.z.y,
						   m.x.z * m.z.y - m.x.y * m.z.z,
						   m.x.y * m.y.z - m.x.z * m.y.y),
					 Vec3f(m.y.z * m.z.x - m.y.x * m.z.z,
						   m.x.x * m.z.z - m.x.z * m.z.x,
						   m.x.z * m.y.x - m.x.x * m.y.z),
					 Vec3f(m.y.x * m.z.y - m.y.y * m.z.x,
						   m.x.y * m.z.x - m.x.x * m.z.y,
						   m.x.x * m.y.y - m.x.y * m.y.x)));
	}

	Mat4f mstar(Mat4f m) {
		return(Mat4f(Vec4f(m.y.y * m.z.z * m.w.w +
						   m.z.y * m.w.z * m.y.w +
						   m.w.y * m.y.z * m.z.w -
						   m.y.y * m.w.z * m.z.w -
						   m.z.y * m.y.z * m.w.w -
						   m.w.y * m.z.z * m.y.w,
						   m.x.y * m.w.z * m.z.w +
						   m.z.y * m.x.z * m.w.w +
						   m.w.y * m.z.z * m.x.w -
						   m.x.y * m.z.z * m.w.w -
						   m.z.y * m.w.z * m.x.w -
						   m.w.y * m.x.z * m.z.w,
						   m.x.y * m.y.z * m.w.w +
						   m.y.y * m.w.z * m.x.w +
						   m.w.y * m.x.z * m.y.w -
						   m.x.y * m.w.z * m.y.w -
						   m.y.y * m.x.z * m.w.w -
						   m.w.y * m.y.z * m.x.w,
						   m.x.y * m.z.z * m.y.w +
						   m.y.y * m.x.z * m.z.w +
						   m.z.y * m.y.z * m.x.w -
						   m.x.y * m.y.z * m.z.w -
						   m.y.y * m.z.z * m.x.w -
						   m.z.y * m.x.z * m.y.w),
					 Vec4f(m.y.x * m.w.z * m.z.w +
						   m.z.x * m.y.z * m.w.w +
						   m.w.x * m.z.z * m.y.w -
						   m.y.x * m.z.z * m.w.w -
						   m.z.x * m.w.z * m.y.w -
						   m.w.x * m.y.z * m.z.w,
						   m.x.x * m.z.z * m.w.w +
						   m.z.x * m.w.z * m.x.w +
						   m.w.x * m.x.z * m.z.w -
						   m.x.x * m.w.z * m.z.w -
						   m.z.x * m.x.z * m.w.w -
						   m.w.x * m.z.z * m.x.w,
						   m.x.x * m.w.z * m.y.w +
						   m.y.x * m.x.z * m.w.w +
						   m.w.x * m.y.z * m.x.w -
						   m.x.x * m.y.z * m.w.w -
						   m.y.x * m.w.z * m.x.w -
						   m.w.x * m.x.z * m.y.w,
						   m.x.x * m.y.z * m.z.w +
						   m.y.x * m.z.z * m.x.w +
						   m.z.x * m.x.z * m.y.w -
						   m.x.x * m.z.z * m.y.w -
						   m.y.x * m.x.z * m.z.w -
						   m.z.x * m.y.z * m.x.w),
					 Vec4f(m.y.x * m.z.y * m.w.w +
						   m.z.x * m.w.y * m.y.w +
						   m.w.x * m.y.y * m.z.w -
						   m.y.x * m.w.y * m.z.w -
						   m.z.x * m.y.y * m.w.w -
						   m.w.x * m.z.y * m.y.w,
						   m.x.x * m.w.y * m.z.w +
						   m.z.x * m.x.y * m.w.w +
						   m.w.x * m.z.y * m.x.w -
						   m.x.x * m.z.y * m.w.w -
						   m.z.x * m.w.y * m.x.w -
						   m.w.x * m.x.y * m.z.w,
						   m.x.x * m.y.y * m.w.w +
						   m.y.x * m.w.y * m.x.w +
						   m.w.x * m.x.y * m.y.w -
						   m.x.x * m.w.y * m.y.w -
						   m.y.x * m.x.y * m.w.w -
						   m.w.x * m.y.y * m.x.w,
						   m.x.x * m.z.y * m.y.w +
						   m.y.x * m.x.y * m.z.w +
						   m.z.x * m.y.y * m.x.w -
						   m.x.x * m.y.y * m.z.w -
						   m.y.x * m.z.y * m.x.w -
						   m.z.x * m.x.y * m.y.w),
					 Vec4f(m.y.x * m.w.y * m.z.z +
						   m.z.x * m.y.y * m.w.z +
						   m.w.x * m.z.y * m.y.z -
						   m.y.x * m.z.y * m.w.z -
						   m.z.x * m.w.y * m.y.z -
						   m.w.x * m.y.y * m.z.z,
						   m.x.x * m.z.y * m.w.z +
						   m.z.x * m.w.y * m.x.z +
						   m.w.x * m.x.y * m.z.z -
						   m.x.x * m.w.y * m.z.z -
						   m.z.x * m.x.y * m.w.z -
						   m.w.x * m.z.y * m.x.z,
						   m.x.x * m.w.y * m.y.z +
						   m.y.x * m.x.y * m.w.z +
						   m.w.x * m.y.y * m.x.z -
						   m.x.x * m.y.y * m.w.z -
						   m.y.x * m.w.y * m.x.z -
						   m.w.x * m.x.y * m.y.z,
						   m.x.x * m.y.y * m.z.z +
						   m.y.x * m.z.y * m.x.z +
						   m.z.x * m.x.y * m.y.z -
						   m.x.x * m.z.y * m.y.z -
						   m.y.x * m.x.y * m.z.z -
						   m.z.x * m.y.y * m.x.z)));
	}

	Mat2f minverse(Mat2f m) {
		return(mstar(m) / mdet(m));
	}

	Mat3f minverse(Mat3f m) {
		return(mstar(m) / mdet(m));
	}

	Mat4f minverse(Mat4f m) {
		return(mstar(m) / mdet(m));
	}

	Mat3f mrotate(Vec3f axis, float angle) {
		axis = vnormal(axis);
		float s = sin(angle);
		float c = cos(angle);
		float x = axis.x;
		float y = axis.y;
		float z = axis.z;
		float xx = x * x;
		float yy = y * y;
		float zz = z * z;
		float xy = x * y * (1 - c);
		float xz = x * z * (1 - c);
		float yz = y * z * (1 - c);
		return(Mat3f(
			Vec3f(xx + (yy + zz) * c, xy + z * s, xz - y * s),
			Vec3f(xy - z * s, yy + (xx + zz) * c, yz + x * s),
			Vec3f(xz + y * s, yz - x * s, zz + (xx + yy) * c)
		));
	}

	Mat2f mface(Vec2f direction) {
		Vec2f normal = Vec2f(-direction.y, direction.x);
		return(Mat2f(direction, vnormal(normal)));
	}

	Vec2f minside(Vec2f v, Mat2f base) {
		return(Vec2f(
			mdet(Mat2f(v, base.y)),
			mdet(Mat2f(base.x, v))
		) / mdet(base));
	}

	Mat4f identity() {
		return(Mat4f(
			Vec4f(1, 0, 0, 0),
			Vec4f(0, 1, 0, 0),
			Vec4f(0, 0, 1, 0),
			Vec4f(0, 0, 0, 1)
		));
	}
};

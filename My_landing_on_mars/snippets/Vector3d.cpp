/*
 * Vector3d.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: moritz
 */

#include <math.h>
#include "Vector3d.h"

Vector3d::Vector3d(float x, float y, float z) {
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vector3d::~Vector3d() {

}

Vector3d Vector3d::operator *(float scale) const {
	return Vector3d(v[0]*scale, v[1]*scale, v[2]*scale);
}

Vector3d Vector3d::operator /(float scale) const {
	return Vector3d(v[0]/scale, v[1]/scale, v[2]/scale);
}

Vector3d Vector3d::operator +(const Vector3d& vec) const {
	return Vector3d(v[0]+vec.v[0], v[1]+vec.v[1], v[2]+vec.v[2]);
}

Vector3d Vector3d::operator -(const Vector3d& vec) const {
	return Vector3d(v[0]-vec.v[0], v[1]-vec.v[1], v[2]-vec.v[2]);
}

Vector3d Vector3d::cross(const Vector3d& vec) const {
	return Vector3d(v[1]*vec.v[2]-v[2]*vec.v[1],
			v[2]*vec.v[0]-v[0]*vec.v[2],
			v[0]*vec.v[1]-v[1]*vec.v[0]);
}

float& Vector3d::operator [](int index) {
	return v[index];
}

float Vector3d::operator [](int index) const {
	return v[index];
}

Vector3d Vector3d::normalize() {
	float m = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
	v[0] /= m;
	v[1] /= m;
	v[2] /= m;
	return *this;
}

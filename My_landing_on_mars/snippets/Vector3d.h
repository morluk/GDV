/*
 * Vector3d.h
 *
 *  Created on: Nov 1, 2014
 *      Author: moritz
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

class Vector3d {
public:
	Vector3d() {};
	Vector3d(float, float, float);
	virtual ~Vector3d();
	float &operator[](int index);
	float operator[](int index) const;
	Vector3d operator*(float scale) const;
	Vector3d operator/(float scale) const;
	Vector3d operator+(const Vector3d &vec) const;
	Vector3d operator-(const Vector3d &vec) const;
	Vector3d cross(const Vector3d& vec) const;
	Vector3d normalize();
private:
	float v[3];
};

#endif /* VECTOR3D_H_ */

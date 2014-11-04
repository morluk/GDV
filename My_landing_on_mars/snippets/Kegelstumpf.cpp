#include <GL/freeglut.h>
#include <math.h>
#include "Kegelstumpf.h"
#include "Vector3d.h"

void Kegelstumpf(GLfloat extent, GLfloat proportion) {
	//Oberseite
	Vector3d pl[74];
//	float xpl[74], zpl[74];

	pl[0][0] = 0.0;
	pl[0][2] = 0.0;
//	xpl[0] = 0.0;
//	zpl[0] = 0.0;
	for (int i = 1; i <= 73; ++i) {
		pl[i][0] = extent / proportion
				* (float) sin(6.28318530718 * (i - 1) / 72.0);
		pl[i][1] = extent;
		pl[i][2] = extent / proportion
				* (float) cos(6.28318530718 * (i - 1) / 72.0);
//		zpl[i] = extent / proportion * (float) cos(6.28318530718 * (i - 1) / 72.0);
//		xpl[i] = extent / proportion * (float) sin(6.28318530718 * (i - 1) / 72.0);
	}
	//Unterseite
	Vector3d pm[74];
//	float xpm[74], zpm[74];

	pm[0][0] = 0.0;
	pm[0][2] = 0.0;
//	xpm[0] = 0.0f;
//	zpm[0] = 0.0f;
	for (int i = 1; i <= 73; i++) {
		pm[i][0] = extent * (float) sin(6.28318530718 * (i - 1) / 72.0);
		pm[i][1] = 0.0;
		pm[i][2] = extent * (float) cos(6.28318530718 * (i - 1) / 72.0);
//		zpm[i] = extent * (float) cos(6.28318530718 * (i - 1) / 72.0);
//		xpm[i] = extent * (float) sin(6.28318530718 * (i - 1) / 72.0);
	}

	Vector3d normals[73];
	for (int i = 0; i < 73; i++) {
		Vector3d vecA = Vector3d(pm[i + 1] - pl[i + 1]);
		Vector3d vecB;
		if (i < 72)
			vecB = Vector3d(pm[i + 2] - pm[i + 1]);
		if (72 == i)
			vecB = Vector3d(pm[1] - pm[i + 1]);
		normals[i] = (vecB-vecA).normalize();
	}

	glBegin(GL_QUAD_STRIP);
	for (int i = 1; i <= 73; i++) {
		glNormal3f(normals[i-1][0],normals[i-1][1],normals[i-1][2]);
		glVertex3f(pl[i][0], pl[i][1], pl[i][2]);
		glNormal3f(normals[i-1][0],normals[i-1][1],normals[i-1][2]);
		glVertex3f(pm[i][0], pm[i][1], pm[i][2]);
//		glVertex3f(xpl[i], extent, zpl[i]);
//		glVertex3f(xpm[i], 0.0f, zpm[i]);
	}
	glEnd();
}

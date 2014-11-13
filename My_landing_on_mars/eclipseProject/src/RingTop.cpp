#include <GL/freeglut.h>
#include <math.h>
#include "Vector3d.h"
#include "RingTop.h"

/*
 * draws top of a 3 dimensional  squared ring, which is a ring drawn with a thick pen.
 * outer radius = extent, inner radius = 0.9 * extent
 * Ring lies in x-z plane.
 */

void RingTop(GLfloat extent) {
	//outer circle
	Vector3d pl[74];

	pl[0][0] = 0.0;
	pl[0][1] = 0.0;
	pl[0][2] = 0.0;

	for (int i = 1; i <= 73; ++i) {
		pl[i][0] = extent * (float) sin(6.28318530718 * (i - 1) / 72.0);
		pl[i][1] = 0.0;
		pl[i][2] = extent * (float) cos(6.28318530718 * (i - 1) / 72.0);
	}
	//inner circle
	Vector3d pm[74];

	pm[0][0] = 0.0;
	pm[0][2] = 0.0;

	for (int i = 1; i <= 73; i++) {
		pm[i][0] = extent * 0.9
				* (float) sin(6.28318530718 * (i - 1) / 72.0);
		pm[i][1] = 0.0;
		pm[i][2] = extent * 0.9
				* (float) cos(6.28318530718 * (i - 1) / 72.0);
	}

	glBegin (GL_QUAD_STRIP);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	//BLAU
	for (int i = 1; i <= 73; i++) {
		glNormal3f(0.0,1.0,0.0);
		glVertex3f(pl[i][0], pl[i][1], pl[i][2]);
		glNormal3f(0.0,1.0,0.0);
		glVertex3f(pm[i][0], pm[i][1], pm[i][2]);
	}
	glEnd();
}

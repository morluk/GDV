#include <GL/freeglut.h>
#include <math.h>
#include "RingTop.h"

/*
 * draws top of a 3 dimensional  squared ring, which is a ring drawn with a thick pen.
 * outer radius = extent, inner radius = 0.9 * extent
 * Ring lies in x-z plane.
 */

void RingTop(GLfloat extent) {
	//outer circle
	float xpl[10], zpl[10];

	xpl[0] = 0.0;
	zpl[0] = 0.0;

	for (int i = 1; i <= 9; ++i) {
		xpl[i] = extent * (float) sin(6.28318530718 * (i - 1) / 8.0);
		zpl[i] = extent * (float) cos(6.28318530718 * (i - 1) / 8.0);
	}

	glBegin (GL_QUAD_STRIP);
	for (int i = 1; i <= 9; i++) {
		glVertex3f(xpl[i], 0.0, zpl[i]);
		glVertex3f(0.9 * xpl[i], 0.0, 0.9 * zpl[i]);
	}
	glEnd();
}

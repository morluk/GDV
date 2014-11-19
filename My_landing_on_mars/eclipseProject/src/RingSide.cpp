#include "RingSide.h"
#include <GL/freeglut.h>
#include <math.h>

void RingSide(GLfloat extent) {

	float xpl[10], zpl[10];

	xpl[0] = 0.0;
	zpl[0] = 0.0;
	for (int i = 1; i <= 9; ++i) {
		xpl[i] = extent * (float)sin ( 6.28318530718*(i-1)/8.0 );
		zpl[i] = extent * (float)cos ( 6.28318530718*(i-1)/8.0 );
	}

	glBegin(GL_QUAD_STRIP);
	for (int i = 1; i <= 9; i++) {
		//upper circle
		glVertex3f(xpl[i], extent, zpl[i]);
		//lower cirlce
		glVertex3f(xpl[i], 0.0, zpl[i]);
	}
	glEnd();
}

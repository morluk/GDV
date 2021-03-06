#include <GL/freeglut.h>
#include <math.h>
#include "Circle.h"

/*
 * models full cirlce around origin in x-z plane with radius = extent
 */

void Circle(GLfloat extent) {

	float xpl[74], zpl[74];

	xpl[0] = 0.0;
	zpl[0] = 0.0;
	for (int i = 1; i <= 73; ++i) {
		xpl[i] = extent * (float)sin ( 6.28318530718*(i-1)/72.0 );
		zpl[i] = extent * (float)cos ( 6.28318530718*(i-1)/72.0 );
	}

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(xpl[0],0.0,zpl[0]);
	for (int i=1; i<=73; i++) {
		glVertex3f(xpl[i],0.0,zpl[i]);
	}
	glEnd();

}

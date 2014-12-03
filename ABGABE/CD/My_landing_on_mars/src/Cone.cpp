#include <GL/freeglut.h>
#include <math.h>
#include "Cone.h"

/*
 * models frustum in x-z plane around origin with lower radius = extent * proportion
 * and height = extent. upper radius of frustum is extent.
 */

void Cone(GLfloat extent, GLfloat proportion) {
	//Upper cirlce
	float xpl[73], zpl[73];

	for (int i = 0; i < 73; ++i) {
		xpl[i] = extent * (float)sin ( 6.28318530718*(i-1)/72.0 );
		zpl[i] = extent * (float)cos ( 6.28318530718*(i-1)/72.0 );
	}

	//Lower circle
	float xpm[73], zpm[73];

	for (int i = 0; i < 73; ++i) {
		xpm[i] = extent * proportion * (float)sin ( 6.28318530718*(i-1)/72.0 );
		zpm[i] = extent * proportion * (float)cos ( 6.28318530718*(i-1)/72.0 );
	}

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 73; i++) {
		glVertex3f(xpl[i], extent, zpl[i]);
		glVertex3f(xpm[i], 0.0, zpm[i]);
	}
	glEnd();
}

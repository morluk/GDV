#include <GL/freeglut.h>
#include <math.h>
#include "Circle.h"
#include "Vector3d.h"

/*
 * zeichnet gefüllten Kreis um Ursprung mit radius = extent
 * in x-z Ebene. Orientierung der Normalen: 1.0 nach oben, -1.0 nach unten (um zu wissen wo aussen ist)
 */

void Circle(GLfloat extent, GLfloat orientation) {

	Vector3d pl[74];

	pl[0][0] = 0.0;	// x coordinate
	pl[0][1] = 0.0; // y coordinate
	pl[0][2] = 0.0; // z coordinate

	for (int i = 1; i <= 73; ++i) {
		pl[i][0] = extent * (float) sin(6.28318530718 * (i - 1) / 72.0);
		pl[i][1] = 0.0;
		pl[i][2] = extent * (float) cos(6.28318530718 * (i - 1) / 72.0);
	}

	glBegin(GL_TRIANGLE_FAN);
	glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
	glNormal3f(0.0f,orientation*1.0f,0.0f);
	glVertex3f(pl[0][0],pl[0][1],pl[0][2]);
	for (int i=1; i<=73; i++) {
		glNormal3f(0.0f,orientation*1.0f,0.0f);
		glVertex3f(pl[i][0],pl[i][1],pl[i][2]);
	}
	glEnd();

}

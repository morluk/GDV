#include <GL/freeglut.h>
#include <math.h>
#include "Kegelstumpf.h"
#include "Vector3d.h"

/*
 * zeichnet Kegelstumpf in x-z Ebene um Ursprung mit unterem Radius = extent * proportion
 * und mit Höhe extent. Oberer Radius des Kegelstumpfs ist extent.
 */

void Kegelstumpf(GLfloat extent, GLfloat proportion) {
	//Oberer Kreis
	Vector3d pl[74];

	pl[0][0] = 0.0;
	pl[0][2] = 0.0;

	for (int i = 1; i <= 73; ++i) {
		pl[i][0] = extent * (float) sin(6.28318530718 * (i - 1) / 72.0);
		pl[i][1] = extent;
		pl[i][2] = extent * (float) cos(6.28318530718 * (i - 1) / 72.0);
	}
	//Unterer Kreis
	Vector3d pm[74];

	pm[0][0] = 0.0;
	pm[0][2] = 0.0;

	for (int i = 1; i <= 73; i++) {
		pm[i][0] = extent * proportion * (float) sin(6.28318530718 * (i - 1) / 72.0);
		pm[i][1] = 0.0;
		pm[i][2] = extent * proportion * (float) cos(6.28318530718 * (i - 1) / 72.0);
	}

	//Normalen
	Vector3d normals[74];
	for (int i = 1; i <= 73; i++) {
		Vector3d vecA = Vector3d(pm[i] - pl[i]);
		Vector3d vecB;
		if (i < 73)
			vecB = Vector3d(pm[i + 1] - pm[i]);
		if (73 == i)
			vecB = Vector3d(pm[1] - pm[i]);
		normals[i] = (vecA.cross(vecB)).normalize();
	}

	glBegin(GL_QUAD_STRIP);
	for (int i = 1; i <= 73; i++) {
		glColor4f(0.0f,1.0f,0.0f,1.0f);	//GRUEN
		if (i%2 == 0)glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
		glNormal3f(normals[i][0],normals[i][1],normals[i][2]);
		glVertex3f(pl[i][0], pl[i][1], pl[i][2]);
		glNormal3f(normals[i][0],normals[i][1],normals[i][2]);
		glVertex3f(pm[i][0], pm[i][1], pm[i][2]);
	}
	glEnd();
}

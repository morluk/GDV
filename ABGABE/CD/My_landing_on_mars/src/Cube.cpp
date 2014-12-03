#include <GL/freeglut.h>
#include "Cube.h"

/**
 * draws squared cube around origin with width = height = fLength. center of cube is origin.
 */

void Cube( GLfloat fLength ) {
	glBegin(GL_POLYGON);   //Front
	glVertex3f(-fLength/2.0f,-fLength/2.0f,+fLength/2.0f);
	glVertex3f(+fLength/2.0f,-fLength/2.0f,+fLength/2.0f);
	glVertex3f(+fLength/2.0f,+fLength/2.0f,+fLength/2.0f);
	glVertex3f(-fLength/2.0f,+fLength/2.0f,+fLength/2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Right
	glVertex3f(+fLength/2.0f,-fLength/2.0f,+fLength/2.0f);
	glVertex3f(+fLength/2.0f,-fLength/2.0f,-fLength/2.0f);
	glVertex3f(+fLength/2.0f,+fLength/2.0f,-fLength/2.0f);
	glVertex3f(+fLength/2.0f,+fLength/2.0f,+fLength/2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Back
	glVertex3f(+fLength/2.0f,+fLength/2.0f,-fLength/2.0f);
	glVertex3f(+fLength/2.0f,-fLength/2.0f,-fLength/2.0f);
	glVertex3f(-fLength/2.0f,-fLength/2.0f,-fLength/2.0f);
	glVertex3f(-fLength/2.0f,+fLength/2.0f,-fLength/2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Left
	glVertex3f(-fLength/2.0f,+fLength/2.0f,-fLength/2.0f);
	glVertex3f(-fLength/2.0f,-fLength/2.0f,-fLength/2.0f);
	glVertex3f(-fLength/2.0f,-fLength/2.0f,+fLength/2.0f);
	glVertex3f(-fLength/2.0f,+fLength/2.0f,+fLength/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Top
	glVertex3f(-fLength/2.0f,+fLength/2.0f,+fLength/2.0f);
	glVertex3f(+fLength/2.0f,+fLength/2.0f,+fLength/2.0f);
	glVertex3f(+fLength/2.0f,+fLength/2.0f,-fLength/2.0f);
	glVertex3f(-fLength/2.0f,+fLength/2.0f,-fLength/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bottom
	glVertex3f(-fLength/2.0f,-fLength/2.0f,-fLength/2.0f);
	glVertex3f(+fLength/2.0f,-fLength/2.0f,-fLength/2.0f);
	glVertex3f(+fLength/2.0f,-fLength/2.0f,+fLength/2.0f);
	glVertex3f(-fLength/2.0f,-fLength/2.0f,+fLength/2.0f);
	glEnd();
}

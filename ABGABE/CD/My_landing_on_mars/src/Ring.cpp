#include <GL/freeglut.h>
#include <math.h>
#include "RingSide.h"
#include "RingTop.h"
#include "Ring.h"

/*
 * models Ring around origin with outer radius extent and inner radius 0.9 * extent.
 * height is 0.2 * extent. Up is y axis.
 */

void Ring(GLfloat extent) {

	glPushMatrix();
	RingTop(extent);
	glTranslatef(0.0f,0.2f,0.0f);
	RingTop(extent);
	glPopMatrix();

	glPushMatrix();	//remember position
	glScalef(1.0f,0.2f,1.0f);	//flatten Ring height
	RingSide(extent);		//cylinder outside
	glScalef(0.9f,1.0f,0.9f);
	RingSide(extent);		//cylinder inside
	glPopMatrix(); // go back
}

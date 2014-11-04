#include <GL/freeglut.h>
#include <math.h>
#include "Rakete.h"
#include "Kegelstumpf.h"

void Rakete(GLfloat KL) {
	glScalef(0.5f,0.5f,0.5f);	//halbe Groesse

	glPushMatrix();
	glTranslatef(0.0f,3.0f*KL,0.0f);
	Kegelstumpf(KL, 10.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,KL,0.0f);
	glScalef(1.0f,2.0f,1.0f);
	Kegelstumpf(KL, 1.0f);		//Zylinder
	glPopMatrix();

	glPushMatrix();
	glScalef(1.5f,1.0f,1.5f);	//oberer Radius passt auf Zylinder
	Kegelstumpf(KL, 1.5f);
	glPopMatrix();
}

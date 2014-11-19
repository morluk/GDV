#include <GL/freeglut.h>
#include <math.h>
#include "Rakete.h"
#include "Kegelstumpf.h"
#include "Circle.h"
#include "Ring.h"

/*
 * draws rocket at origin with lower radius 1.5/4 * extent and top radius 0.1/4 * extent
 * height is extent. Up is pos y axis.
 */

void Rakete(GLfloat KL, GLfloat ringAngle) {
	glPushMatrix();
	glScalef(0.25f,0.25f,0.25f);

	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);	//BLAU
	//Raketenspitze
	glPushMatrix();			// remember where you are
	glScalef(0.1f,1.0f,0.1f);
	glTranslatef(0.0f,3.0f*KL,0.0f);
	Kegelstumpf(KL, 10.0f);
	glTranslatef(0.0f,KL,0.0f);
	Circle(KL,1.0f);
	glPopMatrix();			// discard changes and go back where you came from

	//Raketenkörper
	glPushMatrix();
	glTranslatef(0.0f,KL,0.0f);
	glScalef(1.0f,2.0f,1.0f);
	Kegelstumpf(KL, 1.0f);		//Cylinder
	glPopMatrix();

	//Raketentriebwerke
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glPushMatrix();
	Kegelstumpf(KL, 1.5f);
	Circle(KL*1.5f,-1.0f);
	glPopMatrix();

	//Ringkörper
	glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
	glPushMatrix();
	glScalef(1.5f,1.0f,1.5f);
	glTranslatef(0.0f,2.0f*KL,0.0f);
	Ring(KL,ringAngle);
	glPopMatrix();
	glPopMatrix();
}

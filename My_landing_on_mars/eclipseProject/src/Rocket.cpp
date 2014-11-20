#include <GL/freeglut.h>
#include <math.h>
#include "Rocket.h"
#include "Cone.h"
#include "Circle.h"
#include "Ring.h"
#include "Cube.h"

/*
 * draws rocket around origin in x-z plane with lower radius 0.375 * extent and top radius 0.025 * extent
 * height is extent. Up is pos y axis.
 */

void Rocket(GLfloat KL, GLfloat ringAngle, GLfloat legAngle) {
	glPushMatrix();
	glScalef(0.25f,0.25f,0.25f);	//adjust height of rocket to extent and keep ratio height/width

	//Top of Rocket
	glColor4f(1.0f,1.0f,0.0f,1.0f); //YELLOW
	glPushMatrix();			// remember where you are
	glScalef(0.1f,1.0f,0.1f);	//scale cone and circle to upper radius 1/10 * extent and lower radius extent
	glTranslatef(0.0f,3.0f*KL,0.0f); //move cone and circle up 3*extent y-axis
	Cone(KL, 10.0f);			//draw cone with upper radius extent and lower radius 10 * extent
	glTranslatef(0.0f,KL,0.0f);	//move circle extent up y-axis
	Circle(KL);				// draw circle at top of rocket with radius extent
	glPopMatrix();			// discard changes and go back where you came from

	//Rocket body
	glPushMatrix();
	glTranslatef(0.0f,KL,0.0f);	//move cylinder extent up y-axis
	glScalef(1.0f,2.0f*KL,1.0f);	//stretch cylinder to height 2*extent
	Cone(KL, 1.0f);		//draw Cylinder with height extent and radius extent
	glPopMatrix();

	//Rocket blast pipe
	glColor4f(0.0f,1.0f,1.0f,1.0f);	//CYAN
	glPushMatrix();
	Cone(KL, 1.5f);		//draws cone with upper radius extent and lower radius 1.5 * extent and height extent
	Circle(KL*1.5f);	//draws circle with radius 1.5 * extent
	glPopMatrix();

	//Ring
	glColor4f(1.0f,0.0f,0.0f,1.0f);	//RED
	glPushMatrix();
	glScalef(1.5f,1.0f,1.5f);	//expand ring to outer radius 1.5 * extent
	glTranslatef(0.0f,2.0f*KL,0.0f);	//move ring up y-axis to 2 * extent
	glRotatef(ringAngle,0.0f,1.0f,0.0f);	//rotate ring around rocket body
	Ring(KL);	//draw ring with inner radius 0.9 * extent and outer radius extent and height 0.2 * extent
	glPopMatrix();

	//Legs 1 to 4
	glColor4f(1.0f,1.0f,1.0f,1.0f); //WHITE
	glPushMatrix();
	glTranslatef(0.8*KL,0.0f,0.8*KL);	//translate leg to position
	glRotatef(-legAngle,0.0f,0.0f,1.0f);
	glTranslatef(0.0f,-0.5f*KL,0.0f);	//translate top of cube to y = 0
	glScalef(0.2f,1.0f,0.2f);	//scale width (x,z) to 0.1 * extent
	Cube(KL);	//draw cube as first leg
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8*KL,0.0f,0.6*KL);	//translate leg to position
	glRotatef(legAngle,0.0f,0.0f,1.0f);
	glTranslatef(0.0f,-0.5f*KL,0.0f);	//translate top of cube to y = 0
	glScalef(0.2f,1.0f,0.2f);	//scale width (x,z) to 0.1 * extent
	Cube(KL);	//draw cube as second leg
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8*KL,0.0f,-0.8*KL);	//translate leg to position
	glRotatef(-legAngle,0.0f,0.0f,1.0f);
	glTranslatef(0.0f,-0.5f*KL,0.0f);	//translate top of cube to y = 0
	glScalef(0.2f,1.0f,0.2f);	//scale width (x,z) to 0.1 * extent
	Cube(KL);	//draw cube as third leg
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8*KL,0.0f,-0.6*KL);	//translate leg to position
	glRotatef(legAngle,0.0f,0.0f,1.0f);
	glTranslatef(0.0f,-0.5f*KL,0.0f);	//translate top of cube to y = 0
	glScalef(0.2f,1.0f,0.2f);	//scale width (x,z) to 0.1 * extent
	Cube(KL);	//draw cube as fourth leg
	glPopMatrix();

	glPopMatrix();
}

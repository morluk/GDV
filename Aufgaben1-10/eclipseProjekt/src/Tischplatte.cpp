//Definition einer runden Platte zur Verwendung als Tischplatte

#include <GL/freeglut.h>
#include <math.h>
#include "Tischplatte.h"

void Tischplatte(GLfloat KL)
{ 
	float xpl[74], zpl[74];

	xpl[0] = 0.0;
	zpl[0] = 0.0;
	for (int i = 1; i <= 73; ++i) {
		zpl[i] = KL * (float)cos ( 6.28318530718*(i-1)/72.0 );
		xpl[i] = KL * (float)sin ( 6.28318530718*(i-1)/72.0 );
	}

	glBegin(GL_TRIANGLE_FAN); //Oberseite
	glColor4f(0.5f,0.0f,0.0f,1.0f);	//Dunkelrot
	glVertex3f(0.0f,KL/10.0f,0.0f);
	glColor4f(0.6f,0.4f,0.0f,1.0f);	//Rotbraun
	for ( int i = 1; i <= 73; ++i) {
	glVertex3f(xpl[i],KL/10.0f,zpl[i]);
	}
	glEnd();

	glBegin(GL_POLYGON); //Unterseite
	glColor4f(0.5f,0.0f,0.0f,1.0f);	//Dunkelrot
	for ( int i = 1; i <= 73; ++i) {
	glVertex3f(xpl[i],0.0f,zpl[i]);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP); //Seite
	for ( int i = 1; i <= 73; ++i) {
	glColor4f(0.54f,0.36f,0.0f,1.0f);	//Rotbraun
	glVertex3f(xpl[i],KL/10.0f,zpl[i]);
	glColor4f(0.5f,0.0f,0.0f,1.0f);	//Dunkelrot
	glVertex3f(xpl[i],0.0f,zpl[i]);
	}
	glEnd();

	
}
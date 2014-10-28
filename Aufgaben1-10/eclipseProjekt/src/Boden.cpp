#include <GL/freeglut.h>
#include "Boden.h"

void Boden (GLfloat extent){
	glBegin ( GL_POLYGON );
	glColor4f ( 0.0f,  0.0f, 0.5f, 1.0f );
	glVertex3f (  50.0f*extent, 0.2f*extent,  10.0f*extent);
	glVertex3f (  50.0f*extent, 0.2f*extent, -1.0f*extent);
	glColor4f ( 0.5f,  0.0f, 0.0f, 1.0f );
	glVertex3f ( -50.0f*extent, 0.2f*extent, -1.0f*extent);
	glVertex3f ( -50.0f*extent, 0.2f*extent,  10.0f*extent);
	glEnd();
}

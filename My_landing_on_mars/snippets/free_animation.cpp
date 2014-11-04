#include <iostream>
#include <stdlib.h>
#include <GL/freeglut.h>
#include "Rakete.h"

using namespace std;

GLfloat extent = 1.0; // Mass fuer die Ausdehnung des Modells
GLfloat _angle;
GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };   // Ambient Light Values
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };   // Diffuse Light Values
GLfloat LightPosition[]= { (float)5.0*extent, (float)5.0*extent, (float)10.0*extent, 1.0f };  // Light Position


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27 : exit(0);
	break;
	default: break;
	}
}

void arrow_keys (int a_keys, int x, int y) {
	switch(a_keys) {
	case GLUT_KEY_UP: glutFullScreen();
	break;
	case GLUT_KEY_DOWN : glutReshapeWindow(500,500);
	break;
	default: break;
	}
}

int initRendering() {
	//glShadeModel (GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable (GL_DEPTH_TEST);
	glClearDepth(1.0f);
	//glDepthFunc (GL_LEQUAL);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);             // Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);             // Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);            // Position The Light
	glEnable(GL_LIGHT1);                            // Enable Light One
	glEnable(GL_LIGHTING);      // Enable Lighting
	return true;
}

void handleResize(int w, int h) {
	if (h==0)
		h=1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,w,h);
	glOrtho(-extent*2.0,+extent*2.0,-extent*2.0,+extent*2.0,0.0,+20.0*extent); //Frustum
//	gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5.0*extent, 5.0*extent, 10.0*extent, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Kamerasicht

	glPushMatrix();
	glRotatef(_angle,1.0f,0.0f,0.0f);
	Rakete (extent);
	glPopMatrix();
//	glutSolidSphere(1.0f,20.0f,20.0f);
//	float xpl[74][74], ypl[74][74], zpl[74][74];
//
//	xpl[0][0] = 0.0;
//	ypl[0][0] = 0.0;
//	zpl[0][0] = 0.0;
//	for (int i = 1; i <= 73; ++i) {
//		for (int j = 1; j <= 73; j++) {
//		xpl[i][j] = extent * (float)sin ( 3.141592653589793238*(j-1)/72.0 ) * (float)cos ( 3.141592653589793238*(i-1)/72.0 );
//		ypl[i][j] = extent * (float)sin ( 3.141592653589793238*(j-1)/72.0 ) * (float)sin ( 3.141592653589793238*(i-1)/72.0 );
//		zpl[i][j] = extent * (float)cos ( 3.141592653589793238*(j-1)/72.0 );
//		}
//	}
//	glRotatef(_angle,1.0f,0.0f,0.0f);
//	glBegin(GL_TRIANGLE_FAN);
//	for (int i=1; i<= 73; i++) {
//		for (int j = 1; j <= 73; j++) {
//		glNormal3f(xpl[i][j],ypl[i][j],zpl[i][j]);
//		glVertex3f(xpl[i][j],ypl[i][j],zpl[i][j]);
//		}
//	}
//	glEnd();
	glutSwapBuffers();
}

void update(int value) {
	if (_angle > 360)
		_angle-=360;
	_angle+=1.0f;
	glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, ++value);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Showing Window");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutSpecialFunc(arrow_keys);
	glutTimerFunc(25,update,0);
	glutMainLoop();
	return 0;
}

#include <iostream>
#include <GL/freeglut.h>
#include "global.h"
#include "standards.h"
#include "Rocket.h"

using namespace std;

Mode currentMode = IDLE_START;

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	//black
	glEnable (GL_DEPTH_TEST);
	glClearDepth(1.0f);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5.0*extent, 5.0*extent, 10.0*extent, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Kamerasicht
	if (currentMode == ROCKET_LANDING) {
		//Rackete zeichnen
		glRotatef(_angle,1.0f,0.0f,0.0f);
		Rocket (extent,_ringAngle);
		//Test:
		cout << "Rackete bei " << _rocketHeight << endl;
	} else if (currentMode == ROCKET_STARTING) {
		//Rackete zeichnen
		//Test:
		cout << "Rackete bei " << _rocketHeight << endl;
	} else if (currentMode == IDLE_START) {
		//Rakete zeichen
		Rocket(extent,_ringAngle);
		//Test:
		cout << "IDLE_START" << endl;
	}
	//Boden zeichnen
	glutSwapBuffers();
}

void reshape(int width, int height) {
	if (height==0)
		height=1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,width,height);
	glOrtho(-extent*2.0,+extent*2.0,-extent*2.0,+extent*2.0,0.0,+20.0*extent); //Frustum
	//gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
	glMatrixMode(GL_MODELVIEW);
}

void animate(int value) {
	if (value == 0) {
		currentMode = (Mode) (((int) currentMode) + 1);
		glutTimerFunc(ANIMATE_WAIT_MSEC, animate,
				TIMER_ARRAY[currentMode] / ANIMATE_WAIT_MSEC);
	} else {
		glutTimerFunc(ANIMATE_WAIT_MSEC, animate, --value);
	}

	if (currentMode == ROCKET_LANDING) {
		//values anpassen
		if (_angle > 360)
			_angle-=360;
		_angle+=1.0f;
		if (_ringAngle > 360)
			_ringAngle-=360;
		_ringAngle+=1.0f;
		//test:
		_rocketHeight--;
	}

	if (currentMode == ROCKET_STARTING) {
		//values anpassen
		_rocketHeight++;
	}

	if (currentMode == IDLE_START) {
		if (_ringAngle > 360)
			_ringAngle-=360;
		_ringAngle+=1.0f;
	}

	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	init();
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutTimerFunc(ANIMATE_WAIT_MSEC, animate,
			TIMER_ARRAY[currentMode] / ANIMATE_WAIT_MSEC);
	glutMainLoop();
	return 0;
}

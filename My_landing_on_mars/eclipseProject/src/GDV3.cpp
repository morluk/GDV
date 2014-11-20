#include <iostream>
#include <GL/freeglut.h>
#include "global.h"
#include "standards.h"
#include "Rocket.h"

using namespace std;

//cannot be placed in global.h Set currentMode for Start of Animation
Mode currentMode = IDLE_START;

void init() {
	//TODO: entweder ueberall 0.0f oder 0.0
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	//BLACK
	glEnable (GL_DEPTH_TEST);
	glClearDepth(1.0f);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//TODO: Adjust lookAt()
	gluLookAt(5.0 * extent, 5.0 * extent, 10.0 * extent, 0.0, 0.0, 0.0, 0.0,
			1.0, 0.0); // Kamerasicht

	glPushMatrix();
	glTranslatef(0.0f,-(extent+0.25*extent),0.0f);
	glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
	//TODO: Adjust radius of sphere
	glutSolidSphere(extent,20,20);
	glPopMatrix();

	if (currentMode == IDLE_START) {
		//Rakete zeichen
		glTranslatef(_rocketHeightx,_rocketHeighty,0.0f);
		glRotatef(_rotAngley, 0.0f, 1.0f, 0.0f);
		Rocket(extent, _ringAngle, _legAngle);
		//Test:
		cout << "IDLE_START" << endl;
	} else if (currentMode == ROCKET_LANDING) {
		//Rackete zeichnen
		glTranslatef(_rocketHeightx,_rocketHeighty,0.0f);
		//glRotatef(_angle, 1.0f, 0.0f, 0.0f);
		Rocket(extent, _ringAngle, _legAngle);
		//Test:
		cout << "Rackete landet bei " << _rocketHeightx << endl;
	} else if (currentMode == IDLE_LANDING) {
		//Rakete zeichen
		glTranslatef(_rocketHeightx,_rocketHeighty,0.0f);
		glRotatef(_rotAngleLanding, 0.0f, 0.0f, 1.0f);
		Rocket(extent, _ringAngle, _legAngle);
		//Test:
		cout << "IDLE_LANDING " << _rotAngleLanding << endl;
	} else if (currentMode == ROCKET_STARTING) {
		//Rackete zeichnen
		glTranslatef(_rocketHeightx,_rocketHeighty,0.0f);
		//glRotatef(_angle, 1.0f, 0.0f, 0.0f);
		Rocket(extent, _ringAngle, _legAngle);
		//Test:
		cout << "Rackete startet bei " << _rocketHeightx << endl;
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
	//TODO: Adjust frustum
	glFrustum(-extent*5.0,+extent*5.0,-extent*5.0,+extent*5.0,9.0*extent,+20.0*extent); //Frustum
	//glOrtho(-extent*2.0,+extent*2.0,-extent*2.0,+extent*2.0,0.0,+20.0*extent); //Frustum
	//gluPerspective(45.0,(double)width/(double)height,10.0,20.0);
	glMatrixMode(GL_MODELVIEW);
}

void animate(int value) {

	if (currentMode == IDLE_START) {
		_legAngle = 90.0;
		_rocketHeightx = -5.0;
		_rocketHeighty = 5.0;
		if (_rotAngley > 360)
			_rotAngley-=360;
		_rotAngley+=1.0f;
		if (_ringAngle > 360)
			_ringAngle-=360;
		_ringAngle+=2.0f;
	}

	if (currentMode == ROCKET_LANDING) {
		//set values
		if (_ringAngle > 360)
			_ringAngle-=360;
		_ringAngle+=2.0f;
		if (_legAngle > 0)
			_legAngle -=1.0f;
		if (_rotAngley > 360)
			_rotAngley-=360;
		_rotAngley+=1.0f;
		if (_rocketHeightx < 0)
			_rocketHeightx+=0.01f;
		if (_rocketHeighty > 0)
			_rocketHeighty-=0.01f;
	}

	if (currentMode == IDLE_LANDING) {
		//set values
		_legAngle = 0;
		if (_rotAngley > 360)
			_rotAngley-=360;
		_rotAngley+=1.0f;
		if (_ringAngle > 360)
			_ringAngle-=360;
		_ringAngle+=2.0f;
		if (_rotAngleLanding > 10) {
			_direction = -1.0f;
		} else if (_rotAngleLanding < -10) {
			_direction = 1.0f;
		}
		_rotAngleLanding += _direction;
	}

	if (currentMode == ROCKET_STARTING) {
		//set values
		if (_rotAngley > 360)
			_rotAngley-=360;
		_rotAngley+=1.0f;
		if (_ringAngle > 360)
			_ringAngle-=360;
		_ringAngle+=2.0f;
		if (_legAngle < 90)
			_legAngle +=1.0f;
		if (_rocketHeightx < 5)
			_rocketHeightx+=0.01f;
		if (_rocketHeighty < 5)
			_rocketHeighty+=0.01f;
	}

	glutPostRedisplay();
	if (value == 0) {
		//change currentMode to next Mode type
		currentMode = (Mode) ((((int) currentMode) + 1) % TIMER_ARRAY_LENGTH);
		glutTimerFunc(ANIMATE_WAIT_MSEC, animate,
				TIMER_ARRAY[currentMode] / ANIMATE_WAIT_MSEC);
	} else {
		glutTimerFunc(ANIMATE_WAIT_MSEC, animate, --value);
	}
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

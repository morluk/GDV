#include <iostream>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include "global.h"
#include "standards.h"
#include "Rocket.h"

using namespace std;

/**
 * Entry point and sequence control structure of simulation
 * 'MyLandingOnMars' from Lukas Koehler and Moritz Hilberg
 * WS 14/15
 */

//cannot be placed in global.h Set currentMode for Start of Animation
Mode currentMode = IDLE_START;

GLuint mars;
GLuint ringTexture;

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	//BLACK
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);
	//load textures
	mars = SOIL_load_OGL_texture("images/mars.jpg", SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
							| SOIL_FLAG_COMPRESS_TO_DXT);

	ringTexture = SOIL_load_OGL_texture("images/ring.jpg", SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
							| SOIL_FLAG_COMPRESS_TO_DXT);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//position of camera
	gluLookAt(_cameraX, _cameraY, _cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//modeling the planet
	glPushMatrix();
	glTranslatef(0.0f, -(10.0 * extent + 0.25 * extent), 0.0f);
	glBindTexture(GL_TEXTURE_2D, mars);
	glEnable(GL_TEXTURE_2D);
	glRotatef(90, 0, 0, 1);
	GLUquadricObj* sphere = gluNewQuadric();
	gluQuadricTexture(sphere, GL_TRUE);
	gluSphere(sphere, 10.0 * extent, 60, 20);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//modeling the rocket according to current position
	if (currentMode == IDLE_START) {
		//rocket up in sky
		glTranslatef(_rocketHeightx, _rocketHeighty, 0.0f);
		glRotatef(_rotAngley, 0.0f, 1.0f, 0.0f);
		Rocket(extent, _ringAngle, _legAngle, ringTexture);
		cout << "IDLE_START" << endl;
	} else if (currentMode == ROCKET_LANDING) {
		//rocket is landing
		glTranslatef(_rocketHeightx, _rocketHeighty, 0.0f);
		Rocket(extent, _ringAngle, _legAngle, ringTexture);
		cout << "Rackete landet bei " << _rocketHeightx << endl;
	} else if (currentMode == IDLE_LANDING) {
		//rocket on planet surface
		glTranslatef(_rocketHeightx, _rocketHeighty, 0.0f);
		glRotatef(_rotAngleLanding, 0.0f, 0.0f, 1.0f);
		Rocket(extent, _ringAngle, _legAngle, ringTexture);
		cout << "IDLE_LANDING " << _rotAngleLanding << endl;
	} else if (currentMode == ROCKET_STARTING) {
		//rocket is starting
		glTranslatef(_rocketHeightx, _rocketHeighty, 0.0f);
		Rocket(extent, _ringAngle, _legAngle, ringTexture);
		cout << "Rackete startet bei " << _rocketHeightx << endl;
	}
	glutSwapBuffers();
}

void reshape(int width, int height) {
	if (height == 0)
		height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	//adjust frustum
	gluPerspective(45.0, (double) width / (double) height, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

void animate(int value) {
	//set values according to currentMode
	if (currentMode == IDLE_START) {
		_legAngle = 90.0;
		_rocketHeightx = -5.0;
		_rocketHeighty = 5.0;
		if (_rotAngley > 360)
			_rotAngley -= 360;
		_rotAngley += 1.0f;
		if (_ringAngle > 360)
			_ringAngle -= 360;
		_ringAngle += 2.0f;
	}

	if (currentMode == ROCKET_LANDING) {
		if (_ringAngle > 360)
			_ringAngle -= 360;
		_ringAngle += 2.0f;
		if (_legAngle > 0)
			_legAngle -= 1.0f;
		if (_rotAngley > 360)
			_rotAngley -= 360;
		_rotAngley += 1.0f;
		if (_rocketHeightx < 0)
			_rocketHeightx += 0.01f;
		if (_rocketHeighty > 0)
			_rocketHeighty -= 0.01f;
	}

	if (currentMode == IDLE_LANDING) {
		_legAngle = 0;
		if (_rotAngley > 360)
			_rotAngley -= 360;
		_rotAngley += 1.0f;
		if (_ringAngle > 360)
			_ringAngle -= 360;
		_ringAngle += 2.0f;
		if (_rotAngleLanding > 10) {
			_direction = -1.0f;
		} else if (_rotAngleLanding < -10) {
			_direction = 1.0f;
		}
		_rotAngleLanding += _direction;
	}

	if (currentMode == ROCKET_STARTING) {
		if (_rotAngley > 360)
			_rotAngley -= 360;
		_rotAngley += 1.0f;
		if (_ringAngle > 360)
			_ringAngle -= 360;
		_ringAngle += 2.0f;
		if (_legAngle < 90)
			_legAngle += 1.0f;
		if (_rocketHeightx < 5)
			_rocketHeightx += 0.01f;
		if (_rocketHeighty < 5)
			_rocketHeighty += 0.01f;
	}

	glutPostRedisplay();
	
	//if value == 0 change to next mode, else decrement value and call glutTimerFunc
	if (value == 0) {
		//change currentMode to next Mode type
		currentMode = (Mode) ((((int) currentMode) + 1) % TIMER_ARRAY_LENGTH);
		glutTimerFunc(ANIMATE_WAIT_MSEC, animate,
				TIMER_ARRAY[currentMode] / ANIMATE_WAIT_MSEC);

		//first values on mode change
		_cameraX = cameraXarray[currentMode];
		_cameraY = cameraYarray[currentMode];
		_cameraZ = cameraZarray[currentMode];
	} else {
		glutTimerFunc(ANIMATE_WAIT_MSEC, animate, --value);

		//subtract calculated value before the next mode from camery parameters
		_cameraX -= (cameraXarray[currentMode] - cameraXarray[currentMode + 1])
				/ (TIMER_ARRAY[currentMode] / 10);
		_cameraY -= (cameraYarray[currentMode] - cameraYarray[currentMode + 1])
				/ (TIMER_ARRAY[currentMode] / 10);
		_cameraZ -= (cameraZarray[currentMode] - cameraZarray[currentMode + 1])
				/ (TIMER_ARRAY[currentMode] / 10);
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

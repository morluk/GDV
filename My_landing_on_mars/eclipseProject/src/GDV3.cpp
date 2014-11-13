#include <iostream>
#include <GL/freeglut.h>
#include "global.h"
#include "standards.h"

using namespace std;

Mode currentMode = IDLE_START;

void renderScene() {
	if (currentMode == ROCKET_LANDING) {
		//Rackete zeichnen
		//Test:
		cout << "Rackete bei " << _rocketHeight << endl;
	} else if (currentMode == ROCKET_STARTING) {
		//Rackete zeichnen
		//Test:
		cout << "Rackete bei " << _rocketHeight << endl;
	}
	//Boden zeichnen
}

void reshape(int width, int height) {

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
		//test:
		_rocketHeight--;
	}

	if (currentMode == ROCKET_STARTING) {
		//values anpassen
		_rocketHeight++;
	}

	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutTimerFunc(ANIMATE_WAIT_MSEC, animate,
			TIMER_ARRAY[currentMode] / ANIMATE_WAIT_MSEC);
	glutMainLoop();
	return 0;
}

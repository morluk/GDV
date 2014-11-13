#include <iostream>
#include <GL/freeglut.h>

using namespace std;

enum Mode {
	IDLE, ROCKET_LANDING
};

Mode currentMode;

void renderScene() {

}

void reshape(int width, int height) {

}

void animate(int value) {

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("*** TischleinDeckDich zu sehen");
	glutDisplayFunc (renderScene);
	glutReshapeFunc (reshape);
	glutTimerFunc(10, animate, 0);
	glutMainLoop();
	return 0;
}

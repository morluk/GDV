#ifndef GLOBAL
#define GLOBAL

GLfloat extent = 1.0; // extension of model

#include "standards.h"

//Rocket values
GLfloat _rocketHeightx = -5.0 * extent;
GLfloat _rocketHeighty = 5.0 * extent;
GLfloat _rotAngley, _ringAngle, _legAngle, _rotAngleLanding = 0.0, _direction =
		1.0;

//Camera values
GLfloat _cameraX = cameraXarray[0];
GLfloat _cameraY = cameraYarray[0];
GLfloat _cameraZ = cameraZarray[0];

#endif

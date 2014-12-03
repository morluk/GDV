#ifndef STANDARDS
#define STANDARDS

//Window standards
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "FrGruppe3 'My landing on Mars'";
const int ANIMATE_WAIT_MSEC = 10;

//scheduleList
//order of types is order of animation
enum Mode {
	IDLE_START, ROCKET_LANDING, IDLE_LANDING, ROCKET_STARTING
};

//Timer Standards
//array[i] has to be enum Mode at i
const int TIMER_ARRAY[4] = {2000, 5000, 2000, 5000};
const int TIMER_ARRAY_LENGTH = 4;

//camera standards
//correspond to enum Mode. Order of array:
//start camera position
//position start landing sequence
//position rocket has landed
//position rocket starting
//position start sequence finished

//the shorter a mode is, the quicker the camera changes
//so we have here free hand and can easily add modes
const GLfloat cameraXarray[5] = {	0, 		0, 		-2, 	2,		5	};
const GLfloat cameraYarray[5] = {	5, 		5, 		5, 		2,		2	};
const GLfloat cameraZarray[5] = {	5, 		15, 	5, 		5,		15	};

#endif

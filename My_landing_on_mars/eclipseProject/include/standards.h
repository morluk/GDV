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
//TODO: uebersetzen :D
//das sind die camera arrays. die haengen zusammen mit den modes. die reihenfolge ist:
//start camera position
//position sobald die rakete anfaengt zu landen
//position wenn rakete gelandet ist
//wenn rakete wieder anfaengt zu starten
//wenn rakete fertig

//destor kuerzer ein mode dauert desto schneller wechselt die kamera zur naechsten sicht.
//somit haben wir hier freie auswahl und es ist einfach, falls mal ein mode hinzukommt.
//die kamera einstellungen fand ich so mal ganz gut. koennen aber ja auch mal noch andere testen
const GLfloat cameraXarray[5] = {	0, 		0, 		-2, 	2,		5	};
const GLfloat cameraYarray[5] = {	5, 		5, 		5, 		2,		2	};
const GLfloat cameraZarray[5] = {	5, 		15, 	5, 		5,		15	};

#endif

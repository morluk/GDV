//Window standards
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "*** Rakete zu sehen";
const int ANIMATE_WAIT_MSEC = 10;

//scheduleList
enum Mode {
	IDLE_START, ROCKET_LANDING, IDLE_LANDING, ROCKET_STARTING
};

//Timer Standards
const int TIMER_ARRAY[4] = {5000, 10000, 5000, 10000};
const int TIMER_ARRAY_LENGTH = 4;

//const int START_IDLE_TIME = 5000;
//const int ROCKET_LANDING_TIME = 10000;
//const int LANDING_IDLE_TIME = 5000;
//const int ROCKET_STARTING_TIME = 10000;

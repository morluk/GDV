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

//const int START_IDLE_TIME = 5000;
//const int ROCKET_LANDING_TIME = 10000;
//const int LANDING_IDLE_TIME = 5000;
//const int ROCKET_STARTING_TIME = 10000;

#define VALID_MIN_NUM       0x30
#define VALID_MAX_NUM       0x39


/*  We need to keep track of time */
void setup_time();         //This initializes clocks and sets what time irrigation system began
void start_time();         //This sets what time watering begins that day
void end_time();           //This sets up what time watering ends that day
void down_time();          //This sets what time watering is turned off due to repair, movement, etc.
int interval_watering();   //People can give time on and time off rotations
void timed_watering();     //People can set up what time of day to water

/*  We need to keep track of certain data */
void temperature_pipe();   //Keeps track of temperature of pipe
void temperature_water();  //Keeps track of temperature of water
void temperature_out();    //Keeps track of temperature outside
void error_pipe();         //Senses malfunctions in pipe

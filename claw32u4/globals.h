// global variables

// pinouts
#define servoPin 10   // servo signal pin
#define trigPin 15    // HC-SR04 trigger pin
#define echoPin 15    // echo pin - may use same connection as trigger
#define proxLedPin 14 // proximity led
#define buttonPin 16  // manual operation

// options
const unsigned int
    debuggingLevel = 0, // 0 : no debugging, 1 : events, 2 : numbers
    baudRate = 115200;  // serial baud rate (bps)
const unsigned long
    closePos = 544,      // *** // close position signal (us)
    closeWait = 500,     // *** // (ms) wait when !isOpen
    closeInterval = 500, // *** // (us) closing speed
    openPos = 2400,      // *** // open position signal (us)
    openWait = 1000,     // *** // (ms) wait when isOpen
    openInterval = 300,  // *** // (us) opening speed
    timeout = 5800;      // (us) sensor timeout (out of range) cm / 0.0172
const double
    closeThreshold = 40.0, // (cm) threshold when !isOpen
    openThreshold = 23.0,  // (cm) threshold when isOpen
    readingSF = 0.10;      // distance reading smoothing factor

// *** -> tweak needed

// necessaries
bool
    isArmed = true, //
    isNear = false, //
    isOpen,         //
    buttonLS;       //
double
    distance,  //
    threshold; //
unsigned long
    servoInterval, //
    currentPos,    //
    desiredPos,    //
    tServo = 0,    //
    tNear = 0,     //
    wait,          //
    tms,           //
    tus;           //

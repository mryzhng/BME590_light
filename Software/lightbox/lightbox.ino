// use preprocessor directives to define constants in the code = will never change
#define FLASH_RATE_HZ 2
#define BUTTON_IN D1
#define PWN_LED_OUT D11
#define PWM_MAX 255

// global variables representing "state" across all functions = can change 
// operating mode: 0 - off, 1 - bright, 2 - mid-bright, 3 - dim, 4 - flash
int operating_mode = 0;
// int button_pushed = 0;
bool BUTTON_PUSHED = false;
int previous_button_state = 0;
int PWM_OUT = 0;                //brightness of LED

// executed one-time at device startup
void setup() {

   attachInterrupt(BUTTON_IN, button_pushed, FALLING); // digitalPinToInterrupt(interruptPin) 
                                                       // falling: will change when button release happens
                                                       // define output (PWM) pin connected to LED
                                                       // falling = detect when i release
  pinMode(BUTTON_IN, INPUT)
  pinMode(PWN_LED_OUT, OUTPUT)
  
}

// continually-running loop
// calls functions that are named as "actions"
void loop(){

    check_for_button_press();

    set_pwm_based_on_operating_mode();

    shine_led();

void set_pwn_based_on_operating_mode() {

    switch (operating_mode) {
        case 0:
            PWM_OUT = 0;
            break;
        case 1:
            PWM_OUT = PWM_MAX;
            break;
        case 2:
            PWN_OUT = PWM_MAX/2;
            break;
        case 3:
            PWN_OUT = PWM_MAX/4;
            break;
        case 4:
            PWM_OUT = PWM_MAX;
            flash_the_light();
            break;
    }

}

void button_pushed() {
    BUTTON_PUSHED = true;

}

void flash_the_light() {
  while(true)
    analogWrite(PWM_LED_OUT, PWM_MAX);   // turn the LED on (HIGH is the voltage level)
    delay(1000/FLASH_RATE_HZ);                         // wait for a second
    analogWrite(PWM_LED_OUT, 0);        // turn the LED off by making the voltage 0 (if this doesn't work try "LOW")
    delay(1000/FLASH_RATE_HZ);                       // wait for a second
}

void shine_led() {
    analogWrite(PWM_LED_OUT, PWM_0UT); //value comes from mode set by operating modes
}

void check_for_button_press() {
    if (BUTTON_PUSHED == true) {
      operating mode = operating mode + 1;
      if (operating_mode == 5) {
          operating_mode = 0;
      }
      }

      BUTTON_PUSHED = false;
    }
    
    // set operating_mode
    // reset previous button press state, interrupt catch, etc.
}

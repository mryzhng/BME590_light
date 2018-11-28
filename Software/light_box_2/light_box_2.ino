// use preprocessor directives to define constants in the code = will never change
#define FLASH_RATE_HZ 2
#define BUTTON_IN 2
#define PWM_LED_OUT 11
#define PWM_MAX 255

// global variables representing "state" across all functions = can change 
// operating mode: 0 - off, 1 - bright, 2 - mid-bright, 3 - dim, 4 - flash
int operating_mode = 0;
// int button_pushed = 0;
bool BUTTON_PUSHED = false;
int previous_button_state = 0;
int PWM_OUT = 0;                //brightness of LED
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 100;    // the debounce time; increase if the output flickers
int rise_count = 0;

// executed one-time at device startup
void setup() {
  
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(BUTTON_IN), button_pushed, RISING); // digitalPinToInterrupt(interruptPin) 
                                                       // falling: will change when button release happens
                                                       // define output (PWM) pin connected to LED
                                                       // falling = detect when i release
  pinMode(BUTTON_IN, INPUT_PULLUP);
  pinMode(PWM_LED_OUT, OUTPUT);
  
}

// continually-running loop
// calls functions that are named as "actions"
void loop(){
    int sensorValue = digitalRead(BUTTON_IN);

    Serial.println(sensorValue);
    
    check_for_button_press();
    
    set_pwm_based_on_operating_mode();

    shine_led();
}

void set_pwm_based_on_operating_mode() { 

    switch (operating_mode) {
        case 0:
            PWM_OUT = 0;
            break;
        case 1:
            PWM_OUT = PWM_MAX;
            break;
        case 2:
            PWM_OUT = PWM_MAX/5;
            break;
        case 3:
            PWM_OUT = PWM_MAX/10;
            break;
        case 4:
            flash_the_light();
            //break;
    }

}

void button_pushed() {
    BUTTON_PUSHED = true;
}

void check_for_button_press() {
    if (BUTTON_PUSHED == true) {
//      Serial.print("last debounce time:"); 
//      Serial.println(lastDebounceTime);
//      Serial.print("operating mode:"); 
//      Serial.println(operating_mode);
//      Serial.print("millis:"); 
//      Serial.println(millis());
/*
      if ((millis() - lastDebounceTime) > debounceDelay) {
        rise_count = rise_count + 1; 
        Serial.print("rise count:");
        Serial.println(rise_count);
        Serial.println("---");
        if (rise_count==1){
          operating_mode = operating_mode + 1;
          rise_count = 0;
        }
      }
      
      lastDebounceTime = millis();
 */
      operating_mode = operating_mode + 1;     
      if (operating_mode == 5) {
        operating_mode = 0;
      }
    
    }
      BUTTON_PUSHED = false;
      delay(500);

      //delay(500);
    }
    // set operating_mode
    // reset previous button press state, interrupt catch, etc.


void shine_led() {
    analogWrite(PWM_LED_OUT, PWM_OUT); //value comes from mode set by operating modes
}


void flash_the_light() {
    analogWrite(PWM_LED_OUT, PWM_MAX);   // turn the LED on (HIGH is the voltage level)
    delay(1000/FLASH_RATE_HZ);                         // wait for a second
    analogWrite(PWM_LED_OUT, 0);        // turn the LED off by making the voltage 0 (if this doesn't work try "LOW")
    delay(1000/FLASH_RATE_HZ);                       // wait for a second
}


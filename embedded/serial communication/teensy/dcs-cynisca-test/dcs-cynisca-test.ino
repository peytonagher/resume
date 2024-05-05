#include <../FlexCAN_T4/FlexCAN_T4.h>

#include "globals.h"
#include <Bounce2.h>


// Instantiate a Bounce object
Bounce headlight_button = Bounce();
Bounce brake_light_button = Bounce();
Bounce right_turn_button = Bounce();
Bounce left_turn_button = Bounce();
Bounce hazard_button = Bounce();
Bounce horn_button = Bounce();
Bounce cruise_control_button = Bounce();
Bounce cruise_decel_button = Bounce();
Bounce cruise_accel_button = Bounce();

FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> mc;




void setup() {

  delay(3000);

  // put your setup code here, to run once:
  Serial.begin(9600);

  //can begin
  mc.begin();
  mc.setBaudRate(250000);
  mc.setMaxMB(16);
  mc.enableFIFO();
  mc.enableFIFOInterrupt();
  mc.onReceive(mcSniff);
  mc.mailboxStatus();

  //Headlights setup
  pinMode(headlights_sense, INPUT);
  pinMode(headlights_indicator, OUTPUT);
  pinMode(headlights,OUTPUT);
  digitalWrite(headlights_indicator, HIGH);
  //Brake Lights setup 
  pinMode(brake_light_sense, INPUT);
  pinMode(regen_brake_light_sense, INPUT);
  pinMode(brake_light, OUTPUT);
  //Right Turn Lights setup
  pinMode(right_turn_sense, INPUT);
  pinMode(right_turn_indicator, OUTPUT);
  pinMode(right_turn_light, OUTPUT);
  digitalWrite(right_turn_indicator, HIGH);
  //Left Turn Lights setup 
  pinMode(left_turn_sense, INPUT);
  pinMode(left_turn_indicator, OUTPUT);
  pinMode(left_turn_light, OUTPUT);
  digitalWrite(left_turn_indicator, HIGH);
  //Hazard Lights setup 
  pinMode(hazard_sense, INPUT);
  pinMode(hazard_indicator, OUTPUT); 
  digitalWrite(hazard_indicator, HIGH);
  //Horn ID's 
  pinMode(horn_sense, INPUT);
  pinMode(horn, OUTPUT);
  //Cruise ID's 
  pinMode(cruise_control_sense, INPUT);
  pinMode(cruise_control_indicator, OUTPUT);
  pinMode(cruise_decel_sense, INPUT);
  pinMode(cruise_accel_sense, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(brake_light, HIGH);
  digitalWrite(13, HIGH);
  // digitalWrite(headlights, HIGH);
  // digitalWrite(right_turn_light, HIGH);
  // digitalWrite(left_turn_light, HIGH);
  // digitalWrite(hazard_light, HIGH);
  //digitalWrite(headlights_indicator, HIGH);
  //digitalWrite(right_turn_indicator, HIGH);
  //digitalWrite(left_turn_indicator, HIGH);
  // digitalWrite(hazard_indicator, HIGH);
  // digitalWrite(cruise_control_indicator, HIGH);

  //set up Bounce buttons
  headlight_button.attach (headlights_sense,INPUT);
  brake_light_button.attach (brake_light_sense,INPUT);
  right_turn_button.attach (right_turn_sense,INPUT);
  left_turn_button.attach (left_turn_sense,INPUT);
  hazard_button.attach (hazard_sense,INPUT);
  horn_button.attach (horn_sense,INPUT);
  cruise_control_button.attach (cruise_control_sense,INPUT);
  cruise_decel_button.attach (cruise_decel_sense,INPUT);
  cruise_accel_button.attach (cruise_accel_sense,INPUT);
  
  // DEBOUNCE INTERVAL IN MILLISECONDS
  headlight_button.interval(25);
  brake_light_button.interval(25);
  right_turn_button.interval(25);
  left_turn_button.interval(25);
  hazard_button.interval(25);
  horn_button.interval(25);
  cruise_control_button.interval(25);
  cruise_decel_button.interval(25);
  cruise_accel_button.interval(25);


}

void mcSniff(const CAN_message_t &msg) {
  Serial.print("MB "); Serial.print(msg.mb);
  Serial.print("  OVERRUN: "); Serial.print(msg.flags.overrun);
  Serial.print("  LEN: "); Serial.print(msg.len);
  Serial.print(" EXT: "); Serial.print(msg.flags.extended);
  Serial.print(" TS: "); Serial.print(msg.timestamp);
  Serial.print(" ID: "); Serial.print(msg.id, HEX);
  Serial.print(" Buffer: ");
  for ( uint8_t i = 0; i < msg.len; i++ ) {
    Serial.print(msg.buf[i], HEX); Serial.print(" ");
  } Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  mc.events();
  // UPDATE THE BUTTON
  // YOU MUST CALL THIS EVERY LOOP
  headlight_button.update();
  brake_light_button.update();
  right_turn_button.update();
  left_turn_button.update();
  hazard_button.update();
  horn_button.update();
  cruise_control_button.update();
  cruise_decel_button.update();
  cruise_accel_button.update();


 
  //Headlight logic
  if(headlight_button.fell()){
    digitalToggle(headlights_indicator);
    digitalToggle(headlights);
    }
  //brake light logic
  if(brake_light_button.fell()){
    digitalWrite(brake_light, HIGH);
  }
  if(brake_light_button.rose()){
    digitalWrite(brake_light, LOW);
  }
  //right turn signal logic
  if(right_turn_button.fell()){
    digitalWrite(right_turn_light,LOW);
    digitalToggle(right_turn_bool);
    digitalToggle(right_turn_indicator);
  }
  if(left_turn_bool = true){
      digitalWrite(left_turn_light,(millis()/1000) % 2);
    }
  //left turn signal logic
  if(left_turn_button.fell()){
    digitalWrite(left_turn_light,LOW);
    digitalToggle(left_turn_bool);
    digitalToggle(left_turn_indicator);
  }
    if(left_turn_bool = true){
      digitalWrite(left_turn_light,(millis()/1000) % 2);
    }
  //horn logic
  if(horn_button.fell()){
    digitalWrite(horn,HIGH);
  }
  if(horn_button.rose()){
    digitalWrite(horn,LOW);
  }
  //hazard logic
  if(hazard_button.fell()){
    digitalWrite(right_turn_light,LOW);
    digitalWrite(left_turn_light,LOW);
    digitalToggle(hazard_indicator);
    digitalToggle(hazard_bool);
  }
  if(hazard_bool = true){
    right_turn_bool = true;
    left_turn_bool = true;
  }
  //cruise control logic
  if(cruise_control_button.fell()){
    digitalToggle(cruise_control_indicator);
  }
  //cruise control decel logic
  if(cruise_decel_button.fell()){
    
  }
  //cruise control accel logic
  if(cruise_accel_button.fell()){
    
  }
}

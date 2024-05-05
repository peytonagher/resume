//---Create Variables--- 
//Headlights ID's
const byte headlights_sense = 31;
const byte headlights_indicator = 10;
const byte headlights = 38; 
//Brake Lights ID's
const byte brake_light_sense = 3; //should be 21
const byte regen_brake_light_sense = 22;
const byte brake_light = 34; //should be 39
//Right Turn Light ID's
const byte right_turn_sense = 4;
const byte right_turn_indicator = 26;
const byte right_turn_light = 35;
bool right_turn_bool = false;
//Left Turn Light ID's
const byte left_turn_sense = 3;
const byte left_turn_indicator = 25;
const byte left_turn_light = 34;
bool left_turn_bool = false;
//Hazard lights ID's
const byte hazard_sense = 32;
const byte hazard_indicator = 24;
bool hazard_bool = false;
//Horn ID's
const byte horn_sense = 30;
const byte horn = 41;
//Cruise ID's 
const byte cruise_control_sense = 29;
const byte cruise_control_indicator = 12;
const byte cruise_decel_sense = 2;
const byte cruise_accel_sense = 6;
bool cruise_button_pressed = false;
bool cruise_decel_button_pressed = false;
bool cruise_accel_button_pressed = false;
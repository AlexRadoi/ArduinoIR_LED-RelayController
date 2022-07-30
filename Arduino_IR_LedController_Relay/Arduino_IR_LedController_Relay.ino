#include <IRremote.h>
#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    16
#define BRIGHTNESS  100
#define RECV_PIN  7
#define relay_pin 9
CRGB leds[NUM_LEDS];
bool before;
bool relay_state;
bool color_1;
bool color_2;
bool color_3;
bool color_4;
bool color_5;
bool color_6;
bool color_7;
bool color_8;
bool color_9;
bool key_value;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
    LEDS.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
  irrecv.enableIRIn();   // start the receiver
  before=0; //LED is turned off
  relay_state = 0;
  pinMode(relay_pin,OUTPUT);
  color_1 =0;
  color_2 =0;
  color_3 =0;
  color_4 =0;
  color_5 =0;
  color_6 =0;
  color_7 =0;
  color_8 =0;
  color_9 =0;
}

void loop() {

  if (irrecv.decode(&results)) { // decode the IR data
    int value = results.value;  // store the IR data in a variable
   Serial.println(value, HEX);
   switch(value){
  case 0XFFFFFFFF: // if you press the same key multiple times record that key in a new variable, this helps to clean up unwanted button presses
        value = key_value;
        break;

    
   
  case 0xFFC23D: //Code to turn the LED STRIP OFF (button play/pause on the remote)
    if(before==0){  
      fill_solid(leds,NUM_LEDS,CRGB:: Black);
      FastLED.show();
      before=1; //LED is now turned on
    }
    else{
     fill_solid(leds,NUM_LEDS,CRGB::Black);
     FastLED.show();
      before=0;

    }
    break;
 
    
  case 0xFFA857: //Code to decrease the brightness (button - on the remote)
    
      FastLED.setBrightness(BRIGHTNESS/0.5);
      FastLED.show();
    break;
   
  case 0xFFE01F: //Code to increase the brightness (button + on the remote)
  
      FastLED.setBrightness(BRIGHTNESS*0.5);
         FastLED.show();
      break;
 case 0xFF6897: //Code to turn the Relay ON/OFF (button 0 on the remote)
  if(relay_state == 0){
    digitalWrite(relay_pin,HIGH);
    relay_state =1;
  }
  else{
    digitalWrite(relay_pin,LOW);
    relay_state = 0;
  }
  break;
 case 0xFF30CF: // change color ON/OFF to Violet ( button 1 on the remote)
  if(color_1 == 0){
   fill_solid(leds,NUM_LEDS,CRGB::DarkViolet);
   FastLED.show();
   color_1 = 1;
 }
 else{
  fill_solid(leds,NUM_LEDS,CRGB(247,50, 255));
  FastLED.show();
  color_1 =0;
 }
 break;
FastLED.clear();

case 0xFF18E7:  // change color to a rose white or a darkblue (button 2 on the remote)
  if(color_2 == 0){
   fill_solid(leds,NUM_LEDS,CRGB(58, 81, 157)); 
   FastLED.show();
   color_2 = 1;
 } 
 else{
  fill_solid(leds,NUM_LEDS,CRGB::DeepSkyBlue);
  FastLED.show();
  color_2 =0;
 }
 break;
FastLED.clear();

 case 0xFF7A85: // change color  (button 3 on the remote)
  if(color_3 == 0){
   fill_solid(leds,NUM_LEDS,CRGB::Gold);
   FastLED.show();
   color_3 = 1;
 }
 else{
  fill_solid(leds,NUM_LEDS,CRGB(255, 185, 25));
  FastLED.show();
  color_3 =0;
 }
 break;
FastLED.clear();

  case 0xFF10EF:   //button 4 on the remote, change color
    if (color_4 == 0){
      fill_solid(leds,NUM_LEDS,CRGB(111, 150, 23));
      FastLED.show();
      color_4=1;
    }
    else{
      fill_solid(leds,NUM_LEDS,CRGB(17, 200, 59));
      FastLED.show();
      color_4=0;
    }
      break;
      FastLED.clear();


case 0xFF38C7: //button 5 on the remote, change color
    if (color_5 == 0){
      fill_solid(leds,NUM_LEDS,CRGB::LimeGreen);
      FastLED.show();
      color_5=1;
    }
    else{
      fill_solid(leds,NUM_LEDS,CRGB::LawnGreen);
      FastLED.show();
      color_5=0;
    }
      break;
      FastLED.clear();



      case 0xFF5AA5: //button 6 on the remote, change color
    if (color_6 == 0){
      fill_solid(leds,NUM_LEDS,CRGB(215, 53, 2));
      FastLED.show();
      color_6=1;
    }
    else{
      fill_solid(leds,NUM_LEDS,CRGB::DarkOrange);
      FastLED.show();
      color_6=0;
    }
      break;
      FastLED.clear();


   case 0xFF42BD: //button 7 on the remote
    if (color_7 == 0){
      fill_solid(leds,NUM_LEDS,CRGB(75 ,14, 246));
      FastLED.show();
      color_7=1;
    }
    else{
      fill_solid(leds,NUM_LEDS,CRGB(246,14,75));
      FastLED.show();
      color_7=0;
    }
      break;
      FastLED.clear();


 case 0xFF4AB5: //button 8 on the remote, change color
    if (color_8 == 0){
      fill_solid(leds,NUM_LEDS,CRGB(122,180,169));
      FastLED.show();
      color_8=1;
    }
    else{
      fill_solid(leds,NUM_LEDS,CRGB(139,35,235));
      FastLED.show();
      color_8=0;
    }
      break;
      FastLED.clear();

      

case 0xFF52AD: //button 9 on the remote, change color
    if (color_9 == 0){
      fill_solid(leds,NUM_LEDS,CRGB(0, 252, 126));
      FastLED.show();
      color_9=1;
    }
    else{
      fill_solid(leds,NUM_LEDS,CRGB(139, 252, 0));
      FastLED.show();
      color_9=0;
    }
      break;
      FastLED.clear();
    

    

   case 0xFFA25D:  // play a chaser animation button CH- on the remote
      
   chaser();
      
   break;

  case 0xFF629D: // little animation of a rainbow poping on and off for 2 seconds ( button CH on the remote)
    fill_rainbow(leds,NUM_LEDS,0,255/NUM_LEDS);
    FastLED.show();
    delay(2000);
 
    FastLED.clear();
    fill_solid(leds,NUM_LEDS,CRGB::Black);
    FastLED.show();
  
  break;
  case 0xFFE21D: // button CH+ on the remote, play a breath like animation of rainbow color
       breath();
       break;
  
  }
  irrecv.resume();
  }
}
 void breath() //function to play a breath in and out animation with rainbow colors
{
  for (unsigned long i=0; i<10000; i++){//2 cicluri complete 
   FastLED.setBrightness(ease8InOutCubic(ease8InOutCubic(beatsin8(5))));
     fill_rainbow(leds,NUM_LEDS,0,255/NUM_LEDS);
     FastLED.show();
      
     } 
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } } // fade animation not binded to any key yet
  
void chaser(){

for(long int j=0; j<10; j++){ //10 cicluri
static uint8_t hue = 0;
  for(uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show(); 
    fadeall();
    delay(50);
  }
  
  for(uint8_t i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    delay(50);
  }
}

}
 



  


 

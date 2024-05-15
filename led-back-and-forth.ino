//Global Variables
#define LED1 1 
#define LED2 2 
int blinkDelay = 750;

//Set pin numbers
void setup() {
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
}

void loop() {
  
  //For LED 1
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(blinkDelay); 
  
  //For LED 2
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(blinkDelay);
}

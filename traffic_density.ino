int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading1; // the analog reading from the FSR resistor divider
int fsrReading2;
int plateA[1000][2], plateB[1000][2];
int i = 0;
long ti[100];
int t_counter = 0;

void findReading(int reading2, long time){
  for (int j = 0; j < i; j++){
    if (plateA[j][0] == reading2){
      t[t_counter] = time - plateA[j][1];
      plateA[j][0] = -1;
      plateA[j][1] = -1;
      t_counter++;
    }
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long time = millis(); //start the timer
  
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  if (fsrReading1 > 100) {
    plateA[i][0] = fsrReading1;
    plateA[i][1] = time;
  }
  
  if (fsrReading2 > 100) {
    plateB[i][0] = fsrReading2;
    plateB[i][1] = time;
    findReading(fsrReading2, time);
  }

  delay(1000);
  i++;  
}

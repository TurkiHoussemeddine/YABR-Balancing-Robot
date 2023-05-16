byte send_byte;
int VRX, VRY;
void setup() {
  Serial.begin(38400); 
  delay(20);
}

void loop() {
  VRX = analogRead(A0);
  VRY = analogRead(A1);
  send_byte = B00000000;                                            //Set the send_byte variable to 0
  if(VRX < 400)send_byte |= B00000001;                  //If the variable received_data[0] is smaller then 80 set bit 0 of the send byte variable
  if(VRX > 650)send_byte |= B00000010;                 //If the variable received_data[0] is larger then 170 set bit 1 of the send byte variable
  if(VRY < 400)send_byte |= B00000100;                  //If the variable received_data[1] is smaller then 80 set bit 3 of the send byte variable
  if(VRY > 650)send_byte |= B00001000;                 //If the variable received_data[1] is larger then 170 set bit 2 of the send byte variable
  //delay(1);
  if(send_byte)Serial.write((char)send_byte);                       //Send the send_byte variable if it's value is larger then 0
  //delay(1);                                                        //Create a 40 millisecond loop delay
}

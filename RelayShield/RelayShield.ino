 /**
 *  Name: RelayShield.ino
 *  Purpose: The main code for the Relay shield of the 23G vending machine project.
 *  It receives input from the WifiShield and controls the vending machine. 
 *
 *  @author: Christian Slabbekoorn
 *  @date: December 13th, 2017
 **/

void setup() 
{
  

  shieldcomm.beginSerial(new SoftwareSerial(RX_SERIAL, TX_SERIAL), 9600);
}

void loop() 
{
  

}

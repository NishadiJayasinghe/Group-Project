#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D8
#define RST_PIN D3
MFRC522 mfrc522(SS_PIN, RST_PIN);
 
const char* ssid     = "nyn";
const char* password = "nayana1111";
const char* host = "dnmadhuwantha.000webhostapp.com";

  
void setup() {
  Serial.begin(115200);
  delay(100);
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
}
String town1="balangoda";
String town2="pambahinna";
String town3="beragala";

void loop() {
  
  
  String busid1="NC-4053";
  String busid2="NA-6370";
  String busid3="MC-6534";
  String busid4="CA-7625";
  

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  //////////////

  Serial.print("connecting to ");
  Serial.println(host);

  
  //////////////////////////

  if (content.substring(1) == "25 2B BA 11"){
    sendRequest(busid1);
  }
 
  else  if (content.substring(1) == "27 99 02 89") {
    sendRequest(busid2);
    
  }
  else  if (content.substring(1) == "20 52 89 7C") {
    sendRequest(busid3);
  }

  else  if (content.substring(1) == "98 DE D7 B9") {
    sendRequest(busid4);
  }
  
  Serial.println();
  Serial.println("closing connection");
  Serial.println();
  Serial.println();

}

void sendRequest(String busid){
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  else{
    Serial.print("connected to ");
    Serial.println(host);
  }
  
  String url = "/findmybus/api/insert.php?busid=" + String(busid) + "&town="+ String(town1);
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    delay(400);
    
    while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    }
    /////////////////////

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  else{
    Serial.print("connected to ");
    Serial.println(host);
  }
    Serial.println();
     url = "/findmybus/api/update.php?busid=" + String(busid) + "&town="+ String(town2)+"&checked=0";
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    delay(400);

    while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    }
    /////////////////////
    
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }
    else{
      Serial.print("connected to ");
      Serial.println(host);
    }

    url = "/findmybus/api/update.php?busid=" + String(busid) + "&town="+ String(town3)+"&checked=0";
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    
    delay(400);

    while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
   
  }
  //////
  if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }
    else{
      Serial.print("connected to ");
      Serial.println(host);
    }

    url = "/findmybus/api/delete.php?busid=" + String(busid);
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    
    delay(400);

    while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
   
  }
}





#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include <ESP8266mDNS.h>
#include "index.h"

#define SSID_NAME	"prjball"
#define SSID_PASS	""
#define WIFI_SSID "YOURSSID"
#define WIFI_PWD "YOURPASS"

#define V3 
//#define FORCE_AP_MODE
#define COUNT_MAX	50


ESP8266WebServer server(80);

struct Wifi_Config {
char ssid[32];
char pass[32];
};

Wifi_Config wifi_con_mem;
Wifi_Config wifi_con;


void RootGet() {
    server.send(200, "text/html", str_html);
}

void RootPost() {
  String ssid = server.arg("SSID");
  String pass = server.arg("PASS");
  String angle = server.arg("Angle");
  String frame = server.arg("Frame");
  server.send(200, "text/html", str_html); 
  //server.send(200, "text/html","OK");
  
  if(frame!=""){
  	Serial.print("fno=");
  	Serial.println(frame);
  }
  else if(angle!=""){
  	Serial.print("deg=");
  	Serial.println(angle);
  }
  else if(ssid!=""){
  	char chrssid[32];
  	char chrpass[32];
  	ssid.toCharArray(chrssid,sizeof(chrssid));
  	pass.toCharArray(chrpass,sizeof(chrpass));;
  	strcpy(wifi_con.ssid, chrssid);
  	strcpy(wifi_con.pass, chrpass);
  	EEPROM.put<Wifi_Config>(0, wifi_con);
  	EEPROM.commit();
  	Serial.println("***Saved Wifi Settings***");
  	Serial.println(wifi_con.ssid);		  
  }  
}

void SetRemote(){
  Serial.println("urm");
  server.send(200, "text/html","OK");
}

void SetLocal(){
  Serial.println("swm");
  server.send(200, "text/html","OK");
}

void SetStart(){
  Serial.println("srt");
  server.send(200, "text/html","OK");
}

void SetStop(){
  Serial.println("stp");
  server.send(200, "text/html","OK");
}

void SetFPause(){
  Serial.println("fpa");
  server.send(200, "text/html","OK");
}

void SetInternal(){
  Serial.println("inm");
  server.send(200, "text/html","OK");
}

void SetMemory(){
  Serial.println("sdm");
  server.send(200, "text/html","OK");
}

void SetMode0(){
  Serial.println("frm");
  server.send(200, "text/html","OK");
}
void SetMode1(){
  Serial.println("rot");
  server.send(200, "text/html","OK");
}
void SetMode2(){
  Serial.println("str");
  server.send(200, "text/html","OK");
}
void SetMode3(){
  Serial.println("alw");
  server.send(200, "text/html","OK");
}
void SetPattern0(){
  Serial.println("sw0");
  server.send(200, "text/html","OK");
}
void SetPattern1(){
  Serial.println("sw1");
  server.send(200, "text/html","OK");
}
void SetPattern2(){
  Serial.println("sw2");
  server.send(200, "text/html","OK");
}
void SetPattern3(){
  Serial.println("sw3");
  server.send(200, "text/html","OK");
}

void setup() {
	
	int count=0;
	SetHtml();
	Serial.begin(9600);
	while (!Serial);
	Serial.println(" *Initialized!!* ");
	
	EEPROM.begin(100);
	
	EEPROM.get<Wifi_Config>(0, wifi_con_mem);
	Serial.println(wifi_con_mem.ssid[0]);
 
	if(wifi_con_mem.ssid[0]==NULL){
		//Set Default AP
		strcpy(wifi_con.ssid, WIFI_SSID);
		strcpy(wifi_con.pass, WIFI_PWD);
		Serial.print("Default: ");
    Serial.println(wifi_con.ssid);   
  }else{
		//Set memoey AP
		strcpy(wifi_con.ssid, wifi_con_mem.ssid);
		strcpy(wifi_con.pass, wifi_con_mem.pass);
		Serial.print("Memory:");
    Serial.println(wifi_con.ssid);   			
	}
	
#ifndef FORCE_AP_MODE	
	//Start Wifi Initialize as Client Mode
	WiFi.begin(wifi_con.ssid, wifi_con.pass);
  // Wait until WiFi is connected
  Serial.println("");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    count++;
    if(count>COUNT_MAX)break;
  } 
#endif

	
	Serial.println("");
	//Client Mode
	if(WiFi.status() == WL_CONNECTED){
		Serial.println("**Client Mode**");
		Serial.println("");
		Serial.println("Connected!");
		Serial.print("IP Address: ");
		Serial.println(WiFi.localIP());
		
	}else{
		//Server Mode
		Serial.println("Cannot Find AP. Starting as Server Mode.");
		Serial.println("**Server Mode**");
		byte mac[6];
    String macadr;
		WiFi.macAddress(mac);
    for (int i = 0; i < 6; i++) {
      macadr += String(mac[i], HEX);
    }
    Serial.println("MAC: " + macadr);
		String ssid = "";
		String pass = "";
		ssid=SSID_NAME + String(mac[5], HEX);
		pass="";
		WiFi.softAP(ssid.c_str(), pass.c_str());
    Serial.print("AP SSID: ");
    Serial.print(ssid);
    Serial.print(" PASS: ");
    Serial.println(pass);
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
	}
  

	// Web server setting
  server.on("/", HTTP_GET, RootGet);
	server.on("/", HTTP_POST, RootPost);	
	server.on("/remote/", SetRemote);
	server.on("/local/", SetLocal);
	server.on("/start/", SetStart);
	server.on("/stop/", SetStop);
	server.on("/fpause/", SetFPause);
	server.on("/internal/", SetInternal);
	server.on("/memory/", SetMemory);
	server.on("/mode0/", SetMode0);//animation
	server.on("/mode1/", SetMode1);
	server.on("/mode2/", SetMode2);
	server.on("/mode3/", SetMode3);
	server.on("/pattern0/", SetPattern0);
	server.on("/pattern1/", SetPattern1);
	server.on("/pattern2/", SetPattern2);
	server.on("/pattern3/", SetPattern3);
  server.begin();
  
   if (!MDNS.begin(SSID_NAME)) {
      //ERROR MDNS responder      
    }
    else{
      //MDNS responder started
      MDNS.addService("http", "tcp", 80);      
   }
 Serial.println("Wifi-Init-End");
}

void loop() {
        
  server.handleClient();
   
}

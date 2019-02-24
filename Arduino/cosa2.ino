#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <SocketIoClient.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;
SocketIoClient webSocket;
long randNumber;


void event(const char * payload, size_t length) {
  USE_SERIAL.printf("got message: %s\n", payload);
}

void setup() {
    USE_SERIAL.begin(115200);

    USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

      

    WiFiMulti.addAP("IZZI-A57B", "2WC468402329");

    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    webSocket.on("connect", event);
    webSocket.begin("192.168.0.5", 700);
    // use HTTP Basic Authorization this is optional remove if not needed
    randNumber = random(300);
    while(true){
        delay(100);
        socket.emit("Temperatura", "{\"foo\":\""+randNumber+"\"}");
    }
}

void loop() {
    webSocket.loop();
}

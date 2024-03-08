#include <RealTimeEsp.h>
#include <ESP8266WiFi.h>

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY)
#error Select ESP8266 board
#endif

// Replace with your network credentials
#define SSID "REPLACE_WITH_YOUR_SSID"
#define PASS "REPLACE_WITH_YOUR_PASSWORD"

// Setting up the timeclient
// You need to include your time zone, for me GMT+7
TimeClient realtime(7);

void setup() {
  //Intiallize Serial Monitor
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  // Initialize realtime client
  realtime.setup();
}

void loop() {
  // Update the time
  realtime.update();
  Serial.print("Epoch Time: ");
  Serial.println(realtime.getEpochTime());

  Serial.print("Current Hour: ");
  Serial.println(realtime.getHour());
  Serial.print("Current Minute: ");
  Serial.println(realtime.getMinute());
  Serial.print("Current Second: ");
  Serial.println(realtime.getSecond());

  Serial.print("Formatted Time (24-hour) : ");
  Serial.println(realtime.getFormattedTime());
  Serial.print("Formatted Time (12-hour) : ");
  Serial.println(realtime.getFormattedTime(true));

  Serial.print("Current Week Day: ");
  Serial.println(realtime.getWeekDay());
  Serial.print("Current Week Day Name: ");
  Serial.println(realtime.getWeekDayName());
  Serial.print("Current Week Day Name (Shorten Form): ");
  Serial.println(realtime.getWeekDayName(true));

  Serial.print("Current Month Day: ");
  Serial.println(realtime.getMday());

  Serial.print("Current Month: ");
  Serial.println(realtime.getMonth());
  Serial.print("Current Month Name: ");
  Serial.println(realtime.getMonthName());
  Serial.print("Current Month Name (Shorten Form): ");
  Serial.println(realtime.getMonthName(true));

  Serial.print("Current Year: ");
  Serial.println(realtime.getYear());

  Serial.print("Current Date (American Style): ");
  Serial.println(realtime.getDate("American"));
  Serial.print("Current Date (British Style): ");
  Serial.println(realtime.getDate("British"));
  Serial.print("Current Date (International Style): ");
  Serial.println(realtime.getDate("International"));
  
  Serial.println();
  delay(2000);
}

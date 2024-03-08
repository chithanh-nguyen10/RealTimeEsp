#include <NTPClient.h>
#include <WiFiUdp.h>
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

class TimeClient
{
  private:
    WiFiUDP ntpUDP;
    NTPClient* timeClient;
    String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    String weekDayshort[7]={"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};
    String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    String monthshort[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int offset;
    struct tm* ptm;
    time_t epochTime;

  public:
    void setup();
    void update();
    long long getEpochTime();
    int getHour();
    int getMinute();
    int getSecond();


    //Sunday: 0, Monday: 1, ..., Saturday: 6
    int getWeekDay();


    //Get Weekday name (Sunday -> Saturday), short forms (Sun -> Sat)
    String getWeekDayName(bool is_short = false);


    /*
    Return the formatted time HH:MM:SS
    style=false: 24-hour style
    style=true: 12-hour style
    */
    String getFormattedTime(bool style=false);

    int getMday();
    int getMonth();
    //Get Month name (January -> December), short forms (Jan -> Dec)
    String getMonthName(bool is_short = false);
    int getYear();


    /*
    Return the numberic date in American, British or Internatinal Style
    American: MM/DD/YYYY
    British: DD/MM/YYYY
    International: YYYY/MM/DD
    The default seperate character is '/'
    */
    String getNumericDate(String style, char sep = '/');


    /*
    Return the numberic date in American, British or Internatinal Style
    American: MM/DD/YYYY Ex: September 6, 2019
    British: DD/MM/YYYY Ex: 6 September 2019
    International: YYYY/MM/DD Ex: 2019 September 6
    */
    String getDate(String style, bool is_short=false);


    // Formatted Time without second
    String getFormattedTimeLite(bool style=false);
    // Numeric date without year
    String getNumericDateLite(String style, char sep = '/');
    // Date without year
    String getDateLite(String style, bool is_short=false);

    TimeClient(int);
};
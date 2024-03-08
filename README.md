# Realtime Esp
An Arduino library for reading the current time from NTP Client-Server.
Original written by chithanh-nguyen10.
This library works for ESP8266 and ESP32.
## Features
* Read current time from server with shorter syntax.
* Using the current time data to mar IOT project for graphs, clock, ...
* Get the formatted date, time in many styles.
## Structure
``` cpp
TimeClient(int timezone);
```
Every functions in this library is use for this function. To intialize the structure you need to input your timezone. Example: GMT+7, you need to input 7
### Functions
```cpp
void TimeClient::setup();
```
* Setup the TimeClient, the command fails if the wifi is not connected.
```cpp
void TimeClient::update();
```
* Update the current time, you need to put it in loop function to update the current time.
```cpp
long long TimeClient::getEpochTime();
```
* Get the current epoch time
```cpp
int TimeClient::getHour();
```
* Get the current hour
```cpp
int TimeClient::getMinute();
```
* Get the current minute
```cpp
int TimeClient::getSecond();
```
* Get the current second
``` cpp
int TimeClient::getWeekDay();
```
* Get the current week day in number.
* Sunday: 0, Monday: 1, Tuesday: 2, ..., Saturday: 6.
``` cpp
String TimeClient::getWeekDayName(bool is_short=false);
```
* Get the current week day in text, if the is_short agrument is true the function will return the shorten form of the week day name (Ex: Sun, Mon, Tue).
``` cpp
String TimeClient::getFormattedTime(bool style=false);
```
* Get the current time in the format HH:MM:SS in 24-hour clock. If the style is true, it will return the format in 12-hour clock.
```cpp
int TimeClient::getMday();
```
* Get the current month day
```cpp
int TimeClient::getMonth();
```
* Get the current month
```cpp
int TimeClient::getYear();
```
* Get the current year
``` cpp
String TimeClient::getMonthName(bool is_short=false);
```
* Get the current month name, if the is_short agrument is true the function will return the shorten form of the week day name (Ex: Jan, Feb, Mar).

``` cpp
String TimeClient::getNumericDate(String style, char sep = '/');
```
* The default seperator character is '/'
* The function will return the numeric date in Amerian (MM/DD/YYYY), British (DD/MM/YYYY) or International (YYYY/MM/DD) style

``` cpp
String TimeClient::getDate(String style, bool is_short=false);
```
* The function will return the date in Amerian, British or International style
* If the is_short agrument is true, the month name will be shorten

``` cpp
String TimeClient::getFormattedTimeLite(bool style=false);
```
* Formatted Time without second
``` cpp
String TimeClient::getNumericDateLite(String style, char sep = '/');
```
* Numeric date without year
``` cpp
String TimeClient::getDateLite(String style, bool is_short=false);
```
* Date without year
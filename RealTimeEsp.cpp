#include "RealTimeEsp8266.h"

TimeClient::TimeClient(int timezone) {
  offset = timezone*3600;
  timeClient = new NTPClient(ntpUDP, "pool.ntp.org");
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
}

void TimeClient::setup(){
  // Check the Wifi connection
  //Setup timeclient
  timeClient->begin();
  timeClient->setTimeOffset(offset);
}

//Update time
void TimeClient::update(){
  timeClient->update();
}

long long TimeClient::getEpochTime(){
  time_t epochTime = timeClient->getEpochTime();
  long long res = (long long)epochTime;
  return res;
}

int TimeClient::getHour(){
  return timeClient->getHours();
}

int TimeClient::getMinute(){
  return timeClient->getMinutes();
}

int TimeClient::getSecond(){
  return timeClient->getSeconds();
}

int TimeClient::getWeekDay(){
  return timeClient->getDay();
}


String TimeClient::getWeekDayName(bool is_short){
  int wd = timeClient->getDay();
  if (is_short) return weekDayshort[wd];
  else return weekDays[wd];
}

String TimeClient::getFormattedTime(bool style){
  String suff = "A.M.";
  int hr = timeClient->getHours();
  String h = String(timeClient->getHours());
  String m = String(timeClient->getMinutes());
  String s = String(timeClient->getSeconds());
  if (hr>=12 && style){
    hr-=12;
    suff = "P.M.";
  }
  if (style && hr==0) hr = 12;
  if (style) h = String(hr);
  if (h.length() == 1) h = "0" + h;
  if (m.length() == 1) m = "0" + m;
  if (s.length() == 1) s = "0" + s;
  if (!style) return h+":"+m+":"+s;
  else return h+":"+m+":"+s+" "+suff;
}

int TimeClient::getMday(){
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  return ptm->tm_mday;
}

int TimeClient::getMonth(){
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  return ptm->tm_mon+1;
}

int TimeClient::getYear(){
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  return ptm->tm_year+1900;
}

String TimeClient::getMonthName(bool is_short){
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  int m = ptm->tm_mon+1;
  if (is_short) return monthshort[m-1];
  else return months[m-1];
}

String TimeClient::getNumericDate(String style, char sep){
  assert(style == "American" || style == "British" || style == "International");
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  int d = ptm->tm_mday;
  int m = ptm->tm_mon+1;
  int y = ptm->tm_year+1900;
  if (style == "American") return String(m)+sep+String(d)+sep+String(y);
  else if (style == "British") return String(d)+sep+String(m)+sep+String(y);
  else return String(y)+sep+String(m)+sep+String(d);
}

String TimeClient::getDate(String style, bool is_short){
  assert(style == "American" || style == "British" || style == "International");
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  int d = ptm->tm_mday;
  int m = ptm->tm_mon+1;
  int y = ptm->tm_year+1900;
  String moname;
  if (is_short) moname = monthshort[m-1];
  else moname = months[m-1];

  if (style == "American") return moname+' '+String(d)+", "+String(y);
  else if (style == "British") return String(d)+' '+moname+' '+String(y);
  else return String(y)+' '+moname+' '+String(d);
}

String TimeClient::getFormattedTimeLite(bool style){
  String suff = "A.M.";
  int hr = timeClient->getHours();
  String h = String(timeClient->getHours());
  String m = String(timeClient->getMinutes());
  if (hr>=12 && style){
    hr-=12;
    suff = "P.M.";
  }
  if (style && hr==0) hr = 12;
  if (style) h = String(hr);
  if (h.length() == 1) h = "0" + h;
  if (m.length() == 1) m = "0" + m;
  if (!style) return h+":"+m;
  else return h+":"+m+" "+suff;
}

String TimeClient::getNumericDateLite(String style, char sep){
  assert(style == "American" || style == "British" || style == "International");
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  int d = ptm->tm_mday;
  int m = ptm->tm_mon+1;
  if (style == "American") return String(m)+sep+String(d);
  else if (style == "British") return String(d)+sep+String(m);
  else return String(m)+sep+String(d);
}

String TimeClient::getDateLite(String style, bool is_short){
  assert(style == "American" || style == "British" || style == "International");
  epochTime = timeClient->getEpochTime();
  ptm = gmtime ((time_t *)&epochTime);
  int d = ptm->tm_mday;
  int m = ptm->tm_mon+1;
  String moname;
  if (is_short) moname = monthshort[m-1];
  else moname = months[m-1];

  if (style == "American") return moname+' '+String(d);
  else if (style == "British") return String(d)+' '+moname;
  else return moname+' '+String(d);
}
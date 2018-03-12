#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <string>
#include <list>

struct timeTableElem{
  std::string name,
  s_dep, s_arr,
  s_dep_h, s_dep_m,
  s_arr_h, s_arr_m;
  int i_dep, i_arr;
  void StrToInt(){
      s_dep=s_dep_h+s_dep_m;
      s_arr=s_arr_h+s_arr_m;
      i_dep=stoi(s_dep); i_arr=stoi(s_arr);
  }
};


class TimeTable{
private:
    unsigned int count=0;
    std::string line;
    static int countElem;
    std::list<timeTableElem> listElem;
public:
    void modTimeTable();
    void display();
    void read();
    void write();
};

#endif // TIMETABLE_H

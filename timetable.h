#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <string>
#include <list>

struct timeTableElem{//struct describe TimeTableRows
  std::string name,
  s_dep, s_arr,
  s_dep_h, s_dep_m,
  s_arr_h, s_arr_m;
  int i_dep, i_arr;
  void StrToInt(){// meth. convert string to int
      s_dep=s_dep_h+s_dep_m;
      s_arr=s_arr_h+s_arr_m;
      i_dep=stoi(s_dep); i_arr=stoi(s_arr);
  }
};


class TimeTable{//cl
private:
    unsigned int count=0;
    std::string line;
    static int countElem;
    std::list<timeTableElem> listElem;//TimeTableElement list
public:
    void modTimeTable();//main meth. which modified TimeTable
    void display();//show TimeTable
    void read();//read TimeTable from file(parsing TimeElem)
    void write();//write TimeTable in file
};

#endif // TIMETABLE_H

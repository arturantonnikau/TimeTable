#include <iostream>
#include "timetable.h"

int main()
{
    TimeTable obj;
    obj.read();
    obj.display();
    obj.modTimeTable();
    std::cout<<std::endl;
    obj.display();
    obj.write();

    return 0;
}

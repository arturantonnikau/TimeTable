#include "timetable.h"

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <algorithm>


void TimeTable::modTimeTable(){

    listElem.remove_if([](timeTableElem remElem){//remote service longer than an hour
            if((remElem.i_arr-remElem.i_dep)>100){
                return true;
            }else return false;
    });

    listElem.sort([](const timeTableElem &a, const timeTableElem &b){//service longer than an hour
            if(a.i_dep<b.i_dep){
                return true;
            }else return false;
    });

    while(count!=listElem.size()){
    std::list<timeTableElem>::iterator it=listElem.begin();
        for(std::list<timeTableElem>::iterator it_next=next(listElem.begin());it_next!=listElem.end() ;it++,it_next++){
            if(it->name=="Posh" && it_next->name=="Grotty"){//service having the same departure and arrival
                if(it->i_dep==it_next->i_dep && it->i_arr==it_next->i_arr){//times then always choose Posh Bus Company
                    listElem.erase(it_next);
                    break;
                }
            }
            if(it->i_dep==it_next->i_dep && it->i_arr<it_next->i_arr){//starts at the same time and reaches earlier
                //std::cout<<"FIND 1";
                listElem.erase(it_next);
                break;
            }
            if(it->i_dep<it_next->i_dep && it->i_arr==it_next->i_arr){// starts later and reaches at the same time
                    //std::cout<<"FIND 2";
                    listElem.erase(it);
                    break;
             }
            if(it->i_dep<it_next->i_dep && it->i_arr>it_next->i_arr){//starts later and reaches earlier
                    std::cout<<"FIND 3";
                    listElem.erase(it);
                    break;
            }
        }
       count++;
    }
    listElem.sort([](const timeTableElem &a, const timeTableElem &b){//push down Grotty Elem
            if(a.name=="Posh" && b.name=="Grotty"){
                return true;
            }else return false;
    });
}


void TimeTable::display(){//show all Elem
    if(!(listElem.empty())){
        for(std::list<timeTableElem>::iterator it=listElem.begin();it!=listElem.end();it++){
            std::cout<<it->name<<" "<<it->s_dep_h<<":"<<it->s_dep_m<<" "<<it->s_arr_h<<":"<<it->s_arr_m<<std::endl;
        }

    }
}

void TimeTable::read(){//parsing a file
    std::string line;
    std::ifstream inf;
    inf.open("D:/QTProjects/TimeTable/timetable.txt");
    while(inf.good()){
        timeTableElem temp;
        getline(inf,line);
        std::stringstream strstream(line);
            getline(strstream,temp.name,' ');
            getline(strstream,temp.s_dep_h,':');
            getline(strstream,temp.s_dep_m,' ');
            getline(strstream,temp.s_arr_h,':');
            getline(strstream,temp.s_arr_m,'\n');
            temp.StrToInt();
            listElem.push_back(temp);
    }
    inf.close();
}

void TimeTable::write(){//write data in file
    std::ofstream outf("D:/QTProjects/TimeTable/timetableResult.txt");
    for(std::list<timeTableElem>::iterator it=listElem.begin();it!=listElem.end();it++){
        if(it->name=="Posh"){outf<<it->name<<' '<<it->s_dep_h<<":"<<it->s_dep_m<<' '<<it->s_arr_h<<":"<<it->s_arr_m<<std::endl;}
        else{outf<<std::endl<<it->name<<' '<<it->s_dep_h<<":"<<it->s_dep_m<<' '<<it->s_arr_h<<":"<<it->s_arr_m<<std::endl;}
    }
}

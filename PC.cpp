#include "PC.h"
#include <iostream>
#include <vector>
using namespace std;
PC::PC(){

}

PC::PC(string ip_new, string mascara_new, string hostname_new){
    this->ip=ip_new;
    this->mascara=mascara_new;
    this->hostname=hostname_new;
}

string PC::getip(){
    return ip;
}

void PC::setip(string ip_new){
    ip=ip_new;
}

string PC::getmascara(){
    return mascara;
}

void PC::setmascara(string mascara_new){
    mascara=mascara_new;
}

string PC::gethostname(){
    return hostname;
}

void PC::sethostname(string hostname_new){
    hostname=hostname_new;
}


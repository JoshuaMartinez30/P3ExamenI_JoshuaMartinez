#include <iostream>
#include <vector>
using namespace std;

#ifndef PC_H
#define PC_H

class PC{
    private:
    string ip, mascara, hostname;
    public:
    PC();
    PC(string, string, string);
    string getip();
    void setip(string);
    string getmascara();
    void setmascara(string);
    string gethostname();
    void sethostname(string);
    void Show(int);
    void ping(int);
    ~PC();
};
#endif
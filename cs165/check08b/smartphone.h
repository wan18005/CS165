/****************
 * smartphone.h
 ****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

// TODO: Put your SmartPhone definition here
#include <string>

#include "phone.h"

using namespace std;

class SmartPhone : public Phone
{
private:
   string email;

public:
   void prompt();
   void display();
};

#endif

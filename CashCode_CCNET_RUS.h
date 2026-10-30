
#ifndef CashCode_CCNET_RUS_h
#define CashCode_CCNET_RUS_h

#include "Arduino.h"

class CashCode_CCNET_RUS
{
  public:
    CashCode_CCNET_RUS(int speed);
    void update();
    int getBanknote();
    void disable();
    void enable();
    void reset();
};

#endif

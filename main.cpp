#include <iostream>
#include <string>

#include "controller.h"

#define valuesPerLine 3
#include "serial/serial.h"

int main()
{
  SerialCom::Controller* pController = new SerialCom::Controller();
  pController -> initCommunication();
}

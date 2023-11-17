#include "serialDriver.h"
#include "utilities.h"
#include <limits>
#include <iostream>


#define valuesPerLine 3


void SerialCom::Controller::initCommunication()
{
	bool bCorrectInputFlag = false;
	int iSerialPort = 0;
	std::string sSerialPort;
	uint32_t ui32tBaudrate = 0;
	uint32_t ui32tTimeout = 0;

	SerialDriver* m_pSerialDriver = new SerialDriver();

	std::cout << "Which port do you want to use? Please type port numer ..."  << std::endl;
	std::cin >> iSerialPort;
	m_pSerialDriver -> setSeriaPort(iSerialPort);

	sSerialPort = "COM" + iSerialPort;
	m_pSerialDriver -> setSeriaPort(m_sSerialPort);

	std::cout << "Which baudrate do you want to use? Please select of the following ..."  << std::endl;
	int i = 0;
	while(i <= ((sizeof(aiBaudrates)/sizeof(int)) - valuesPerLine)){
		std::cout << aiBaudrates[i] << " " << aiBaudrates[i+1] << " " << aiBaudrates[i+2] << std::endl;
		i = i + valuesPerLine;
	}

	while(!bCorrectInputFlag){
		std::cin >> ui32tBaudrate;
		if(!checkArrayContains(ui32tBaudrate, aiBaudrates, sizeof(aiBaudrates)/sizeof(uint32_t))){
			std::cout << "Please type a baudrate from the list!";
		} else {
			bCorrectInput = true;
			m_pSerialDriver -> setBaudrate(ui32tBaudrate);
		}
	}

	bCorrectInputFlag = false;

	std::cout << "Which Timeout do you want to use?"  << std::endl;
	while (!bCorrectInput){
		std::cin >> ui32tTimeout;
		while(isType(ui32tTimeout, "uint32_t");
		if(((ui32tTimeout > std::numeric_limits<uint32_t>::min()) && (ui32tTimeout < std::numeric_limits<uint32_t>::max())){
			bCorrectInput = true;
		} else {
			std::cout << "Please type a realistic timeout!";
		}
	}
/*
	bCorrectInputFlag = false;

	std::cout << "How many databits do you want to use? Type a value between 5 and 8..."  << std::endl;
	while (!bCorrectInput){
		std::cin >> ui32tTimeout;
		if(ui32tTimeout){
			std::cout << "Please type a baudrate from the list!";
		} else {
			bCorrectInput = true;
		}
	}



	try
  {
    m_pSerialPort = make_unique<Serial>(m_port, ui32tBaudrate, Timeout::simpleTimeout(ui32tTimeout), eightbits,
                                        parity_none, stopbits_one, flowcontrol_none);
  } mcatch (exception& e)
  {
    cerr << "Exception at initialization of" + sSerialPort + ": " << e.what() << endl;
    return XRayCtrlResult::FAILED;
  }
*/
}

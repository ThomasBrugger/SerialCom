#include "view.h"
#include "utilities.h"

namespace SerialCom{
	#define valuesPerLine 3
}

int SerialCom::View::getSerialPortNumber(){
	int iSerialPort = 0;
	std::string outputText = "Which port do you want to use? Please type port numer ... ";
	iSerialPort = printTextAndValidateInput(outputText,iSerialPort);
	return iSerialPort;
}

uint32_t SerialCom::View::getBaudrate(){
	uint32_t ui32tBaudrate = 0;
	std::string outputText = "Which baudrate do you want to use? Please select of the following ... ";
	int i = 0;
	while(i <= ((sizeof(aiBaudrates)/sizeof(int)) - valuesPerLine)){
		outputText += ('\n' + std::to_string(aiBaudrates[i]) + " " + std::to_string(aiBaudrates[i+1]) + " " + std::to_string(aiBaudrates[i+2]));
		i = i + valuesPerLine;
	}
	outputText += " ... ";

	ui32tBaudrate = printTextAndValidateInput(outputText,ui32tBaudrate);
	while(!checkArrayContains(ui32tBaudrate, aiBaudrates, sizeof(aiBaudrates)/sizeof(uint32_t))){
		std::cout << "Please type a baudrate of the list!" << std::endl;
		ui32tBaudrate = printTextAndValidateInput(outputText,ui32tBaudrate);
	}
	return ui32tBaudrate;
}

uint32_t SerialCom::View::getTimeout(){
	uint32_t ui32tTimeout = 0;
	std::string outputText = "Which Timeout do you want to use? Type a value between 0 and 4294967295 ... ";
	ui32tTimeout = printTextAndValidateInput(outputText,ui32tTimeout);
	while(!((ui32tTimeout > std::numeric_limits<uint32_t>::min()) && (ui32tTimeout < std::numeric_limits<uint32_t>::max()))){
		std::cout << "Please type a timeout between 0 and 4294967295" << std::endl;
		ui32tTimeout = printTextAndValidateInput(outputText,ui32tTimeout);
	}
	return ui32tTimeout;
}

int SerialCom::View::getBytesize(){
	int iByteSize = 0;
	std::string outputText = "How many databits do you want to use? Type a value between 5 and 8 ... ";
	iByteSize = printTextAndValidateInput(outputText,iByteSize);
	while(!((iByteSize >= 5) && (iByteSize <= 8))){
		std::cout << "Please type a value between 5 and 8" << std::endl;
		iByteSize = printTextAndValidateInput(outputText,iByteSize);
	}
	return iByteSize;
}

int SerialCom::View::getParity(){
	int iParity = 0;
	std::string outputText = "Which parity do you want to use? Type 0 = parity_none, 1 = parity_odd, 2 = parity_even, 3 = parity_mark, 4 = parity_space ... ";
	iParity = printTextAndValidateInput(outputText,iParity);
	while(!((iParity >=0) && (iParity <= 4))){
		std::cout << "Please type a value between 0 and 4" << std::endl;
		iParity = printTextAndValidateInput(outputText,iParity);
	}
	return iParity;
}

int SerialCom::View::getStopbits(){
	int iStopbits = 0;
	std::string outputText = "How many stopbits do you want to use? Type 1, 2 or 3 (if you type 3 you select 1.5 stopbits) ... ";
	iStopbits = printTextAndValidateInput(outputText,iStopbits);
	while(!((iStopbits >= 1) && (iStopbits <= 3))){
		std::cout << "Please type a value between 1 and 3" << std::endl;
		iStopbits = printTextAndValidateInput(outputText,iStopbits);
	}
	return iStopbits;
}

int SerialCom::View::getFlowcontrol(){
	int iFlowcontrol = 0;
	std::string outputText = "Which flowcontrol do you want to use? Type 0 = flowcontrol_none, 1 = flowcontrol_software, 2 = flowcontrol_hardware ... ";
	iFlowcontrol = printTextAndValidateInput(outputText,iFlowcontrol);
	while(!((iFlowcontrol >= 0) && (iFlowcontrol <= 2))){
		std::cout << "Please type a value between 1 and 3" << std::endl;
		iFlowcontrol = printTextAndValidateInput(outputText,iFlowcontrol);
	}
	return iFlowcontrol;
}

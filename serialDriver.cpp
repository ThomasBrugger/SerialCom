#include "serialDriver.h"
#include <iostream>

//Setter
void SerialCom::SerialDriver::setSerialPortNumber(int iSerialPort){
	m_iSerialPort = iSerialPort;
}

void SerialCom::SerialDriver::setSerialPortString(std::string sSerialPort){
	m_sSerialPort = sSerialPort;
}

void SerialCom::SerialDriver::setBaudrate(uint32_t ui32tBaudrate){
	m_ui32tBaudrate = ui32tBaudrate;
}

void SerialCom::SerialDriver::setTimeout(uint32_t ui32tTimeout){
	m_ui32tTimeout = ui32tTimeout;
}

void SerialCom::SerialDriver::setBytesize(int iByteSize){
	m_bsBytesize = (serial::bytesize_t)iByteSize;
}

void SerialCom::SerialDriver::setParity(int iParity){
	m_prParity = (serial::parity_t)iParity;
}

void SerialCom::SerialDriver::setStopbits(int iStopbits){
	m_sbStopbits = (serial::stopbits_t)iStopbits;
}

void SerialCom::SerialDriver::setFlowcontrol(int iFlowcontrol){
	m_fcFlowcontrol = (serial::flowcontrol_t)iFlowcontrol;
}

bool SerialCom::SerialDriver::initDriver(){
	try
  {
    m_pSerialPort = new serial::Serial(m_sSerialPort, m_ui32tBaudrate, serial::Timeout::simpleTimeout(m_ui32tTimeout), m_bsBytesize,
                                        m_prParity, m_sbStopbits, m_fcFlowcontrol);
		return true;
  } catch (std::exception& e)
  {
    std::cerr << "Exception at initialization of" + m_sSerialPort + ": " << e.what() << std::endl;
    return false;
  }
}

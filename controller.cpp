#include "controller.h"

void SerialCom::Controller::initCommunication()
{
	SerialDriver* m_pSerialDriver = new SerialDriver();
	View*	m_pView = new View();

	int iSerialPort = m_pView -> getSerialPortNumber();
	m_pSerialDriver -> setSerialPortNumber(iSerialPort);

	std::string sSerialPort = "COM" + iSerialPort;
	m_pSerialDriver -> setSerialPortString(sSerialPort);

	uint32_t ui32tBaudrate = m_pView -> getBaudrate();
	m_pSerialDriver -> setBaudrate(ui32tBaudrate);

	uint32_t ui32tTimeout = m_pView -> getTimeout();
	m_pSerialDriver -> setTimeout(ui32tTimeout);

	int iByteSize = m_pView -> getBytesize();
	m_pSerialDriver -> setBytesize(iByteSize);

	int iParity = m_pView -> getParity();
	m_pSerialDriver -> setParity(iParity);

	int iStopbits = m_pView -> getStopbits();
	m_pSerialDriver -> setStopbits(iStopbits);

	int iFlowcontrol = m_pView -> getFlowcontrol();
	m_pSerialDriver -> setFlowcontrol(iFlowcontrol);

}

#ifndef __SERIALCOM_SERIAL_H__
#define __SERIALCOM_SERIAL_H__

#include <string>
#include <memory>

#include "serial/serial.h"

namespace SerialCom
{
	class SerialDriver{

		public: //Functions
			void setSerialPortNumber(int iSerialPort);
			void setSerialPortString(std::string sSerialPort);
			void setBaudrate(uint32_t ui32tBaudrate);
			void setTimeout(uint32_t ui32tTimeout);
			void setBytesize(int iBytesize);
			void setParity(int iParity);
			void setStopbits(int iStopbits);
			void setFlowcontrol(int iFlowcontrol);
			bool initDriver();

		private: //Functions


		private: //Variables
			int m_iSerialPort{1};
			std::string m_sSerialPort{"COM1"};
			uint32_t m_ui32tBaudrate{9600};
			uint32_t m_ui32tTimeout{1000};
			serial::bytesize_t m_bsBytesize{serial::eightbits};
			serial::parity_t m_prParity{serial::parity_none};
			serial::stopbits_t m_sbStopbits{serial::stopbits_one};
			serial::flowcontrol_t m_fcFlowcontrol{serial::flowcontrol_none};


			serial::Serial* m_pSerialPort{nullptr};
	};
}

#endif // __SERIALCOM_SERIAL_H__

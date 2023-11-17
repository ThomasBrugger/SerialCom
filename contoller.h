#ifndef __SERIALCOM_CONTROLLER_H__
#define __SERIALCOM_CONTROLLER_H__

#include <string>
#include <memory>

#include "ThirdParty/serial-683e12d/include/serial/serial.h"

namespace SerialCom
{
	class Controller{

		public:
			void initCommunication();

		private:
			std::unique_ptr<serial::Serial> m_pSerialPort;

			const uint32_t aiBaudrates[18] = {75,110,134,150,300,600,1200,1800,2400,4800,7200,9600,14400,19200,38400,57600,115200,128000};
			const uint32_t aiDatabits[4] = {5,6,7,8};
			const std::string asParities[5] = {"parity_none", "parity_odd", "parity_even", "parity_mark", "parity_space"};

	};
}

#endif // __SERIALCOM_CONTROLLER_H__

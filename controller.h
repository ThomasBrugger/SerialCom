#ifndef __SERIALCOM_CONTROLLER_H__
#define __SERIALCOM_CONTROLLER_H__

#include <string>
#include <memory>

#include "serialDriver.h"
#include "view.h"
#include "utilities.h"
#include "serial/serial.h"

namespace SerialCom
{
	class Controller{

		public:
			void initCommunication();

		private:
			SerialDriver* m_pSerialDriver{nullptr};
			View*	m_pView{nullptr};

	};
}

#endif // __SERIALCOM_CONTROLLER_H__

#ifndef __SERIALCOM_UTILITIES_H__
#define __SERIALCOM_UTILITIES_H__

#include <limits>
#include <typeinfo>
#include <iostream>

namespace SerialCom
{
	template <typename T>
	bool checkArrayContains(T value, const T* arr, size_t arrSize){
		int i = 0;
		bool contains = false;

		while((i <= arrSize) && !contains){
			if(value == arr[i]){
				contains = true;
			}
			i++;
		}
		return contains;
	}

	template <typename T>
	T printTextAndValidateInput(std::string outputText,T userInput)
	{
		while (std::cout << outputText && !(std::cin >> userInput)) {
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			std::cout << "Invalid input; please re-enter.\n\n";
		}
		return userInput;
	}

}

#endif // __SERIALCOM_UTILITIES_H__

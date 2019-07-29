#pragma once
#include <string>
#include <iostream>

class illegalParameterValue
{
public:
	illegalParameterValue() :
		message("Illegal parameter value") {};
	illegalParameterValue(const char* theMeaasge)
	{
		message = theMeaasge;
	}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
#include "Input.h"
#include <iostream>

void Input::staticCallbackFunction(void * p,const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	((Input*)p)->callBackFunction(keyCode,keyboardEvent);
	
}

Input::Input(){
//Input::Input(const cbFunction f) :func(f)
//{
	facade = std::make_unique<InputFacade>(staticCallbackFunction,this);
}

void Input::parseKeyBindings(std::string string) {};

void Input::getKeyPressed()
{
	facade->handleKeyPressed();
};

void Input::getKeyReleased()
{
	facade->handleKeyReleased();
};

void Input::callBackFunction(KeyCodes keyCode, KeyboardEvent keyboardEvent) 
{
	std::cout << "has been passed to input" << std::endl;
}
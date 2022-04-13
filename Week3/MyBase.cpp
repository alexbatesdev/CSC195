#include "MyBase.h"

// ///////////////////////////////////////////
int MyBase::AddSomething(int initVal) {
	//return initVal + 1;
	return MyBase::AddSomething(initVal) + 1;
}
#pragma once
#include <iostream>
using namespace std;

enum DegreeProgram
{
	SECURITY, NETWORK, SOFTWARE
};
//enumerated data type for degree programs - SECURITY, NETWORK & SOFTWARE.

static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
//sets static constant strings for the degree program types.
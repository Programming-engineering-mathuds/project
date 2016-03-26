#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
class combo
{
public:
	combo();
	combo(char* text);
	~combo();
	void print();
	int getSize();
	char* getText();
	char* comboText;
	int getXR() {
		return XR;
	};
	int getXL() {
		return XL;
	};
	int getYU() {
		return YU;
	};
	int getYD() {
		return YD;
	};
	int size;
	int XR;
	int XL;
	int YU;
	int YD;
};


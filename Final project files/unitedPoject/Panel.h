#pragma once
#include "iControl.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "vector"
#include "Label.h"

using namespace std;



class Panel : public  iControl
{
	int FirstFrameRun = 0;
	int weHaveFocus = 0;
	void add(iControl *c);
	void getAllControls(vector<iControl*> &pan){ pan = controlers; };
	vector<iControl*> controlers;
	Label nullFocuse;
public:
	Panel(int height, int width);
	~Panel(){};
	void AddControler(iControl& control, int left, int top);
	void frame(int size);
	void draw(Graphics &g, int left, int top, size_t layer);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charater) {};
	void setLocation(int x, int y);
	void getAllControls(vector < iControl * > *controls) 
	{ 
		int focuseCount = 0;
		controls->clear();
		for (int i = 0; i < controlers.size(); i++) controls->push_back(controlers[i]);
	};
	
};
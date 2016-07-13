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
	//void getFocuse();
	void getAllControls(vector<iControl*> &pan){ pan = controlers; };
	//int myHeight;
	//int myWidth;
	vector<iControl*> controlers;
	Label nullFocuse;
public:
	Panel(int height, int width);
	~Panel(){};
	void AddControler(iControl& control, int left, int top);
	void frame(int size);
	//void traverseFocuse();
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
	
	/* No need, alleady in is iControl.h
	static iControl* getFocus()
	{
		for (int i = 0; i < controlers.size(); i++)
		{
			Panel *checkPanel;
			checkPanel = dynamic_cast<Panel*>(controlers[i]);
			if (checkPanel != 0)return controlers[i]->getFocus();
			else if (controlers[i]->getFocus()) return controlers[i];
		};
	}
	*/
};
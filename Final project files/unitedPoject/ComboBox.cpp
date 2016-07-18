#include "ComboBox.h"
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

ComboBox::ComboBox(int width, vector<string> entries) : Panel(entries.size(), width), cBoxHeader(23, "Please Select An Item")
{


}

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Label.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Label l(10, "test");
		}

	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "GraphicsMock.h"
#include "NumericBox.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			GraphicsMock g;
			Panel panel(20, 20);
			panel.setBorder(BorderType::Single);
			NumericBox box(10, -10, 10);
			box.setForeground(Color::Black);
			box.setBackground(Color::Red);
			panel.AddControler(box, 3, 3);
			panel.draw(g, 0, 0, 0);

			Assert::IsFalse(box.canGetFocus());
			Assert::AreEqual(box.getHight(), 3);
			Assert::AreEqual(panel.getHight(), 20);
			Assert::IsTrue(box.getVisible());
			g.clearAt(0, 0, 5);
			Assert::IsTrue(g.isClear());
		}

	};
}
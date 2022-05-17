#include "pch.h"
#include "CppUnitTest.h"
#include "../BellmanFord.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BellmanFordTest
{
	TEST_CLASS(BellmanFordTest)
	{
	public:
		
		TEST_METHOD(TestParserExeption)
		{
			Route listRouteTest;
			List<string> helpListTest;
			try {
				parser(listRouteTest, helpListTest);
			}
			catch (const logic_error error) {
				Assert::AreEqual("Error opening file!\n", error.what());
			}
		}

		TEST_METHOD(TestcheapFlight)
		{
			Route listRouteTest;
			List<string> helpListTest;
			helpListTest.push_back("St.Petersburg");
			helpListTest.push_back("Moscow");
			helpListTest.push_back("Khabarovsk");
			listRouteTest.push_back("St.Petersburg", "Moscow", 1);
			listRouteTest.push_back("St.Petersburg", "Khabarovsk", 20);
			listRouteTest.push_back("Moscow", "Khabarovsk", 3);
			Assert::IsTrue(cheapFlight("St.Petersburg", "Khabarovsk", listRouteTest, helpListTest) == 4);
			Assert::IsTrue(cheapFlight("St.Petersburg", "Moscow", listRouteTest, helpListTest) == 1);
			try {
				cheapFlight("St.Petersburg", "St.Petersburg", listRouteTest, helpListTest);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("You chose the wrong route\n", error.what());
			}
		}
	};
}

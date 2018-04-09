#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "calculator.hpp"


#include <iostream>



TEST_CASE( "Calculator", "All" ){



	Calculator c1("5+5");
	CHECK(c1.getResult() == "10");

	Calculator c2("n5+5");
	CHECK(c2.getResult() == "0");

	Calculator c3("5+n5");
	CHECK(c3.getResult() == "0");

	Calculator c4("5+5n");
	CHECK(c4.getResult() == "Synthaxe Error");

	Calculator c5("9+5+log(10)");
	CHECK(c5.getResult() == "15");

	Calculator c6("9.5+5+log(10)");
	CHECK(c6.getResult() == "15.5");

	Calculator c7("log(10)");
	CHECK(c7.getResult() == "1");

	Calculator c8("1203091.380901*1092.109/10902+13092");
	CHECK(c8.getResult() == "133611.80599");

	Calculator c9("Fact(3)");
	CHECK(c9.getResult() == "6");

}
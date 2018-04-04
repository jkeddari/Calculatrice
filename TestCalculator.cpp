#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "calculator.hpp"


#include <iostream>



TEST_CASE( "Calculator", "All" ){
	
	Calculator c1("5+5");
	CHECK(c1.getResult() == "10.000000");

	Calculator c2("n5+5");
	CHECK(c2.getResult() == "0.000000");

	Calculator c3("5+n5");
	CHECK(c3.getResult() == "0.000000");

	Calculator c4("5+5n");
	CHECK(c4.getResult() == "Synthaxe Error");


}
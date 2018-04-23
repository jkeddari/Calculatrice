#define CATCH_CONFIG_MAIN
#include "../headers/catch.hpp"

#include "../headers/calculator.hpp"


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


	Calculator c9("fact(2*1.5)");
	CHECK(c9.getResult() == "6");

	Calculator c10("10+99.2-n4+sin(13)+cos(cos(cos(10)))");
	CHECK(c10.getResult() == "114.405134");

	Calculator c11("n(10+99.2-n4+sin(13)+cos(cos(cos(10))))");
	CHECK(c11.getResult() == "-114.405134");

	Calculator c12("5n5");
	CHECK(c12.getResult() == "Synthaxe Error");

	Calculator c13("(n5+5)");
	CHECK(c13.getResult() == "0");

	Calculator c14("(5+.5+2)");
	CHECK(c14.getResult() == "7.5");

	Calculator c15("2+3*2");
	CHECK(c15.getResult() == "8");

	Calculator c16("2*10");
	CHECK(c16.getResult() == "20");

	Calculator c17("fact(3.5)");
	CHECK(c17.getResult() == "3.323351");

	Calculator c18("fact(4.5)");
	CHECK(c18.getResult() == "11.631728");

	Calculator c19("10%2");
	CHECK(c19.getResult() == "0");

}
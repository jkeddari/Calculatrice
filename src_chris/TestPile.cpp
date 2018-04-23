#define CATCH_CONFIG_MAIN
#include "../headers/catch.hpp"

#include "../headers/Pile.hpp"
#include <string>


#include <iostream>



TEST_CASE( "Pile", "All" ){
	Pile p;

	p.push("1");
	CHECK(p.top() == "1");
	p.push("2");
	CHECK(p.top() == "2");
	CHECK(p.size() == 2);
	CHECK(p.empty() == false);
	p.pop();
	CHECK(p.top() == "1");
	p.pop();
	CHECK(p.empty() == true);

}
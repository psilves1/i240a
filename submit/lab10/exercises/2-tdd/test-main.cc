//This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN 
#include "catch.h"

#include "digit-sum.hh"

TEST_CASE( "digit sums computed", "[digitSum]" ) {
  REQUIRE(digitSum("") == 0);
  REQUIRE(digitSum("7") == 7);
  REQUIRE(digitSum("5") == 5);
  REQUIRE(digitSum("7 + 2") == 9);
  REQUIRE(digitSum("7 + 2 + 4") == 13);
  REQUIRE(digitSum("8 ++ 4") == 8);

}


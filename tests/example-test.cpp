#include "../library/example-header.h"
#include "catch.h"

TEST_CASE("simple-test", "[simple]") { REQUIRE(example::foo() == 1); }

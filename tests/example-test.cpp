#include "catch.h"
#include "../library/example-header.h"

TEST_CASE("simple-test", "[simple]")
{
    REQUIRE(foo() == 1);
}

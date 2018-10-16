#include "catch.h"
#include "../library/example-header.h"

TEST_CASE("simple-test", "[simple]")
{
    REQUIRE(example::foo() == 1);
}

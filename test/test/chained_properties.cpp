#include "pch.h"
#include "winrt/test_component.ChainedProperties.h"

using namespace winrt::test_component::ChainedProperties;

TEST_CASE("chained_properties")
{
    // The sequence of chained properties within a single class does not matter.
    Base b;
    b.Other(3).Second(2).First(1);
    REQUIRE(b.First() == 1);
    REQUIRE(b.Second() == 2);
    REQUIRE(b.Other() == 3);

    // The sequence of chained properties within a hierarchy must be ordered from most derived to least derived.
    Derived d;
    d.Other(5).Third(3).Fourth(4).First(1).Second(2);
    REQUIRE(d.First() == 1);
    REQUIRE(d.Second() == 2);
    REQUIRE(d.Third() == 3);
    REQUIRE(d.Fourth() == 4);
    REQUIRE(d.Other() == 5);
}

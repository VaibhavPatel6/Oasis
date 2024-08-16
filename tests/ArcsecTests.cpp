#include "catch2/catch_test_macros.hpp"
#include "Oasis/Arcsec.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

TEST_CASE("Simplify ArcSec with Real Operand", "[ArcSec]") {
    Oasis::Arcsec arcsec { Oasis::Real { 2.0 } };
    auto simplified = arcsec.Simplify();
    REQUIRE(simplified->Equals(Oasis::Real(M_PI / 3.0)));
}

TEST_CASE("Simplify ArcSec with Variable Operand", "[ArcSec]") {
    Oasis::Variable x { "x" };
    Oasis::Arcsec arcsec { x };
    auto simplified = arcsec.Simplify();
    REQUIRE(simplified->Equals(arcsec));
}

TEST_CASE("ArcSec ToString", "[ArcSec]") {
    Oasis::Variable x { "x" };
    Oasis::Arcsec arcsec { x };
    REQUIRE(arcsec.ToString() == "arcsec(x)");
}

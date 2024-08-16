#include "catch2/catch_test_macros.hpp"
#include "Oasis/Arccot.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

TEST_CASE("Simplify ArcCot with Real Operand", "[ArcCot]") {
    Oasis::Arccot arccot { Oasis::Real { 1.0 } };
    auto simplified = arccot.Simplify();
    REQUIRE(simplified->Equals(Oasis::Real(M_PI / 4.0)));
}

TEST_CASE("Simplify ArcCot with Variable Operand", "[ArcCot]") {
    Oasis::Variable x { "x" };
    Oasis::Arccot arccot { x };
    auto simplified = arccot.Simplify();
    REQUIRE(simplified->Equals(arccot));
}

TEST_CASE("ArcCot ToString", "[ArcCot]") {
    Oasis::Variable x { "x" };
    Oasis::Arccot arccot { x };
    REQUIRE(arccot.ToString() == "arccot(x)");
}

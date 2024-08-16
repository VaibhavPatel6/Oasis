#include "catch2/catch_test_macros.hpp"
#include "Oasis/Arccsc.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

TEST_CASE("Simplify ArcCsc with Real Operand", "[ArcCsc]") {
    Oasis::Arccsc arccsc { Oasis::Real { 1.0 } };
    auto simplified = arccsc.Simplify();
    REQUIRE(simplified->Equals(Oasis::Real(M_PI / 2.0)));
}

TEST_CASE("Simplify ArcCsc with Variable Operand", "[ArcCsc]") {
    Oasis::Variable x { "x" };
    Oasis::Arccsc arccsc { x };
    auto simplified = arccsc.Simplify();
    REQUIRE(simplified->Equals(arccsc));
}

TEST_CASE("ArcCsc ToString", "[ArcCsc]") {
    Oasis::Variable x { "x" };
    Oasis::Arccsc arccsc { x };
    REQUIRE(arccsc.ToString() == "arccsc(x)");
}

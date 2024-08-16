#include "catch2/catch_test_macros.hpp"
#include "Oasis/Csc.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

TEST_CASE("Simplify Csc with Real Operand", "[Csc]") {
    Oasis::Csc csc { Oasis::Real { M_PI / 2.0 } };
    auto simplified = csc.Simplify();
    REQUIRE(simplified->Equals(Oasis::Real(1.0)));
}

TEST_CASE("Simplify Csc with Variable Operand", "[Csc]") {
    Oasis::Variable x { "x" };
    Oasis::Csc csc { x };
    auto simplified = csc.Simplify();
    REQUIRE(simplified->Equals(csc));
}

TEST_CASE("Csc ToString", "[Csc]") {
    Oasis::Variable x { "x" };
    Oasis::Csc csc { x };
    REQUIRE(csc.ToString() == "csc(x)");
}

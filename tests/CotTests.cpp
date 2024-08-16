#include "catch2/catch_test_macros.hpp"
#include "Oasis/Cot.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

TEST_CASE("Simplify Cot with Real Operand", "[Cot]") {
    Oasis::Cot cot { Oasis::Real { M_PI / 4.0 } };
    auto simplified = cot.Simplify();
    REQUIRE(simplified->Equals(Oasis::Real(1.0)));
}

TEST_CASE("Simplify Cot with Variable Operand", "[Cot]") {
    Oasis::Variable x { "x" };
    Oasis::Cot cot { x };
    auto simplified = cot.Simplify();
    REQUIRE(simplified->Equals(cot));
}

TEST_CASE("Cot ToString", "[Cot]") {
    Oasis::Variable x { "x" };
    Oasis::Cot cot { x };
    REQUIRE(cot.ToString() == "cot(x)");
}

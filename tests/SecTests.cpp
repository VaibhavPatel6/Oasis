#include "catch2/catch_test_macros.hpp"
#include "Oasis/Sec.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

TEST_CASE("Simplify Sec with Real Operand", "[Sec]") {
    Oasis::Sec sec { Oasis::Real { M_PI / 3.0 } };
    auto simplified = sec.Simplify();
    REQUIRE(simplified->Equals(Oasis::Real(2.0)));
}

TEST_CASE("Simplify Sec with Variable Operand", "[Sec]") {
    Oasis::Variable x { "x" };
    Oasis::Sec sec { x };
    auto simplified = sec.Simplify();
    REQUIRE(simplified->Equals(sec));
}

TEST_CASE("Sec ToString", "[Sec]") {
    Oasis::Variable x { "x" };
    Oasis::Sec sec { x };
    REQUIRE(sec.ToString() == "sec(x)");
}

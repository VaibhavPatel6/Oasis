#include "Arccsc.hpp"
#include "Real.hpp"
#include <cmath>

namespace Oasis {
    Arccsc::Arccsc(const Expression& operand) : UnaryExpression(operand) {}

    auto Arccsc::Simplify() const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify();
        Arccsc simplifiedArccsc { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(std::asin(1.0 / realOperand->GetValue()));
        }

        return simplifiedArccsc.Copy();
    }
    
    auto Arccsc::Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify(subflow);
        Arccsc simplifiedArccsc { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(std::asin(1.0 / realOperand->GetValue()));
        }

        return simplifiedArccsc.Copy();
    }
    
    std::string Arccsc::ToString() const {
        return "arccsc(" + GetOperand().ToString() + ")";
    }

    auto Arccsc::Copy() const -> std::unique_ptr<Expression> {
        return std::make_unique<Arccsc>(*this);
    }
} // namespace Oasis

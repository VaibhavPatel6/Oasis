#include "Csc.hpp"
#include "Real.hpp"
#include <cmath>

namespace Oasis {
    Csc::Csc(const Expression& operand) : UnaryExpression(operand) {}

    auto Csc::Simplify() const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify();
        Csc simplifiedCsc { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(1.0 / std::sin(realOperand->GetValue()));
        }

        return simplifiedCsc.Copy();
    }
    
    auto Csc::Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify(subflow);
        Csc simplifiedCsc { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(1.0 / std::sin(realOperand->GetValue()));
        }

        return simplifiedCsc.Copy();
    }
    
    std::string Csc::ToString() const {
        return "csc(" + GetOperand().ToString() + ")";
    }

    auto Csc::

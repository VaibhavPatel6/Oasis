#include "Arccot.hpp"
#include "Real.hpp"
#include <cmath>

namespace Oasis {
    Arccot::Arccot(const Expression& operand) : UnaryExpression(operand) {}

    auto Arccot::Simplify() const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify();
        Arccot simplifiedArccot { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(M_PI / 2 - std::atan(realOperand->GetValue()));
        }

        return simplifiedArccot.Copy();
    }
    
    auto Arccot::Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify(subflow);
        Arccot simplifiedArccot { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(M_PI / 2 - std::atan(realOperand->GetValue()));
        }

        return simplifiedArccot.Copy();
    }
    
    std::string Arccot::ToString() const {
        return "arccot(" + GetOperand().ToString() + ")";
    }

    auto Arccot::Copy() const -> std::unique_ptr<Expression> {
        return std::make_unique<Arccot>(*this);
    }
} // namespace Oasis

#include "Cot.hpp"
#include "Real.hpp"
#include <cmath>

namespace Oasis {
    Cot::Cot(const Expression& operand) : UnaryExpression(operand) {}

    auto Cot::Simplify() const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify();
        Cot simplifiedCot { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(1.0 / std::tan(realOperand->GetValue()));
        }

        return simplifiedCot.Copy();
    }
    
    auto Cot::Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify(subflow);
        Cot simplifiedCot { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(1.0 / std::tan(realOperand->GetValue()));
        }

        return simplifiedCot.Copy();
    }
    
    std::string Cot::ToString() const {
        return "cot(" + GetOperand().ToString() + ")";
    }

    auto Cot::Copy() const -> std::unique_ptr<Expression> {
        return std::make_unique<Cot>(*this);
    }
} // namespace Oasis

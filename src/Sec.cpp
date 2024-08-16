#include "Sec.hpp"
#include "Real.hpp"
#include <cmath>

namespace Oasis {
    Sec::Sec(const Expression& operand) : UnaryExpression(operand) {}

    auto Sec::Simplify() const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify();
        Sec simplifiedSec { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(1.0 / std::cos(realOperand->GetValue()));
        }

        return simplifiedSec.Copy();
    }
    
    auto Sec::Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify(subflow);
        Sec simplifiedSec { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(1.0 / std::cos(realOperand->GetValue()));
        }

        return simplifiedSec.Copy();
    }
    
    std::string Sec::ToString() const {
        return "sec(" + GetOperand().ToString() + ")";
    }

    auto Sec::Copy() const -> std::unique_ptr<Expression> {
        return std::make_unique<Sec>(*this);
    }
} // namespace Oasis

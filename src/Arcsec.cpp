#include "Arcsec.hpp"
#include "Real.hpp"
#include <cmath>

namespace Oasis {
    Arcsec::Arcsec(const Expression& operand) : UnaryExpression(operand) {}

    auto Arcsec::Simplify() const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify();
        Arcsec simplifiedArcsec { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(std::acos(1.0 / realOperand->GetValue()));
        }

        return simplifiedArcsec.Copy();
    }
    
    auto Arcsec::Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> {
        auto simplifiedOperand = GetOperand().Simplify(subflow);
        Arcsec simplifiedArcsec { *simplifiedOperand };

        if (auto realOperand = Real::Specialize(*simplifiedOperand); realOperand != nullptr) {
            return std::make_unique<Real>(std::acos(1.0 / realOperand->GetValue()));
        }

        return simplifiedArcsec.Copy();
    }
    
    std::string Arcsec::ToString() const {
        return "arcsec(" + GetOperand().ToString() + ")";
    }

    auto Arcsec::Copy() const -> std::unique_ptr<Expression> {
        return std::make_unique<Arcsec>(*this);
    }
} // namespace Oasis

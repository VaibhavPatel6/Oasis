#ifndef OASIS_ARCSEC_HPP
#define OASIS_ARCSEC_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Arcsec : public UnaryExpression {
public:
    explicit Arcsec(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Arcsec, OperandT)

    EXPRESSION_TYPE(Arcsec)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_ARCSEC_HPP

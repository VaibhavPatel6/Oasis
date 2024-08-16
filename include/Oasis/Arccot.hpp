#ifndef OASIS_ARCCOT_HPP
#define OASIS_ARCCOT_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Arccot : public UnaryExpression {
public:
    explicit Arccot(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Arccot, OperandT)

    EXPRESSION_TYPE(Arccot)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_ARCCOT_HPP

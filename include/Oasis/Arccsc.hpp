#ifndef OASIS_ARCCSC_HPP
#define OASIS_ARCCSC_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Arccsc : public UnaryExpression {
public:
    explicit Arccsc(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Arccsc, OperandT)

    EXPRESSION_TYPE(Arccsc)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_ARCCSC_HPP

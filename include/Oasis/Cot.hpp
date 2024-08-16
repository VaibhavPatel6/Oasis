#ifndef OASIS_COT_HPP
#define OASIS_COT_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Cot : public UnaryExpression {
public:
    explicit Cot(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Cot, OperandT)

    EXPRESSION_TYPE(Cot)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_COT_HPP

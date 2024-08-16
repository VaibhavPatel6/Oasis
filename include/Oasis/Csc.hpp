#ifndef OASIS_CSC_HPP
#define OASIS_CSC_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Csc : public UnaryExpression {
public:
    explicit Csc(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Csc, OperandT)

    EXPRESSION_TYPE(Csc)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_CSC_HPP

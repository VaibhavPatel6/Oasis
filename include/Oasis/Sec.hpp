#ifndef OASIS_SEC_HPP
#define OASIS_SEC_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Sec : public UnaryExpression {
public:
    explicit Sec(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Sec, OperandT)

    EXPRESSION_TYPE(Sec)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_SEC_HPP

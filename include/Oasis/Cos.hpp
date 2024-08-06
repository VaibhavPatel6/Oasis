#ifndef OASIS_COS_HPP
#define OASIS_COS_HPP

#include "UnaryExpression.hpp"

namespace Oasis {

class Cos : public UnaryExpression {
public: 
    explicit Cos(const Expression& operand);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto Simplify(tf::Subflow& subflow) const -> std::unique_ptr<Expression> override;
    [[nodiscard]] auto ToString() const -> std::string override;
    [[nodiscard]] auto Copy() const -> std::unique_ptr<Expression> override;

    IMPL_SPECIALIZE_UNARYEXPR(Cos, OperandT)

    EXPRESSION_TYPE(Cos)
    EXPRESSION_CATEGORY(UnExp)
};

} // namespace Oasis

#endif // OASIS_COS_HPP

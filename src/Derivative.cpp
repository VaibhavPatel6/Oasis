//
// Created by bachia on 4/12/2024.
//

#include "Oasis/Derivative.hpp"
#include "Oasis/Add.hpp"
#include "Oasis/Divide.hpp"
#include "Oasis/Exponent.hpp"
#include "Oasis/Expression.hpp"
#include "Oasis/Log.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Subtract.hpp"
#include "Oasis/Undefined.hpp"

#include <cmath>
#include <string>

namespace Oasis {
    
Derivative<Expression>::Derivative(const Expression& exp, const Expression& var)
    : BinaryExpression(exp, var)
{
}

auto Derivative<Expression>::Simplify() const -> std::unique_ptr<Expression>
{
    auto simplifiedExpression = mostSigOp ? mostSigOp->Simplify() : nullptr;
    auto simplifiedVar = leastSigOp ? leastSigOp->Simplify() : nullptr;
    return simplifiedExpression->Differentiate(*simplifiedVar);
}

std::unique_ptr<Expression> Derivative<Expression, Expression>::Simplify(tf::Subflow& subflow) const
{
    std::unique_ptr<Expression> simplifiedExpression, simplifiedVar;

    tf::Task expressionSimplifyTask = subflow.emplace([this, &simplifiedExpression](tf::Subflow& sbf) {
        if (!mostSigOp) {
            return;
        }

        simplifiedExpression = mostSigOp->Simplify(sbf);
    });

    tf::Task varSimplifyTask = subflow.emplace([this, &simplifiedVar](tf::Subflow& sbf) {
        if (!leastSigOp) {
            return;
        }
        
        simplifiedVar = leastSigOp->Simplify(sbf);
    });

    subflow.join();

    if (!simplifiedExpression || !simplifiedVar) {
        return std::make_unique<Undefined>();
    }

    return simplifiedExpression->Differentiate(*simplifiedVar);
}

std::unique_ptr<Expression> Derivative<Expression, Expression>::Differentiate(const Expression& differentiationVariable) const
{
    return mostSigOp->Differentiate(*leastSigOp)->Differentiate(differentiationVariable);
}

auto Derivative<Expression>::Specialize(const Expression& other) -> std::unique_ptr<Derivative<Expression, Expression>>
{
    if (!other.Is<Oasis::Derivative>()) {
        return nullptr;
    }

    auto otherGeneralized = other.Generalize();
    return std::make_unique<Derivative>(dynamic_cast<const Derivative&>(*otherGeneralized));
}

auto Derivative<Expression>::Specialize(const Expression& other, tf::Subflow& subflow) -> std::unique_ptr<Derivative>
{
    if (!other.Is<Oasis::Derivative>()) {
        return nullptr;
    }
    auto otherGeneralized = other.Generalize(subflow);
    return std::make_unique<Derivative>(dynamic_cast<const Derivative&>(*otherGeneralized));
}
}

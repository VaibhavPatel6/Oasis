//
// Created by Matthew McCall on 4/28/24.
//

#include <fmt/core.h>

#include "Oasis/InFixSerializer.hpp"

#include "Oasis/Add.hpp"
#include "Oasis/Derivative.hpp"
#include "Oasis/Divide.hpp"
#include "Oasis/Exponent.hpp"
#include "Oasis/Integral.hpp"
#include "Oasis/Log.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/Negate.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Subtract.hpp"
#include "Oasis/Variable.hpp"

namespace Oasis {

void InFixSerializer::Serialize(const Real& real)
{
    result = fmt::format("{:.5}", real.GetValue());
}

void InFixSerializer::Serialize(const Imaginary& imaginary)
{
    result = "i";
}

void InFixSerializer::Serialize(const Variable& variable)
{
    result = variable.GetName();
}

void InFixSerializer::Serialize(const Undefined& undefined)
{
    result = "Undefined";
}

void InFixSerializer::Serialize(const Add<>& add)
{
    add.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    add.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("({}+{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Subtract<>& subtract)
{
    subtract.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    subtract.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("({}-{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Multiply<>& multiply)
{
    multiply.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    multiply.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("({}*{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Divide<>& divide)
{
    divide.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    divide.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("({}/{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Exponent<>& exponent)
{
    exponent.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    exponent.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("({}^{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Log<>& log)
{
    log.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    log.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("log({},{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Negate<Expression>& negate)
{
    negate.GetOperand().Serialize(*this);
    const auto opStr = getResult();

    result = fmt::format("-({})", opStr);
}

void InFixSerializer::Serialize(const Derivative<>& derivative)
{
    derivative.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    derivative.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("dd({},{})", mostSigOpStr, leastSigOpStr);
}

void InFixSerializer::Serialize(const Integral<>& integral)
{
    integral.GetMostSigOp().Serialize(*this);
    const auto mostSigOpStr = getResult();

    integral.GetLeastSigOp().Serialize(*this);
    const auto leastSigOpStr = getResult();

    result = fmt::format("in({},{})", mostSigOpStr, leastSigOpStr);
}

// Add serialization for the new functions
void InFixSerializer::Serialize(const Sec<>& sec) 
{
    sec.GetOperand().Serialize(*this);
    const auto operandStr = getResult();

    result = fmt::format("sec({})", operandStr);
}

void InFixSerializer::Serialize(const Arcsec<>& arcsec)
{
    arcsec.GetOperand().Serialize(*this);
    const auto operandStr = getResult();

    result = fmt::format("arcsec({})", operandStr);
}

void InFixSerializer::Serialize(const Csc<>& csc) 
{
    csc.GetOperand().Serialize(*this);
    const auto operandStr = getResult();

    result = fmt::format("csc({})", operandStr);
}

void InFixSerializer::Serialize(const Arccsc<>& arccsc) 
{
    arccsc.GetOperand().Serialize(*this);
    const auto operandStr = getResult();

    result = fmt::format("arccsc({})", operandStr);
}

void InFixSerializer::Serialize(const Cot<>& cot) 
{
    cot.GetOperand().Serialize(*this);
    const auto operandStr = getResult();

    result = fmt::format("cot({})", operandStr);
}

void InFixSerializer::Serialize(const Arccot<>& arccot) 
{
    arccot.GetOperand().Serialize(*this);
    const auto operandStr = getResult();
    
    result = fmt::format("arccot({})", operandStr);
}

std::string InFixSerializer::getResult() const
{
    return result;
}

} // Oasis
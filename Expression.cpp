#include "Expression.h"
#include "cmath"


/* ------------   ALREADY IMPLEMENTED   ------------ */
std::ostream& operator<<(std::ostream& out, const Expression& expression)
{
	expression.Info(out); return out;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
SingleExpression::SingleExpression(float value) : m_value(value) { }

/* ------------   ALREADY IMPLEMENTED   ------------ */
MultiExpression::MultiExpression(Expression* lhs, Expression* rhs)
{
    this->m_left = lhs;
    this->m_right = rhs;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
MultiExpression::~MultiExpression()
{
    delete this->m_left;
    delete this->m_right;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
Constant::Constant(float value) : SingleExpression(value) { }

/* ------------   ALREADY IMPLEMENTED   ------------ */
void Constant::Info(std::ostream& out) const
{
    out << this->m_value;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
float Constant::Evaluate() const
{
    return this->m_value;
}

/* ------------   STAGE_1 (3Pts)   ------------ */
SquareRoot::SquareRoot(float value) : SingleExpression(value) { }

void SquareRoot::Info(std::ostream& out) const
{
    out << this->m_value;
}

float SquareRoot::Evaluate() const
{
    return sqrt(m_value);
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Power::Power(float value, float power) : SingleExpression(value), power(power) { }

void Power::Info(std::ostream& out) const
{
    out << this->m_value << " ";
    out << this->power;
}

float Power::Evaluate() const
{
    return pow(m_value, power);
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Addition::Addition(Expression* lhs, Expression* rhs): MultiExpression(lhs, rhs) {}

float Addition::Evaluate() const {
    return m_left->Evaluate() + m_right->Evaluate();
}

void Addition::Info(std::ostream& out) const
{
    out << m_left->Evaluate() << " + " << m_right->Evaluate();
}
/* ------------   STAGE_1 (3Pts)   ------------ */
Subtraction::Subtraction(Expression* lhs, Expression* rhs): MultiExpression(lhs, rhs) {}

float Subtraction::Evaluate() const {
    return m_left->Evaluate() - m_right->Evaluate();
}

void Subtraction::Info(std::ostream& out) const
{
    out << m_left->Evaluate() << " - " << m_right->Evaluate();
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Multiplication::Multiplication(Expression* lhs, Expression* rhs): MultiExpression(lhs, rhs) {}

float Multiplication::Evaluate() const {
    return m_left->Evaluate() * m_right->Evaluate();
}

void Multiplication::Info(std::ostream& out) const
{
    out << m_left->Evaluate() << " * " << m_right->Evaluate();
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Division::Division(Expression* lhs, Expression* rhs): MultiExpression(lhs, rhs) {}

float Division::Evaluate() const {
    return m_left->Evaluate() / m_right->Evaluate();
}

void Division::Info(std::ostream& out) const
{
    out << m_left->Evaluate() << " / " << m_right->Evaluate();
}



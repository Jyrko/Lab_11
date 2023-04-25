#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

class Expression /* ------------   ALREADY IMPLEMENTED   ------------ */
{
public:
    virtual float Evaluate() const = 0;
    virtual void Info(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Expression& expression);
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class SingleExpression : public Expression
{
protected:
    float m_value;

    SingleExpression(float value);
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class MultiExpression : public Expression
{
protected:
    Expression *m_left;
    Expression *m_right;

    MultiExpression(Expression* lhs, Expression* rhs);

    virtual ~MultiExpression();
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class Constant : public SingleExpression
{
public:
    Constant(float value);

    virtual float Evaluate() const override;
    virtual void Info(std::ostream& out) const override;
};

/* ------------   STAGE_1 (3Pts)   ------------ */
class SquareRoot : public SingleExpression {
    public: 
        SquareRoot(float value);
        
        virtual float Evaluate() const override;
        virtual void Info(std::ostream& out) const override;

};

/* ------------   STAGE_1 (3Pts)   ------------ */
class Power : public SingleExpression {
    private: 
        float power;
     public: 
        Power(float value, float power);
        
        virtual float Evaluate() const override;
        virtual void Info(std::ostream& out) const override;
};

/* ------------   STAGE_1 (3Pts)   ------------ */
class Addition : public MultiExpression {
    public:
        Addition(Expression* lhs, Expression* rhs);

        virtual float Evaluate() const override;
        virtual void Info(std::ostream& out) const override;

};

/* ------------   STAGE_1 (3Pts)   ------------ */
class Subtraction : public MultiExpression {
    public:
        Subtraction(Expression* lhs, Expression* rhs);

        virtual float Evaluate() const override;
        virtual void Info(std::ostream& out) const override;
};

/* ------------   STAGE_1 (3Pts)   ------------ */
class Multiplication : public MultiExpression {
    public:
        Multiplication(Expression* lhs, Expression* rhs);

        virtual float Evaluate() const override;
        virtual void Info(std::ostream& out) const override;
};

/* ------------   STAGE_1 (3Pts)   ------------ */
class Division : public MultiExpression {
    public:
        Division(Expression* lhs, Expression* rhs);

        virtual float Evaluate() const override;
        virtual void Info(std::ostream& out) const override;
};

#endif /* EXPRESSION_H */

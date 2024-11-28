#pragma once
#include "base.hpp"

class Programa: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class Statementlist: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class Statement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class StatementTail: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class Expression: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class ExpressionTail: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class BinaryExpression: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class BinaryExpressionPrime: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class UnaryExpression: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class LiteralExpression: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class Term: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class TermPrime: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class Factor: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class IfStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class IfStatementPrime: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class WhileStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class ForStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class BreakStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class ReturnStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class ProcedureStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class AssignmentStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class DeclarationStatement: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class BinaryOperator: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class UnaryOperator: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class IncrementExpression: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class Type: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};

class ParameterList: public IBaseProductionFactory {
  virtual std::string getName() const override;
  virtual std::vector < AnySymbol > create(size_t token) override;
};
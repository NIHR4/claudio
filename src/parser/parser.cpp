#include "parser.hpp"
#include "../lexer/claudio.h"
#include <functional>
#include <utility>
#include <variant>

//parsing rules
#include "rules/program.hpp"
#include "rules/assignment_statement.hpp"
#include "rules/assignment_statement.hpp"
#include "rules/binary_expression.hpp"
#include "rules/binary_expression.hpp"
#include "rules/break_statement.hpp"
#include "rules/break_statement.hpp"
#include "rules/common.hpp"
#include "rules/common.hpp"
#include "rules/expression.hpp"
#include "rules/expression.hpp"
#include "rules/for_statement.hpp"
#include "rules/for_statement.hpp"
#include "rules/identifier.hpp"
#include "rules/identifier.hpp"
#include "rules/if_statement.hpp"
#include "rules/if_statement.hpp"
#include "rules/increment_expression.hpp"
#include "rules/increment_expression.hpp"
#include "rules/literal_expression.hpp"
#include "rules/literal_expression.hpp"
#include "rules/procedure_statement.hpp"
#include "rules/procedure_statement.hpp"
#include "rules/program.hpp"
#include "rules/program.hpp"
#include "rules/return_statement.hpp"
#include "rules/return_statement.hpp"
#include "rules/statement.hpp"
#include "rules/statement.hpp"
#include "rules/statement_list.hpp"
#include "rules/statement_list.hpp"
#include "rules/symbols.hpp"
#include "rules/term.hpp"
#include "rules/term.hpp"
#include "rules/unary_expression.hpp"
#include "rules/unary_expression.hpp"
#include "rules/while_statement.hpp"
#include "rules/while_statement.hpp"




void parser::parse(antlr4::CommonTokenStream &stream)
{
    
    std::stack<SymbolMix> symbolStack;
    size_t inputIdx=0;

    symbolStack.push(lexer::claudio::EOF);
    symbolStack.push(Symbols::PROGRAM);
    while (symbolStack.size() > 0)
    {
        auto currentSymbol = symbolStack.top();
        symbolStack.pop();
        //Current token in the input stream
        antlr4::Token *token = stream.get(inputIdx);

        //Parse Non-Terminal Symbols
        if(std::holds_alternative<tagNonTerminalSymb>(currentSymbol)) {
            auto symbol = std::get<tagNonTerminalSymb>(currentSymbol).val;
            std::vector<SymbolMix> production;
            
            if(symbol == Symbols::PROGRAM) production = parse_rules::matchProgram(token);
        }
        //Parse Terminal Symbols
        else if(std::holds_alternative<tagTerminalSymb>(currentSymbol)){
            auto terminalSymbol = std::get<tagTerminalSymb>(currentSymbol).val;
            if(terminalSymbol == token->getType()) {
                
            }
            
        }
        
        
        //if(currentSymbol == Symbols::PROGRAM)


    }
    


}
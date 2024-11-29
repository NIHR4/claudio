#include "decorator.hpp"

std::string handleSymbol(const AnySymbol& symbol) {
    std::string res;
    if(std::holds_alternative<tag::nterm>(symbol)){
        res = symbolToString(std::get<tag::nterm>(symbol).val);
    }else{
        res = tokenToString(std::get<tag::term>(symbol).val);
    }
   
    return res;
}


ASTNode convertToAST(ParseTree& parseTree, ParseTreeNode parseNode, AST& ast, ASTNode parent) {
    // Map parse tree node type to AST node type
    std::string nodeType = handleSymbol(*parseNode);

    if (nodeType == "PROGRAM") {
        // Create the root AST node
        ASTNode programNode = ast.insert(parent, { "PROGRAM", "" });
        for (auto child = parseTree.begin(parseNode); child != parseTree.end(parseNode); ++child) {
            convertToAST(parseTree, child, ast, programNode);
        }
        return programNode;
    } else if (nodeType == "STATEMENT_LIST") {
        // Flatten statement list into AST
        ASTNode stmtListNode = ast.append_child(parent, { "STATEMENTS", "" });
        for (auto child = parseTree.begin(parseNode); child != parseTree.end(parseNode); ++child) {
            convertToAST(parseTree, child, ast, stmtListNode);
        }
        return stmtListNode;
    } else if (nodeType == "ASSIGNMENT_STATEMENT") {
        // Create assignment node
        ASTNode assignmentNode = ast.append_child(parent, { "ASSIGNMENT", "" });
        auto idNode = parseTree.begin(parseNode); // First child: identifier
        auto exprNode = ++parseTree.begin(parseNode); // Second child: expression
        ast.append_child(assignmentNode, { "ID", handleSymbol(*idNode) });
        convertToAST(parseTree, exprNode, ast, assignmentNode);
        return assignmentNode;
    } /*else if (nodeType == "BINARY_EXPR") {
        // Create binary operation node
        ASTNode binaryOpNode = ast.append_child(parent, { "BINARY_OP", "" });
        auto leftNode = parseTree.begin(parseNode); // First child: left operand
        auto opNode = ++parseTree.begin(parseNode); // Second child: operator
        auto rightNode = ++(++parseTree.begin(parseNode)); // Third child: right operand
        convertToAST(parseTree, leftNode, ast, binaryOpNode);
        ast.append_child(binaryOpNode, { "OPERATOR", handleSymbol(*opNode) });
        convertToAST(parseTree, rightNode, ast, binaryOpNode);
        return binaryOpNode;
    } else if (nodeType == "DECLARATION_STATEMENT") {
        // Create declaration node
        ASTNode declarationNode = ast.append_child(parent, { "DECLARATION", "" });
        auto typeNode = parseTree.begin(parseNode); // First child: type
        auto idNode = ++parseTree.begin(parseNode); // Second child: identifier
        ast.append_child(declarationNode, { "TYPE", handleSymbol(*typeNode) });
        ast.append_child(declarationNode, { "ID", handleSymbol(*idNode) });
        return declarationNode;
    } else if (nodeType == "ID" || nodeType == "LITERAL") {
        // Create a terminal node
        return ast.append_child(parent, { nodeType, handleSymbol(*parseNode) });
    }*/

    // Default: Traverse children without adding a new AST node
    for (auto child = parseTree.begin(parseNode); child != parseTree.end(parseNode); ++child) {
        convertToAST(parseTree, child, ast, parent);
    }
    return parent;
}

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../parser/symbols.hpp"
#include <treehh/tree.hh>
#include <any>




// Define ParseTreeNode and ASTNode
struct NodeData {
    std::string type; // Node type (e.g., "PROGRAM", "ASSIGNMENT")
    std::string value; // Optional value (e.g., "x", "+")
};

// Type aliases for trees
using ParseTree = tree<AnySymbol>;
using ParseTreeNode = ParseTree::iterator;

using AST = tree<NodeData>;
using ASTNode = AST::iterator;

ASTNode convertToAST(ParseTree& parseTree, ParseTreeNode parseNode, AST& ast, ASTNode parent = ASTNode());
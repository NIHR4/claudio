lexer grammar claudio;

// Data types
INT64       : 'int64';
BYTE        : 'byte';
FLOAT       : 'float';
VOID        : 'void';
BOOL        : 'bool';
STRING      : 'string';

// Control flow keywords
IF          : 'if';
ELSE        : 'else';
WHILE       : 'while';
FOR         : 'for';
BREAK       : 'break';

// Other keywords
FUNCTION    : 'function';
ROUTINE     : 'routine';
RETURN      : 'return';

// Operators
LPAREN      : '(';
RPAREN      : ')';
LBRACE      : '{';
RBRACE      : '}';
LBRACKET    : '[';
RBRACKET    : ']';

MINUS       : '-';
PLUS        : '+';
MUL         : '*';
DIV         : '/';

INCREMENT   : '++';
DECREMENT   : '--';
GE          : '>=';
LE          : '<=';
EQ          : '==';
ASSIGN      : '=';

NOT         : '!';
NEQ         : '!=';
SEMICOLON   : ';';
COMMA       : ',';

// Literals and identifiers
ID          : [a-zA-Z] [a-zA-Z0-9]*;
INT_LITERAL : [0-9]+;
STRING_LITERAL : '"' ~["]* '"';

// Whitespace and comments
WS          : [ \t\r\n]+ -> skip;
COMMENT     : '//' ~[\r\n]* -> skip;

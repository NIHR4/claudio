
// Generated from claudio.g4 by ANTLR 4.13.2


#include "claudio.h"


using namespace antlr4;

using namespace lexer;


using namespace antlr4;

namespace {

struct ClaudioStaticData final {
  ClaudioStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ClaudioStaticData(const ClaudioStaticData&) = delete;
  ClaudioStaticData(ClaudioStaticData&&) = delete;
  ClaudioStaticData& operator=(const ClaudioStaticData&) = delete;
  ClaudioStaticData& operator=(ClaudioStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag claudioLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ClaudioStaticData> claudioLexerStaticData = nullptr;

void claudioLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (claudioLexerStaticData != nullptr) {
    return;
  }
#else
  assert(claudioLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ClaudioStaticData>(
    std::vector<std::string>{
      "INT64", "BYTE", "FLOAT", "VOID", "BOOL", "STRING", "IF", "ELSE", 
      "WHILE", "FOR", "BREAK", "FUNCTION", "ROUTINE", "RETURN", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "MINUS", "PLUS", 
      "MUL", "DIV", "INCREMENT", "DECREMENT", "GE", "LE", "EQ", "ASSIGN", 
      "GR_THAN", "LS_THAN", "NOT", "NEQ", "SEMICOLON", "COMMA", "ID", "INT_LITERAL", 
      "STRING_LITERAL", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int64'", "'byte'", "'float'", "'void'", "'bool'", "'string'", 
      "'if'", "'else'", "'while'", "'for'", "'break'", "'function'", "'routine'", 
      "'return'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'-'", "'+'", 
      "'*'", "'/'", "'++'", "'--'", "'>='", "'<='", "'=='", "'='", "'>'", 
      "'<'", "'!'", "'!='", "';'", "','"
    },
    std::vector<std::string>{
      "", "INT64", "BYTE", "FLOAT", "VOID", "BOOL", "STRING", "IF", "ELSE", 
      "WHILE", "FOR", "BREAK", "FUNCTION", "ROUTINE", "RETURN", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "MINUS", "PLUS", 
      "MUL", "DIV", "INCREMENT", "DECREMENT", "GE", "LE", "EQ", "ASSIGN", 
      "GR_THAN", "LS_THAN", "NOT", "NEQ", "SEMICOLON", "COMMA", "ID", "INT_LITERAL", 
      "STRING_LITERAL", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,41,254,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,
  	1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,
  	1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,
  	1,33,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,5,36,218,8,36,10,36,12,36,
  	221,9,36,1,37,4,37,224,8,37,11,37,12,37,225,1,38,1,38,5,38,230,8,38,10,
  	38,12,38,233,9,38,1,38,1,38,1,39,4,39,238,8,39,11,39,12,39,239,1,39,1,
  	39,1,40,1,40,1,40,1,40,5,40,248,8,40,10,40,12,40,251,9,40,1,40,1,40,0,
  	0,41,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,
  	73,37,75,38,77,39,79,40,81,41,1,0,6,2,0,65,90,97,122,3,0,48,57,65,90,
  	97,122,1,0,48,57,1,0,34,34,3,0,9,10,13,13,32,32,2,0,10,10,13,13,258,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,
  	0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,
  	55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,
  	0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,
  	0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,1,83,1,0,0,0,3,89,1,0,0,0,5,
  	94,1,0,0,0,7,100,1,0,0,0,9,105,1,0,0,0,11,110,1,0,0,0,13,117,1,0,0,0,
  	15,120,1,0,0,0,17,125,1,0,0,0,19,131,1,0,0,0,21,135,1,0,0,0,23,141,1,
  	0,0,0,25,150,1,0,0,0,27,158,1,0,0,0,29,165,1,0,0,0,31,167,1,0,0,0,33,
  	169,1,0,0,0,35,171,1,0,0,0,37,173,1,0,0,0,39,175,1,0,0,0,41,177,1,0,0,
  	0,43,179,1,0,0,0,45,181,1,0,0,0,47,183,1,0,0,0,49,185,1,0,0,0,51,188,
  	1,0,0,0,53,191,1,0,0,0,55,194,1,0,0,0,57,197,1,0,0,0,59,200,1,0,0,0,61,
  	202,1,0,0,0,63,204,1,0,0,0,65,206,1,0,0,0,67,208,1,0,0,0,69,211,1,0,0,
  	0,71,213,1,0,0,0,73,215,1,0,0,0,75,223,1,0,0,0,77,227,1,0,0,0,79,237,
  	1,0,0,0,81,243,1,0,0,0,83,84,5,105,0,0,84,85,5,110,0,0,85,86,5,116,0,
  	0,86,87,5,54,0,0,87,88,5,52,0,0,88,2,1,0,0,0,89,90,5,98,0,0,90,91,5,121,
  	0,0,91,92,5,116,0,0,92,93,5,101,0,0,93,4,1,0,0,0,94,95,5,102,0,0,95,96,
  	5,108,0,0,96,97,5,111,0,0,97,98,5,97,0,0,98,99,5,116,0,0,99,6,1,0,0,0,
  	100,101,5,118,0,0,101,102,5,111,0,0,102,103,5,105,0,0,103,104,5,100,0,
  	0,104,8,1,0,0,0,105,106,5,98,0,0,106,107,5,111,0,0,107,108,5,111,0,0,
  	108,109,5,108,0,0,109,10,1,0,0,0,110,111,5,115,0,0,111,112,5,116,0,0,
  	112,113,5,114,0,0,113,114,5,105,0,0,114,115,5,110,0,0,115,116,5,103,0,
  	0,116,12,1,0,0,0,117,118,5,105,0,0,118,119,5,102,0,0,119,14,1,0,0,0,120,
  	121,5,101,0,0,121,122,5,108,0,0,122,123,5,115,0,0,123,124,5,101,0,0,124,
  	16,1,0,0,0,125,126,5,119,0,0,126,127,5,104,0,0,127,128,5,105,0,0,128,
  	129,5,108,0,0,129,130,5,101,0,0,130,18,1,0,0,0,131,132,5,102,0,0,132,
  	133,5,111,0,0,133,134,5,114,0,0,134,20,1,0,0,0,135,136,5,98,0,0,136,137,
  	5,114,0,0,137,138,5,101,0,0,138,139,5,97,0,0,139,140,5,107,0,0,140,22,
  	1,0,0,0,141,142,5,102,0,0,142,143,5,117,0,0,143,144,5,110,0,0,144,145,
  	5,99,0,0,145,146,5,116,0,0,146,147,5,105,0,0,147,148,5,111,0,0,148,149,
  	5,110,0,0,149,24,1,0,0,0,150,151,5,114,0,0,151,152,5,111,0,0,152,153,
  	5,117,0,0,153,154,5,116,0,0,154,155,5,105,0,0,155,156,5,110,0,0,156,157,
  	5,101,0,0,157,26,1,0,0,0,158,159,5,114,0,0,159,160,5,101,0,0,160,161,
  	5,116,0,0,161,162,5,117,0,0,162,163,5,114,0,0,163,164,5,110,0,0,164,28,
  	1,0,0,0,165,166,5,40,0,0,166,30,1,0,0,0,167,168,5,41,0,0,168,32,1,0,0,
  	0,169,170,5,123,0,0,170,34,1,0,0,0,171,172,5,125,0,0,172,36,1,0,0,0,173,
  	174,5,91,0,0,174,38,1,0,0,0,175,176,5,93,0,0,176,40,1,0,0,0,177,178,5,
  	45,0,0,178,42,1,0,0,0,179,180,5,43,0,0,180,44,1,0,0,0,181,182,5,42,0,
  	0,182,46,1,0,0,0,183,184,5,47,0,0,184,48,1,0,0,0,185,186,5,43,0,0,186,
  	187,5,43,0,0,187,50,1,0,0,0,188,189,5,45,0,0,189,190,5,45,0,0,190,52,
  	1,0,0,0,191,192,5,62,0,0,192,193,5,61,0,0,193,54,1,0,0,0,194,195,5,60,
  	0,0,195,196,5,61,0,0,196,56,1,0,0,0,197,198,5,61,0,0,198,199,5,61,0,0,
  	199,58,1,0,0,0,200,201,5,61,0,0,201,60,1,0,0,0,202,203,5,62,0,0,203,62,
  	1,0,0,0,204,205,5,60,0,0,205,64,1,0,0,0,206,207,5,33,0,0,207,66,1,0,0,
  	0,208,209,5,33,0,0,209,210,5,61,0,0,210,68,1,0,0,0,211,212,5,59,0,0,212,
  	70,1,0,0,0,213,214,5,44,0,0,214,72,1,0,0,0,215,219,7,0,0,0,216,218,7,
  	1,0,0,217,216,1,0,0,0,218,221,1,0,0,0,219,217,1,0,0,0,219,220,1,0,0,0,
  	220,74,1,0,0,0,221,219,1,0,0,0,222,224,7,2,0,0,223,222,1,0,0,0,224,225,
  	1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,76,1,0,0,0,227,231,5,34,0,
  	0,228,230,8,3,0,0,229,228,1,0,0,0,230,233,1,0,0,0,231,229,1,0,0,0,231,
  	232,1,0,0,0,232,234,1,0,0,0,233,231,1,0,0,0,234,235,5,34,0,0,235,78,1,
  	0,0,0,236,238,7,4,0,0,237,236,1,0,0,0,238,239,1,0,0,0,239,237,1,0,0,0,
  	239,240,1,0,0,0,240,241,1,0,0,0,241,242,6,39,0,0,242,80,1,0,0,0,243,244,
  	5,47,0,0,244,245,5,47,0,0,245,249,1,0,0,0,246,248,8,5,0,0,247,246,1,0,
  	0,0,248,251,1,0,0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,252,1,0,0,0,251,
  	249,1,0,0,0,252,253,6,40,0,0,253,82,1,0,0,0,6,0,219,225,231,239,249,1,
  	6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  claudioLexerStaticData = std::move(staticData);
}

}

claudio::claudio(CharStream *input) : Lexer(input) {
  claudio::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *claudioLexerStaticData->atn, claudioLexerStaticData->decisionToDFA, claudioLexerStaticData->sharedContextCache);
}

claudio::~claudio() {
  delete _interpreter;
}

std::string claudio::getGrammarFileName() const {
  return "claudio.g4";
}

const std::vector<std::string>& claudio::getRuleNames() const {
  return claudioLexerStaticData->ruleNames;
}

const std::vector<std::string>& claudio::getChannelNames() const {
  return claudioLexerStaticData->channelNames;
}

const std::vector<std::string>& claudio::getModeNames() const {
  return claudioLexerStaticData->modeNames;
}

const dfa::Vocabulary& claudio::getVocabulary() const {
  return claudioLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView claudio::getSerializedATN() const {
  return claudioLexerStaticData->serializedATN;
}

const atn::ATN& claudio::getATN() const {
  return *claudioLexerStaticData->atn;
}




void claudio::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  claudioLexerInitialize();
#else
  ::antlr4::internal::call_once(claudioLexerOnceFlag, claudioLexerInitialize);
#endif
}

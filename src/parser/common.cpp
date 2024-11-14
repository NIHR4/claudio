#include "common.hpp"
namespace parse_rules
{

    std::unordered_map<MatcherPtr, std::string> matcherNames = {
        {TE::matchIdentifier, "matchIdentifier"},
        {TE::matchNumber, "matchNumber"},
        {TE::matchIf,"matchIf"},
        {TE::matchIfNot, "matchIfNot"},
    };
    
    
    
    
    
    
    void log(const std::string& message)
    {
#ifdef NDEBUG
        std::cout << message << std::endl;
#endif
    }

    std::vector<AnySymbol> findProductionRule(const std::vector<ProductionRule>& rules, antlr4::Token * token, std::string originator) {
        const auto tokenType = static_cast<size_t>(token->getType());
        auto it = std::find_if(rules.cbegin(), rules.cend(),
            [&tokenType](const ProductionRule& rule) {
            return rule.matcher(tokenType);
            }
        );
        if (it != rules.cend()) {
            log("matched production rule ({})");
            
            return it->production(token);
        }else{
            throw std::runtime_error("no production rules match");
        } 
    }
    
} // namespace parse_rules

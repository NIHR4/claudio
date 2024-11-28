#include "common.hpp"
namespace parse_rules
{
    std::vector<AnySymbol> findProductionRule(const std::vector<ProductionRule>& rules, antlr4::Token * token) {
        const auto tokenType = static_cast<size_t>(token->getType());
        auto it = std::find_if(rules.cbegin(), rules.cend(),
            [&tokenType](const ProductionRule& rule) {
            return rule.matcher(tokenType);
            }
        );
        if (it != rules.cend()) return it->production(token);
        else throw std::runtime_error("no production rules match");
    }
    
} // namespace parse_rules

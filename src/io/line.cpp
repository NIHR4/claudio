#pragma once
#include "line.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> SourceLine::createNewIndexMap(const std::string& original, const std::string& transformed) {
    std::size_t lenOriginal = original.size();
    std::size_t lenTransformed = transformed.size();

    // Matrix to store the cost and original index mapping
    using IntPair = std::pair<int,int>;
    std::vector<std::vector<IntPair>> dp(lenOriginal + 1, std::vector<std::pair<int, int>>(lenTransformed + 1, {0, -1}));

    // Initialize base cases for deletions and insertions
    for (int i = 1; i <= lenOriginal; ++i) {
        dp[i][0] = {i, i - 1}; 
    }
    for (int j = 1; j <= lenTransformed; ++j) {
        dp[0][j] = {j, -1}; 
    }

    // Fill the dp table with the minimum cost and original index mapping
    for (int i = 1; i <= lenOriginal; ++i) {
        for (int j = 1; j <= lenTransformed; ++j) {
            if (original[i - 1] == transformed[j - 1]) {
                // No-op
                dp[i][j] = {dp[i - 1][j - 1].first, i - 1};
            } else {
                int deleteCost = dp[i - 1][j].first + 1;
                int insertCost = dp[i][j - 1].first + 1;
                int substituteCost = dp[i - 1][j - 1].first + 1;

                // Choose the minimum cost operation
                if (deleteCost <= insertCost && deleteCost <= substituteCost) {
                    dp[i][j] = {deleteCost, i - 1};  // Deletion
                } else if (insertCost <= deleteCost && insertCost <= substituteCost) {
                    dp[i][j] = {insertCost, -1};  // Insertion
                } else {
                    dp[i][j] = {substituteCost, i - 1};  // Substitution
                }
            }
        }
    }

    // Backtrack to map the transformed string indices to the original string
    int i = lenOriginal, j = lenTransformed;
    std::vector<int> transformedToOriginalMap;

    while (i > 0 || j > 0) {
        int currentCost = dp[i][j].first;
        int originalIndex = dp[i][j].second;

        if (i > 0 && j > 0 && dp[i][j].first == dp[i - 1][j - 1].first && original[i - 1] == transformed[j - 1]) {
            transformedToOriginalMap.push_back(originalIndex);
            --i;
            --j;
        } else if (i > 0 && dp[i][j].first == dp[i - 1][j].first + 1) {
            --i;
        } else if (j > 0 && dp[i][j].first == dp[i][j - 1].first + 1) {
            transformedToOriginalMap.push_back(-1);
            --j;
        } else {
            transformedToOriginalMap.push_back(originalIndex);
            --i;
            --j;
        }
    }

    std::reverse(transformedToOriginalMap.begin(), transformedToOriginalMap.end());
    return transformedToOriginalMap;
}
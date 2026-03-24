// AlchemyWorkshop.h

#pragma once
#include "RecipeManager.h"
#include "StockManager.h"
#include <string>
#include <vector>

class AlchemyWorkshop
{
public:
    void AddRecipe(const std::string& potionName, const std::vector<std::string>& ingredients);

    void DisplayAllRecipes() const;

    int GetStockByName(const std::string& potionName) const;

    bool DispensePotionByName(const std::string& potionName);

    std::vector<std::string> DispensePotionsByIngredient(const std::string& ingredient);

    void ReturnPotionByName(const std::string& potionName);

private:
    RecipeManager recipeManager_;
    StockManager stockManager_;
};
// AlchemyWorkshop.cpp

#include "AlchemyWorkshop.h"
#include <iostream>

void AlchemyWorkshop::AddRecipe(const std::string& potionName, const std::vector<std::string>& ingredients)
{
    PotionRecipe* addedRecipe = recipeManager_.AddRecipe(potionName, ingredients);

    if (addedRecipe != nullptr)
    {
        stockManager_.InitializeStock(potionName);
    }
    else
    {
        std::cout << potionName << " 레시피는 이미 존재합니다.\n";
    }
}

void AlchemyWorkshop::DisplayAllRecipes() const
{
    const std::vector<PotionRecipe>& recipes = recipeManager_.GetAllRecipes();

    if (recipes.empty())
    {
        std::cout << "등록된 레시피가 없습니다.\n";
        return;
    }

    for (const auto& recipe : recipes)
    {
        std::cout << "물약 이름: " << recipe.GetName() << "\n";
        std::cout << "재료: ";

        const std::vector<std::string>& ingredients = recipe.GetIngredients();
        for (size_t i = 0; i < ingredients.size(); ++i)
        {
            std::cout << ingredients[i];
            if (i + 1 < ingredients.size())
            {
                std::cout << ", ";
            }
        }

        std::cout << "\n현재 재고: " << stockManager_.GetStock(recipe.GetName()) << "\n";
        std::cout << "-------------------------\n";
    }
}

int AlchemyWorkshop::GetStockByName(const std::string& potionName) const
{
    PotionRecipe* recipe = const_cast<RecipeManager&>(recipeManager_).FindRecipeByName(potionName);

    if (recipe == nullptr)
    {
        std::cout << potionName << " 레시피가 존재하지 않습니다.\n";
        return 0;
    }

    return stockManager_.GetStock(potionName);
}

bool AlchemyWorkshop::DispensePotionByName(const std::string& potionName)
{
    PotionRecipe* recipe = recipeManager_.FindRecipeByName(potionName);

    if (recipe == nullptr)
    {
        std::cout << potionName << " 레시피가 존재하지 않습니다.\n";
        return false;
    }

    if (!stockManager_.DispensePotion(potionName))
    {
        std::cout << potionName << " 재고가 부족합니다.\n";
        return false;
    }

    return true;
}

std::vector<std::string> AlchemyWorkshop::DispensePotionsByIngredient(const std::string& ingredient)
{
    std::vector<std::string> dispensedPotions;
    std::vector<PotionRecipe> recipes = recipeManager_.FindRecipesByIngredient(ingredient);

    if (recipes.empty())
    {
        std::cout << ingredient << " 재료를 사용하는 레시피가 없습니다.\n";
        return dispensedPotions;
    }

    for (const auto& recipe : recipes)
    {
        if (stockManager_.DispensePotion(recipe.GetName()))
        {
            dispensedPotions.push_back(recipe.GetName());
        }
        else
        {
            std::cout << recipe.GetName() << " 재고가 부족합니다.\n";
        }
    }

    return dispensedPotions;
}

void AlchemyWorkshop::ReturnPotionByName(const std::string& potionName)
{
    PotionRecipe* recipe = recipeManager_.FindRecipeByName(potionName);

    if (recipe == nullptr)
    {
        std::cout << potionName << " 레시피가 존재하지 않습니다.\n";
        return;
    }

    int beforeStock = stockManager_.GetStock(potionName);
    stockManager_.ReturnPotion(potionName);
    int afterStock = stockManager_.GetStock(potionName);

    if (beforeStock == afterStock)
    {
        std::cout << potionName << " 재고는 이미 최대치입니다.\n";
    }
}
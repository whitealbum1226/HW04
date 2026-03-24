// RecipeManager.cpp

#include "RecipeManager.h"

PotionRecipe* RecipeManager::AddRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    PotionRecipe* foundRecipe = FindRecipeByName(name);
    if (foundRecipe != nullptr)
    {
        return nullptr;
    }

    recipes_.emplace_back(name, ingredients);
    return &recipes_.back();
}

PotionRecipe* RecipeManager::FindRecipeByName(const std::string& name)
{
    for (auto& recipe : recipes_)
    {
        if (recipe.GetName() == name)
        {
            return &recipe;
        }
    }

    return nullptr;
}

std::vector<PotionRecipe> RecipeManager::FindRecipesByIngredient(const std::string& ingredient) const
{
    std::vector<PotionRecipe> result;

    for (const auto& recipe : recipes_)
    {
        const std::vector<std::string>& ingredients = recipe.GetIngredients();

        for (const auto& currentIngredient : ingredients)
        {
            if (currentIngredient == ingredient)
            {
                result.push_back(recipe);
                break;
            }
        }
    }

    return result;
}

const std::vector<PotionRecipe>& RecipeManager::GetAllRecipes() const
{
    return recipes_;
}
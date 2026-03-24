// RecipeManager.h

#pragma once
#include "PotionRecipe.h"
#include <string>
#include <vector>

class RecipeManager
{
public:
    PotionRecipe* AddRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    PotionRecipe* FindRecipeByName(const std::string& name);

    std::vector<PotionRecipe> FindRecipesByIngredient(const std::string& ingredient) const;

    const std::vector<PotionRecipe>& GetAllRecipes() const;

private:
    std::vector<PotionRecipe> recipes_;
};
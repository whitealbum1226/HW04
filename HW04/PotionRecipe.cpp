// PotionRecipe.cpp

#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
    : name_(name), ingredients_(ingredients)
{
}

const std::string& PotionRecipe::GetName() const
{
    return name_;
}

const std::vector<std::string>& PotionRecipe::GetIngredients() const
{
    return ingredients_;
}
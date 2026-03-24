// PotionRecipe.h

#pragma once
#include <string>
#include <vector>

class PotionRecipe
{
public:
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    const std::string& GetName() const;
    const std::vector<std::string>& GetIngredients() const;

private:
    std::string name_;
    std::vector<std::string> ingredients_;
};
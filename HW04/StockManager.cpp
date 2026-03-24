// StockManager.cpp

#include "StockManager.h"

void StockManager::InitializeStock(const std::string& potionName)
{
    if (potionStock_.find(potionName) == potionStock_.end())
    {
        potionStock_[potionName] = MAX_STOCK;
    }
}

bool StockManager::DispensePotion(const std::string& potionName)
{
    auto it = potionStock_.find(potionName);

    if (it == potionStock_.end())
    {
        return false;
    }

    if (it->second <= 0)
    {
        return false;
    }

    --(it->second);
    return true;
}

void StockManager::ReturnPotion(const std::string& potionName)
{
    auto it = potionStock_.find(potionName);

    if (it == potionStock_.end())
    {
        return;
    }

    if (it->second < MAX_STOCK)
    {
        ++(it->second);
    }
}

int StockManager::GetStock(const std::string& potionName) const
{
    auto it = potionStock_.find(potionName);

    if (it == potionStock_.end())
    {
        return 0;
    }

    return it->second;
}
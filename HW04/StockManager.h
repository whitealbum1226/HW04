// StockManager.h

#pragma once
#include <string>
#include <map>

class StockManager
{
public:
    static constexpr int MAX_STOCK = 3;

    void InitializeStock(const std::string& potionName);

    bool DispensePotion(const std::string& potionName);

    void ReturnPotion(const std::string& potionName);

    int GetStock(const std::string& potionName) const;

private:
    std::map<std::string, int> potionStock_;
};
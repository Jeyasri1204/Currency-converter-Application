#include <iostream> 
#include <iomanip> 
using namespace std; 
enum class CurrencyType { 
USD, 
EUR, 
INR 
}; 
string currencyToString(CurrencyType type) { 
switch (type) { 
case CurrencyType::USD: return "USD"; 
case CurrencyType::EUR: return "EUR"; 
case CurrencyType::INR: return "INR"; 
default: return ""; 
} 
} 
class Currency { 
private: 
double amount; 
CurrencyType type; 
public: 
Currency(double amt = 0.0, CurrencyType t = CurrencyType::U public : amount(amt), type(t) {} 
Currency operator=(const Currency &other) { 
if (this != &other) { 
double converted = other.amount; 
if (other.type == CurrencyType::USD && type == CurrencyType::EUR) 
converted = other.amount * 0.92; 
else if (other.type == CurrencyType::USD && type == CurrencyType::INR) 
converted = other.amount * 82.0; 
else if (other.type == CurrencyType::EUR && type == CurrencyType::USD) 
converted = other.amount * 1.09; 
else if (other.type == CurrencyType::EUR && type == CurrencyType::INR) 
converted = other.amount * 89.0; 
else if (other.type == CurrencyType::INR && type == CurrencyType::USD) 
converted = other.amount * 0.012; 
else if (other.type == CurrencyType::INR && type == CurrencyType::EUR) 
converted = other.amount * 0.011; 
else 
converted = other.amount;  
amount = converted; 
} 
return *this; 
} 
void display() const { 
cout << fixed << setprecision(2) 
<< amount << " " << currencyToString(type) << endl; 
} 
double getAmount() const { return amount; } 
CurrencyType getType() const { return type; } 
}; 
CurrencyType selectCurrency() { 
int choice; 
cout << "Select currency:\n1. USD\n2. EUR\n3. INR\nChoice: "; 
cin >> choice; 
switch (choice) { 
case 1: return CurrencyType::USD; 
case 2: return CurrencyType::EUR; 
case 3: return CurrencyType::INR; 
default: return CurrencyType::USD; 
} 
} 
int main() { 
double amt; 
cout << "Enter amount: "; 
cin >> amt; 
cout << "Source currency:\n"; 
CurrencyType srcType = selectCurrency(); 
cout << "Target currency:\n"; 
CurrencyType tgtType = selectCurrency(); 
Currency source(amt, srcType); 
Currency target(0, tgtType); 
target = source; 
cout << "\nConverted Amount: "; 
target.display(); 
cout << "\nTransaction Record:\n" 
<< fixed << setprecision(2) 
<< source.getAmount() << " " << currencyToString(source.getType()) 
<< " -> " << target.getAmount() << " " << currencyToString(target.getType()); 
return 0; 
}
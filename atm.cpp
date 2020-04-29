#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

class ATM {

private:
    //  vector<unsigned int> note;
    //unsigned short int curren;
    vector<unsigned> cur_notes[3];

public:
    // Конструктор, создаёт пустой банкомат
    ATM() {}

    // Деструктор, если нужен

    // Вносит в устройство набор купюр
    // - в векторе notes перечислены достоинства вносимых купюр (разумеется, возможны повторы)
    // - в поле currency указан код валюты
    void deposit(const vector<unsigned int>& notes, unsigned short int currency) //: note(notes), curren(currency){}
    {
        for (int num : notes)
            cur_notes[currency].push_back(num);
    }

    // Снять сумму amount в валюте currency, выдав её максимально крупными купюрами
    // - если операция прошла успешно, учесть выданные купюры в банкомате и вернуть их в возвращаемом vector-е
    // - если целиком запрошенную сумму выдать невозможно, не выдавать ничего и вернуть пустой vector
    vector<unsigned int> withdraw_large(unsigned int amount, unsigned short int currency)
    {
        vector<unsigned> fnote;
        vector<unsigned> sterto;
        unsigned int A = amount;
        sort(cur_notes[currency].begin(), cur_notes[currency].end(), [](int x, int y) { return x > y; });

        for (unsigned i = 0; i < cur_notes[currency].size(); ++i) {
            if ((A >= cur_notes[currency][i]) && (A > 0)) {
                A = A - cur_notes[currency][i];
                 sterto.push_back(i);
                fnote.push_back(cur_notes[currency][i]);
            }
        }
        if (A == 0)
           { cur_notes[currency].erase(cur_notes[currency].begin(), cur_notes[currency].begin() + fnote.size());
            for(auto num : sterto)
                           cur_notes[currency].erase(cur_notes[currency].begin() + num);}
        else

            fnote.clear();

        return fnote;
    }

    // Снять сумму amount в валюте currency, выдав её максимально мелкими купюрами
    // - если операция прошла успешно, учесть выданные купюры в банкомате и вернуть их в возвращаемом vector-е
    // - если целиком запрошенную сумму выдать невозможно, не выдавать ничего и вернуть пустой vector
    vector<unsigned int> withdraw_small(unsigned int amount, unsigned short int currency)
    {
        vector<unsigned> fnote;
        unsigned int A = amount;
         vector<unsigned> sterto;
        sort(cur_notes[currency].begin(), cur_notes[currency].end(), [](int x, int y) { return x < y; });

        for (unsigned i = 0; i < cur_notes[currency].size(); ++i) {
            if ((A >=cur_notes[currency][i]) && (A > 0)) {
                A = A - cur_notes[currency][i];
                fnote.push_back(cur_notes[currency][i]);
                sterto.push_back(i);

           }
       }
       if (A == 0)
          { cur_notes[currency].erase(cur_notes[currency].begin(), cur_notes[currency].begin() + fnote.size());
           for(auto num : sterto)
                          cur_notes[currency].erase(cur_notes[currency].begin() + num);}
       else

           fnote.clear();

       return fnote;
    }

    // Вернуть максимальную сумму, доступную в валюте currency
    unsigned int check_reserve(unsigned short int currency)
    {
        unsigned int sum = 0;
        for (unsigned i = 0; i < cur_notes[currency].size(); ++i) {
            sum = sum + cur_notes[currency][i];
        }
        return sum;
    }
};
const unsigned short int RUB = 0;
const unsigned short int USD = 1;
const unsigned short int NCC = 2;

int main()
{
    vector<unsigned int> rubles = { 50, 100, 100, 500, 50, 1000, 100, 100, 1000, 5000 };
    vector<unsigned int> dollars = { 100, 100, 100 };
    vector<unsigned int> nuka_cola_caps = { 1, 1, 1, 1, 1 };

    ATM atm;
    atm.deposit(rubles, RUB);
    atm.deposit(dollars, USD);
    atm.deposit(nuka_cola_caps, NCC);

    cout << "Reserves: " << endl;
    for (unsigned short int code = 0; code <= 2; code++) {
        cout << "Currency " << code << ": " << atm.check_reserve(code) << endl;
    }

    vector<unsigned int> result;
    result = atm.withdraw_large(1000, RUB);
    cout << "Asked withdraw_large for 1000 RUB, got " << result.size() << " banknotes" << endl;
    //  for(auto num : result) cout << num<< "o";

    result = atm.withdraw_small(1000, RUB);
    cout << "Asked withdraw_small for 1000 RUB, got " << result.size() << " banknotes" << endl;

    result = atm.withdraw_small(1000, USD);
    cout << "Asked withdraw_small for 1000 USD, got " << result.size() << " banknotes" << endl;

    result = atm.withdraw_large(3, NCC);
    cout << "Asked withdraw_large for 3 NCC, got " << result.size() << " banknotes" << endl;

    cout << "Reserves: " << endl;
    for (unsigned short int code = 0; code <= 2; code++) {
        cout << "Currency " << code << ": " << atm.check_reserve(code) << endl;
    }

    return 0;
}

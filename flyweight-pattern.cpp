#include <iostream>
#include <unordered_map> //зберігання вже створених об'єктів//
using namespace std;

class Character {
private:
    char symbol;
public:
    Character(char s) : symbol(s) {}
    void display(int position) const {
        cout << "Character '" << symbol << "' at position " << position << endl;
    }
};

class CharacterFactory {
private:
    unordered_map<char, Character*> pool;
public:
    Character* getCharacter(char symbol) {
        if (pool.find(symbol) == pool.end()) {
            pool[symbol] = new Character(symbol);
        }
        return pool[symbol];
    }

    ~CharacterFactory() {
        for (auto& pair : pool) {
            delete pair.second;
        }
    }
};

int main() {
    CharacterFactory factory;

    Character* a1 = factory.getCharacter('A');
    Character* a2 = factory.getCharacter('A');
    Character* b1 = factory.getCharacter('B');

    a1->display(1);
    a2->display(2);
    b1->display(3);

    return 0;
}
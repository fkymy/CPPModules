#include <iostream>
#include <string>

class Pony {
public:
    Pony(std::string name, int weight);
    ~Pony();

    void run() const;

private:
    std::string name;
    int weight;
};

Pony::Pony(std::string name, int weight) : name(name), weight(weight) {
    std::cout << "こんにちは！" << std::endl;
}

Pony::~Pony() {
    std::cout << "さようなら！" << std::endl;
}

void Pony::run() const {
    std::cout << name << ": 「うおおおおお」" << std::endl;
}

void ponyOnTheStack() {
    Pony pony("haruurara", 397);
    pony.run();
}

void ponyOnTheHeap() {
    Pony *pony = new Pony("specialweek", 422);
    if (pony == NULL) return;
    pony->run();
    delete pony;
}

int main() {
    ponyOnTheStack();
    ponyOnTheHeap();

    system("leaks a.out");

    return 0;
}

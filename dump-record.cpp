class VBase {
    virtual void corge();
    int j;
};

class SBase1 {
    virtual void grault();
    int k;
};

class SBase2 {
    virtual void grault();
    int k;
};

class SBase3 {
    void grault();
    int k;
};

class Class : public SBase1, SBase2, SBase3, virtual VBase {
public:
    void bar();
    virtual void baz();
    // virtual member function templates not allowed, thinking about memory
    // layout and vtables will tell you why
    // template<typename T>
    // virtual void quux();
private:
    int i;
    char c;
public:
    float f;
private:
    double d;
public:
    short s;
};

class Derived : public Class {
    virtual void qux();
};

int main() {
    return sizeof(Derived);
}


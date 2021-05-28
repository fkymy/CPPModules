class BaseClass
{
public:
    virtual ~BaseClass() {} // Polymorphic classes need virtual destructors
    virtual void doSomething();
private:
    int baseX, baseY;
};

class DerivedClass: public BaseClass
{
public:
    virtual void doSomething(); // Override BaseClass version
private:
    int derX, derY;
};

int main() {
    return sizeof(DerivedClass);
}

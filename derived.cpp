class BaseClass
{
private:
    int baseX, baseY;
};
class DerivedClass: public BaseClass {
private:
   int derX, derY;
};

int main() {
    return sizeof(DerivedClass);
}

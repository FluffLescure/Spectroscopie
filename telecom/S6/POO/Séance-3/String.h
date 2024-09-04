#ifndef STRING
#define STRING

class String {
private:
    char *str;
    int length;

public:
    String();
    String(const char *s);
    String(const String &s);
    ~String();
    int getLength() const;
    void print() const;
    char operator[](int i) const;
    void operator=(const String &s);
    String operator+(const String &s) const;
};

#endif
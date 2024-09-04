#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String::String() {
    this->str = NULL;
    this->length = 0;
}

String::String(const char* s)
    : length(strlen(s)) {
    this->str = (char*)malloc(sizeof(char) * this->length);
    strcpy(this->str, s);
}

String::String(const String& s)
    : length(s.length) {
    this->str = (char*)malloc(sizeof(char) * s.length);
    strcpy(this->str, s.str);
}

String::~String() {
    free(this->str);
}

int String::getLength() const {
    return this->length;
}

void String::print() const {
    printf("\n%s", this->str);
}

char String::operator[](int i) const {
    if (i < 0 || i >= length) {
        printf("ERROR: Violation of memory access, check string length");
        abort();
    }
    return this->str[i];
}

void String::operator=(const String& s) {
    this->length = s.length;
    for (int i = 0; i < s.length; i++)
        this->str[i] = s.str[i];
}

String String::operator+(const String& s) const {
    String concat;
    concat.length = this->length + s.length;
    concat.str = (char*)malloc(sizeof(char) * concat.length);
    for (int i = 0; i < this->length; i++)
        concat.str[i] = this->str[i];
    for (int i = this->length; i < concat.length; i++)
        concat.str[i] = s.str[i - this->length];
    return concat;
}
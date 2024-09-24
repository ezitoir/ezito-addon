

#include <stdarg.h>
#include <cstring>
#include <string>

#include "node.h"
#include "ezito.h"


Ezito::Var::String::String() {
    this->val.ResetAsString();
}

Ezito::Var::String::String(char value){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
}

Ezito::Var::String::String(char * value) {
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
}

Ezito::Var::String::String(const char * value) {
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
}

Ezito::Var::String::String(const Ezito::Var::String * value) { 
    this->val = value->val;
}

Ezito::Var::String::String(const Ezito::Var::String & value) { 
    this->val = value.val;
}

Ezito::Var::String::String(Ezito::Var value){
    if(!value.IsEmpty() && value.IsString()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::String::String(v8::Local<v8::Value> value) {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(v8::Local<v8::String> value) {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(v8::Local<v8::StringObject> value) {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::String::String(v8::MaybeLocal<v8::Value> value) {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}



v8::Local<v8::Value> Ezito::Var::String::Context(){
    return this->val;
}



bool Ezito::Var::String::IsEmpty() {
    return this->val.IsEmpty() || !this->val.IsString(); 
}


const char * Ezito::Var::String::CppValue(){
    if(this->IsEmpty()){
        return NULL;
    }

    return Ezito::Var::GetCppValue(
        this->val.AsString()
    );
}
 


Ezito::Var::String::operator Ezito::Var(){ 
    return Ezito::Var(this->val);
};

Ezito::Var::String::operator Ezito::Var() const {
    return Ezito::Var(this->val);
};

Ezito::Var::String::operator Value(){ 
    return this->val;
};

Ezito::Var::String::operator Value() const {
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::Value>() { 
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::Value> () const {
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::String>() {
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::String> () const{
    return this->val;
};



Ezito::Var::String::operator char *(){ 
    return Ezito::Var::GetCppValue(this->val.AsString());
}

Ezito::Var::String::operator char * () const {
    Ezito::Var::String val(*this);
    const char * str = val.CppValue(); 
    char * result = reinterpret_cast<char *>(std::malloc(std::strlen(result) + 1));
    std::strcpy( result , str);
    return result ;
}

 

Ezito::Var::String::operator Ezito::TypeOf(){
    return Ezito::TypeOf("String");
}

Ezito::Var::String::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("String");
}






Ezito::Var::String Ezito::Var::String::operator=(const Ezito::Var::String& value){
    this->val=value.val;
    return *this;
}

Ezito::Var::String Ezito::Var::String::operator=(const Ezito::Var::String* value){
    this->val=value->val;
    return *this;
}





 


Ezito::Var::String::~String(){}
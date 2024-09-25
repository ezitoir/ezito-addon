

#include <stdarg.h>
#include <cstring>
#include <string>

#include "node.h"
#include "ezito.h"


Ezito::Var::String::String() {
    this->val.ResetAsString();
    this->length = 0;
}

Ezito::Var::String::String(char value) : String(){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
    const char str[1] = { value };
    this->length = std::strlen(str);
}

Ezito::Var::String::String(char * value) : String(){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
    this->length = this->val.AsString()->Length();
}

Ezito::Var::String::String(const char * value) : String(){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
    this->length = std::strlen(value);
}

Ezito::Var::String::String(const Ezito::Var::String * value) : String(){ 
    this->val = value->val;
    this->length = value->length;
}

Ezito::Var::String::String(const Ezito::Var::String & value) : String(){ 
    this->val = value.val;
    this->length = value.length;
}

Ezito::Var::String::String(Value value){
    if(!value.IsEmpty() && value.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(Ezito::Var value) : String() {
    if(!value.IsEmpty() && value.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::String::String(v8::Local<v8::Value> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = value.As<v8::String>()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(v8::Local<v8::String> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(v8::Local<v8::StringObject> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::String::String(v8::MaybeLocal<v8::Value> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
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


v8::Local<v8::String> Ezito::Var::String::v8(){ 
    return this->val.AsString();
}


Ezito::Var Ezito::Var::String::Var(){
    return this->val;
}
 

Ezito::Var::String Ezito::Var::String::operator=(const Ezito::Var::String& value){
    this->val = value.val;
    this->length = value.length;
    return *this;
}

Ezito::Var::String Ezito::Var::String::operator=(const Ezito::Var::String* value){
    this->val = value->val;
    this->length = value->length;
    return *this;
}

Ezito::Var::String Ezito::Var::String::operator=(const char * value){
    this->val = Ezito::Var::CreateValue(value);
    this->length = this->val.AsString()->Length();
    return *this;
}

v8::Local<v8::String> Ezito::Var::String::operator->(){
    return this->val.AsString() ;
}

Ezito::Var Ezito::Var::String::prototypeCall(const char * name, int count , ...){
    Ezito::Global global("String");
    Ezito::Var::Object prototype(global.Get("prototype"));

    Ezito::Var proto(prototype[name]);
    if(proto.IsFunction()){
        Ezito::Var::Function protoFn(proto);
        if(count > 0){
            v8::Local<v8::Value> * argv = new v8::Local<v8::Value>[count]();
            va_list args; 
            va_start(args, count);
            for (int i = 0; i < count; i++){
                argv[i] = static_cast<v8::Local<v8::Value>>(va_arg(args, Value));
            }
            va_end(args); 
            Ezito::Var result = protoFn.v8()->Call(
                Ezito::Node::Context() ,
                this->Var(),
                count,
                count > 0 ? argv : NULL
            );
            delete[] argv;
            return result;
        } 
    }

    return Ezito::Var();
}
 


Ezito::Var::String::~String(){}

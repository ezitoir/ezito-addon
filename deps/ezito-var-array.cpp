



 




#include "ezito.h"




Ezito::Var::Array::Array(){
    this->val = Ezito::Var::Undefined().Context();
    this->length = 0;
}

Ezito::Var::Array::Array(const Ezito::Var::Array * value) { 
    this->val = value->val;
}

Ezito::Var::Array::Array(const Ezito::Var::Array & value) { 
    this->val = value.val;
}

Ezito::Var::Array::Array(Value value){
    if(!value.IsEmpty() && value.IsArray()){
        this->val = value;
        this->length = this->val.AsArray()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Array::Array(Ezito::Var value){
    if(!value.IsEmpty() && value.IsArray()){
        this->val = value;
        this->length = this->val.AsArray()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Array::Array(v8::Local<v8::Value> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsArray()){
        this->val = value;
        this->length = this->val.AsArray()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::Array::Array(v8::Local<v8::Array> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsArray()){
        this->val = value;
        this->length = this->val.AsArray()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::Array::Array(v8::MaybeLocal<v8::Value> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsArray()){
        this->val = value;
        this->length = this->val.AsArray()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Array::Array(v8::MaybeLocal<v8::Array> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsArray()){
        this->val = value;
        this->length = this->val.AsArray()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

v8::Local<v8::Value> Ezito::Var::Array::Context() {
    return this->val;
}

v8::Local<v8::Array> Ezito::Var::Array::v8(){ 
    return this->val.AsArray();
}

Ezito::Var Ezito::Var::Array::Var(){
    return this->val;
}

bool Ezito::Var::Array::IsEmpty() {
    return this->val.IsEmpty() || !this->val.IsArray();
}





Ezito::Var Ezito::Var::Array::prototypeCall(const char * name, int count , ...){
    Ezito::Global global("Array");
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
 




void Ezito::Var::Array::Push(const char*value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        Ezito::Var::CreateValue(value)
    );
    this->length ++;
}

void Ezito::Var::Array::Push(int value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length ,
        Ezito::Var::CreateValue(value)
    );

    this->length ++;
}
  
void Ezito::Var::Array::Push(double value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        Ezito::Var::CreateValue(value)
    );
    this->length ++;
}

void Ezito::Var::Array::Push(float value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        Ezito::Var::CreateValue(value)
    );
    this->length ++;
}

void Ezito::Var::Array::Push(long long int value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        Ezito::Var::CreateValue(value)
    );
    this->length ++;
}

void Ezito::Var::Array::Push(bool value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        Ezito::Var::CreateValue(value)
    );

    this->length ++;
}

void Ezito::Var::Array::Push(Ezito::Var value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        value.Context()
    ); 
    this->length ++;
}

void Ezito::Var::Array::Push(v8::Local<v8::Value> value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }

    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        value
    ); 
    this->length ++;
}

void Ezito::Var::Array::Push(v8::MaybeLocal<v8::Value> value){
    if(this->val.IsEmpty()){
        this->val.ResetAsArray();
    }
    
    Ezito::Var val(value);
    this->val.AsArray()->Set(
        Ezito::Node::Context(),
        this->length,
        val.Context()
    ); 
    this->length ++;
}





Ezito::Var::Array::operator Ezito::Var(){
    return Ezito::Var(this->val);
}

Ezito::Var::Array::operator Ezito::Var() const{
    return Ezito::Var(this->val);
}

Ezito::Var::Array::operator Value(){ 
    return this->val;
};

Ezito::Var::Array::operator Value() const {
    return this->val;
};


Ezito::Var::Array::operator v8::Local<v8::Value>(){
    return this->val;
}

Ezito::Var::Array::operator v8::Local<v8::Value>() const{
    return this->val;
}

Ezito::Var::Array::operator v8::Local<v8::Array>(){
    return this->val;
}

Ezito::Var::Array::operator v8::Local<v8::Array>() const{
    return this->val;
}

Ezito::Var::Array::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Array");
}

Ezito::Var::Array::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("Array");
}
 

Ezito::Var Ezito::Var::Array::operator[](int index) {
    if(index >= this->length) return Ezito::Var::CreateValue();
    return Ezito::Var(
        this->val.AsArray()->Get(
            Ezito::Node::Context(),
            index
        ) 
    );
}


Ezito::Var::Array Ezito::Var::Array::operator=(const Ezito::Var::Array& value){
    this->val = value.val; 
    return *this;
}
Ezito::Var::Array Ezito::Var::Array::operator=(const Ezito::Var::Array* value){
    this->val = value->val; 
    return *this;
}

v8::Local<v8::Array> Ezito::Var::Array::operator->(){
    return this->val.AsArray();
}

Ezito::Var::Array::~Array(){}

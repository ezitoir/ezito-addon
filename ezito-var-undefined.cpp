

#include "ezito.h"



Ezito::Var::Undefined::Undefined(){
    
}

Ezito::Var::Undefined::Undefined(const Ezito::Var::Undefined * value) { 
    this->val = value->val;
}

Ezito::Var::Undefined::Undefined(const Ezito::Var::Undefined & value) { 
    this->val = value.val;
}

Ezito::Var::Undefined::Undefined(Ezito::Var value){
    if(value.IsUndefined()){
        this->val = value;
    }
}

Ezito::Var::Undefined::Undefined(v8::Local<v8::Value> value){
    if(!value.IsEmpty() && value->IsUndefined()){
        this->val = value;
    }
}
Ezito::Var::Undefined::Undefined(v8::Local<v8::Primitive> value){
   if(value->IsUndefined()){
        this->val = value;
    }
}

Ezito::Var::Undefined::Undefined(v8::MaybeLocal<v8::Primitive> value){
    if(!value.IsEmpty()){
        this->val =  Ezito::Var(value);
    }
}
 
v8::Local<v8::Value> Ezito::Var::Undefined::Context() {
    return this->val;
}


Ezito::Var::Undefined::operator Ezito::Var(){ 
    return Ezito::Var(this->val);
};

Ezito::Var::Undefined::operator Ezito::Var() const {
    return Ezito::Var(this->val);
};

Ezito::Var::Undefined::operator Value(){ 
    return this->val;
};

Ezito::Var::Undefined::operator Value() const {
    return this->val;
};

Ezito::Var::Undefined::operator v8::Local<v8::Value>() { 
    return this->val;
};

Ezito::Var::Undefined::operator v8::Local<v8::Value> () const {
    return this->val;
};

Ezito::Var::Undefined::operator v8::Local<v8::Primitive>() {
    return this->val;
};

Ezito::Var::Undefined::operator v8::Local<v8::Primitive> () const{
    return this->val;
};


Ezito::Var::Undefined::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Undefined");
}

Ezito::Var::Undefined::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("Undefined");
}


Ezito::Var::Undefined::~Undefined(){

}

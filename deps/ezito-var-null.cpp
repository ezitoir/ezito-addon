

#include "ezito.h"



Ezito::Var::Null::Null(){
    this->val = v8::Null(Ezito::Node::Isolate());
}
 
Ezito::Var::Null::Null(Ezito::Var value){
    if(value.IsNull()){
        this->val = value;
    }
}

Ezito::Var::Null::Null(v8::Local<v8::Value> value){
    if(!value.IsEmpty() && value->IsNull()){
        this->val = value;
    }
}
Ezito::Var::Null::Null(v8::Local<v8::Primitive> value){
   if(value->IsNull()){
        this->val = value;
    }
}

Ezito::Var::Null::Null(v8::MaybeLocal<v8::Primitive> value){
    if(!value.IsEmpty()){
        this->val =  Ezito::Var(value);
    }
}
 
v8::Local<v8::Value> Ezito::Var::Null::Context() {
    return this->val;
}


Ezito::Var::Null::operator Ezito::Var(){ 
    return Ezito::Var(this->val);
};

Ezito::Var::Null::operator Ezito::Var() const {
    return Ezito::Var(this->val);
};

Ezito::Var::Null::operator Value(){ 
    return this->val;
};

Ezito::Var::Null::operator Value() const {
    return this->val;
};

Ezito::Var::Null::operator v8::Local<v8::Value>() { 
    return this->val;
};

Ezito::Var::Null::operator v8::Local<v8::Value> () const {
    return this->val;
};

Ezito::Var::Null::operator v8::Local<v8::Primitive>() {
    return this->val;
};

Ezito::Var::Null::operator v8::Local<v8::Primitive> () const{
    return this->val;
};


Ezito::Var::Null::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Null");
}

Ezito::Var::Null::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("Null");
}


Ezito::Var::Null::~Null(){

}

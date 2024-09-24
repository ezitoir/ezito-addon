

#include "ezito.h"


Ezito::Var::Boolean::Boolean(){
    this->val = false;
}

Ezito::Var::Boolean::Boolean(bool value){
    this->val = value;
}

Ezito::Var::Boolean::Boolean(const Ezito::Var::Boolean * value) { 
    this->val = value->val;
}

Ezito::Var::Boolean::Boolean(const Ezito::Var::Boolean & value) { 
    this->val = value.val;
}



Ezito::Var::Boolean::Boolean(Ezito::Var value) { 
    if(!value.IsEmpty() && value.IsBoolean()){
        this->val = value;
        return;
    };
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Boolean::Boolean(v8::Local<v8::Value> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsBoolean()){
        this->val = value.As<v8::Boolean>();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Boolean::Boolean(v8::MaybeLocal<v8::Value> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsBoolean()){
        this->val = value.ToLocalChecked().As<v8::Boolean>();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


v8::Local<v8::Value> Ezito::Var::Boolean::Context(){
    return this->val;
}

bool Ezito::Var::Boolean::IsEmpty() {
    return this->val.IsObject() || !this->val.IsBoolean(); 
}


const bool Ezito::Var::Boolean::CppValue (){
    if(this->IsEmpty()) return false;
    const bool result = Ezito::Var::GetCppValue(
        this->val.AsBoolean()
    );
    return result;
}


Ezito::Var::Boolean::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Boolean");
}

Ezito::Var::Boolean::operator Ezito::TypeOf() const { 
    return Ezito::TypeOf("Boolean");
}

 
Ezito::Var::Boolean::~Boolean(){
    
}


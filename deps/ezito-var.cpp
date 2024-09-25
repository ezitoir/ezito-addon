


#include "ezito.h"


Ezito::Var::Var() : Value(){

}

Ezito::Var::Var(Value value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::String value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::Number value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::Null value){
    this->val = value.Context();
}


Ezito::Var::Var(Ezito::Var::Undefined value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::Object value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::Array value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::Function value){
    this->val = value.Context();
}

Ezito::Var::Var(Ezito::Var::Boolean value){
    this->val = value.Context();
}


Ezito::Var::operator  Value(){
    return this->val;
}


Ezito::Var::operator  Value() const{
    return this->val;
}






Ezito::Var::String Ezito::Var::ToString() {
    return Ezito::Var::String(this->val);
}

Ezito::Var::Number Ezito::Var::ToNumber(){
    return Ezito::Var::Number(this->val);
}

Ezito::Var::Function Ezito::Var::ToFunction(){
    return Ezito::Var::Function(this->val);
}

Ezito::Var::Object Ezito::Var::ToObject(){
    return Ezito::Var::Object(this->val);
}
 

Ezito::Var::Boolean Ezito::Var::ToBoolean(){
    return Ezito::Var::Boolean(this->val);
}

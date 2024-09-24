


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

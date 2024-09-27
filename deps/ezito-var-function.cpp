

#include "ezito.h"




Ezito::Var::Function::Function(){

}

Ezito::Var::Function::Function(const Ezito::Var::Function * value) { 
    this->val = value->val;
}

Ezito::Var::Function::Function(const Ezito::Var::Function & value) { 
    this->val = value.val;
}

Ezito::Var::Function::Function(Value value){
    if(!value.IsEmpty() && value.IsFunction()){
        this->val = value.Context();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::Function::Function(Ezito::Var value){ 
    if(!value.IsEmpty() && value.IsFunction()){
        this->val = value.Context();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Function::Function(v8::Local<v8::Value> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsFunction()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Function::Function(v8::Local<v8::Function> value){
    if(!value.IsEmpty()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Function::Function(v8::MaybeLocal<v8::Value> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsFunction()){
        this->val = val.Context();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Function::Function(v8::MaybeLocal<v8::Function> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsFunction()){
        this->val = val.Context();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var Ezito::Var::Function::prototypeCall(const char * name, int count , ...){
    Ezito::Global global("Function");
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




Ezito::Var::Function::Function(Ezito::FunctionCallback callback, const char * name){
    this->val = Ezito::Var::CreateValue(callback , name);
}

Ezito::Var::Function::Function(Ezito::FunctionCallback callback, const char * name , v8::Local<v8::Value> data ){
    this->val = Ezito::Var::CreateValue(callback , name , data);
}


Ezito::Var::Function::Function(Ezito::FunctionCallbackWithReturnV8Value callback, const char * name){
    this->val = Ezito::Var::CreateValue(callback , name);
}

Ezito::Var::Function::Function(Ezito::FunctionCallbackWithReturnV8Value2 callback, const char * name, v8::Local<v8::Value> data ){
    this->val = Ezito::Var::CreateValue(callback , name , data);
}

Ezito::Var::Function::Function(Ezito::FunctionCallbackWithReturnV8Value3 callback, const char * name, void * data){
    this->val = Ezito::Var::CreateValue(callback , name , data);
}


Ezito::Var::Function::Function(Ezito::FunctionCallbackWithReturnValue callback, const char * name){
    this->val = Ezito::Var::CreateValue(callback , name );
}

Ezito::Var::Function::Function(Ezito::FunctionCallbackWithReturnValue2 callback, const char * name, v8::Local<v8::Value> data ){
    this->val = Ezito::Var::CreateValue(callback , name , data);
}
  
Ezito::Var::Function::Function(Ezito::FunctionCallbackWithReturnValue3 callback, const char * name , void * data){
    this->val = Ezito::Var::CreateValue(callback , name , data);
}
  


v8::Local<v8::Value> Ezito::Var::Function::Context(){
    return this->val;
}

v8::Local<v8::Function> Ezito::Var::Function::v8(){
    return this->val.AsFunction();
}

Ezito::Var Ezito::Var::Function::Var(){
    return this->val;
}

bool Ezito::Var::Function::IsEmpty(){ 
    return this->val.IsEmpty() || !this->val.IsFunction();
}


Ezito::Var Ezito::Var::Function::Call( ){
    return this->Call(0);
}

Ezito::Var Ezito::Var::Function::Call(v8::Local<v8::Value> context){
    return this->Call(context , 0);
}

Ezito::Var Ezito::Var::Function::Call(int count , ...){
 
    v8::Local<v8::Value> * argv = new v8::Local<v8::Value>[count]();
    va_list args; 
    va_start(args, count);
    for (int i = 0; i < count; i++){
        argv[i] = static_cast<v8::Local<v8::Value>>(va_arg(args, Value));
    }
    va_end(args);
        
    Ezito::Var result = this->val.AsFunction()->Call(
        Ezito::Node::Context(),
        this->val.Context(),
        count,
        count > 0 ? argv : NULL
    );
    delete[] argv;
    return result;
}

Ezito::Var Ezito::Var::Function::Call(v8::Local<v8::Value> context, int count , ...){
    v8::Local<v8::Value> * argv = new v8::Local<v8::Value>[count]();
    va_list args; 
    va_start(args, count);
    for (int i = 0; i < count; i++){
        argv[i] = static_cast<v8::Local<v8::Value>>(va_arg(args, Value));
    }
    va_end(args);
        
    Ezito::Var result = this->val.AsFunction()->Call(
        Ezito::Node::Context() ,
        context,
        count,
        count > 0 ? argv : NULL
    );
    delete[] argv;
    return result;
}


 
Ezito::Var Ezito::Var::Function::CallNew( ){
    return this->Call(0);
}
 

Ezito::Var Ezito::Var::Function::CallNew(int count , ...){
 
    v8::Local<v8::Value> * argv = new v8::Local<v8::Value>[count]();
    va_list args; 
    va_start(args, count);
    for (int i = 0; i < count; i++){
        argv[i] = static_cast<v8::Local<v8::Value>>(va_arg(args, Value));
    }
    va_end(args);
        
    Ezito::Var result = this->val.AsFunction()->CallAsConstructor(
        Ezito::Node::Context(), 
        count,
        count > 0 ? argv : NULL
    );
    delete[] argv;
    return result;
}
 













Ezito::Var::Function::operator Ezito::Var(){
    return Ezito::Var(this->val);
}

Ezito::Var::Function::operator Ezito::Var() const{
    return Ezito::Var(this->val);
}

Ezito::Var::Function::operator Value(){ 
    return this->val;
};

Ezito::Var::Function::operator Value() const {
    return this->val;
};

Ezito::Var::Function::operator v8::Local<v8::Value>(){
    return this->val;
}

Ezito::Var::Function::operator v8::Local<v8::Value>() const{
    return this->val;
}

Ezito::Var::Function::operator v8::Local<v8::Function>(){
    return this->val;
}
Ezito::Var::Function::operator v8::Local<v8::Function>() const{
    return this->val;
}


Ezito::Var::Function Ezito::Var::Function::operator=(const Ezito::Var::Function& value){
    this->val=value.val;
    return *this;
}

Ezito::Var::Function Ezito::Var::Function::operator=(const Ezito::Var::Function* value){
    this->val=value->val;
    return *this;
}



v8::Local<v8::Function> Ezito::Var::Function::operator->(){
    return this->val.AsFunction();
}







Ezito::Var::Function::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Function");
}

Ezito::Var::Function::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("Function");
}













Ezito::Var::Function::~Function(){

}
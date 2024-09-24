

#include "ezito.h"




Ezito::Var::Object::Object(){
    this->val.ResetAsObject();
}


Ezito::Var::Object::Object(const Ezito::Var::Object * value) { 
    this->val = value->val;
}

Ezito::Var::Object::Object(const Ezito::Var::Object & value) { 
    this->val = value.val;
}

Ezito::Var::Object::Object(Ezito::Var value){
    if(!value.IsEmpty() && value.IsObject()){
        this->val = value;
        return;
    };
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Object::Object(v8::Local<v8::Value> value){ 
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsObject()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::Object::Object(v8::Local<v8::Object> value){ 
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsObject()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::Object::Object(v8::MaybeLocal<v8::Value> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsObject()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

v8::Local<v8::Value> Ezito::Var::Object::Context() {
    return this->val;
}

bool Ezito::Var::Object::IsEmpty() {
    return this->val.IsObject() || !this->val.IsObject(); 
}


void Ezito::Var::Object::Set(int index, Ezito::Var::int16_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(int index, Ezito::Var::un_int16_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}


void Ezito::Var::Object::Set(int index, Ezito::Var::int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}


void Ezito::Var::Object::Set(int index, Ezito::Var::un_int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}


void Ezito::Var::Object::Set(int index, Ezito::Var::l_int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}


void Ezito::Var::Object::Set(int index, Ezito::Var::un_l_int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}


void Ezito::Var::Object::Set(int index, Ezito::Var::int64_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(int index, Ezito::Var::un_int64_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(int index, double value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(int index, float value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}



void Ezito::Var::Object::Set(int index, const char*value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(int index, bool value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

   this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(int index, Ezito::Var value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

   this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        value.Context()
    );  
}

void Ezito::Var::Object::Set(int index, v8::Local<v8::Value> value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        value
    );
}

void Ezito::Var::Object::Set(int index, v8::MaybeLocal<v8::Value> value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }
    
    Var val(value);
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index,
        val.Context()
    );  
}



void Ezito::Var::Object::Set(int index , void * value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }
    
    Var val(value);
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index ,
        val.Context()
    );  
}


void Ezito::Var::Object::Set(const char* name, Ezito::Var::int16_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::un_int16_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::un_int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::l_int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::un_l_int32_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}


void Ezito::Var::Object::Set(const char* name, Ezito::Var::int64_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::un_int64_t value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var(value)
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        value
    );
}

void Ezito::Var::Object::Set(const char* name, Ezito::Var::Object value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        value
    );
}
void Ezito::Var::Object::Set(const char* name, v8::Local<v8::Value> value){
    if(!this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        value
    );
}

void Ezito::Var::Object::Set(const char* name, v8::MaybeLocal<v8::Value> value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }
    
    Var val(value);
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        val.Context()
    );  
}



void Ezito::Var::Object::Set(const char* name, void * value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }
    
    Var val(value);
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        val.Context()
    );  
}







Ezito::Var::Object::operator Ezito::Var(){
    return Ezito::Var(this->val);
}

Ezito::Var::Object::operator Ezito::Var() const{
    return Ezito::Var(this->val);
}

Ezito::Var::Object::operator Value(){ 
    return this->val;
};

Ezito::Var::Object::operator Value() const {
    return this->val;
};

Ezito::Var::Object::operator v8::Local<v8::Value>(){
    return this->val;
}

Ezito::Var::Object::operator v8::Local<v8::Value>() const{
    return this->val;
}

Ezito::Var::Object::operator v8::Local<v8::Object>(){
    return this->val;
}
Ezito::Var::Object::operator v8::Local<v8::Object>() const{
    return this->val;
}







Ezito::Var::Object::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Object");
}

Ezito::Var::Object::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("Object");
}




Ezito::Var Ezito::Var::Object::operator[](const char * key) { 
    return Ezito::Var(
        this->val.AsObject()->Get(
            Ezito::Node::Context(),
            Ezito::Var(key).Context()
        )
    );
}


Ezito::Var::Object Ezito::Var::Object::operator=(const Ezito::Var::Object& value){
    this->val = value.val; 
    return *this;
}
Ezito::Var::Object Ezito::Var::Object::operator=(const Ezito::Var::Object* value){
    this->val = value->val; 
    return *this;
}





Ezito::Var::Object::~Object(){}


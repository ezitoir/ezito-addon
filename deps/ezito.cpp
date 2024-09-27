


#include "ezito.h"





Ezito::Node::Isolate::Isolate():val(v8::Isolate::GetCurrent()){};
Ezito::Node::Isolate::~Isolate(){};
Ezito::Node::Isolate::operator v8::Isolate*(){return this->val;};
Ezito::Node::Isolate::operator v8::Isolate*()const{return this->val;};
v8::Isolate * Ezito::Node::Isolate::operator ->(){return this->val;}

Ezito::Node::Context::Context():val(v8::Isolate::GetCurrent()->GetCurrentContext()){};
Ezito::Node::Context::~Context(){};
Ezito::Node::Context::operator v8::Local<v8::Context>(){return this->val;};
Ezito::Node::Context::operator v8::Local<v8::Context>()const {return this->val;};
v8::Context * Ezito::Node::Context::operator ->(){return this->val.operator->();};


Ezito::TypeOf::TypeOf(){}
Ezito::TypeOf::TypeOf(const char * val):str(val){};
Ezito::TypeOf::~TypeOf(){};
Ezito::TypeOf::operator char*(){ return (char *)this->str.data();}
Ezito::TypeOf::operator char*()const {return (char *)this->str.data();};

























Ezito::Node::Throw::Throw( const char * error){
    Ezito::Node::Isolate isolate; 
    #if NODE_MAJOR_VERSION >= 16
    isolate->ThrowError(Ezito::Var(error));
    #else
    isolate->ThrowException(Ezito::Var(error));
    #endif
    
}
Ezito::Node::Throw::~Throw(){}

Ezito::Node::Throw::Exception::Exception(const char * error){
    Ezito::Node::Isolate isolate;
    isolate->ThrowException(Ezito::Var(error));
} 

Ezito::Node::Throw::Exception::~Exception(){}

Ezito::Node::Throw::Exception::TypeError::TypeError(const char * error){
    Ezito::Node::Isolate isolate; 
    isolate->ThrowException(
        v8::Exception::TypeError(
            Value(error)
        )
    );
} 
Ezito::Node::Throw::Exception::TypeError::~TypeError(){} 






Ezito::Node::Throw::Exception::RangeError::RangeError(const char * error){
    Ezito::Node::Isolate isolate;
    isolate->ThrowException(
        v8::Exception::RangeError(
            Value(error)
        )
    );
} 

Ezito::Node::Throw::Exception::RangeError::~RangeError(){} 


Ezito::Node::Throw::Exception::Error::Error(const char * error){
    Ezito::Node::Isolate isolate;
    isolate->ThrowException(
        v8::Exception::Error(
            Value(error)
        )
    );
} 

Ezito::Node::Throw::Exception::Error::~Error(){} 




Ezito::Node::Throw::Exception::ReferenceError::ReferenceError(const char * error){
    Ezito::Node::Isolate isolate;
    isolate->ThrowException(
        v8::Exception::ReferenceError(
            Value(error)
        )
    );
} 

Ezito::Node::Throw::Exception::ReferenceError::~ReferenceError(){} 





Ezito::Node::Throw::Exception::SyntaxError::SyntaxError(const char * error){
    Ezito::Node::Isolate isolate;
    isolate->ThrowException(
        v8::Exception::SyntaxError(
            Value(error)
        )
    );
} 

Ezito::Node::Throw::Exception::SyntaxError::~SyntaxError(){} 




void Ezito::Node::Throw::Exception::Argumants(const char * name , Ezito::TypeOf type){
    char * str = (char *)std::malloc(sizeof(char*) * 150);
    sprintf(str, "Argumant %s must be %s", name , static_cast<char *>(type));
    Ezito::Node::Throw::Exception::TypeError(static_cast<const char *>(str));
    std::free(str);
};

void Ezito::Node::Throw::Exception::Constructor(const char * name){
    char * str = (char *)std::malloc(sizeof(char*) * 200);
    sprintf(str, "Class constructor %s cannot be invoked without 'new'", name);
    Ezito::Node::Throw::Exception::TypeError(static_cast<const char *>(str));
    std::free(str);
};



















Ezito::Global::Global(){
    Ezito::Node::Isolate isolate;
    Ezito::Node::Context context;

    this->val = context->Global();

}

Ezito::Global::Global(const char * name){
    Ezito::Node::Isolate isolate;
    Ezito::Node::Context context;

    this->val = context->Global();
    Ezito::Var::Object gl(this->val);
    this->val =  gl[name];
}

Ezito::Global::~Global(){}



Ezito::Var Ezito::Global::Get(const char * name){
    Ezito::Var::Object gl(this->val);
    return gl[name];
}



 




Ezito::Global::String::String(){
    Ezito::Node::Isolate isolate;
    Ezito::Node::Context context;
    Ezito::Var::Object global(context->Global());
    this->string = global["String"].AsFunction();
    this->stringPrototype = this->string.CallNew(1 , Ezito::Var(""));
}



Ezito::Global::String::String(const char * value) : String() {
    this->stringPrototype = this->string.CallNew( 1 , Ezito::Var(value));
}

Ezito::Global::String::String(Ezito::Var value){
    if(value.IsString()){
        this->stringPrototype = this->string.CallNew( 1 , value);
    }
}

Ezito::Global::String::String(v8::Local<v8::Value> value) : String(){
    Ezito::Var val(value);
    if(val.IsString()){
        this->stringPrototype = this->string.CallNew( 1 , val);
    }
}

Ezito::Global::String::String(v8::Local<v8::String>) : String(){
    this->stringPrototype = this->string.CallNew( 1 , val);
}



Ezito::Var::Function Ezito::Global::String::protptype(const char * proName){
    Ezito::Var::Function pro(this->stringPrototype[proName]);
    if(pro.IsEmpty()) Ezito::Node::Throw("String.prototype ");
    return pro;
}



Ezito::Global::String::operator v8::Local<v8::Value>(){
    return static_cast<v8::Local<v8::Value>>(this->stringPrototype);
}

Ezito::Global::String::operator v8::Local<v8::Value>() const{
    return static_cast<v8::Local<v8::Value>>(this->stringPrototype);
}


Ezito::Global::String Ezito::Global::String::operator=(const Ezito::Global::String& value){ 
    this->string = value.string;
    this->stringPrototype = value.stringPrototype;
    return *this;
}

Ezito::Global::String Ezito::Global::String::operator=(const Ezito::Global::String* value){
    this->string = value->string;
    this->stringPrototype = value->stringPrototype;
    return *this;
}




Ezito::Global::String::~String(){

}









Ezito::Global::Process::Process(){
    Ezito::Node::Isolate isolate;
    Ezito::Node::Context context;
    Ezito::Var::Object global(context->Global());
    this->process = global["process"].AsObject(); 
}
 

void Ezito::Global::Process::On(const char * eventName ,  Ezito::Global::Process::ProcessCallback callback,  void * data){
    Ezito::Global::Process::DataTransfer * dataTransfer = new Ezito::Global::Process::DataTransfer();
    dataTransfer->callback = callback;
    dataTransfer->userData = data; 
    Ezito::Var sharedData(dataTransfer);

    Ezito::Var::Function localCallback([](Ezito::Argumants args){
        Value external =  args.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        
        Ezito::Global::Process::DataTransfer * data = static_cast<Ezito::Global::Process::DataTransfer *>(
            external.AsExternal()->Value()
        );
        
        data->callback(args , data->userData ); 
        delete data;
    },NULL, sharedData);



    Ezito::Var::Function on(this->process["on"].AsFunction());
    if(on.IsEmpty()){
        on = this->process["addListener"].AsFunction();
        if(!on.IsEmpty()){
            on.Call(this->process.Context() , 2 , Ezito::Var(eventName) , localCallback);
        }
    }
    else {
        on.Call(this->process.Context(),2 , Ezito::Var(eventName) , localCallback);
    }
    
}

Ezito::Global::Process::~Process(){

}



























 
Ezito::Class::Class(){
    Ezito::Node::Isolate isolate;
    this->shared_data = NULL;
    this->external_data = v8::Local<v8::Value>();
    this->class_context = v8::FunctionTemplate::New(isolate, [](Ezito::Argumants a){});
    this->class_context -> InstanceTemplate()->SetInternalFieldCount(1);
    this->class_name = Ezito::Var("");
};

Ezito::Class::Class(v8::FunctionCallback callback ,  const char * class_name){
    Ezito::Node::Isolate isolate;
    this->shared_data = NULL;
    this->external_data = v8::Local<v8::Value>();
    this->class_context = v8::FunctionTemplate::New(isolate, callback);
    this->class_context->InstanceTemplate()->SetInternalFieldCount(1);
    this->class_context->SetClassName(Ezito::Var(class_name));
}

Ezito::Class::Class( v8::FunctionCallback callback ,  const char * class_name , v8::Local<v8::Value> data = v8::Local<v8::Value>()){
    Ezito::Node::Isolate isolate;
    this->shared_data = NULL;
    this->class_context = v8::FunctionTemplate::New(isolate, callback , data);
    this->class_context->InstanceTemplate()->SetInternalFieldCount(1);
    this->class_name =  Ezito::Var(class_name); 
    this->class_context->SetClassName(this->class_name);
    this->external_data = data;
}

Ezito::Class::Class(v8::FunctionCallback callback, const char * class_name , v8::Local<v8::FunctionTemplate> extends){
    Ezito::Node::Isolate isolate;
    this->shared_data = NULL;
    this->external_data = v8::Local<v8::Value>();
    v8::Local<v8::Value> data = v8::Local<v8::Value>();
    this->class_context = v8::FunctionTemplate::New(isolate, callback, data ,v8::Signature::New(isolate, extends));
    this->class_context->InstanceTemplate()->SetInternalFieldCount(1); 
    this->class_context->SetClassName( Ezito::Var(class_name));
}

Ezito::Class::Class(v8::FunctionCallback callback, const char * class_name , v8::Local<v8::Function> extends){
    Ezito::Node::Isolate isolate;
    this->shared_data = NULL;
    #if NODE_MAJOR_VERSION >= 10
    v8::Local<v8::Value> data = v8::Local<v8::Value>(); 
    this->class_context = v8::FunctionTemplate::New(
        isolate, 
        callback,
        data,
        v8::Signature::New(isolate, extends.As<v8::FunctionTemplate>())
    );

    this->class_context->InstanceTemplate()->SetInternalFieldCount(1);
    this->class_name = Ezito::Var(class_name);
    this->class_context->SetClassName(this->class_name);
    #endif
}

Ezito::Class::Class(
    v8::FunctionCallback callback ,
    const char * class_name ,
    v8::Local<v8::FunctionTemplate> extends ,
    v8::Local<v8::Value> data 
    ){ 
    Ezito::Node::Isolate isolate;
    this->shared_data = NULL;
    this->class_context = v8::FunctionTemplate::New(isolate, callback, data ,v8::Signature::New(isolate, extends));
    this->class_context->InstanceTemplate()->SetInternalFieldCount(1);
    this->class_name = Ezito::Var(class_name);
    this->class_context->SetClassName(this->class_name);
    
}

 

void Ezito::Class::SetMethod(v8::FunctionCallback callback , const char * func_name , v8::Local<v8::Value> data){
    Ezito::Node::Isolate isolate;
    Ezito::Var sharedData(data);
    if(sharedData.IsEmpty()){
        if(this->shared_data != NULL){
            sharedData = Ezito::Var(this->shared_data);
        }
    }

    this->class_context->PrototypeTemplate()->Set(
        Ezito::Var(func_name),
        v8::FunctionTemplate::New(
            isolate,
            callback,
            sharedData,
            v8::Signature::New(isolate, this->class_context)
        )
    );
} 

void Ezito::Class::SetField(
    v8::AccessorGetterCallback getter_callback ,
    v8::AccessorSetterCallback setter_callbak,
    const char * field_name ,
    v8::Local<v8::Value> data ){ 
    Ezito::Node::Isolate isolate;
    
    Ezito::Var sharedData(data);
    if(sharedData.IsEmpty()){
        if(this->shared_data != NULL){
            sharedData = Ezito::Var(this->shared_data);
        }
    }

    this->class_context->InstanceTemplate()->SetAccessor(
        Ezito::Var(field_name),
        getter_callback,
        setter_callbak,
        sharedData,
        v8::AccessControl::DEFAULT,
        v8::PropertyAttribute::None
    );
}

void Ezito::Class::SetProperty(const char * pro_name , v8::Local<v8::Value> value){
    this->class_context->GetFunction(Ezito::Node::Context()).ToLocalChecked()->Set(
        Ezito::Node::Context(),
        Ezito::Var(pro_name),
        value
    );
}

void Ezito::Class::SetProperty(v8::AccessorGetterCallback callback , const char * func_name , v8::Local<v8::Value> data){}

void Ezito::Class::SetConstructor(v8::FunctionCallback callback , v8::Local<v8::Value> data){
    if(data.IsEmpty() && this->shared_data == NULL) return this->class_context->SetCallHandler(callback);
    
    Ezito::Var sharedData(data);
    if(sharedData.IsEmpty()){
        if(this->shared_data != NULL){
            sharedData = Ezito::Var(this->shared_data);
        }
    }

    this->class_context.Clear();
    this->class_context = v8::FunctionTemplate::New(Ezito::Node::Isolate(), callback, sharedData);
    this->class_context->InstanceTemplate()->SetInternalFieldCount(1);
    this->class_context->SetClassName(this->class_name);
}

void Ezito::Class::SetName(const char * class_name){
    this->class_name.Clear();
    this->class_name = Ezito::Var(class_name);
    this->class_context->SetClassName(this->class_name);
}


void Ezito::Class::SetSharedData(void * data){
    this ->shared_data = data;
}


v8::Local<v8::Value> Ezito::Class::Cast(){
    v8::MaybeLocal<v8::Function> fn = this -> class_context -> GetFunction(
        Ezito::Node::Context()
    );
    if(fn.IsEmpty()){
        return v8::Local<v8::Function>();
    }
    return fn.ToLocalChecked();
}

v8::Local<v8::Value> Ezito::Class::Context(){
    v8::MaybeLocal<v8::Function> fn = this -> class_context -> GetFunction(
        Ezito::Node::Context()
    );
    if(fn.IsEmpty()){
        return v8::Local<v8::Function>();
    }
    return fn.ToLocalChecked();
}


v8::Local<v8::String> Ezito::Class::GetClassName(){
    return this->class_name;
}

 


Ezito::Class::operator v8::Local<v8::Function>(){
    v8::MaybeLocal<v8::Function> fn = this -> class_context -> GetFunction(
        Ezito::Node::Context()
    );
    if(fn.IsEmpty()){
        return v8::Local<v8::Function>();
    }
    return fn.ToLocalChecked();
}

Ezito::Class::operator v8::Local<v8::Function>() const{
    v8::MaybeLocal<v8::Function> fn = this -> class_context -> GetFunction(
        Ezito::Node::Context()
    );
    if(fn.IsEmpty()){
        return v8::Local<v8::Function>();
    }
    return fn.ToLocalChecked();
}

 
Ezito::Class::operator v8::Local<v8::FunctionTemplate>(){
    return this->class_context;
}

Ezito::Class::operator v8::Local<v8::FunctionTemplate>() const{
    return this->class_context;
}
 

Ezito::Class::operator v8::Local<v8::Value>(){
    v8::MaybeLocal<v8::Function> fn = this -> class_context -> GetFunction(
        Ezito::Node::Context()
    );
    if(fn.IsEmpty()){
        return v8::Local<v8::Function>();
    }
    return fn.ToLocalChecked();
}

Ezito::Class::operator v8::Local<v8::Value>() const{
        v8::MaybeLocal<v8::Function> fn = this -> class_context -> GetFunction(
        Ezito::Node::Context()
    );
    if(fn.IsEmpty()){
        return v8::Local<v8::Function>();
    }
    return fn.ToLocalChecked();
}


Ezito::Class Ezito::Class::operator=(const Class& string){
    this -> class_context = string.class_context;
    return *this;
}

Ezito::Class Ezito::Class::operator=(const Class* string){
    this -> class_context = string->class_context;
    return *this;
}

v8::Local<v8::FunctionTemplate> Ezito::Class::operator->(){
    return this -> class_context;
    
};







void Ezito::Class::SetCleanHook(void(callback)(void *) , void * data){
    #if NODE_MAJOR_VERSION >= 10
    node::AddEnvironmentCleanupHook(
        Ezito::Node::Isolate(),
        callback,
        data
    );
    return;
    #endif
    
    Ezito::CleanHookDataTransfer * dataTransfer = new Ezito::CleanHookDataTransfer();
    dataTransfer->callback = callback;
    dataTransfer->userData = data;

    Ezito::Global::Process process;
    process.On("exit" , [](Ezito::Argumants args , void * d){
        Ezito::CleanHookDataTransfer  * a = static_cast<Ezito::CleanHookDataTransfer  *>(d);
        a->callback(a->userData);
        delete a;
    }, dataTransfer);
}



Ezito::Class::~Class(){}



 









 
void Ezito::CleanHook(void(callback)(void *) , void * data){
    #if NODE_MAJOR_VERSION >= 10
    node::AddEnvironmentCleanupHook(
        Ezito::Node::Isolate(),
        callback,
        data
    );
    return;
    #endif
    
    Ezito::CleanHookDataTransfer * dataTransfer = new Ezito::CleanHookDataTransfer();
    dataTransfer->callback = callback;
    dataTransfer->userData = data;

    Ezito::Global::Process process;
    process.On("exit" , [](Ezito::Argumants args , void * d){
        Ezito::CleanHookDataTransfer  * a = static_cast<Ezito::CleanHookDataTransfer  *>(d);
        a->callback(a->userData);
        delete a;
    }, data);

    process.On("error" , [](Ezito::Argumants args , void * d){
        Ezito::CleanHookDataTransfer  * a = static_cast<Ezito::CleanHookDataTransfer  *>(d);
        delete a;
    }, data);
}



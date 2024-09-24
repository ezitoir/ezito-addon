






#include "ezito.h"




Value::Value(){
    this->val = Value::CreateValue();
}


Value::Value(short int value){
    this->val = Value::CreateValue(value); 
}


Value::Value(unsigned short int value){
    this->val = Value::CreateValue(value); 
}


Value::Value(int value){
    this->val = Value::CreateValue(value); 
}

Value::Value(long int value){
    this->val = Value::CreateValue( value); 
}

Value::Value(unsigned int value) {
    this->val = Value::CreateValue( value); 
}


Value::Value(unsigned long int value) {
    this->val = Value::CreateValue( value); 
}


Value::Value(long long int value){
    this->val = Value::CreateValue(value);
}

Value::Value(unsigned long long int value){
    this->val = Value::CreateValue(value);
}


Value::Value(double value){
    this->val = Value::CreateValue( value); 
}

Value::Value(float value){
    this->val = Value::CreateValue( value); 
}


Value::Value(bool value){
    this -> val = Value::CreateValue( value); 
}



Value::Value(char value){
    this->val = Value::CreateValue(value);
}

Value::Value(char * value){
    this -> val = Value::CreateValue( value); 
}

Value::Value(const char * value){
    this -> val = Value::CreateValue( value); 
}

Value::Value(std::string value){
    this -> val = Value::CreateValue(value); 
}



Value::Value(void * data){
    this->val = v8::External::New(v8::Isolate::GetCurrent() , data);
}




Value::Value(v8::Local<v8::Value> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value;
    }
}

Value::Value(v8::Local<v8::String> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::StringObject> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Boolean> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::BooleanObject> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Object> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Array> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

#if NODE_MAJOR_VERSION >= 10
Value::Value(v8::Local<v8::BigInt> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::BigIntObject> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}
#endif

Value::Value(v8::Local<v8::Number> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::NumberObject> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Function> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Int32> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Primitive> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::Integer> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue(0);
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}

Value::Value(v8::Local<v8::External> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.As<v8::Value>();
    } 
}



Value::Value(v8::MaybeLocal<v8::Value> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}


Value::Value(v8::MaybeLocal<v8::String> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::Boolean> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::Object> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::Array> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::Number> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

#if NODE_MAJOR_VERSION >= 10
Value::Value(v8::MaybeLocal<v8::BigInt> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    } 
}

Value::Value(v8::MaybeLocal<v8::BigIntObject> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    } 
}
#endif

Value::Value(v8::MaybeLocal<v8::Function> value) {
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::Int32> value) {
    if(value.IsEmpty()){
        this -> val = v8::Local<v8::Value>();
    }
    else {
        this -> val = value.ToLocalChecked();
    }   
}

Value::Value(v8::MaybeLocal<v8::Primitive> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::Integer> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}

Value::Value(v8::MaybeLocal<v8::External> value){
    if(value.IsEmpty()){
        this->val = Value::CreateValue();
    }
    else {
        this->val = value.ToLocalChecked();
    }
}




Value::Value(v8::FunctionCallback callback ){
    this -> val = Value::CreateValue(callback , 0);
}


Value::Value(v8::FunctionCallback callback , const char * name ){
    this -> val = Value::CreateValue(callback , name);
}

Value::Value(v8::FunctionCallback callback , const char * name , v8::Local<v8::Value> data = v8::Local<v8::Value> ()){
    this -> val = Value::CreateValue(callback , name , data);
}




Value::Value(Value::FunctionCallbackWithReturnV8Value callback ){
    this -> val = Value::CreateValue(callback , 0);
}

Value::Value(Value::FunctionCallbackWithReturnV8Value callback , const char * name ){
    this -> val = Value::CreateValue(callback , name );
}

Value::Value(Value::FunctionCallbackWithReturnV8Value2 callback  , const char * name , v8::Local<v8::Value> data = v8::Local<v8::Value> ()){
    this -> val = Value::CreateValue(callback , name , data);
}

Value::Value(Value::FunctionCallbackWithReturnV8Value3 callback , const char * name , void * data){
    this -> val = Value::CreateValue(callback , name , data);
}



Value::Value(Value::FunctionCallbackWithReturnValue callback ){
    this -> val = Value::CreateValue(callback , 0);
}
Value::Value(Value::FunctionCallbackWithReturnValue callback , const char * name ){
    this -> val = Value::CreateValue(callback , name );
}

Value::Value(Value::FunctionCallbackWithReturnValue2 callback  , const char * name , v8::Local<v8::Value> data = v8::Local<v8::Value> ()){
    this -> val = Value::CreateValue(callback , name , data);
}

Value::Value(Value::FunctionCallbackWithReturnValue3 callback , const char * name , void * data){
    this -> val = Value::CreateValue(callback , name , data);
}


Value::Value(Value::FunctionCallbackWithReturnVar callback ){
    this -> val = Value::CreateValue(callback , 0);
}
Value::Value(Value::FunctionCallbackWithReturnVar callback , const char * name ){
    this -> val = Value::CreateValue(callback , name );
}

Value::Value(Value::FunctionCallbackWithReturnVar2 callback  , const char * name , v8::Local<v8::Value> data = v8::Local<v8::Value> ()){
    this -> val = Value::CreateValue(callback , name , data);
}

Value::Value(Value::FunctionCallbackWithReturnVar3 callback , const char * name , void * data){
    this -> val = Value::CreateValue(callback , name , data);
}



v8::Local<v8::Value> Value::Cast(){
    return this->val;
}
 

v8::Local<v8::Value> Value::Context(){
    return this->val;
}
 












 
v8::Local<v8::Value> Value::CreateValue(){
    return v8::Undefined(v8::Isolate::GetCurrent());
}

v8::Local<v8::Value> Value::CreateValue(char value){
    const char test[2] = {value , '\0'};
    v8::Isolate* isolate = v8::Isolate::GetCurrent(); 
    return v8::String::NewFromUtf8( isolate , test , v8::NewStringType::kInternalized).ToLocalChecked();
}

v8::Local<v8::Value> Value::CreateValue(const char* value){
    v8::Isolate* isolate = v8::Isolate::GetCurrent(); 
    return v8::String::NewFromUtf8( isolate ,value , v8::NewStringType::kInternalized).ToLocalChecked();
}

v8::Local<v8::Value> Value::CreateValue(std::string value){
    return Value::CreateValue(value.data()).As<v8::Value>();
}


    /**
     * short int(16 bits) -32768 to 32768
     * create v8::Local::Value::Int32 
     */
v8::Local<v8::Value> Value::CreateValue(Value::int16_t value){
    return v8::Int32::New(v8::Isolate::GetCurrent() , value).As<v8::Value>();
}

    /**
     * unsigned short int(16 bits) 0 to 65,535
     * create v8::Local::Value::Int32 
     */
v8::Local<v8::Value> Value::CreateValue(Value::un_int16_t value){
    return v8::Int32::New(v8::Isolate::GetCurrent() , value).As<v8::Value>();
}
    /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32 
     */
v8::Local<v8::Value> Value::CreateValue(Value::int32_t value){
    return v8::Int32::New(v8::Isolate::GetCurrent() , value).As<v8::Value>();
}
     /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32
     */ 
v8::Local<v8::Value> Value::CreateValue(Value::l_int32_t value){
    return v8::Int32::New(v8::Isolate::GetCurrent() , value).As<v8::Value>();
}

     /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32
     */ 
v8::Local<v8::Value> Value::CreateValue(Value::un_int32_t   value){
    return v8::Int32::New(v8::Isolate::GetCurrent() , value).As<v8::Value>();
} 

     /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32
     */ 
v8::Local<v8::Value> Value::CreateValue(Value::un_l_int32_t   value){
    return v8::Int32::New(v8::Isolate::GetCurrent() , value).As<v8::Value>();
} 

    /**
     * int(64 bits) -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
     * create v8::Local::Value::BigInt or if v8 not suported BigInt return v8::Local::Value::Number
     */  
v8::Local<v8::Value> Value::CreateValue(Value::int64_t value){ 
    #if NODE_MAJOR_VERSION >= 10
        return v8::BigInt::New( v8::Isolate::GetCurrent() , static_cast<long long >(value)).As<v8::Value>();
    #else
        return v8::Number::New( v8::Isolate::GetCurrent() , static_cast<double>(value)).As<v8::Value>();
    #endif
}
    /**
     * int(64 bits)  0 to 18,446,744,073,709,551,615
     * create v8::Local::Value::BigInt or if v8 not suported BigInt return v8::Local::Value::Number
     */   
v8::Local<v8::Value> Value::CreateValue(Value::un_int64_t value){
    #if NODE_MAJOR_VERSION >= 10
        return v8::BigInt::New( v8::Isolate::GetCurrent() , value).As<v8::Value>();
    #else
        return v8::Number::New( v8::Isolate::GetCurrent() , static_cast<double>(value)).As<v8::Value>();;
    #endif 
}

v8::Local<v8::Value> Value::CreateValue(double value){
    return v8::Number::New(v8::Isolate::GetCurrent() , static_cast<double>(value)).As<v8::Value>();
}

v8::Local<v8::Value> Value::CreateValue(float value){
    return v8::Number::New( v8::Isolate::GetCurrent() , static_cast<double>(value)).As<v8::Value>();
}

v8::Local<v8::Value> Value::CreateValue(bool value){
    return v8::Boolean::New( v8::Isolate::GetCurrent() , value).As<v8::Value>();;
}

v8::Local<v8::Value> Value::CreateValue(void * data){
    return v8::External::New( v8::Isolate::GetCurrent() , data);
}












v8::Local<v8::Value> Value::CreateValue( Value::FunctionCallback callback ,  const char * name ){
    v8::Local<v8::FunctionTemplate> functionTemplate = v8::FunctionTemplate::New(
        v8::Isolate::GetCurrent(),
        callback
    );
    
    v8::Local<v8::Function> function = functionTemplate -> GetFunction(
        v8::Isolate::GetCurrent() -> GetCurrentContext() 
    ).ToLocalChecked();
    
    if( name != 0 ) function -> SetName(Value::CreateValue(name).As<v8::String>());
    return function;
}

v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallback callback , 
    const char * name , 
    v8::Local<v8::Value> data){
    
    v8::Local<v8::FunctionTemplate> functionTemplate = v8::FunctionTemplate::New(
        v8::Isolate::GetCurrent(),
        callback,
        data
    );

    v8::Local<v8::Function> function = functionTemplate -> GetFunction(
        v8::Isolate::GetCurrent() -> GetCurrentContext() 
    ).ToLocalChecked();

    if(name != 0) function -> SetName(Value::CreateValue(name).As<v8::String>());
    return function;
}











/**
 * create fucntion with out user data voif or v8::Local::Value
 */
v8::Local<v8::Value> Value::CreateValue(Value::FunctionCallbackWithReturnV8Value callback,  const char * name ){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackV8Value = callback;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        v8::Local<v8::Value> result = dataTransfer->callbackV8Value(info);
        delete dataTransfer;
        info.GetReturnValue().Set(result);
    }, name , Value(dataTransfer));
 
}



/**
 * create fucntion with user data voif or v8::Local::Value
 */
v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnV8Value2 callback,
    const char * name ,
    v8::Local<v8::Value> data 
){ 
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackV8Value2 = callback;
    dataTransfer->userValueData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        v8::Local<v8::Value> result = dataTransfer->callbackV8Value2(info , dataTransfer->userValueData);
        delete dataTransfer;
        info.GetReturnValue().Set(result);
    }, name , Value(dataTransfer));
}



/**
 * create fucntion with user data voif or v8::Local::Value
 */
v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnV8Value3 callback,
    const char * name ,
    void * data
){ 
     Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackV8Value3 = callback;
    dataTransfer->userData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        v8::Local<v8::Value> result = dataTransfer->callbackV8Value3(info , dataTransfer->userData);
        delete dataTransfer;
        info.GetReturnValue().Set(result);
    }, name , Value(dataTransfer));
}













v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnValue callback, 
    const char * name 
){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackValue = callback;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Value result = dataTransfer->callbackValue(info);
        delete dataTransfer;
        info.GetReturnValue().Set(result.Context());

    }, name , Value(dataTransfer));
}



v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnValue2 callback, 
    const char * name ,
    v8::Local<v8::Value> data 
){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackValue2 = callback;
    dataTransfer->userValueData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Value result = dataTransfer->callbackValue2(info , dataTransfer->userValueData);
        delete dataTransfer;
        info.GetReturnValue().Set(result.Context());
    }, name , Value(dataTransfer));
}



v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnValue3 callback, 
    const char * name ,
    void * data
){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackValue3 = callback;
    dataTransfer->userData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Value result = dataTransfer->callbackValue3(info , dataTransfer->userData);
        delete dataTransfer;
        info.GetReturnValue().Set(result.Context());
    }, name , Value(dataTransfer));
}
















v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnVar callback, 
    const char * name 
){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackVar = callback;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Ezito::Var result =  dataTransfer->callbackVar(info);
        delete dataTransfer;
        info.GetReturnValue().Set(result.Context());
    }, name , Value(dataTransfer));
}



v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnVar2 callback, 
    const char * name ,
    v8::Local<v8::Value> data = v8::Local<v8::Value>()
){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackVar2 = callback;
    dataTransfer->userValueData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Ezito::Var result = dataTransfer->callbackVar2(info , dataTransfer->userValueData);
        delete dataTransfer;
        info.GetReturnValue().Set(result.Context());
    }, name , Value(dataTransfer));
}



v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnVar3 callback, 
    const char * name ,
    void * data
){
    Value::CallbackDataTransfer * dataTransfer = new Value::CallbackDataTransfer;
    dataTransfer->callbackVar3 = callback;
    dataTransfer->userData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Ezito::Var result = dataTransfer->callbackVar3(info , dataTransfer->userData);
        delete dataTransfer; 
        info.GetReturnValue().Set(result.Context());
    }, name , Value(dataTransfer));
}





 



v8::Local<v8::String> Value::CreateStringValue(const char * value){
    return static_cast<v8::Local<v8::String>>(Value(value));
}

v8::Local<v8::Boolean> Value::CreateBooleanValue(bool value){
    return static_cast<v8::Local<v8::Boolean>>(Value(value));
}

v8::Local<v8::Number> Value::CreateNumberValue(double value){
    return static_cast<v8::Local<v8::Number>>(Value(value));
}

v8::Local<v8::Int32> Value::CreateIntValue(long int value){
    return static_cast<v8::Local<v8::Int32>>(Value(value));
}



v8::Local<v8::String> Value::CreateEmptyStringValue(){
    return Value::CreateValue("").As<v8::String>();
}

v8::Local<v8::Object> Value::CreateEmptyObjectValue(){
    return v8::Object::New(v8::Isolate::GetCurrent()).As<v8::Object>();
}

v8::Local<v8::Array> Value::CreateEmptyArrayValue(){
    return v8::Array::New(v8::Isolate::GetCurrent() , 0).As<v8::Array>();
}




char * Value::GetCppValue(v8::Local<v8::String> value) {
    char * result = (char *)std::malloc(sizeof(char *));
    result = NULL;
    if(!value.IsEmpty() && value->IsString()){ 
        #if NODE_MAJOR_VERSION >= 8
        v8::String::Utf8Value v8String( v8::Isolate::GetCurrent(), value.As<v8::Value>());
        #else
        v8::String::Utf8Value v8String(value.As<v8::Value>());
        #endif
        std::free(result);
        result = (char *)std::malloc(sizeof(char *) * std::strlen(*v8String));
        std::strcpy(result , *v8String);
        return result; 
    }
    result = "";
    return result;
}

bool Value::GetCppValue(v8::Local<v8::Boolean> value) {
    Value val(value);
    if(val.IsEmpty() || !val.IsBoolean()) return false; 
    return value->Value();
}

double Value::GetCppValue(v8::Local<v8::Number> value) {
    Value val(value);
    if(val.IsEmpty() || !val.IsNumber()) return 0; 
    return static_cast<double>(value->Value());
}

long int Value::GetCppValue(v8::Local<v8::Int32> value) {
    Value val(value);
    if(val.IsEmpty() || !val.IsNumber()) return 0; 
    return static_cast<long int>(value->Value());
}

void * Value::GetCppValue(v8::Local<v8::External> value) {
    Value val(value);
    if(val.IsEmpty() || !val.IsExternal()) return NULL; 
    return static_cast<void *>(value->Value());
}











bool Value::IsEmpty(){
    return this->val.IsEmpty() || this->val->IsUndefined();
}

bool Value::IsUndefined(){
    return  this->val->IsUndefined();
}

bool Value::IsNull(){
    return this->val->IsNull(); 
}

bool Value::IsNumber(){
    #if NODE_MAJOR_VERSION >= 10
    return !this->IsEmpty() && (
        this->val->IsNumber() || this->val->IsNumberObject() || this->val->IsBigInt() || this->val->IsBigIntObject()
    );
    #endif
    return !this->IsEmpty() && (this->val->IsNumber() || this->val->IsNumberObject());
}

bool Value::IsBigInt(){
    #if NODE_MAJOR_VERSION >= 10
    return !this->IsEmpty() && (this->val->IsBigInt() || this->val->IsBigIntObject());
    #endif
    return false;
}

bool Value::IsInt(){
    return !this->IsEmpty() && this->val->IsInt32();
}

bool Value::IsBoolean(){
    return !this->IsEmpty() && (this->val->IsBoolean() || this->val->IsBooleanObject());
}

bool Value::IsObject(){
    return !this->IsEmpty() && this->val->IsObject();
}

bool Value::IsFunction(){
    return !this->IsEmpty() && this->val->IsFunction();
}

bool Value::IsString(){
    return !this->IsEmpty() && (this->val->IsString() || this->val->IsStringObject());
}

bool Value::IsArray(){
    return !this->IsEmpty() && this->val->IsArray();
}


bool Value::IsExternal(){
    return !this->IsEmpty() && this->val->IsExternal();
}









v8::Local<v8::Object> Value::AsObject(){
    return this->val.As<v8::Object>();
}

v8::Local<v8::Array> Value::AsArray(){
    return this->val.As<v8::Array>();
}

v8::Local<v8::String> Value::AsString() {
    return this->val.As<v8::String>();
}

v8::Local<v8::Number> Value::AsNumber() {
    #if NODE_MAJOR_VERSION >= 10
    if(this->IsBigInt()){
        v8::Local<v8::BigInt> bigint = this->AsBigInt();
        double result = static_cast< double >(bigint->Int64Value());
        return Value(result);
    } 
    #endif
    return this->val.As<v8::Number>();
}


#if NODE_MAJOR_VERSION >= 10
v8::Local<v8::BigInt> Value::AsBigInt() {
    return this->val.As<v8::BigInt>();
}
#else 
v8::Local<v8::Number> Value::AsBigInt() {
    return this->val.As<v8::Number>();
}
#endif

v8::Local<v8::Function> Value::AsFunction() {
    return this->val.As<v8::Function>();
}

v8::Local<v8::Boolean> Value::AsBoolean() {
    return this->val.As<v8::Boolean>();
}

v8::Local<v8::External> Value::AsExternal() {
    return this->val.As<v8::External>();
}

 
 void  Value::ResetAsObject(){
    if(!this->IsObject()){ 
        this->val.Clear();
        this->val = Value::CreateEmptyObjectValue().As<v8::Value>();
    } 
}

 void Value::ResetAsArray(){
    if(!this->IsArray()){ 
        this->val.Clear();
        this->val = Value::CreateEmptyArrayValue().As<v8::Value>();
    } 
}

void  Value::ResetAsString() {
    if(!this->val->IsString()){
        this->val.Clear();
        this->val = Value::CreateEmptyStringValue().As<v8::Value>();
    } 
} 

void Value::ResetAsUdefined() { 
    this->val.Clear();
    this->val = Value::CreateValue();
} 

Value::operator v8::Local<v8::Array>(){
    return this->val.As<v8::Array>();
}

Value::operator v8::Local<v8::Number>(){
    return this->val.As<v8::Number>();
}
 
Value::operator v8::Local<v8::Function>(){
    return this->val.As<v8::Function>();
}

Value::operator v8::Local<v8::Name>(){
    return this->val.As<v8::Name>();
}

Value::operator v8::Local<v8::Object>(){
    return this->val.As<v8::Object>();
}

Value::operator v8::Local<v8::Primitive>(){
    return v8::Null(v8::Isolate::GetCurrent());
}

Value::operator v8::Local<v8::String>(){
    return this->val.As<v8::String>();
}

Value::operator v8::Local<v8::Boolean>(){
    return this->val.As<v8::Boolean>();
}

Value::operator v8::Local<v8::Value>(){
    return this->val.As<v8::Value>();
}

Value::operator v8::Local<v8::Int32>(){
    return this->val.As<v8::Int32>();
}

Value::operator v8::Local<v8::Array>() const {
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Array>();
    #else
    this->val->ToObject(v8::Isolate::GetCurrent());
    #endif
    
}

Value::operator v8::Local<v8::Number>() const{
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Number>();
    #else
    return v8::Local<v8::Number>::Cast<v8::Value>(this->val);
    #endif
}

Value::operator v8::Local<v8::Function>() const {
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Function>();
    #else 
    return v8::Local<v8::Function>::Cast<v8::Value>(this->val);
    #endif 
}

Value::operator v8::Local<v8::Name>() const {
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Name>();
    #else
   return v8::Local<v8::Name>::Cast<v8::Value>(this->val);
    #endif 
}

Value::operator v8::Local<v8::Object>() const {
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Object>();
    #else 
    return v8::Local<v8::Object>::Cast<v8::Value>(this->val);
    #endif 
}

Value::operator v8::Local<v8::Primitive>() const {
    return v8::Null(v8::Isolate::GetCurrent());
}

Value::operator v8::Local<v8::String>() const {
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::String>();
    #else
    return v8::Local<v8::String>::Cast<v8::Value>(this->val);
    #endif 
}

Value::operator v8::Local<v8::Value>() const {
    #if NODE_MAJOR_VERSION >= 7 
    return this->val;
    #else
    return this->val;
    #endif 
}

Value::operator v8::Local<v8::Boolean>() const{
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Boolean>();
    #else
    return v8::Local<v8::Boolean>::Cast<v8::Value>(this->val);
    #endif 
}

Value::operator v8::Local<v8::Int32>() const{
    #if NODE_MAJOR_VERSION >= 7 
    return this->val.As<v8::Int32>();
    #else 
    return v8::Local<v8::Int32>::Cast<v8::Value>(this->val);
    #endif 
}




















Value Value::operator=(char value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(char * value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(const char * value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(int value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(long int value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(long long int value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(float value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(double value) {
    this->val= Value::CreateValue(value);
    return *this;
}

Value Value::operator=(bool value) {
    this->val= Value::CreateValue(value);
    return *this;
}


Value Value::operator=(const Value& value){
    this->val = value.val; 
    return *this;
}
Value Value::operator=(const Value* value){
    this->val = value->val; 
    return *this;
}

Value Value::operator [](const char* key){
    
    if(!this->IsEmpty() && this->IsObject()){ 
        return Value (
            this->AsObject()->Get(
                v8::Isolate::GetCurrent()->GetCurrentContext(),
                static_cast<v8::Local<v8::Value>>(
                    Value(
                        key
                    )
                )
            )
        );
    }

    return Value();
}

Value Value::operator[](int index){
 
    if(!this->IsEmpty() && this->IsArray()){
        int length = this->AsArray()->Length();
        if(index >= length ) return Value();
        return Value (
            this->AsArray()->Get(
                v8::Isolate::GetCurrent()->GetCurrentContext(),
                index
            )
        );
    }

    if(!this->IsEmpty() && this->IsString()){
        const char * str = Value::GetCppValue( this->AsString());
        if(index >= std::strlen(str)) return Value();
        return Value(str[index]);
    }

    return Value();
}


Value::~Value(){}


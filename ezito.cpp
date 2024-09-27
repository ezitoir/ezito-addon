






#include "deps/ezito.h"




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

Value::Value(v8::FunctionCallback callback , const char * name , v8::Local<v8::Value> data ){
    this -> val = Value::CreateValue(callback , name , data);
}

Value::Value(v8::FunctionCallback callback , const char * name , void * data  = NULL){
    this -> val = Value::CreateValue(callback , name , data);
}





Value::Value(Value::FunctionCallbackWithReturnV8Value callback ){
    this -> val = Value::CreateValue(callback , 0);
}

Value::Value(Value::FunctionCallbackWithReturnV8Value callback , const char * name ){
    this -> val = Value::CreateValue(callback , name );
}

Value::Value(Value::FunctionCallbackWithReturnV8Value2 callback  , const char * name , v8::Local<v8::Value> data ){
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

Value::Value(Value::FunctionCallbackWithReturnValue2 callback  , const char * name , v8::Local<v8::Value> data){
    this -> val = Value::CreateValue(callback , name , data);
}

Value::Value(Value::FunctionCallbackWithReturnValue3 callback , const char * name , void * data){
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

v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallback callback , 
    const char * name , 
    void * data ){

    return Value::CreateValue( callback , name , Value::CreateValue(data));
}










/**
 * create fucntion with out user data voif or v8::Local::Value
 */
v8::Local<v8::Value> Value::CreateValue(Value::FunctionCallbackWithReturnV8Value callback,  const char * name ){
    Value::CallbackDataTransfer * dataTransfer = (Value::CallbackDataTransfer *)std::malloc(sizeof(Value::CallbackDataTransfer));
    dataTransfer->callbackV8Value = callback;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        v8::Local<v8::Value> result = dataTransfer->callbackV8Value(info);
        //std::free(dataTransfer);
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
    Value::CallbackDataTransfer * dataTransfer = (Value::CallbackDataTransfer *)std::malloc(sizeof(Value::CallbackDataTransfer));
    dataTransfer->callbackV8Value2 = callback;
    dataTransfer->userValueData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        v8::Local<v8::Value> result = dataTransfer->callbackV8Value2(info , dataTransfer->userValueData);
        //std::free(dataTransfer);
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
    Value::CallbackDataTransfer * dataTransfer = (Value::CallbackDataTransfer *)std::malloc(sizeof(Value::CallbackDataTransfer));
    dataTransfer->callbackV8Value3 = callback;
    dataTransfer->userData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        v8::Local<v8::Value> result = dataTransfer->callbackV8Value3(info , dataTransfer->userData);
        //std::free(dataTransfer);
        info.GetReturnValue().Set(result);
    }, name , Value(dataTransfer));
}













v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnValue callback, 
    const char * name 
){
    Value::CallbackDataTransfer * dataTransfer = (Value::CallbackDataTransfer *)std::malloc(sizeof(Value::CallbackDataTransfer));
    dataTransfer->callbackValue = callback;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Value result = dataTransfer->callbackValue(info);
        //std::free(dataTransfer);
        info.GetReturnValue().Set(result.Context());

    }, name , Value(dataTransfer));
}



v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnValue2 callback, 
    const char * name ,
    v8::Local<v8::Value> data 
){
    Value::CallbackDataTransfer * dataTransfer = (Value::CallbackDataTransfer *)std::malloc(sizeof(Value::CallbackDataTransfer));
    dataTransfer->callbackValue2 = callback;
    dataTransfer->userValueData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Value result = dataTransfer->callbackValue2(info , dataTransfer->userValueData);
        //std::free(dataTransfer);
        info.GetReturnValue().Set(result.Context());
    }, name , Value(dataTransfer));
}



v8::Local<v8::Value> Value::CreateValue(
    Value::FunctionCallbackWithReturnValue3 callback, 
    const char * name ,
    void * data
){
    Value::CallbackDataTransfer * dataTransfer = (Value::CallbackDataTransfer *)std::malloc(sizeof(Value::CallbackDataTransfer));
    dataTransfer->callbackValue3 = callback;
    dataTransfer->userData = data;

    return Value([](Value::Argumants info){
        Value external =  info.Data().As<v8::External>();
        if(external.IsEmpty()) return;
        Value::CallbackDataTransfer * dataTransfer = static_cast<Value::CallbackDataTransfer *>(
            external.AsExternal()->Value()
        );
        Value result = dataTransfer->callbackValue3(info , dataTransfer->userData);
        //std::free(dataTransfer);
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

Value Value::operator[](Value::int32_t index){
 
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
        if(static_cast<Value::un_int32_t>(index) >= std::strlen(str)) return Value();
        return Value(str[index]);
    }

    return Value();
}


Value Value::operator[](Value::l_int32_t index){
 
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
        if(static_cast<Value::un_l_int32_t>(index) >= std::strlen(str)) return Value();
        return Value(str[index]);
    }

    return Value();
}


Value::~Value(){}





 




#include "deps/ezito.h"




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
 

#include "deps/ezito.h"


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


Ezito::Var::Boolean::Boolean(Value value){
    if(!value.IsEmpty() && value.IsBoolean()){
        this->val = value;
        return;
    };
    this->val = Ezito::Var::Undefined().Context();
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



#include "deps/ezito.h"




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

#include "deps/ezito.h"



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



#include "deps/ezito.h" 

Ezito::Var::Number::Number(){ 
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Number::Number(int value) {
    this->val = Ezito::Var(
        Ezito::Var::CreateNumberValue(
            static_cast<double>(
                value
            )
        )
   );
}

Ezito::Var::Number::Number(long int value) {
    this->val = Ezito::Var(
        Ezito::Var::CreateNumberValue(
            static_cast<double>(
                value
            )
        )
    );

}

Ezito::Var::Number::Number(long long int value) {
    this->val = Ezito::Var(
        Ezito::Var::CreateNumberValue(
            static_cast<double>(
                value
            )
        )
    );
}

Ezito::Var::Number::Number(double value) {
    this->val = Ezito::Var(
        Ezito::Var::CreateNumberValue(
            static_cast<double>(
                value
            )
        )
   );
}

Ezito::Var::Number::Number(float value) {
    this->val = Ezito::Var(
        Ezito::Var::CreateNumberValue(
            static_cast<double>(
                value
            )
        )
    );
}

Ezito::Var::Number::Number(const Ezito::Var::Number * value) { 
    this->val = value->val;
}

Ezito::Var::Number::Number(const Ezito::Var::Number & value) { 
    this->val = value.val;
}



Ezito::Var::Number::Number(Value value){
    if(!value.IsEmpty() && value.IsNumber()){
        this->val = value;
        return;
    };
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::Number::Number(Ezito::Var value) { 
    if(!value.IsEmpty() && value.IsNumber()){
        this->val = value;
        return;
    };
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Number::Number(v8::Local<v8::Value> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsNumber()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Number::Number(v8::Local<v8::Int32> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsNumber()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Number::Number(v8::Local<v8::Number> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsNumber()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

#if NODE_MAJOR_VERSION >= 10
Ezito::Var::Number::Number(v8::Local<v8::BigInt> value){
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsNumber()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::Number::Number(v8::Local<v8::BigIntObject> value){ 
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsNumber()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}
#endif

Ezito::Var::Number::Number(v8::MaybeLocal<v8::Value> value) {
    Ezito::Var val(value); 
    if(!val.IsEmpty() && val.IsNumber()){
        this->val = value;
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


v8::Local<v8::Value> Ezito::Var::Number::Context(){
    return this->val;
}

Ezito::Var Ezito::Var::Number::Var(){
    return this->val;
}

v8::Local<v8::Number> Ezito::Var::Number::v8(){
    return this->val.AsNumber();
}


Ezito::Var Ezito::Var::Number::prototypeCall(const char * name, int count , ...){
    Ezito::Global global("Number");
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
 

bool Ezito::Var::Number::IsEmpty() {
    return this->val.IsEmpty() || !this->val.IsNumber(); 
}


bool Ezito::Var::Number::haveDecimal(){
    if(this->val.IsNumber()){
        if(this->val.Context()->IsInt32()){
            return false;
        }
        
        #if NODE_MAJOR_VERSION >= 10
        if(this->val.Context()->IsBigInt() || this->val.Context()->IsBigIntObject()){
            return false;
        }
        #endif
        
        return true;
    }

    return false;
}


const double Ezito::Var::Number::CppValue (){
    if(this->IsEmpty()) return 0;
    double result = Ezito::Var::GetCppValue(
        this->val.AsNumber()
    );
    return result;
} 





Ezito::Var::Number::operator Ezito::Var(){
    return Ezito::Var(this->val);
}

Ezito::Var::Number::operator Ezito::Var() const{
    return Ezito::Var(this->val);
}

Ezito::Var::Number::operator Value(){ 
    return this->val;
};

Ezito::Var::Number::operator Value() const {
    return this->val;
};

Ezito::Var::Number::operator v8::Local<v8::Value>(){
    return this->val;
}

Ezito::Var::Number::operator v8::Local<v8::Value>() const{
    return this->val;
}

Ezito::Var::Number::operator v8::Local<v8::Number>(){
    return this->val;
}
Ezito::Var::Number::operator v8::Local<v8::Number>() const{
    return this->val;
}






Ezito::Var::Number::operator int() {
    Ezito::Var::Number val(*this);
    if(val.IsEmpty()) val = 0;
    return static_cast<int>(
        Ezito::Var::GetCppValue(
            static_cast<v8::Local<v8::Number>>(val)
        )
    );
};

Ezito::Var::Number::operator int() const {
    Ezito::Var::Number val(*this);
    if(val.IsEmpty()) val = 0;
    return static_cast<int>(
        Ezito::Var::GetCppValue(
            static_cast<v8::Local<v8::Number>>(val)
        )
    );
}


Ezito::Var::Number::operator float() {
    Ezito::Var::Number val(*this);
    if(val.IsEmpty()) val = 0;
    return static_cast<float>(
        Ezito::Var::GetCppValue(
            static_cast<v8::Local<v8::Number>>(val)
        )
    );
};

Ezito::Var::Number::operator float() const {
    Ezito::Var::Number val(*this);
    if(val.IsEmpty()) val = 0;
    return static_cast<float>(
        Ezito::Var::GetCppValue(
            static_cast<v8::Local<v8::Number>>(val)
        )
    );
}


Ezito::Var::Number::operator double() {
    Ezito::Var::Number val(*this);
    if(val.IsEmpty()) val = 0;
    return static_cast<double>(
        Ezito::Var::GetCppValue(
            static_cast<v8::Local<v8::Number>>(val)
        )
    );
};

Ezito::Var::Number::operator double() const {
    Ezito::Var::Number val(*this);
    if(val.IsEmpty()) val = 0;
    return static_cast<double>(
        Ezito::Var::GetCppValue(
            static_cast<v8::Local<v8::Number>>(val)
        )
    );
}






Ezito::Var::Number::operator Ezito::TypeOf(){
    return Ezito::TypeOf("Number");
}

Ezito::Var::Number::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("Number");
}















Ezito::Var::Number Ezito::Var::Number::operator +(int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(long long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(long int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(long long int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}


Ezito::Var::Number Ezito::Var::Number::operator +=(int  value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +=(long int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +=(long long int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}


Ezito::Var::Number Ezito::Var::Number::operator +=(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +=(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(long int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(long long int value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(Number value) { 
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    if(value.IsEmpty()){
        value = 0;
    }

    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + Ezito::Var::GetCppValue(value.Context().As<v8::Number>()) );
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(Number value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    if(value.IsEmpty()){
        value = 0;
    }

    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - Ezito::Var::GetCppValue(value.Context().As<v8::Number>()) );
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +=(Number value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    if(value.IsEmpty()){
        value = 0;
    }

    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + Ezito::Var::GetCppValue(value.Context().As<v8::Number>()) );
    return *this;
}  

Ezito::Var::Number Ezito::Var::Number::operator -=(Number value) {
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    if(value.IsEmpty()){
        value = 0;
    }

    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - Ezito::Var::GetCppValue(value.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(const Ezito::Var::Number & value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +(const Ezito::Var::Number * value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(const Ezito::Var::Number & value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -(const Ezito::Var::Number * value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator +=(const Ezito::Var::Number & value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
} 

Ezito::Var::Number Ezito::Var::Number::operator +=(const Ezito::Var::Number * value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) + Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(const Ezito::Var::Number & value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator -=(const Ezito::Var::Number * value) {
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) - Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}































Ezito::Var::Number Ezito::Var::Number::operator/(int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator/(long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator/(long long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / static_cast<double>(value));
    return *this;
}
 
Ezito::Var::Number Ezito::Var::Number::operator/(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / static_cast<double>(value));
    return *this;
}
 
Ezito::Var::Number Ezito::Var::Number::operator/(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / static_cast<double>(value));
    return *this;
}
 
Ezito::Var::Number Ezito::Var::Number::operator/(Number value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    if(value.IsEmpty()){
        value = 0;
    }

    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / Ezito::Var::GetCppValue(value.Context().As<v8::Number>()) );
    return *this;
}
   
Ezito::Var::Number Ezito::Var::Number::operator/(const Ezito::Var::Number & value){
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator/(const Ezito::Var::Number * value){
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) / Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}
 


Ezito::Var::Number Ezito::Var::Number::operator*(int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator*(long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator*(long long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * static_cast<double>(value));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator*(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * static_cast<double>(value));
    return *this;
}
 
Ezito::Var::Number Ezito::Var::Number::operator*(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * static_cast<double>(value));
    return *this;
}
 
Ezito::Var::Number Ezito::Var::Number::operator*(Number value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    if(value.IsEmpty()){
        value = 0;
    }

    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * Ezito::Var::GetCppValue(value.Context().As<v8::Number>()) );
    return *this;
}
 
Ezito::Var::Number Ezito::Var::Number::operator*(const Ezito::Var::Number & value){
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator*(const Ezito::Var::Number * value){
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    this->val = Ezito::Var(Ezito::Var::GetCppValue(this->val.AsNumber()) * Ezito::Var::GetCppValue(val.Context().As<v8::Number>()));
    return *this;
}
 












bool Ezito::Var::Number::operator ==(int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return  Ezito::Var::GetCppValue(this->val.AsNumber()) == static_cast<double>(value); 
}

bool Ezito::Var::Number::operator ==(long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return  Ezito::Var::GetCppValue(this->val.AsNumber()) == static_cast<double>(value); 
}

bool Ezito::Var::Number::operator ==(long long int value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return  Ezito::Var::GetCppValue(this->val.AsNumber()) == static_cast<double>(value); 
}

bool Ezito::Var::Number::operator ==(double value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return  Ezito::Var::GetCppValue(this->val.AsNumber()) == static_cast<double>(value); 
}

bool Ezito::Var::Number::operator ==(float value){
    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return  Ezito::Var::GetCppValue(this->val.AsNumber()) == static_cast<double>(value); 
}

bool Ezito::Var::Number::operator ==(const Ezito::Var::Number & value){
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return Ezito::Var::GetCppValue(this->val.AsNumber()) == Ezito::Var::GetCppValue(val.Context().As<v8::Number>());
}

bool Ezito::Var::Number::operator ==(const Ezito::Var::Number * value){
    Ezito::Var::Number val(value);
    if(val.IsEmpty()){
        val = 0;
    }

    if(this->IsEmpty()){
        this->val = Ezito::Var::CreateNumberValue(0);
    }
    return Ezito::Var::GetCppValue(this->val.AsNumber()) == Ezito::Var::GetCppValue(val.Context().As<v8::Number>());
}






 






Ezito::Var::Number Ezito::Var::Number::operator=(const Ezito::Var::Number& value){
    this->val=value.val;
    return *this;
}

Ezito::Var::Number Ezito::Var::Number::operator=(const Ezito::Var::Number* value){
    this->val=value->val;
    return *this;
}


v8::Local<v8::Number> Ezito::Var::Number::operator->(){
    return this->val.AsNumber() ;
}


Ezito::Var::Number::~Number(){}






#include "deps/ezito.h"




Ezito::Var::Object::Object(){
    this->val.ResetAsObject();
}


Ezito::Var::Object::Object(const Ezito::Var::Object * value) { 
    this->val = value->val;
}

Ezito::Var::Object::Object(const Ezito::Var::Object & value) { 
    this->val = value.val;
}

Ezito::Var::Object::Object(Value value){
    if(!value.IsEmpty() && value.IsObject()){
        this->val = value;
        return;
    };
    this->val = Ezito::Var::Undefined().Context();
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
    
    Ezito::Var val(value);
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
    
    Ezito::Var val(value);
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        index ,
        val.Context()
    );  
}






Ezito::Var Ezito::Var::Object::prototypeCall(const char * name, int count , ...){
    Ezito::Global global("Object");
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

void Ezito::Var::Object::Set(const char* name, double value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var::CreateValue(value)
    );
}

void Ezito::Var::Object::Set(const char* name, float value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }

    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        Ezito::Var::CreateValue(value)
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
    
    Ezito::Var val(value);
    this->val.AsObject()->Set(
        Ezito::Node::Context(),
        Ezito::Var(name),
        val.Context()
    );  
}

void Ezito::Var::Object::Set(const char* name, const char* value){
    if(this->val.IsObject()){
        this->val.ResetAsObject();
    }
    
    Ezito::Var val(value);
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
    
    Ezito::Var val(value);
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

v8::Local<v8::Object> Ezito::Var::Object::v8(){ 
    return this->val.AsObject();
}

Ezito::Var Ezito::Var::Object::Var(){
    return this->val;
}

Ezito::Var::Object Ezito::Var::Object::operator=(const Ezito::Var::Object& value){
    this->val = value.val; 
    return *this;
}
Ezito::Var::Object Ezito::Var::Object::operator=(const Ezito::Var::Object* value){
    this->val = value->val; 
    return *this;
}


v8::Local<v8::Object> Ezito::Var::Object::operator->(){
    return this->val.AsObject() ;
}

 

Ezito::Var::Object::~Object(){}


 
#include "deps/ezito.h"


Ezito::Var::String::String() {
    this->val.ResetAsString();
    this->length = 0;
}

Ezito::Var::String::String(char value) : String(){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
    const char str[1] = { value };
    this->length = std::strlen(str);
}

Ezito::Var::String::String(char * value) : String(){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
    this->length = this->val.AsString()->Length();
}

Ezito::Var::String::String(const char * value) : String(){
    this->val.Context().Clear();
    this->val = Ezito::Var(value);
    this->length = std::strlen(value);
}

Ezito::Var::String::String(const Ezito::Var::String * value) : String(){ 
    this->val = value->val;
    this->length = value->length;
}

Ezito::Var::String::String(const Ezito::Var::String & value) : String(){ 
    this->val = value.val;
    this->length = value.length;
}

Ezito::Var::String::String(Value value){
    if(!value.IsEmpty() && value.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(Ezito::Var value) : String() {
    if(!value.IsEmpty() && value.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::String::String(v8::Local<v8::Value> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = value.As<v8::String>()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(v8::Local<v8::String> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}

Ezito::Var::String::String(v8::Local<v8::StringObject> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}


Ezito::Var::String::String(v8::MaybeLocal<v8::Value> value) : String() {
    Ezito::Var val(value);
    if(!val.IsEmpty() && val.IsString()){
        this->val = value;
        this->length = this->val.AsString()->Length();
        return;
    }
    this->val = Ezito::Var::Undefined().Context();
}



v8::Local<v8::Value> Ezito::Var::String::Context(){
    return this->val;
}



bool Ezito::Var::String::IsEmpty() {
    return this->val.IsEmpty() || !this->val.IsString(); 
}


const char * Ezito::Var::String::CppValue(){
    if(this->IsEmpty()){
        return NULL;
    }

    return Ezito::Var::GetCppValue(
        this->val.AsString()
    );
}
 


Ezito::Var::String::operator Ezito::Var(){ 
    return Ezito::Var(this->val);
};

Ezito::Var::String::operator Ezito::Var() const {
    return Ezito::Var(this->val);
};

Ezito::Var::String::operator Value(){ 
    return this->val;
};

Ezito::Var::String::operator Value() const {
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::Value>() { 
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::Value> () const {
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::String>() {
    return this->val;
};

Ezito::Var::String::operator v8::Local<v8::String> () const{
    return this->val;
};



Ezito::Var::String::operator char *(){ 
    return Ezito::Var::GetCppValue(this->val.AsString());
}

Ezito::Var::String::operator char * () const {
    Ezito::Var::String val(*this);
    const char * str = val.CppValue(); 
    char * result = reinterpret_cast<char *>(std::malloc(std::strlen(result) + 1));
    std::strcpy( result , str);
    return result ;
}

 

Ezito::Var::String::operator Ezito::TypeOf(){
    return Ezito::TypeOf("String");
}

Ezito::Var::String::operator Ezito::TypeOf() const {
    return Ezito::TypeOf("String");
}


v8::Local<v8::String> Ezito::Var::String::v8(){ 
    return this->val.AsString();
}


Ezito::Var Ezito::Var::String::Var(){
    return this->val;
}
 

Ezito::Var::String Ezito::Var::String::operator=(const Ezito::Var::String& value){
    this->val = value.val;
    this->length = value.length;
    return *this;
}

Ezito::Var::String Ezito::Var::String::operator=(const Ezito::Var::String* value){
    this->val = value->val;
    this->length = value->length;
    return *this;
}

Ezito::Var::String Ezito::Var::String::operator=(const char * value){
    this->val = Ezito::Var::CreateValue(value);
    this->length = this->val.AsString()->Length();
    return *this;
}

v8::Local<v8::String> Ezito::Var::String::operator->(){
    return this->val.AsString() ;
}

Ezito::Var Ezito::Var::String::prototypeCall(const char * name, int count , ...){
    Ezito::Global global("String");
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
 


Ezito::Var::String::~String(){}


#include "deps/ezito.h"



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



#include "deps/ezito.h"


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


Ezito::Var::operator Value(){
    return this->val;
}


Ezito::Var::operator Value() const{
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



#include "deps/ezito.h"





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


Ezito::TypeOf::TypeOf(){
    this->str = (char *)std::malloc(sizeof(char) * 1);
}

Ezito::TypeOf::TypeOf(const char * val) : TypeOf(){ 
    std::free(this->str);
    this->str = (char *)std::malloc((sizeof(char) * std::strlen(val)) + 1);
    std::strcpy(this->str , val); 
};

Ezito::TypeOf::~TypeOf(){
    std::free(this->str);
    this->str = 0;
};

Ezito::TypeOf::operator char*(){ return (char *)this->str;}
Ezito::TypeOf::operator char*()const {return (char *)this->str;};

























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
    const char * vtype = static_cast<char *>(type);
    char * str = (char *) std::malloc((sizeof(char) * ( 18 + std::strlen(name) + std::strlen(vtype))) + 1);
    sprintf(str, "Argumant %s must be %s", name , vtype);
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




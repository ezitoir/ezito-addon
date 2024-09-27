


 
#include <stdarg.h>
#include <string.h>  
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "node.h"

#ifndef V8_EZITO_VALUE_PARENT_HEADER
#define V8_EZITO_VALUE_PARENT_HEADER 
 


class Value;  


namespace Ezito {
    typedef struct CleanHookDataTransfer{ 
        void(*callback)(void *); 
        void * userData;
    } CleanHookDataTransfer; 
    
    typedef struct CallbackDataTransfer {
        void(*callback)(void *); 
        void * userVoidData;
        v8::Local<v8::Value> userValueData;

        v8::Local<v8::Value>(*callbackV8Value)(const v8::FunctionCallbackInfo<v8::Value>&);
        v8::Local<v8::Value>(*callbackV8Value2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
        v8::Local<v8::Value>(*callbackV8Value3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

        Value(*callbackValue)(const v8::FunctionCallbackInfo<v8::Value>&);
        Value(*callbackValue2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
        Value(*callbackValue3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

        Value(*callbackVar)(const v8::FunctionCallbackInfo<v8::Value>&);
        Value(*callbackVar2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
        Value(*callbackVar3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);
    } CallbackDataTransfer; 

    namespace Node {
        class Isolate;
        class Context;
    }; 
    class Class;
    class TypeOf;
    class Var;
    
    typedef const v8::FunctionCallbackInfo<v8::Value>& Argumants;
 
};

 




 
















class Value {
    protected:
    v8::Local<v8::Value> val; 
    private:
    public:
    typedef struct CallbackDataTransfer {
        void(*callback)(void *); 
        void * userData;
        v8::Local<v8::Value> userValueData;
        v8::Local<v8::Value>(*callbackV8Value)(const v8::FunctionCallbackInfo<v8::Value>&);
        v8::Local<v8::Value>(*callbackV8Value2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
        v8::Local<v8::Value>(*callbackV8Value3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

        Value(*callbackValue)(const v8::FunctionCallbackInfo<v8::Value>&);
        Value(*callbackValue2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
        Value(*callbackValue3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

        Ezito::Var(*callbackVar)(const v8::FunctionCallbackInfo<v8::Value>&);
        Ezito::Var(*callbackVar2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
        Ezito::Var(*callbackVar3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);
    } CallbackDataTransfer; 
    typedef const v8::FunctionCallbackInfo<v8::Value>& Argumants;
    typedef void(FunctionCallback)(const v8::FunctionCallbackInfo<v8::Value>&);

    typedef v8::Local<v8::Value>(FunctionCallbackWithReturnV8Value)(const v8::FunctionCallbackInfo<v8::Value>&);
    typedef v8::Local<v8::Value>(FunctionCallbackWithReturnV8Value2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
    typedef v8::Local<v8::Value>(FunctionCallbackWithReturnV8Value3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

    typedef Value(FunctionCallbackWithReturnValue)(const v8::FunctionCallbackInfo<v8::Value>&);
    typedef Value(FunctionCallbackWithReturnValue2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>);
    typedef Value(FunctionCallbackWithReturnValue3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

    typedef Ezito::Var(FunctionCallbackWithReturnVar)(const v8::FunctionCallbackInfo<v8::Value>&); 
    typedef Ezito::Var(FunctionCallbackWithReturnVar2)(const v8::FunctionCallbackInfo<v8::Value>& , v8::Local<v8::Value>); 
    typedef Ezito::Var(FunctionCallbackWithReturnVar3)(const v8::FunctionCallbackInfo<v8::Value>& , void *);

    typedef short int          int16_t;
    typedef unsigned short int un_int16_t;
    typedef int                int32_t;
    typedef long int           l_int32_t;
    typedef unsigned int       un_int32_t;
    typedef unsigned long int  un_l_int32_t; 
    typedef long long          int64_t;
    typedef unsigned long long un_int64_t;
    
    /**
     *  set val to undefined
     */
    Value(); 
    /**
     * short int(16 bits) -32768 to 32768
     * create v8::Local::Value::Int32 
     */
    Value(Value::int16_t);
    /**
     * unsigned short int(16 bits) 0 to 65,535
     * create v8::Local::Value::Int32 
     */
    Value(Value::un_int16_t);
    /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32 
     */
    Value(Value::int32_t);
    /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32 
     */
    Value(Value::l_int32_t);
    /**
     * int(32 bits) 0 to 4,294,967,295
     * create v8::Local::Value::Int32
     */  
    Value(Value::un_int32_t);
    /**
     * int(32 bits) 0 to 4,294,967,295
     * create v8::Local::Value::Int32
     */  
    Value(Value::un_l_int32_t);
    /**
     * int(64 bits) -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
     * create v8::Local::Value::BigInt or if v8 not suported BigInt return v8::Local::Value::Number
     */  
    Value(Value::int64_t);
    /**
     * int(64 bits)  0 to 18,446,744,073,709,551,615
     * create v8::Local::Value::BigInt or if v8 not suported BigInt return v8::Local::Value::Number
     */   
    Value(Value::un_int64_t);
    /**
     * create v8::Local::Value::Number
     */
    Value(float);
    /**
     * create v8::Local::Value::Number
     */
    Value(double);
    /**
     * create v8::Local::Value::Boolean
     */
    Value(bool);
    /**
     * create v8::Local::Value::String
     */
    Value(char );
    /**
     * create v8::Local::Value::String
     */
    Value(char *);
    /**
     * create v8::Local::Value::String
     */
    Value(const char *);
    /**
     * create v8::Local::Value::External
     */
    Value(void * data);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Value>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::String>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::StringObject>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Boolean>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::BooleanObject>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Object>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Array>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Function>);  
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Number>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::NumberObject>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Int32>);
    #if NODE_MAJOR_VERSION >= 10
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::BigInt>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::BigIntObject>);
    #endif
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Primitive>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::Integer>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::Local<v8::External>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Value>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::String>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Boolean>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Object>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Array>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Function>); 
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Number>); 
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Int32>);
    #if NODE_MAJOR_VERSION >= 10
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::BigInt>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::BigIntObject>);
    #endif
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Primitive>); 
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::Integer>);
    /**
     * @note if the value is empty, the value will remain undefined
     */
    Value(v8::MaybeLocal<v8::External>);
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(v8::FunctionCallback);
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(v8::FunctionCallback , const char *  );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(v8::FunctionCallback , const char *  , v8::Local<v8::Value> );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(v8::FunctionCallback , const char *  , void *);
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnV8Value );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnV8Value ,  const char * );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnV8Value2 ,  const char * , v8::Local<v8::Value> );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnV8Value3 ,  const char * , void *);
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnValue );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnValue ,  const char * );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnValue2 ,  const char * , v8::Local<v8::Value> );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnValue3 ,  const char * , void *);
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnVar );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnVar ,  const char * );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnVar2 ,  const char * , v8::Local<v8::Value> );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    Value(Value::FunctionCallbackWithReturnVar3 ,  const char * , void *); 
    ~Value();


    virtual bool IsEmpty();
    virtual bool IsUndefined();
    virtual bool IsString();
    virtual bool IsFunction(); 
    virtual bool IsArray();
    virtual bool IsObject();
    virtual bool IsNull();
    virtual bool IsBoolean();
    virtual bool IsNumber();
    virtual bool IsBigInt();
    virtual bool IsInt();
    virtual bool IsExternal();
    
    /**
     * convert val to v8::Local::Value::Object
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsObject();
     */
    virtual v8::Local<v8::Object> AsObject();
    /**
     * convert val to v8::Local::Value::Array
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     */
    virtual v8::Local<v8::Array> AsArray();
    /**
     * convert val to v8::Local::Value::String
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsString();
     */
    virtual v8::Local<v8::String> AsString();
    /**
     * convert val to v8::Local::Value::Number
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note if value is equal to BigInt, first the value is read and then an instance of v8::Local::Value::Number is created.
     * @note Value::IsNumber();
     */
    virtual v8::Local<v8::Number> AsNumber(); 
    #if NODE_MAJOR_VERSION >= 10
    /**
     * convert val to v8::Local::Value::Number
     * @note If v8 does not support BigInt, the value will be equal to v8::Local::Value::Number
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsBigInt();
     */
    virtual v8::Local<v8::BigInt> AsBigInt();
    #else
    /**
     * convert val to v8::Local::Value::Number
     * @note If v8 does not support BigInt, the value will be equal to v8::Local::Value::Number
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsBigInt();
     */
    virtual v8::Local<v8::Number> AsBigInt();
    #endif
    /**
     * convert val to v8::Local::Value::Function
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsFunction();
     */
    virtual v8::Local<v8::Function> AsFunction();
    /**
     * convert val to v8::Local::Value::Function
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsBoolean();
     */
    virtual v8::Local<v8::Boolean> AsBoolean();
    /**
     * convert val to v8::Local::Value::External
     * @note it is better to first check that it is not empty or equal to your goal to avoid runtime errors
     * @note Value::IsExternal();
     */
    virtual v8::Local<v8::External> AsExternal();

    /**
     * reset to empty object => {}
     * @note If the value has already been set and the conditions have been removed
     */
    virtual void ResetAsObject();
    /**
     * reset to empty arr => []
     * @note If the value has already been set and the conditions have been removed
     */
    virtual void ResetAsArray();
    /**
     * reset to empty str => ""
     * @note If the value has already been set and the conditions have been removed
     */
    virtual void ResetAsString(); 
    /**
     * reset to empty undef = > undefined
     * @note If the value has already been set and the conditions have been removed
     */
    virtual void ResetAsUdefined();  


    virtual v8::Local<v8::Value> Cast();
    virtual v8::Local<v8::Value> Context();
    

    /**
     * create v8::Local::Value::Undefined
     */
    static v8::Local<v8::Value> CreateValue();
    /**
     * create v8::Local::Value::String
     */
    static v8::Local<v8::Value> CreateValue(char);
    /**
     * create v8::Local::Value::String
     */
    static v8::Local<v8::Value> CreateValue(const char*);
    /**
     * short int(16 bits) -32768 to 32768
     * create v8::Local::Value::Int32 
     */
    static v8::Local<v8::Value> CreateValue(Value::int16_t);
    /**
     * unsigned short int(16 bits) 0 to 65,535
     * create v8::Local::Value::Int32 
     */
    static v8::Local<v8::Value> CreateValue(Value::un_int16_t); 
    /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32 
     */
    static v8::Local<v8::Value> CreateValue(Value::int32_t);
    /**
     * int(32 bits) -2,147,483,647 to 2,147,483,647
     * create v8::Local::Value::Int32
     */  
    static v8::Local<v8::Value> CreateValue(Value::l_int32_t);
    /**
     * int(32 bits) 0 to 4,294,967,295
     * create v8::Local::Value::Int32
     */  
    static v8::Local<v8::Value> CreateValue(Value::un_int32_t);  
    /**
     * int(32 bits) 0 to 4,294,967,295
     * create v8::Local::Value::Int32
     */  
    static v8::Local<v8::Value> CreateValue(Value::un_l_int32_t);
    /**
     * int(64 bits) -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
     * create v8::Local::Value::BigInt or if v8 not suported BigInt return v8::Local::Value::Number
     */  
    static v8::Local<v8::Value> CreateValue(Value::int64_t);
    /**
     * int(64 bits)  0 to 18,446,744,073,709,551,615
     * create v8::Local::Value::BigInt or if v8 not suported BigInt return v8::Local::Value::Number
     */   
    static v8::Local<v8::Value> CreateValue(Value::un_int64_t);
    /**
     * create v8::Local::Value::Number
     */
    static v8::Local<v8::Value> CreateValue(double);
    /**
     * create v8::Local::Value::Number
     */
    static v8::Local<v8::Value> CreateValue(float);
    /**
     * create v8::Local::Value::Boolean
     */
    static v8::Local<v8::Value> CreateValue(bool);
    /**
     * create v8::Local::Value::External
     */
    static v8::Local<v8::Value> CreateValue(void *);


    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallback ,
        const char *
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallback ,
        const char *,
        v8::Local<v8::Value> 
    );

    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallback ,
        const char *,
        void *
    );


    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class.
     * you can send retrun v8::Local::Value to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnV8Value ,
        const char *
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous 
     * you can send retrun v8::Local::Value to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnV8Value2 ,
        const char * ,
        v8::Local<v8::Value>
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * void * , create v8::Local::Value::Externak set to args.Data() to share data between functions or methods of class.
     * you can send retrun v8::Local::Value to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnV8Value3 ,
        const char * ,
        void *
    );
    

    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class.
     * you can send retrun Value to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnValue ,
        const char *
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class.
     * you can send retrun Value to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnValue2 ,
        const char * ,
        v8::Local<v8::Value> 
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class.
     * you can send retrun Value to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnValue3 ,
        const char * ,
        void *
    );
    

    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous 
     * you can send retrun Ezito::Var to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnVar ,
        const char *
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class.
     * you can send retrun Ezito::Var to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnVar2 ,
        const char * ,
        v8::Local<v8::Value> 
    );
    /**
     * create v8 fucntion 
     * if name set To NULL(0) function set to anonymous
     * v8::Lcoal::Value data , set to args.Data() to share data between functions or methods of class.
     * you can send retrun Ezito::Var to return;
     */
    static v8::Local<v8::Value> CreateValue(
        Value::FunctionCallbackWithReturnVar3 ,
        const char * ,
        void *
    );
    


    /**
     * create v8::Local::Value::String
     */
    static v8::Local<v8::String> CreateStringValue(const char *);
    /**
     * create v8::Local::Value::Boolean
     */
    static v8::Local<v8::Boolean> CreateBooleanValue(bool);
    /**
     * create v8::Local::Value::Number
     */
    static v8::Local<v8::Number> CreateNumberValue(double);
    /**
     * create v8::Local::Value::String
     */
    static v8::Local<v8::Int32> CreateIntValue(long int);


    /**
     * create empty v8::Local::Value::String
     * @example 
     * v8::Local<v8::String> str = Value::CreateEmptyStringValue(); 
     * str == "" => true
      */
    static v8::Local<v8::String> CreateEmptyStringValue();
    /**
     * create empty v8::Local::Value::Object
     * @example 
     * v8::Local<v8::Object> obj = Value::CreateEmptyObjectValue(); 
     * obj == {} => true
      */
    static v8::Local<v8::Object> CreateEmptyObjectValue();
    /**
     * create empty v8::Local::Value::Array
     * @example 
     * v8::Local<v8::Array> arr = Value::CreateEmptyArrayValue(); 
     * arr == [] => true
      */
    static v8::Local<v8::Array> CreateEmptyArrayValue();


    /**
     * get cpp value from v8::Local::Value::String
     * when the value is empty , empty str => return "";
     */
    static char * GetCppValue(v8::Local<v8::String>);
    /**
     * get cpp value from v8::Local::Value::Boolean
     * when the value is empty , empty bol => return false;
     */
    static bool GetCppValue(v8::Local<v8::Boolean>); 
    /**
     * get cpp value from v8::Local::Value::Number
     * when the value is empty , empty num => return 0;
     */
    static double GetCppValue(v8::Local<v8::Number>);
    /**
     * get cpp value from v8::Local::Value::Int32
     * when the value is empty , empty num => return 0;
     */
    static long int GetCppValue(v8::Local<v8::Int32>);
    /**
     * get cpp value from v8::Local::Value::External
     * when the value is empty , empty ext => return NULL;
     */
    static void * GetCppValue(v8::Local<v8::External>);
    


    operator v8::Local<v8::Value> () const;
    operator v8::Local<v8::Value>();
    operator v8::Local<v8::String> () const;
    operator v8::Local<v8::String>();
    operator v8::Local<v8::Object> () const;
    operator v8::Local<v8::Object>();
    operator v8::Local<v8::Boolean> () const;
    operator v8::Local<v8::Boolean>();
    operator v8::Local<v8::Number> () const;
    operator v8::Local<v8::Number>();
    operator v8::Local<v8::Int32> () const;
    operator v8::Local<v8::Int32> ();
    operator v8::Local<v8::Array> () const;
    operator v8::Local<v8::Array>();
    operator v8::Local<v8::Primitive> () const;
    operator v8::Local<v8::Primitive>();
    operator v8::Local<v8::Function> () const;
    operator v8::Local<v8::Function>();
    operator v8::Local<v8::Name> () const;
    operator v8::Local<v8::Name>();

    Value operator=(char);
    Value operator=(char *);
    Value operator=(const char *);

    Value operator=(int);
    Value operator=(long int);
    Value operator=(long long int);
    Value operator=(float);
    Value operator=(double);
    Value operator=(bool);

    Value operator=(const Value& value);
    Value operator=(const Value* value);

    Value operator [](const char*);
    Value operator [](Value::int32_t);
    Value operator [](Value::l_int32_t);
};

















































namespace Ezito {
    typedef  Value::FunctionCallback FunctionCallback; 
    typedef  Value::FunctionCallbackWithReturnV8Value FunctionCallbackWithReturnV8Value;
    typedef  Value::FunctionCallbackWithReturnV8Value2 FunctionCallbackWithReturnV8Value2;
    typedef  Value::FunctionCallbackWithReturnV8Value3 FunctionCallbackWithReturnV8Value3;
    typedef  Value::FunctionCallbackWithReturnValue FunctionCallbackWithReturnValue;
    typedef  Value::FunctionCallbackWithReturnValue2 FunctionCallbackWithReturnValue2;
    typedef  Value::FunctionCallbackWithReturnValue3 FunctionCallbackWithReturnValue3;
    typedef  Value::FunctionCallbackWithReturnVar FunctionCallbackWithReturnVar;
    typedef  Value::FunctionCallbackWithReturnVar2 FunctionCallbackWithReturnVar2;
    typedef  Value::FunctionCallbackWithReturnVar3 FunctionCallbackWithReturnVar3;

    class Var : public Value {
        public:
        class Object;
        class Array;
        class String;
        class Boolean;
        class Int;
        class BigInt;
        class Number;
        class Function;
        class Undefined;
        class Null;

        Var();
        Var(Value);
        Var(String);
        Var(Object);
        Var(Array);
        Var(Function);
        Var(Boolean); 
        Var(Number);
        Var(Undefined);
        Var(Null); 
        using Value::Value;
        operator Value();
        operator Value() const;


        Ezito::Var::String ToString();
        Ezito::Var::Number ToNumber();
        Ezito::Var::Function ToFunction();
        Ezito::Var::Object ToObject();  
        Ezito::Var::Boolean ToBoolean();









 
        class Object {
            protected:
            Value val;
            public:
            /**
             * set to undefined
             * when set var to constructor , value checked , if not empty change to object
             */
            Object();
            Object(const Object *);
            Object(const Object &);
            Object(Value);
            Object(Ezito::Var);
            Object(v8::Local<v8::Value>);
            Object(v8::Local<v8::Object>);
            Object(v8::MaybeLocal<v8::Value>);
            ~Object(); 
            bool IsEmpty();
            void CppValue() = delete;
            /**
             * return context of value
             */
            v8::Local<v8::Value> Context(); 
            /**
             * return this.Context() as v8::Local<v8::String>
             */
            v8::Local<v8::Object> v8();
            /**
             * return this.val
             */
            Ezito::Var Var(); 
            /**
             * call of prototype like String.prototype.slice.call(...);
             */
            Ezito::Var prototypeCall(const char * , int count , ...);


            void Set(int , const char*);

            void Set(int , Ezito::Var::int16_t);
            void Set(int , Ezito::Var::un_int16_t);
            void Set(int , Ezito::Var::int32_t);
            void Set(int , Ezito::Var::un_int32_t);
            void Set(int , Ezito::Var::l_int32_t);
            void Set(int , Ezito::Var::un_l_int32_t);  
            void Set(int , Ezito::Var::int64_t);  
            void Set(int , Ezito::Var::un_int64_t);  

            void Set(int , double);
            void Set(int , float);

            void Set(int , bool);

            void Set(int , Ezito::Var);
            void Set(int , Ezito::Var::Object);
            void Set(int , v8::Local<v8::Value>); 
            void Set(int , v8::MaybeLocal<v8::Value>);

            void Set(int , void *);

            void Set(const char* , const char*);

            void Set(const char* , Ezito::Var::int16_t);
            void Set(const char* , Ezito::Var::un_int16_t);
            void Set(const char* , Ezito::Var::int32_t);
            void Set(const char* , Ezito::Var::un_int32_t);
            void Set(const char* , Ezito::Var::l_int32_t);
            void Set(const char* , Ezito::Var::un_l_int32_t);  
            void Set(const char* , Ezito::Var::int64_t);  
            void Set(const char* , Ezito::Var::un_int64_t);  
            void Set(const char* , double);
            void Set(const char* , float); 

            void Set(const char* , bool);
        
            void Set(const char* , Ezito::Var);
            void Set(const char* , Ezito::Var::Object);
            void Set(const char* , v8::Local<v8::Value>); 
            void Set(const char* , v8::MaybeLocal<v8::Value>); 
         
            void Set(const char* , void *);

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Object>();
            operator v8::Local<v8::Object>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

            operator char*() = delete;
            operator char*() const = delete;
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete;
            operator bool() = delete;
            operator bool() const = delete;

            Ezito::Var::Object operator=(const Ezito::Var::Object& value);
            Ezito::Var::Object operator=(const Ezito::Var::Object* value);
            Ezito::Var operator[](const char *); 
            v8::Local<v8::Object> operator->();


        };














        class Array {
            protected:
            Value val;
            public:
            long int length;
            Array();
            Array(const Array *);
            Array(const Array &);
            Array(Value);
            Array(Ezito::Var);
            Array(v8::Local<v8::Value>);
            Array(v8::Local<v8::Array>);
            Array(v8::MaybeLocal<v8::Value>);
            ~Array(); 
            bool IsEmpty();
            void CppValue() = delete;

            /**
             * return context of value
             */
            v8::Local<v8::Value> Context(); 
            /**
             * return this.Context() as v8::Local<v8::String>
             */
            v8::Local<v8::Array> v8();
            /**
             * return this.val
             */
            Ezito::Var Var(); 
            /**
             * call of prototype like String.prototype.slice.call(...);
             */
            Ezito::Var prototypeCall(const char * , int count , ...);
        
            void Push(char*);
            void Push(const char*);
            void Push(int);
            void Push(double);
            void Push(float);
            void Push(long long int);
            void Push(bool);
            void Push(Ezito::Var);
            void Push(v8::Local<v8::Value>);
            void Push(v8::MaybeLocal<v8::Value>);

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Array>();
            operator v8::Local<v8::Array>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

            operator char*() = delete;
            operator char*() const = delete;
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete;
            operator bool() = delete;
            operator bool() const = delete;
            
            Ezito::Var::Array operator=(const Ezito::Var::Array& value);
            Ezito::Var::Array operator=(const Ezito::Var::Array* value); 
            Ezito::Var operator[](int); 
            v8::Local<v8::Array> operator->(); 
        };

        


        class String {
            protected:
            Value val;
            public:
            Ezito::Var::un_l_int32_t length;
            String();
            String(char);
            String(char *);
            String(const char *);
            String(const String *);
            String(const String &);
            String(Value);
            String(Ezito::Var);
            String(v8::Local<v8::Value>);
            String(v8::Local<v8::String>);
            String(v8::Local<v8::StringObject>);
            String(v8::MaybeLocal<v8::Value>);
            ~String();
            v8::Local<v8::Value> Context();
            bool IsEmpty();
            const char * CppValue();
            /**
             * return this.Context() as v8::Local<v8::String>
             */
            v8::Local<v8::String> v8();
            /**
             * return this.val
             */
            Ezito::Var Var(); 
            /**
             * call of prototype like String.prototype.slice.call(...);
             */
            Ezito::Var prototypeCall(const char * , int count , ...);

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::String>();
            operator v8::Local<v8::String>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

            operator char*();
            operator char*() const; 
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete;
            operator bool() = delete;
            operator bool() const = delete;
            

            Ezito::Var::String operator=(const Ezito::Var::String & value);
            Ezito::Var::String operator=(const Ezito::Var::String * value);
            Ezito::Var::String operator=(const char *);
            Ezito::Var operator[](int);
            v8::Local<v8::String> operator->(); 
        };



        
        class Number {
            protected:
            Value val;
            public :
            Number();
            Number(int);
            Number(long int);
            Number(long long int);
            Number(double);
            Number(float);
            Number(const Number *);
            Number(const Number &);
            Number(Value);
            Number(Ezito::Var);
            Number(v8::Local<v8::Value>);
            Number(v8::Local<v8::Int32>);
            Number(v8::Local<v8::Number>);
            #if NODE_MAJOR_VERSION >= 10
            Number(v8::Local<v8::BigInt>);
            Number(v8::Local<v8::BigIntObject>);
            #endif
            Number(v8::MaybeLocal<v8::Value>);
            ~Number(); 
            bool IsEmpty();
            bool haveDecimal();
            const double CppValue();
            /**
             * return context of value
             */
            v8::Local<v8::Value> Context(); 
            /**
             * return this.Context() as v8::Local<v8::String>
             */
            v8::Local<v8::Number> v8();
            /**
             * return this.val
             */
            Ezito::Var Var(); 
            /**
             * call of prototype like String.prototype.slice.call(...);
             */
            Ezito::Var prototypeCall(const char * , int count , ...);

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Number>();
            operator v8::Local<v8::Number>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

            operator char*() = delete;
            operator char*() const = delete;
            operator bool() = delete;
            operator bool() const = delete;
            operator int();
            operator int() const;
            operator long();
            operator long() const;
            operator float();
            operator float() const;
            operator double();
            operator double() const;

            Number operator +(int);
            Number operator +(long int);
            Number operator +(long long int);
            Number operator +(double);
            Number operator +(float);
            Number operator -(int);
            Number operator -(long int);
            Number operator -(long long int);
            Number operator -(double);
            Number operator -(float);
            Number operator +=(int);
            Number operator +=(long int);
            Number operator +=(long long int);
            Number operator +=(double);
            Number operator +=(float);
            Number operator -=(int);
            Number operator -=(long int);
            Number operator -=(long long int);
            Number operator -=(double);
            Number operator -=(float);
            Number operator +(Number);
            Number operator -(Number);  
            Number operator +=(Number);  
            Number operator -=(Number);

            Number operator +(const Ezito::Var::Number & value);
            Number operator +(const Ezito::Var::Number * value);
            Number operator -(const Ezito::Var::Number & value);  
            Number operator -(const Ezito::Var::Number * value);  
            Number operator +=(const Ezito::Var::Number & value);  
            Number operator +=(const Ezito::Var::Number * value);  
            Number operator -=(const Ezito::Var::Number & value);
            Number operator -=(const Ezito::Var::Number * value);



            Number operator /(int);
            Number operator /(long int);
            Number operator /(long long int); 
            Number operator /(double); 
            Number operator /(float); 
            Number operator /(Number);   
            Number operator /(const Ezito::Var::Number & value);
            Number operator /(const Ezito::Var::Number * value); 

            Number operator *(int);
            Number operator *(long int);
            Number operator *(long long int);
            Number operator *(double); 
            Number operator *(float); 
            Number operator *(Number); 
            Number operator *(const Ezito::Var::Number & value);
            Number operator *(const Ezito::Var::Number * value); 

            bool operator ==(int);
            bool operator ==(long int);
            bool operator ==(long long int); 
            bool operator ==(double); 
            bool operator ==(float);
            bool operator ==(const Ezito::Var::Number & value);
            bool operator ==(const Ezito::Var::Number * value);

            Ezito::Var::Number operator=(const Ezito::Var::Number & value);
            Ezito::Var::Number operator=(const Ezito::Var::Number * value);
            v8::Local<v8::Number> operator->();  

            
        };



        class Boolean {
            protected:
            Value val;
            public:
            Boolean();
            Boolean(bool);
            Boolean(const Boolean *);
            Boolean(const Boolean &);
            Boolean(Ezito::Var);
            Boolean(Value);
            Boolean(v8::Local<v8::Value>);
            Boolean(v8::Local<v8::Boolean>);
            Boolean(v8::MaybeLocal<v8::Value>);
            ~Boolean();
            v8::Local<v8::Value> Context();
            v8::Local<v8::Boolean> v8();
            bool IsEmpty();
            const bool CppValue();
            Ezito::Var Var();


            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Boolean>();
            operator v8::Local<v8::Boolean>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

            operator bool();
            operator bool() const;
            operator char*() = delete;
            operator char*() const = delete;
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete;

 

        };

        

        class Function {
            protected:
            Value val;
            public:
            Function();
            Function(const Function *);
            Function(const Function &);
            Function(Value);
            Function(Ezito::Var);
            Function(v8::Local<v8::Value>);
            Function(v8::Local<v8::Function>);
            Function(v8::MaybeLocal<v8::Function>);

            Function(Ezito::FunctionCallback , const char * );
            Function(Ezito::FunctionCallback , const char * , v8::Local<v8::Value>); 

            Function(Ezito::FunctionCallbackWithReturnV8Value , const char * );  
            Function(Ezito::FunctionCallbackWithReturnV8Value2 , const char * , v8::Local<v8::Value>); 
            Function(Ezito::FunctionCallbackWithReturnV8Value3 , const char * , void *);

            Function(Ezito::FunctionCallbackWithReturnValue , const char * );
            Function(Ezito::FunctionCallbackWithReturnValue2 , const char * , v8::Local<v8::Value>);  
            Function(Ezito::FunctionCallbackWithReturnValue3 , const char * , void * data);

            Function(Ezito::FunctionCallbackWithReturnVar , const char * );
            Function(Ezito::FunctionCallbackWithReturnVar2 , const char * , v8::Local<v8::Value>);  
            Function(Ezito::FunctionCallbackWithReturnVar3 , const char * , void * data);
            ~Function(); 
            bool IsEmpty();
            void CppValue() = delete;
            /**
             * return context of value
             */
            v8::Local<v8::Value> Context(); 
            /**
             * return this.Context() as v8::Local<v8::String>
             */
            v8::Local<v8::Function> v8();
            /**
             * return this.val
             */
            Ezito::Var Var(); 
            /**
             * call of prototype like String.prototype.slice.call(...);
             */
            Ezito::Var prototypeCall(const char * , int count , ...);

            Ezito::Var Call();
            Ezito::Var Call(int count , ...);
            Ezito::Var Call(v8::Local<v8::Value> context);
            Ezito::Var Call(v8::Local<v8::Value>context, int count , ...);

            Ezito::Var CallNew();
            Ezito::Var CallNew(int count , ...); 

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Function>();
            operator v8::Local<v8::Function>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;
            
            operator char*() = delete;
            operator char*() const = delete;
            operator bool() = delete;
            operator bool() const = delete;
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete;

            Function operator=(const Function& value);
            Function operator=(const Function* value); 

            v8::Local<v8::Function> operator->();
        };



        class Undefined {
            protected:
            Value val;
            public:
            Undefined();
            Undefined(const Undefined *);
            Undefined(const Undefined &);
            Undefined(Ezito::Var);
            Undefined(v8::Local<v8::Value>);
            Undefined(v8::Local<v8::Primitive>);
            Undefined(v8::MaybeLocal<v8::Primitive>);
            ~Undefined();
            v8::Local<v8::Value> Context();
            bool IsEmpty() = delete;
            void CppValue() = delete;

            operator bool() = delete;
            operator bool() const = delete;
            operator char*() = delete;
            operator char*() const = delete;
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete;

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Primitive>();
            operator v8::Local<v8::Primitive>() const; 

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

        };
        
        
        
        
        
        
        
        
        
        class Null {
            protected:
            Value val;
            public:
            Null();
            Null(const Null *);
            Null(const Null &);
            Null(Ezito::Var);
            Null(v8::Local<v8::Value>);
            Null(v8::Local<v8::Primitive>);
            Null(v8::MaybeLocal<v8::Primitive>);
            ~Null();
            v8::Local<v8::Value> Context();
            bool IsEmpty();
            const bool CppValue();

            operator Ezito::Var();
            operator Ezito::Var() const;
            operator Value();
            operator Value() const;
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            operator v8::Local<v8::Primitive>();
            operator v8::Local<v8::Primitive>() const;

            operator Ezito::TypeOf();
            operator Ezito::TypeOf() const;

            operator bool() = delete;
            operator bool() const = delete;
            operator char*() = delete;
            operator char*() const = delete;
            operator int() = delete;
            operator int() const = delete;
            operator float() = delete;
            operator float() const = delete;
            operator double() = delete;
            operator double() const = delete; 

        };

    };





    namespace Node {



        class Isolate {
           protected:
           v8::Isolate * val;
           public:
           Isolate();
           ~Isolate();
           operator v8::Isolate*();
           operator v8::Isolate*()const;
           v8::Isolate * operator ->();
        };




        class Context {
           protected:
           v8::Local<v8::Context> val;
           public:
           Context();
           ~Context();
           operator v8::Local<v8::Context>();
           operator v8::Local<v8::Context>()const;
           v8::Context * operator ->();
        };










        class Throw {
            private:
            public:
            class Error;
            class Exception;
            Throw(const char *);
            ~Throw();

            class Exception {
                private:
                public:
                class Error;
                class RangeError;
                class ReferenceError;
                class TypeError;
                class SyntaxError; 
                Exception(const char *); 
                ~Exception(); 
                class TypeError{
                    private:
                    public:
                    TypeError(const char *);
                    ~TypeError();
                    operator v8::Local<v8::Value>();
                    operator v8::Local<v8::Value>() const;
                    operator void(){return;}
                };
                class RangeError{
                    private:
                    public:
                    RangeError(const char *);
                    ~RangeError();
                    operator v8::Local<v8::Value>();
                    operator v8::Local<v8::Value>() const;
                };
                class ReferenceError{
                    private:
                    public:
                    ReferenceError(const char *);
                    ~ReferenceError();
                    operator v8::Local<v8::Value>();
                    operator v8::Local<v8::Value>() const;
                };
                class SyntaxError{
                    private:
                    public:
                    SyntaxError(const char *);
                    ~SyntaxError();
                    operator v8::Local<v8::Value>();
                    operator v8::Local<v8::Value>() const;
                };
                class Error{
                    private:
                    public:
                    Error(const char *);
                    ~Error();
                    operator v8::Local<v8::Value>();
                    operator v8::Local<v8::Value>() const;
                };
                static void Argumants(const char * name , Ezito::TypeOf type);
                static void Constructor(const char * name);
            };
        };

    };










    
    class TypeOf {
        private:
        std::string str;
        public:
        TypeOf();
        TypeOf(const char *);
        ~TypeOf();
        operator char*();
        operator char*() const;
    };















    class Global {
        protected:
        Value val;
        public:
        class String;
        class Process;
        Global();
        Global(const char *);
        ~Global();
        Ezito::Var Get(const char *);


        class String {
            protected:
            Value val;
            Ezito::Var::Function string;
            Ezito::Var::Object stringPrototype;
            public:
            String();
            String(const char *);
            String(Ezito::Var);
            String(v8::Local<v8::Value>);
            String(v8::Local<v8::String>);
            ~String();
            Ezito::Var::Function protptype(const char *);
            operator v8::Local<v8::Value>();
            operator v8::Local<v8::Value>() const;
            String operator=(const String &);
            String operator=(const String *);
        };




        class Process{
            public:
            typedef void(ProcessCallback)(Ezito::Argumants , void *);
            protected:
            Ezito::Var::Object process;
            typedef struct DataTransfer {
                void * userData;
                ProcessCallback * callback;
                int c ;
            } DataTransfer;
            public: 
            Process();
            ~Process();
            void On(const char * name, ProcessCallback , void * data = 0);
            Ezito::Var::Function protptype(const char *);
        };

    };

















    class Class {
        protected:
        v8::Local<v8::FunctionTemplate> class_context;
        v8::Local<v8::Value> external_data;
        v8::Local<v8::String> class_name;
        void * shared_data;
        public:
        Class();
        
        Class( 
            v8::FunctionCallback callback, 
            const char * class_name 
        );

        Class(
            v8::FunctionCallback callback, 
            const char * class_name , 
            v8::Local<v8::Value> data
        ); 

        Class(
            v8::FunctionCallback callback, 
            const char * class_name , 
            v8::Local<v8::Function> extends
        );

        Class( 
            v8::FunctionCallback callback, 
            const char * class_name , 
            v8::Local<v8::FunctionTemplate> extends
        );
        
        Class(
            v8::FunctionCallback callback, 
            const char * class_name ,
            v8::Local<v8::FunctionTemplate> extends, 
            v8::Local<v8::Value> data
        );
        virtual ~Class();
        void SetCleanHook(void(callback)(void *) , void * data);
        void SetMethod(
            v8::FunctionCallback callback ,
            const char * func_name ,
            v8::Local<v8::Value> data = v8::Local<v8::Value>()
        );
        void SetField(
            v8::AccessorGetterCallback getter_callback ,
            v8::AccessorSetterCallback setter_callbak,
            const char * field_name ,
            v8::Local<v8::Value> data = v8::Local<v8::Value>()
        );
        void SetConstructor(
            v8::FunctionCallback callback ,
            v8::Local<v8::Value> data = v8::Local<v8::Value>()
        );
        void SetProperty(const char * pro_name , v8::Local<v8::Value> value);
        void SetProperty(v8::AccessorGetterCallback callback , const char * func_name , v8::Local<v8::Value> data);
        void SetName(const char * class_name);
        void SetSharedData(void *);
        v8::Local<v8::Value> Cast();
        v8::Local<v8::Value> Context();
        v8::Local<v8::String> GetClassName();
        operator v8::Local<v8::Value>();
        operator v8::Local<v8::Value>() const;
        operator v8::Local<v8::Function>();
        operator v8::Local<v8::Function>() const; 
        operator v8::Local<v8::FunctionTemplate>();
        operator v8::Local<v8::FunctionTemplate>() const; 
         

        Class operator=(const Class& string);
        Class operator=(const Class* string);

        v8::Local<v8::FunctionTemplate> operator ->();
    };

    static void CleanHook(void(callback)(void *) , void * data);
};

 

#endif
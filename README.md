



## Table of contents
 * [Installation](#Installation)
 * [Features](#Features)
 * [Examples](#Examples)

## Installation 

npm install ezito-addon



## Features

 * easily use to variable
 * easily write functions 
 * easily write classes


Since all this library is written with c++ and its source is available, refer to the source reference for more information.

It has been tried to reduce the difficulty of creating and working with variables at least a little, it is easier to create functions, it is easy to create classes, it is easy to work with variables with object type. 

The only important thing in this library is to cast correctly and check the conversion value, because if the wrong value is set, the value will be set to undefined.

If you encounter a bug, report it so that it can be fixed

## binding.gyp
```json
{
    "targets": [
        { 
            "target_name": "test",  
            "sources": [  
                "<!@(node -p \"require('ezito-addon').ezito\")",
                "build.cpp",
            ], 
        }
    ]
}
```

## Examples
   * frist app . create hello_world() fucntion and set to module.exports.hello_world
   * create variable

**Create Fucntion** : create hello_world() fucntion

```cpp 
#include "node.h"
#include "ezito.h"

void init(v8::Local<v8::Object> exports ,v8::Local<v8::Object> module){
    Ezito::Var::Object exportsObj(exports);  

    Ezito::Var hello_world([](Ezito::Argumants info){ 
        return Value("Hello to the world from cpp :)");
    });

    exportsObj.Set("hello_world" , v8.Context()); 
};


NODE_MODULE(TEST , init);
```
- use node gyp to be used

```js
const { hello_world } = require("ezito-bindings")("your build node name");
console.log(
    hello_world()
);
/// out : Hello to the world from cpp :)
```

**Create Variable 1** : create variable
- If you create an empty instance of a variable, its value will always be not undefined .
- but if you pass an empty value from node js variables to any type of variable created with Ezito::Var, the value will be undefined in any case.

```cpp
#include "node.h"
#include "ezito.h"
Ezito::Var a; // is set to undefined
EZito::Var::String str; // is set to undefined
EZito::Var::Boolean str; // is set to undefined;
EZito::Var::Number num; // is set to undefined;
EZito::Var::Undefined undef; // always is undefined
EZito::Var::Null nul; // always is null
```

**Create Variable 2** : create variable

```cpp
#include "node.h"
#include "ezito.h"

// set to v8::Local::Value::Int32
Ezito::Var a(1);
// set to v8::Local::Value::Number
Ezito::Var a(1.3);
// set to v8::Local::Value::Big int if suported else set to v8::Local::Value::Number
Ezito::Var a(4434434344433);

// set to v8::Local::Value::Int32
Ezito::Var::Number a(1);
// set to v8::Local::Value::Number
Ezito::Var::Number a(1.3);
// set to v8::Local::Value::Big int if suported else set to v8::Local::Value::Number
Ezito::Var::Number a(4434434344433);

// This type of value method applies to all variables created by type

```


**Create Object Variable** : create object variable

**Create Fucntion** : create fucntion

```cpp
#include "node.h"
#include "ezito.h"


Ezito::Var v8([](Ezito::Argumants info){
    v8::Local<v8::Value> v = Value("V8 value \n");
    return v;
});

Ezito::Var value([](Ezito::Argumants info){ 
    return Value("value \n");
});

Ezito::Var var([](Ezito::Argumants info){
    Ezito::Var::Number o(info[0]);
    o = 3423423423423423423;
    std::cout << o.CppValue() << "(--------)\n";
    return Ezito::Var(3423423423423423423);
});

// you can called v8::Local::Value::Function Call method from fucntion created with value
var.AsFunction()->Call( ...);

 
/*
You can use all created functions with Ezito::Var::Function
When you create function samples with type Ezito::Var::Function or value (in case of value from v8 object, be sure to check if it is empty) you can call it more easily
*/
Ezito::Var::Function v8([](Ezito::Argumants info){
    v8::Local<v8::Value> v = Value("V8 value \n");
    return v;
});

Ezito::Var::Function value([](Ezito::Argumants info){ 
    return Value("value \n");
});

Ezito::Var::Function var([](Ezito::Argumants info){
    Ezito::Var::Number o(info[0]);
    o = 3423423423423423423;
    std::cout << o.CppValue() << "(--------)\n";
    return Ezito::Var(3423423423423423423);
});

var.Call(1 , Ezito::Var(1)); []

```




**Create Class** : create class
```cpp

class A  : public Ezito::Class {
    public:
    A(){
        this->SetName("A");
        this->SetConstructor(A::New);
        this->SetMethod(A::HelloWorld, "HelloWorld");
        this->SetCleanHook([](void * i){
            std::cout << "clean \n";
        }, NULL);
        Ezito::Global::Process process;
        process.On("exit" ,[](Ezito::Argumants info , void * data){
            std::cout << "exit cpp \n";
        });
    };
    
    static void New(const v8::FunctionCallbackInfo<v8::Value>& info){
        info.GetReturnValue().Set(info.This());
    };
    
    static void HelloWorld(const v8::FunctionCallbackInfo<v8::Value>& info){
        Ezito::Var argumants(info[0]); 
        std::cout << "boolean :" << argumants.IsBoolean() << "\n" ; 
        std::cout << "string : " << argumants.IsString() << "\n" ;
        std::cout << "fucntion : " << argumants.IsFunction() << "\n" ;
        std::cout << "int : " << argumants.IsInt() << "\n" ;
        std::cout << "number : " << argumants.IsNumber() << "\n" ; 
        Ezito::Var::String s("dfds");
        if(argumants.IsFunction()){
            Ezito::Var::Function fn(argumants);
            Ezito::Var::Object args;
            args.Set("next" , Ezito::Var(
                [](Ezito::Argumants args){
                    return Ezito::Var ("Called");
                }
            ));

            fn.Call(1, args);
        }
        info.GetReturnValue().Set(static_cast<v8::Local<v8::Value>>(s));
    };
    ~A(){
        std::cout << "~ de counstructor";
    };
};

```




Since all this library is written with c++ and its source is available, refer to the source reference for more information.

It has been tried to reduce the difficulty of creating and working with variables at least a little, it is easier to create functions, it is easy to create classes, it is easy to work with variables with object type. 

The only important thing in this library is to cast correctly and check the conversion value, because if the wrong value is set, the value will be set to undefined.

If you encounter a bug, report it so that it can be fixed
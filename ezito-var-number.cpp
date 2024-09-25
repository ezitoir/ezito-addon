


#include "ezito.h" 
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





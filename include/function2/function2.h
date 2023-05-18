#pragma once


namespace function2 {
    const float Pi = 3.141592f;
    const float Epsilon = 0.00001f;

    enum class TypeF {
        Square,
        Garmonic
    };
    class Function2 {
    private:
        TypeF _type;
        float _a;
        float _b;
        float _c;
    public:
        Function2();
        Function2(TypeF type, float a);
        Function2(TypeF type, float a, float b);
        Function2(TypeF type, float a, float b, float c);
        TypeF get_type();
        float  get_a();
        float  get_b();
        float  get_c();
        float Square_pervoobraz(float x, float a, float b, float c);
        float function_x(float x);
        Function2 proizvod();
        Function2 pervoobraz();
    };

    class Function2_list {
    public:
        static const int COUNTER = 10;
    private:
        Function2 _function[COUNTER];
        int _size;
    public:
        Function2_list();
        int get_size();
        Function2 operator[](int index) const;
        void Function_add(const Function2& _f);
        void Function_Instal(const Function2& _f, int index);
        void Function_Insert(const Function2& _f, int index);
        void Function_Delete(int index);
        int last_max(const Function2_list& function, const float x);
    };
}



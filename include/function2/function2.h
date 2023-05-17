#pragma once

#include <string>
#include <stdexcept>
#include <memory>
#include <vector>

using namespace std;
namespace function2 {
    const float Pi = 3.141592f;
    const float Epsilon = 0.00001f;

    enum class TypeF {
        Square,
        Garmonic
    };
    class Function2;

    using Function2Ptr = std::shared_ptr<Function2>;
    class Function2 {
   /* private:
        TypeF _type;
        float _a;
        float _b;
        float _c;*/
    public:
        /*static Function2Ptr create_square(float a, float b, float c);
        static Function2Ptr create_garmonic(float a, float b, float c);
        Function2(TypeF type, float a);
        Function2(TypeF type, float a, float b);
        Function2(TypeF type, float a, float b, float c);
        TypeF get_type() const;
        float  get_a() const;
        float  get_b() const;
        float  get_c() const;
        float function_x(float x) const;
        Function2Ptr proizvod() const;
        Function2Ptr pervoobraz() const;
        Function2Ptr clone() const;
        friend std::ostream& operator<<(std::ostream& out, Function2Ptr& function);*/
        //
        virtual void print_function() const = 0;
        virtual float function_x(float x) const = 0;
        virtual Function2Ptr proizvod() const = 0;
        virtual Function2Ptr pervoobraz() const = 0;
        virtual Function2Ptr clone() const = 0;
        virtual bool equals(Function2Ptr other) const = 0;
        virtual ~Function2() = default;
    protected:
        Function2() = default;
        Function2(const Function2&) = default;
        Function2& operator=(const Function2&) = default;
    };

    class SquareFunction : public Function2 {
    private:
        float _a;
        float _b;
        float _c;
    public:
        SquareFunction(float a, float b, float c);
        float  get_a() const;
        float  get_b() const;
        float  get_c() const;
        float function_x(float x) const override;
        Function2Ptr proizvod() const override;
        Function2Ptr pervoobraz() const override;
        Function2Ptr clone() const override;
        bool equals(Function2Ptr other) const override;

    };
    class GarmonicFunction : public Function2 {
    private:
        float _a;
        float _b;
        float _c;
    public:
        GarmonicFunction(float a, float b, float c);
        float  get_a() const;
        float  get_b() const;
        float  get_c() const;
        float function_x(float x) const override;
        Function2Ptr proizvod() const override;
        Function2Ptr pervoobraz() const override;
        Function2Ptr clone() const override;
        bool equals(Function2Ptr other) const override;

    };
    /*bool operator==(const Function2& lhs, const Function2& rhs);
    bool operator!=(const Function2& lhs, const Function2& rhs);*/

    class Function2_list {
    private:
        std::vector<Function2Ptr> _function;
        /*Function2Ptr* _function;
        int _size;*/
    public:
        Function2_list() = default;
        Function2_list(const Function2_list& other);
        Function2_list& operator=(const Function2_list& rhs);
        int size() const;
        Function2Ptr operator[](int index) const;
        void Function_add(Function2Ptr f);
        void Function_Instal(Function2Ptr f, int index);
        void Function_Insert(Function2Ptr f, int index);
        void Function_Delete(int index);
        void swap(Function2_list& other);
        void show();
        
        /*Function2_list();
        ~Function2_list();//деструктор
        Function2_list(const Function2_list& other);//конструктор копирования
        Function2_list& operator=(const Function2_list& rhs);//Оператор присваивания
        int get_size() const;
        Function2Ptr operator[](int index) const;
        void Function_add(Function2Ptr const _f);
        void Function_Instal( Function2Ptr const _f, int index);
        void Function_Insert( Function2Ptr const _f, int index);
        void Function_Delete(int index);
        void swap(Function2_list& other);
        void show();*/
        
    };
    int last_max(const Function2_list& function, float x);
}



#include <iostream>
#include <math.h>

using namespace std;
/*
1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram
(параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle
(прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных
классах переопределить эту функцию, исходя из геометрических формул нахождения
площади.*/


//============================================================================================================
class Figure
{
public:
    Figure (const double& hight, const double& width){}
    virtual const double& Area()=0;
    virtual ~Figure(){}
};

class Parallelogram : public Figure
{
public:
    Parallelogram (const double hight, const double width, const double alfa)
    : Figure ( hight, width) {}

    const double& Area( const double hight = 5, const double width = 3, const double alfa = 30 )
    {
        double area( width * hight * sin(alfa));
        return Area();
    }
    void printArea ()
    {
        cout << "Area = " << Area() << endl;
    }
};
class Rectangle : public Parallelogram
{
public:
    Rectangle (const double hight, const double width, const double alfa = 90)
    : Parallelogram ( hight, width, alfa) {}

    const double& Area( const double hight = 5, const double width = 3, const double alfa = 30 )
    {
        double area( width * hight * sin(alfa));
        return Area();
    }
    void printArea ()
    {
        cout << "Area = " << Area() << endl;
    }
//~Rectangle();
};
class Square : public Parallelogram
{
public:
    Square (const double hight, const double width, const double alfa = 90)
    : Parallelogram ( hight, width, alfa) {}

    const double& Area( const double hight = 5, const double width = 3, const double alfa = 30 )
    {
        double area( width * hight * sin(alfa));
        return Area();
    }
    void printArea ()
    {
        cout << "Area = " << Area() << endl;
    }
//~Square();
};
class Rhombus : public Parallelogram
{
public:
    Rhombus (const double hight, const double width, const double alfa)
    : Parallelogram ( hight, width, alfa) {}

    const double& Area( const double hight = 5, const double width = 3, const double alfa = 30 )
    {
        double area( width * hight * sin(alfa));
        return Area();
    }
    void printArea ()
    {
        cout << "Area = " << Area() << endl;
    }
//~Rhombus();
};
class Circle : public Figure
{
public:
    Circle (const double& hight, const double& width)
    : Figure ( hight, width) {}
    virtual const double& Area( const double hight = 5, const double width = (3,1415926535) )
    {
        double area( width * hight * hight);
        return Area();
    }
    void printArea ()
    {
        cout << "Area = " << Area() << endl;
    }
    ~Circle();
};

//============================================================================================================
//============================================================================================================
/*2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов
наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они
выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой
последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз
смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего"
базового класса создает самый "дочерний" класс.*/
//============================================================================================================

class Car
{
protected:
    string company;
    string model;
public:
    Car (const string& p_company, const string& p_model){}
    virtual void printCar(const string& p_company, const string& p_model)
    {
        company = p_company;
        model = p_model;
        cout << "Model: " << model << " .Company: " << company << endl;
    }

};
class PasangerCar : virtual public Car
{
public:
    PasangerCar (const string& p_company, const string& p_model)
    : Car (company, model) {}

    /*void printCar (const string& p_company, const string& p_model)
    {
        company = p_company;
        model = p_model;
        cout << company << model;
    }*/

};

class Bus : virtual public Car
{
public:
    Bus (const string& p_company, const string& p_model)
    : Car (company, model) {}

    void printCar (const string& p_company, const string& p_model)
    {
        company = p_company;
        model = p_model;
        cout << company << model;
    }
};
class Minivan : public Bus, public PasangerCar
{
public:
    Minivan (const string& p_company, const string& p_model)
    : Car (company, model), Bus (company, model) , PasangerCar (company, model){}


    /*void printCar (const string& p_company, const string& p_model)
    {
        company = p_company;
        model = p_model;
        cout << company << model;
    }*/
};

//============================================================================================================
/*3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
● математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
● унарный оператор (-)
● логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности,
попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.*/
//============================================================================================================

class Fraction
{
    public:
    int f_a;
    int f_b;
    Fraction (){}

    float fraction ( int a = 7, int b = 6)
    {
        f_a = a;
        f_b = b;
        float result ( f_a / f_b);
        return result;
    }
};
    class Dollars
{
private:
int m_dollars;
public:
    Dollars(int dollars) { m_dollars = dollars; }
    // Эта функция является методом класса!
    // Вместо параметра dollars в перегрузке через дружественную функцию здесь
    //неявный параметр, на который указывает указатель *this
    Dollars operator+(int value)
    {
    return Dollars(m_dollars + value);
    }
    int getDollars() { return m_dollars; }
};


/*4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три
поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля
масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом
классе должно быть два метода:
● метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он
ее поворачивает лицом вверх, и наоборот.
● метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/

int main()
{

    Dollars dollars1(7);
    Dollars dollars2 = dollars1 + 3;
    cout << "I have " << dollars2.getDollars() << " dollars.\n";

    cout << "Bye!" <<  endl;

    return 0;
}

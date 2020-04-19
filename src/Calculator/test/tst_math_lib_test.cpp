/**
  * @file tst_math_lib_test.cpp
  * @author David Sladký
  * @brief Test class for math_lib.
  */

#include <QtTest>
#include "math_lib.h"

class math_lib_test : public QObject
{
    Q_OBJECT

public:
    math_lib_test();
    ~math_lib_test();

private slots:
    void addition1();
    void addition2();
    void addition3();
    void addition4();
    void addition5();

    void subtraction1();
    void subtraction2();
    void subtraction3();
    void subtraction4();
    void subtraction5();

    void division1();
    void division2();
    void division3();
    void division4();
    void division5();

    void multiplication1();
    void multiplication2();
    void multiplication3();
    void multiplication4();
    void multiplication5();

    void factorial1();
    void factorial2();
    void factorial3();
    void factorial4();
    void factorial5();

    void power1();
    void power2();
    void power3();
    void power4();
    void power5();

    void root1();
    void root2();
    void root3();
    void root4();
    void root5();

};

math_lib_test::math_lib_test()
{

}

math_lib_test::~math_lib_test()
{

}

void math_lib_test::addition1()
{
    math_lib tmp;
    QVERIFY(tmp.addition(5, 4) == 9.0);
}

void math_lib_test::addition2()
{
    math_lib tmp;
    QVERIFY(tmp.addition(0, 0) == 0.0);
}

void math_lib_test::addition3()
{
    math_lib tmp;
    QCOMPARE(tmp.addition(-99999, 2), -99997.0);
}

void math_lib_test::addition4()
{
    math_lib tmp;
    QCOMPARE(tmp.addition(-7, -42), -49.0);
}

void math_lib_test::addition5()
{
    math_lib tmp;
    QCOMPARE(tmp.addition(66, 100), 166.0);
}

void math_lib_test::subtraction1()
{
    math_lib tmp;
    QCOMPARE(tmp.subtraction(5, 4), 1.0);
}

void math_lib_test::subtraction2()
{
    math_lib tmp;
    QCOMPARE(tmp.subtraction(0, 0), 0.0);
}

void math_lib_test::subtraction3()
{
    math_lib tmp;
    QCOMPARE(tmp.subtraction(-99999, 2), -100001.0);
}

void math_lib_test::subtraction4()
{
    math_lib tmp;
    QCOMPARE(tmp.subtraction(-7, -42), 35.0);
}

void math_lib_test::subtraction5()
{
    math_lib tmp;
    QCOMPARE(tmp.subtraction(66, 100), -34.0);
}

void math_lib_test::division1()
{
    math_lib tmp;
    QCOMPARE(tmp.division(5, 4), 5.0/4);
}

void math_lib_test::division2()
{
    math_lib tmp;
    QVERIFY_EXCEPTION_THROWN(tmp.division(0, 0), std::logic_error);
}

void math_lib_test::division3()
{
    math_lib tmp;
    QCOMPARE(tmp.division(-99999, 2), -99999.0/2);
}

void math_lib_test::division4()
{
    math_lib tmp;
    QCOMPARE(tmp.division(-7, -42), -7.0/-42);
}

void math_lib_test::division5()
{
    math_lib tmp;
    QCOMPARE(tmp.division(66, 100), 66.0/100);
}

void math_lib_test::multiplication1()
{
    math_lib tmp;
    QCOMPARE(tmp.multiplication(5, 4), 20.0);
}

void math_lib_test::multiplication2()
{
    math_lib tmp;
    QCOMPARE(tmp.multiplication(42, 0), 0.0);
}

void math_lib_test::multiplication3()
{
    math_lib tmp;
    QCOMPARE(tmp.multiplication(-99999, 2), -199998.0);
}

void math_lib_test::multiplication4()
{
    math_lib tmp;
    QCOMPARE(tmp.multiplication(-7, -42), 294.0);
}

void math_lib_test::multiplication5()
{
    math_lib tmp;
    QCOMPARE(tmp.multiplication(66, 100), 6600.0);
}

void math_lib_test::factorial1()
{
    math_lib tmp;
    QCOMPARE(tmp.factorial(-5), 0.0);
}

void math_lib_test::factorial2()
{
    math_lib tmp;
    QCOMPARE(tmp.factorial(1), 1.0);
}

void math_lib_test::factorial3()
{
    math_lib tmp;
    QVERIFY_EXCEPTION_THROWN(tmp.factorial(161), std::logic_error);
}

void math_lib_test::factorial4()
{
    math_lib tmp;
    QCOMPARE(tmp.factorial(10), 3628800.0);
}

void math_lib_test::factorial5()
{
    math_lib tmp;
    QCOMPARE(tmp.factorial(5), 120.0);
}

void math_lib_test::power1()
{
    math_lib tmp;
    QCOMPARE(tmp.power(-5, 0), 1.0);
}

void math_lib_test::power2()
{
    math_lib tmp;
    QCOMPARE(tmp.power(1, 1), 1.0);
}

void math_lib_test::power3()
{
    math_lib tmp;
    QCOMPARE(tmp.power(3, -5), 0.0);
}

void math_lib_test::power4()
{
    math_lib tmp;
    QCOMPARE(tmp.power(10, 10), 10000000000.0);
}

void math_lib_test::power5()
{
    math_lib tmp;
    QCOMPARE(tmp.power(5,2), 25.0);
}

void math_lib_test::root1()
{
    math_lib tmp;
    QCOMPARE(tmp.root(-5, -2), 0.0);
}

void math_lib_test::root2()
{
    math_lib tmp;
    QCOMPARE(tmp.root(1, 1), 1.0);
}

void math_lib_test::root3()
{
    math_lib tmp;
    QCOMPARE(tmp.root(3, 2), std::pow(3.0, 1.0/2.0));
}

void math_lib_test::root4()
{
    math_lib tmp;
    QCOMPARE(tmp.root(10, 10), std::pow(10.0, 1.0/10.0));
}

void math_lib_test::root5()
{
    math_lib tmp;
    QCOMPARE(tmp.root(27,3), 3.0);
}

QTEST_APPLESS_MAIN(math_lib_test)

#include "tst_math_lib_test.moc"

/*** End of file tst_math_lib_test.cpp */

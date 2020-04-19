#include <QtTest>
#include "../app/math_lib.h"

// add necessary includes here

class math_lib_test : public QObject
{
    Q_OBJECT

public:
    math_lib_test();
    ~math_lib_test();

private slots:
    void test_case1();

};

math_lib_test::math_lib_test()
{

}

math_lib_test::~math_lib_test()
{

}

void math_lib_test::test_case1()
{
    math_lib tmp;
    QVERIFY(tmp.addition(5, 4) == 9);
}

QTEST_APPLESS_MAIN(math_lib_test)

#include "tst_math_lib_test.moc"

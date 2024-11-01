#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.3 r/lab 6.3 r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRecursive
{
    TEST_CLASS(UnitTestRecursive)
    {
    public:
        // Тестування функції create
        TEST_METHOD(TestCreate)
        {
            const int SIZE = 10;
            int arr[SIZE];
            int MIN = -10, MAX = 10;

            create(arr, SIZE, MIN, MAX, 0);

            for (int i = 0; i < SIZE; i++) {
                Assert::IsTrue(arr[i] >= MIN && arr[i] <= MAX, L"Element out of range");
            }
        }

        // Тестування функції countPositive
        TEST_METHOD(TestCountPositive)
        {
            int arr[] = { -3, 5, -1, 4, -6, 2, 0 };
            int expectedCount = 3; // три додатних елементи: 5, 4, 2

            int actualCount = countPositive(arr, 7, 0);

            Assert::AreEqual(expectedCount, actualCount, L"Positive count mismatch");
        }

        // Тестування функції sortAscending
        TEST_METHOD(TestSortAscending)
        {
            int arr[] = { 3, -2, 5, 1, 0 };
            int expectedArr[] = { -2, 0, 1, 3, 5 };

            sortAscending(arr, 5);

            for (int i = 0; i < 5; i++) {
                Assert::AreEqual(expectedArr[i], arr[i], L"Array element mismatch after sorting");
            }
        }

        // Тестування шаблонної функції templateSortAscending
        TEST_METHOD(TestTemplateSortAscending)
        {
            int arr[] = { 4, 1, -3, 7, 0 };
            int expectedArr[] = { -3, 0, 1, 4, 7 };

            templateSortAscending(arr, 5);

            for (int i = 0; i < 5; i++) {
                Assert::AreEqual(expectedArr[i], arr[i], L"Array element mismatch after template sorting");
            }
        }

        // Тестування шаблонної функції templateCountPositive
        TEST_METHOD(TestTemplateCountPositive)
        {
            int arr[] = { -1, 2, 3, -4, 5 };
            int expectedCount = 3; // три додатних елементи: 2, 3, 5

            int actualCount = templateCountPositive(arr, 5, 0);

            Assert::AreEqual(expectedCount, actualCount, L"Positive count mismatch in template function");
        }
    };
}

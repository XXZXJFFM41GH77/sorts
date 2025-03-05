# ПОСТАНОВКА ЗАДАЧИ
Реализовать два метода сортировки выделенного в динамической памяти массива чисел и провести их экспериментальное сравнение.
При реализации каждого метода вычислить число сравнений элементов и число обменов элементов.
Сравнение методов сортировки необходимо проводить на одних и тех же исходных массивах, при этом
следует рассмотреть массивы разной длины. Рассмотреть, как минимум, n = 10, 100, 1000, 10000.
Генерация исходных массивов для сортировки реализуется отдельной функцией, создающей в зависимости от
заданного параметра и заданной длины конкретный массив, в котором:

- элементы уже упорядочены (1);
- элементы упорядочены в обратном порядке (2);
- расстановка элементов случайна (3, 4).

## Элементы массива
64-разрядные целые числа (long long int)

## Вид сортировки
Числа упорядочиваются по неубыванию

## Методы сортировки

1. Метод простого выбора
2. Быстрая сортировка, рекурсивная реализация

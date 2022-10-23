# ClassString

### Лабораторная работа по курсу "Основы C++"

В ней был реализован класс **String**, перегружены основные операции для работы с ней.<br>
Точка входа в приложение - **Class String.cpp**
<br>
| Метод класса  | Описание метода |
| ------------- | ------------- |
| Конструктор String()  | Определяет пустую строку длины 0  |
| Конструктор String(const char* value)  | Определяет строку, заполненную значениями, на которые ссылается указатель |
| Конструктор String(int length, char symbol)  | Определяет строку, заполненную значениями symbol, повторенными length раз |
| Конструктор String(const String& string)  | Определяет строку, заполненную значениями из объекта переданного класса  |
| operator=(const String& string)  | Перегруженный оператор "=" |
| operator+(const String& str, const String& str2)  | Перегруженный оператор "+" |
| operator==(const String& string) | Перегруженный оператор равенства для объекта String  |
| operator==(const char* string)  | Перегруженный оператор равенства для указателя  |
| operator<=(const String& string) | Перегруженный оператор "<=" для объекта String  |
| operator<=(const char* string)  | Перегруженный оператор "<=" для указателя  |
| operator>=(const String& string) | Перегруженный оператор ">=" для объекта String  |
| operator>=(const char* string)  | Перегруженный оператор ">=" для указателя  |
| operator>(const String& string) | Перегруженный оператор ">" для объекта String  |
| operator>(const char* string)  | Перегруженный оператор ">" для указателя  |
| operator<(const String& string) | Перегруженный оператор "<" для объекта String  |
| operator<(const char* string)  | Перегруженный оператор "<" для указателя  |
| operator<<(ostream& out, String& string)  | Перегруженный оператор вывода  |
| cmp(const String& string)  | Метод сравнения объектов класса String. Возвращаемые значения: 0 - равенство, -1 - значение экземпляра, через который был вызван метод, меньше сравниваемого, 1 в ином случае |
| cmp(const char *string)  | Метод сравнения объекта класса String и указателя на символы. Возвращаемые значения: 0 - равенство, -1 - значение экземпляра, через который был вызван метод, меньше сравниваемого, 1 в ином случае |
| getLength()  | Получение длины строки  |
| getIndexOfSymbol(char symbol)  | Получение первого индекса вхождения символа в строке, если символ не входит в строку, то -1  |
| getIndexOfWord(String& string)  | Получение первого индекса вхождения подстроки в строке, если подстрока не входит в строку, то -1  |
| operator\*(String& str, int N)  | Перегруженный оператор "\*", дублирует слово в str N раз |
| invert(String& string)  | Оператор, который меняет очередность символов в строке на противоположную: первый символ становится последним и т.д. |
| operator[](int N)  | Перегруженный оператор обращения к N-ому символу |
| operator new[](size_t N)  | Перегруженный оператор создания экземпляра класса |
| toLower()  | Перевод строки в нижний регистр  |
| toUpper()  | Перевод строки в верхний регистр  |

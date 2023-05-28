#include <iostream>
#include <vector>


template<typename T>
void print(const std::vector<T> &vector);

template<typename T>
void move_vectors(std::vector<T> &vector_one, std::vector<T> &vector_two);

int main() {
    #if WIN32
    setlocale(LC_ALL, "ru");
    #endif

    std::cout << "\tПеремещение объектов\n" << std::endl;

    std::vector<std::string> one = {"test_string1", "test_string2"};
    std::vector<std::string> two;

    std::cout << "Векторы до перемещения:" << std::endl;
    std::cout << "\tВектор 'one': ";
    print(one);
    std::cout << "\tВектор 'two': ";
    print(two);
    std::cout << std::endl;

    move_vectors(one, two);

    std::cout << "Векторы после перемещения:" << std::endl;
    std::cout << "\tВектор 'one': ";
    print(one);
    std::cout << "\tВектор 'two': ";
    print(two);

    std::cin.get();
    return 0;
}

template <typename T>
void print(const std::vector<T> &vector) {
    for (const auto &el : vector) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void move_vectors(std::vector<T> &vector_one, std::vector<T> &vector_two) {
    std::vector<T> temp = std::move(vector_one);
    vector_one = std::move(vector_two);
    vector_two = std::move(temp);
}

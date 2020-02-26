lass Storage
{
private:
    unsigned int n;
    unsigned int* conteiner;
public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n)
    {
        this->n = n;
        this->conteiner = new unsigned int[n];
    }

    // Добавьте нужный деструктор
    virtual ~Storage()
    {
        delete [] conteiner;
    }

    // Получение размерности хранилища
    unsigned getSize() { return n; }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i)
    {
        return conteiner[i];
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value) {
        conteiner[i] = value;
    }
};

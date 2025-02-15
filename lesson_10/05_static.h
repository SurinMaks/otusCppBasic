#pragma once

class Counter
{
  public:
    Counter();
    ~Counter();

    // Статический метод не привязан ни к какому объекту.
    // Создается один экземпляр для всех объектов класса.
    static int getCount();

    // Статический член класса является общим для всех экземпляров структуры.
    // Иными словами: статические члены класса не связаны с объектами структуры.
  private:
    static int count; // объявляем, но не определяем.
};

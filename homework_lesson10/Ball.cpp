#include "Ball.hpp"
#include <cmath>

/**
 * Конструктор класса Ball
 * @param radius радиус шара
 * @param x координаты центра шара (x, y)
 * @param y координаты центра шара (x, y)
 * @param vx его скорости (vx, vy)
 * @param vy его скорости (vx, vy)
 * @param red три составляющие цвета шара
 * @param green три составляющие цвета шара
 * @param blue три составляющие цвета шара
 * @param isCollidable требуется ли обрабатывать пересечение шаров как столкновение
 */
Ball::Ball(double radius, double x, double y, double vx, double vy, double red, double green, double blue, bool isCollidable)
{
    this->radius = radius;

    center.x = x;
    center.y = y;
    
    velocity.x = vx;
    velocity.y = vy;

    this->red = red;
    this->green = green;
    this->blue = blue;

    this->isCollidable = isCollidable;
}

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    // TODO: место для доработки
    this->velocity = velocity.vector();

}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    // TODO: место для доработки
    return velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    // TODO: место для доработки
    Color color(red, green, blue);
    painter.draw(center,radius,color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    // TODO: место для доработки
    this->center.x = center.x;
    this->center.y = center.y;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    // TODO: место для доработки
    return center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    // TODO: место для доработки
    return radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    // TODO: место для доработки
    return M_PI * (radius * radius * radius) * 4. / 3.;
}

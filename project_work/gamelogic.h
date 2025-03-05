#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "GameStatus.h"

class GameLogic
{
    public:
        GameLogic();
        GameStatus CheckMoves(const unsigned int newPositionX, const unsigned int newPositionY);
        void setFieldSize(const unsigned int length, const unsigned int width);
        void reset();
        void PrintInformation();


    private:
        const int kDx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int kDy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        unsigned int length_{0};
        unsigned int width_{0};
        unsigned int position_x_{0};//текущая позиция X
        unsigned int position_y_{0};//текущая позиция Y
        unsigned int number_of_turns_{0};//количество сделанных ходов
        unsigned int max_number_of_turns_{0};//максимально возможное количество ходов
        bool game_is_on_{false};
        void setMaxNumberOfTurns();
        void setNumberOfTurns();
        void setCurrentPosition(const unsigned int newPositionX, const unsigned int newPositionY);
        void GameIsOn(bool status);

        //отладочные функции
        void PrintCurrentPosition();
        void PrintFiledSize();
        void PrintNumberOfTurns();
        void PrintMaxNumberOfTurns();

};

#endif // GAMELOGIC_H

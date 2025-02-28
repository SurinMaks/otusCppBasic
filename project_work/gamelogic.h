#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic
{
    public:
        GameLogic();
        bool CheckMoves(int row, int col);
        void GetCurrentPosition(int row, int col);
        void GetGieldSize(int row, int col);

    private:
        const int kDx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int kDy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

};

#endif // GAMELOGIC_H

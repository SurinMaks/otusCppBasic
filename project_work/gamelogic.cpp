#include "gamelogic.h"
#include <QDebug>

GameLogic::GameLogic() {}

GameStatus GameLogic::CheckMoves(const unsigned int newPositionX, const unsigned int newPositionY){
    std::vector<std::pair<int, int>> possibleMoves;

    if(number_of_turns_ == 0){ //первый ход
        setCurrentPosition(newPositionX, newPositionY);
        setNumberOfTurns();
        return GameStatus::Continue;
    }
    else{ // второй и далее ход
        for (int i = 0; i < 8; ++i) { //сформируем все возможные ходы
            int checkX = position_x_ + kDx[i];
            int checkY = position_y_ + kDy[i];
            possibleMoves.push_back({checkX, checkY});
        }

        for(const auto &el : possibleMoves){
            if(el.first == newPositionX && el.second == newPositionY){
                setCurrentPosition(newPositionX, newPositionY);
                setNumberOfTurns();
                if(number_of_turns_ == max_number_of_turns_){
                    return GameStatus::Win;
                }
                return GameStatus::Continue;
            }
        }
    }
    return GameStatus::Fail;
}

void GameLogic::setFieldSize(const unsigned int length, const unsigned int widt){
    length_ = length;
    width_ = widt;
    setMaxNumberOfTurns();
}

void GameLogic::setCurrentPosition(const unsigned int newPositionX, const unsigned int newPositionY){
    position_x_ = newPositionX;
    position_y_ = newPositionY;
}

void GameLogic::setNumberOfTurns(){
    ++number_of_turns_;
}

void GameLogic::setMaxNumberOfTurns(){
    max_number_of_turns_ = length_ * width_;
}

void GameLogic::PrintInformation(){
    PrintCurrentPosition();
    // PrintFiledSize();
    PrintNumberOfTurns();
    // PrintMaxNumberOfTurns();
}

void GameLogic::PrintCurrentPosition(){
    qDebug() << "Game Logic. position: " << position_x_ << " " << position_y_;
}

void GameLogic::PrintFiledSize(){
    qDebug() << "Game Logic. field size: " << length_ << " " << width_;
}

void GameLogic::PrintNumberOfTurns(){
    qDebug() << "Game Logic. number of turns: " << number_of_turns_;
}

void GameLogic::PrintMaxNumberOfTurns(){
    qDebug() << "Game Logic. max number of turns: " <<max_number_of_turns_;
}

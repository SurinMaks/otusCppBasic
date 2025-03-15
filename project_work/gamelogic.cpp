#include "gamelogic.h"
#include <vector>
#include <QDebug>

GameLogic::GameLogic() = default;

GameStatus GameLogic::CheckMoves(const unsigned int &newPositionX,
								 const unsigned int &newPositionY) {
	std::vector<std::pair<int, int>> possibleMoves;
	if (number_of_turns_ == 0) {  // первый ход
		GameIsOn(true);
		setCurrentPosition(newPositionX, newPositionY);
		setNumberOfTurns();
		return GameStatus::Continue;
	} else {						   // второй и далее ход
		for (int i = 0; i < 8; ++i) {  // сформируем все возможные ходы
			const int checkX = position_x_ + kDx[i];
			const int checkY = position_y_ + kDy[i];
			possibleMoves.push_back({checkX, checkY});
		}

		for (const auto &el : possibleMoves) {
			if (el.first == newPositionX && el.second == newPositionY) {
				setCurrentPosition(newPositionX, newPositionY);
				setNumberOfTurns();
				if (number_of_turns_ == max_number_of_turns_) {
					GameIsOn(false);
					return GameStatus::Win;
				}
				return GameStatus::Continue;
			}
		}
	}
	return GameStatus::Fail;
}

void GameLogic::setFieldSize(const unsigned int &length,
							 const unsigned int &widt) {
	length_ = length;
	width_ = widt;
	setMaxNumberOfTurns();
}

void GameLogic::reset() {
	position_x_ = 0;
	position_y_ = 0;
	number_of_turns_ = 0;
}

void GameLogic::setCurrentPosition(const unsigned int &newPositionX,
								   const unsigned int &newPositionY) {
	position_x_ = newPositionX;
	position_y_ = newPositionY;
}

void GameLogic::setNumberOfTurns() { ++number_of_turns_; }

void GameLogic::setMaxNumberOfTurns() {
	max_number_of_turns_ = length_ * width_;
}

void GameLogic::GameIsOn(bool status) { game_is_on_ = status; }

void GameLogic::PrintInformation() {
	PrintCurrentPosition();
	PrintFiledSize();
	PrintNumberOfTurns();
	PrintMaxNumberOfTurns();
}

void GameLogic::PrintCurrentPosition() {
	qDebug() << "Game Logic. position: " << position_x_ << " " << position_y_;
}

void GameLogic::PrintFiledSize() {
	qDebug() << "Game Logic. field size: " << length_ << " " << width_;
}

void GameLogic::PrintNumberOfTurns() {
	qDebug() << "Game Logic. number of turns: " << number_of_turns_;
}

void GameLogic::PrintMaxNumberOfTurns() {
	qDebug() << "Game Logic. max number of turns: " << max_number_of_turns_;
}

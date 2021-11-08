#include "Chessboard.h"
#include "RookFigure.h"
#include <gtest/gtest.h>

using namespace crazy_rooks;

TEST(ChessBoardTest, BasicTest) {
  Chessboard board;
  for (auto col = 0; col < CHESS_BOARD_WIDTH; ++col) {
    for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
      bool squareEmpty = false;
      ASSERT_NO_THROW(squareEmpty = board.squares()->at(0)[0].isEmpty());
      ASSERT_TRUE(squareEmpty);
    }
  }
  ASSERT_EQ(board.figures()->size(), 0);
}

TEST(ChessBoardTest, AddFigureTest) {
  Chessboard board;
  ASSERT_EQ(board.figures()->size(), 0);
  RookFigure tower;
  ASSERT_TRUE(board.addFigure(board.squares()->at(0)[0], std::make_shared<RookFigure>(tower)));
  ASSERT_EQ(board.figures()->size(), 1);
  ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
}

TEST(ChessBoardTest, AddSameFigureTest) {
  Chessboard board;
  ASSERT_EQ(board.figures()->size(), 0);
  RookFigure tower;
  ASSERT_TRUE(board.addFigure(board.squares()->at(0)[0], std::make_shared<RookFigure>(tower)));
  ASSERT_EQ(board.figures()->size(), 1);
  ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
  ASSERT_FALSE(board.addFigure(board.squares()->at(3)[3], std::make_shared<RookFigure>(tower)));
  ASSERT_EQ(board.figures()->size(), 1);
}

TEST(ChessBoardTest, AddFigureToOccupiedSquareTest) {
  Chessboard board;
  ASSERT_EQ(board.figures()->size(), 0);
  RookFigure tower;
  ASSERT_TRUE(board.addFigure(board.squares()->at(0)[0], std::make_shared<RookFigure>(tower)));
  ASSERT_EQ(board.figures()->size(), 1);
  ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
  RookFigure tower2;
  ASSERT_FALSE(board.addFigure(board.squares()->at(0)[0], std::make_shared<RookFigure>(tower2)));
  ASSERT_EQ(board.figures()->size(), 1);
}

TEST(ChessBoardTest, AddMultipleFiguresTest) {
  Chessboard board;
  ASSERT_EQ(board.figures()->size(), 0);
  for (auto i = 0; i < 8; ++i) {
    RookFigure tower;
    ASSERT_TRUE(board.addFigure(board.squares()->at(i)[i], std::make_shared<RookFigure>(tower)));
    ASSERT_EQ(board.figures()->size(), i + 1);
  }
}
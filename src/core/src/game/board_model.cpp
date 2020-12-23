#include "board_model.h"
#include <iostream>
#include <iomanip>

BoardModel::BoardModel(const unsigned int gridSize)
    : GameObject()
    , m_gridSize(gridSize)
    , m_gameBoard(std::make_unique<Board>(gridSize))
{}

void BoardModel::playAt(unsigned int row, unsigned int column, Player player)
{
    if(m_gameBoard->getTile(row, column)->GetState() == Tile::State::BLANK)
    {
        m_gameBoard->getTile(row, column)->SetPlayer(&player);
    }
    else
    {
        throw std::runtime_error("You can not play there, another tile has already taken.");
    }
}

void BoardModel::drawBoard() const
{
    std::cout << std::endl << "------------------------------------------" << std::endl;

    for(unsigned int i = 0; i < m_gameBoard->getGridSize(); i++)
    {
        for(unsigned int y = 0; y < m_gameBoard->getGridSize(); y++)
        {
            if(m_gameBoard->getTile(i,y)->GetState() != Tile::State::BLANK)
            {
                std::cout << std::internal << std::setw(2) << m_gameBoard->getTile(i, y);
                if(y < this->m_gridSize - 1)
                {
                    std::cout << " | ";
                }
            }
            else
            {
                std::cout << std::internal << std::setw(2)<< " ";
                if(y < this->m_gridSize - 1)
                {
                    std::cout << " | ";
                }
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl << "------------------------------------------" << std::endl;
}

std::vector<std::unique_ptr<Board>> BoardModel::generatePossibleStates(Player player)
{
    //empty vector of BoardModel
    std::vector<std::unique_ptr<Board>> movesSet;

    //Lopps Through each Row
    for (unsigned int  row =  0 ; row < m_gameBoard->getGridSize(); row++)
    {
        //Loop through each colum
        for (unsigned int column = 0 ; column < m_gameBoard->getGridSize(); column++)
        {
            // if we have a free spot generate a possible outcome
            if (m_gameBoard->getTile(row, column)->GetState() == Tile::State::BLANK)
            {
                std::unique_ptr<Board> possibleGameState(new Board(*m_gameBoard.get(), row, column, player));

                //add this to a vector of valid moves
                movesSet.push_back(std::move(possibleGameState));
            }
        }
    }

    // move the board fields out
    return movesSet;
}

bool BoardModel::nextChildBoard(Player player, Board* childBoard)
{
    // Check is children board already implemented or null
    if(!m_childrenBoard)
    {
        m_childrenBoard = std::make_shared<Board>(m_gridSize);
    }

    for(unsigned int row = childBoard->getCachedLastRowPlayed(); row < m_gameBoard->getGridSize(); row++)
    {
        for(unsigned int column = childBoard->getCachedLastColumnPlayed(); column < m_gameBoard->getGridSize(); column++)
        {
            if(m_gameBoard->getTile(row, column)->GetState() == Tile::State::BLANK
                    && (childBoard->getRowPlayed() != row || childBoard->getColumnPlayed() != column))
            {
                auto childBoardPtr = m_childrenBoard.get();

                std::destroy_at(childBoardPtr);
                std::uninitialized_fill_n(childBoardPtr, 1, Board(*childBoard, row, column, player));
                childBoard->setCachedLastRowPlayed(row);
                childBoard->setCachedLastColumnPlayed(column);

                return true;
            }
        }

        childBoard->setCachedLastColumnPlayed(0);
    }

    return false;
}

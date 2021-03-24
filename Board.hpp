#pragma once
#include <string>
#include "Direction.hpp"
namespace ariel {
    class Board{
        public:
            void post(unsigned int row, unsigned int column,Direction direction,std::string const & message); 
            std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int  length ) ;
            void show();
    };
}

/**
 *Test.cpp for snowman
 * AUTHORS: mor234
 * 
 */

#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"

using namespace ariel;
#include <string>
//bad -post on
//read somting that isnt their

//post on empty place
//post on something
//מודעה ריקה


    Board board1;
    Board board2;
TEST_CASE("Simple cases: good Post and Read") {
 //******Post on empty location******//

    //***Horizontal***//
    board1.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "abcd");
	CHECK(board1.read(/*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/4)=="abcd") ; 
    
    //post next to written location
    board1.post(/*row=*/0, /*column=*/4, Direction::Horizontal, "efg");
	CHECK(board1.read(/*row=*/0, /*column=*/4, Direction::Horizontal, /*length=*/3)=="efg") ;
    CHECK(board1.read(/*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/7)=="abcdefg") ; 

    //write in the next line
    board1.post(/*row=*/1, /*column=*/0, Direction::Horizontal, "abcd2");
	CHECK(board1.read(/*row=*/1, /*column=*/0, Direction::Horizontal, /*length=*/5)=="abcd2") ; 

    //*example for more locations*//
    
    //check spacial characters works normaly- \n
    board1.post(/*row=*/20, /*column=*/87, Direction::Horizontal, "abcd\n");
	CHECK(board1.read(/*row=*/20, /*column=*/87, Direction::Horizontal, /*length=*/5)=="abcd\n") ;

    board1.post(/*row=*/11112, /*column=*/35670, Direction::Horizontal, "abcd");
	CHECK(board1.read(/*row=*/11112, /*column=*/35670, Direction::Horizontal, /*length=*/4)=="abcd") ;

    //overrwrite in the same location
    board1.post(/*row=*/11112, /*column=*/35670, Direction::Horizontal, "1234");
   	CHECK(board1.read(/*row=*/11112, /*column=*/35670, Direction::Horizontal, /*length=*/4)=="1234") ;

   


    //***Vertical***//

    board2.post(/*row=*/0, /*column=*/0, Direction::Vertical, "abcd");
	CHECK(board2.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/4)=="abcd") ; 
    
    //post next to written location
    board2.post(/*row=*/4, /*column=*/0, Direction::Vertical, "efg");
	CHECK(board2.read(/*row=*/4, /*column=*/0, Direction::Vertical, /*length=*/3)=="efg") ;
    CHECK(board2.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/7)=="abcdefg") ; 

    //write in the next column
    board2.post(/*row=*/0, /*column=*/1, Direction::Vertical, "abcd2");
	CHECK(board2.read(/*row=*/0, /*column=*/1, Direction::Vertical, /*length=*/5)=="abcd2") ; 

    //*example for more locations*//
    
    //check spacial characters works normaly- \n
    board2.post(/*row=*/20, /*column=*/87, Direction::Vertical, "abcd\n");
	CHECK(board2.read(/*row=*/20, /*column=*/87, Direction::Vertical, /*length=*/5)=="abcd\n") ;

    board2.post(/*row=*/11112, /*column=*/35670, Direction::Vertical, "abcd");
	CHECK(board2.read(/*row=*/11112, /*column=*/35670, Direction::Vertical, /*length=*/4)=="abcd") ;
    
     //overrwrite in the same location
    board2.post(/*row=*/11112, /*column=*/35670, Direction::Vertical, "1234");
   	CHECK(board2.read(/*row=*/11112, /*column=*/35670, Direction::Vertical, /*length=*/4)=="1234") ;

}

TEST_CASE("Post and Read empty messeges") {
    //******Read from empty location******//
    //***Horizontal***//
    CHECK(board2.read(/*row=*/1000, /*column=*/1000, Direction::Horizontal, /*length=*/4)=="____");
    //***Vertical***//
    CHECK(board2.read(/*row=*/1000, /*column=*/1000, Direction::Vertical, /*length=*/4)=="____");

    //******Post empty messege******//
    //***Horizontal***//
    board2.post(/*row=*/1000, /*column=*/1000, Direction::Horizontal, "");
    CHECK(board2.read(/*row=*/1000, /*column=*/1000, Direction::Vertical, /*length=*/4)=="____");
    //***Vertical***//
    board2.post(/*row=*/1000, /*column=*/1000, Direction::Vertical, "");
    CHECK(board2.read(/*row=*/1000, /*column=*/1000, Direction::Vertical, /*length=*/4)=="____");

    //******Read messege with len 0******//
    //***Horizontal***//
    CHECK(board2.read(/*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/0)=="");
    //***Vertical***//
    CHECK(board2.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/0)=="");


    //******Read including empty location******//
    board2.post(/*row=*/1000, /*column=*/1000, Direction::Vertical, "1");

    //***Horizontal***//
    CHECK(board2.read(/*row=*/1000, /*column=*/999, Direction::Horizontal, /*length=*/4)=="_1__");
    //***Vertical***//
    CHECK(board2.read(/*row=*/999, /*column=*/1000, Direction::Vertical, /*length=*/4)=="_1__");
}

TEST_CASE("General cases: Post and Read") {


    //******General Cases:******//
    Board board;
     
    //***write over -Horizontal***//
    board.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "123");
    board.post(/*row=*/0, /*column=*/2, Direction::Horizontal, "789");

	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/6)=="12789_") ; 

     //***write over -Vertical***//
     //over Horizontal
    board.post(/*row=*/0, /*column=*/1, Direction::Vertical, "hello");
    CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/6)=="1h789_") ; 

     //over Vertical
    board.post(/*row=*/2, /*column=*/1, Direction::Vertical, "makom");
    CHECK(board.read(/*row=*/0, /*column=*/1, Direction::Vertical, /*length=*/6)=="hemak") ; 


    //write in distance
    //***Horizontal***//
    board.post(/*row=*/100, /*column=*/100, Direction::Horizontal, "hello");
    board.post(/*row=*/100, /*column=*/107, Direction::Horizontal, "world\n");
    CHECK(board.read(/*row=*/100, /*column=*/100, Direction::Horizontal, /*length=*/13)=="hello__world\n") ; 
    //***Vertical***//
    board.post(/*row=*/100, /*column=*/100, Direction::Vertical, "hello");
    board.post(/*row=*/107, /*column=*/100, Direction::Vertical, "world\n");
    CHECK(board.read(/*row=*/100, /*column=*/100, Direction::Vertical, /*length=*/13)=="hello__world\n") ; 

    //read row made of columns:
    board.post(/*row=*/1000, /*column=*/1000, Direction::Vertical, "hello");
    board.post(/*row=*/1000, /*column=*/1001, Direction::Vertical, "world");
    board.post(/*row=*/1000, /*column=*/1002, Direction::Vertical, "sound");
    CHECK(board.read(/*row=*/1004, /*column=*/1000, Direction::Horizontal, /*length=*/3)=="odd") ; 

    //read column made of rows:
    board.post(/*row=*/830, /*column=*/30, Direction::Horizontal, "hello");
    board.post(/*row=*/831, /*column=*/30, Direction::Horizontal, "AVIRON");
    board.post(/*row=*/832, /*column=*/30, Direction::Horizontal, "song&poem");
    board.post(/*row=*/833, /*column=*/30, Direction::Horizontal, "she sounds great");
    CHECK(board.read(/*row=*/830, /*column=*/33, Direction::Vertical, /*length=*/4)=="lRg ") ; 

}



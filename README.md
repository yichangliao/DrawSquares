# DrawSquares

### A C++ console game. Try score as much as possible by drawing squares.

* Rule:
    - smallest square: 2 tiles X 2 tiles. You will score 4 points
    - initial Ink : 10 pt.
    - draw 1 tile : -1 pt of ink.
    - Hit Refill : +2 pt of ink, once hit the refill, refill will be gone..
    - Hit your line, stop draw, check the shape is square
      - succeed to draw a square : score points(steps to achieve a square), get ink point(half of the steps to achieve a square), clear your draw, but objects on the board remain.
      - Fail to draw a square : clear your draw, but objects one the board remain.
          
* Objects can be obtain : max 3 items to carry, when you use the object, you won’t lose your ink point. Every step can only use one object.
    - Blow : clear max 8 needles around your current position.
    - Pop: it will create 5 random items in 24 tiles where are closed to your current position. The items might be created are Blow, Ram, Pop, Needle, Refill.


* Combo:
    - 4 consecutive same square(return to the same location): + extra 4 times the scores you have earn ed on the 4 squares. You will also earn 10 pt ink.


* Space class:
  - private: 
	- char object;
	- int x;
	- int y;
	- Space *top;
	- Space *right;
	- Space *left;
	- Space *bottom;
  - public:

* Derived class:
  - Ink class
  - Refill class
  - Blow class
  - Pop class

* Other classes:
  - Board
  - Game

* Menu:
  - w : up		s:down		a:left		d:right
  - e : show objects
  - q : quit

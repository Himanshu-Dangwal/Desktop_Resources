//Castle.h

// iostream is only used for the operator<< function.

// Do not print anything directly to cout from this or any other class

//#include "innocent.h"#include "guard.h"#include "indentured_guard.h"#include "roving_guard.h"#include "hunter_guard.h" // this class does not provide UI no does it contain main.
//
//class Castle
//
//{/** stream insertion operator overload */
//
//    friend std::ostream& operator<<(std::ostream& out, const Castle& castle);  
//
//    public:
//
//    /** castle constructor. Initializes the castle */
//
//    Castle();
//
///** move the position of the hero
//
//     @ parameter move the direction in which the hero must move: must be a valid move
//
//     @ throws invalid_argument exception if move is invalid */
//
//    void move(char move);
//
///** Castle destructor. Deletes all heap based objects (including guards) */
//
//    ~Castle(){}
//
//private:
//
//    std::vector guards; Innocent* hero; Innocent* wife;
//
//    };

//Guard.h

//#include "person.h" #include "position.h" // should inherit from Person but be an abstract class

//class Guard
//
//{public:
//
//    /** Guard constructor. Calls person constructor * @parameter pos is the initial position. * @parameter type is the type of person. */
//
//    Guard(const Position& pos, char type); /** Moves the guard. This is a pure virtual function which is overrriden in the derived guards* @parameter move determines the  position to move to. Should be a pure virtual function, * Defaults to 'A' for auto */
//
//    void move(char move = 'A')    /** Virtual Destructor */
//
//    ~Guard() {};
//
//protected:
//
//private:
//
//};
//
//hunter_guard.h
//
//#include #include #include "person.h" #include "position.h" #include "guard.h" #include "innocent.h" // should inherit from Guard

//class HunterGuard
//
//{public:
//
///** HunterGuard constructor. Calls Guard constructor with type 'H' * @parameter pos is the initial position.    * @parameter hero is a pointer to the hero object in the castle */
//
//    HunterGuard(const Position& pos, const Innocent& hero);
//
///** Moves the guard. This function overrides in the Guard's pure virtual function *  moves this guard towards the hero either in the x or y direction. * @parameter move determines the  position to move to. Should be a pure virtual function, * Defaults to 'A' for auto */
//
//    void move(const char move = 'A');
//
///** Destructor */ ~HunterGuard(){};
//
//    protected:
//
//private:
//
//    const Innocent* hero;
//
//};
//
//indentured_guard.h
//
//#include #include #include "person.h" #include "position.h" #include "guard.h" // should inherit from guard

//class IndenturedGuard{
//
//public:
//
//    /** IndenturedGuard constructor. Calls Guard constructor with type 'I' * @parameter pos is the initial position.*/
//
//    IndenturedGuard(const Position& pos);
//
///** Moves the guard. This function overrrides in the Guard's pure virtual function *  has a 15% chance of moving this guard in a random direction. * @parameter move determines the  position to move to. Should be a pure virtual function, * Defaults to 'A' for aut */
//
//    void move(const char move = 'A');
//
//     /** Destructor */ ~IndenturedGuard(){}
//
//    protected:
//
//private:
//
//};

//person.h
//
//#include "position.h"

// The base class of Guards and Innocents and is abstract

//class Person{
//
//public:
//
//    /** Person object. the base class for guards and Innocents * @parameter pos. the initial position * @parameter type. the type of person */
//
//    Person(const Position& pos, char type);    /** Gets the current position of the Person * @return position. */
//
//    Position getPosition() const; /** Gets the type of the person [I, R, H, Y, W] * @return the type of the Person*/
//
//    char getType() const;    /** Equality operator * @parameter other the other person object* @return true if this object has the same position as the other and false otherwise */
//
//    bool operator==(const Person& other) const; /** Inequality operator* @parameter other the other person object * @return false if this object has the same position as the other and true otherwise */
//
//    bool operator!=(const Person& other) const; /** Moves the Person from the current position to pos. This is a pure virtual function * @parameter move determines the direction to move. The default value is 'A' for auto  */
//
//    void move(char move = 'A');
//
///** Virtual Destructor */    ~Person(){}
//
//   protected:
//
//    Position* pos;
//
//    char type;
//
//private:
//
//};

//roving_guard.h

//#include #include #include "person.h" #include "position.h" #include "guard.h"

// should inherit from Guard

//class RovingGuard{
//
//public:
//
//    /** RovingGuard constructor. Calls Guard constructor with type 'R' * @parameter pos is the initial position.*/
//
//    RovingGuard(const Position& pos); /** Moves the guard. This function overrides in the Guard's pure virtual function                      *  moves this guard in a random direction.* @parameter move determines the  position to move to. Should be a pure virtual function, *            Defaults to 'A' for auto */
//
//    void move(const char move = 'A');
//
///** Destructor */ ~RovingGuard(){};
//
//    
//
//protected:
//
//private:
//
//};

//position.h
//
//#include

//struct Position
//
//{
//
//    size_t x;
//
//    size_t y;
//
//    Position(size_t x, size_t y) :x{x}, y{y} {}
//
//    Position(Position& other) :x{other.x}, y{other.y} {}
//
//};

//Innocent.h

//#include "person.h" #include "position.h"

// should inherit from Person

//class Innocent{
//
//public:
//
//    /** Innocent constructor. Calls person constructor * @parameter pos is the initial position. * @parameter type is the type of person. */
//
//    Innocent(const Position& pos, char type);
//
///** Moves the Innocent based on the pos argument.   *  This function overrrides in the Guard's pure virtual function * @parameter move determines the updated position to move to. Moves: [N, S, E, W, P, C] * throws invalid_argument exception if pos is an invalid move */
//
//    void move(const char move);
//
///** Destructor */ ~Innocent(){};
//
//    protected:
//
//private:
//
//};
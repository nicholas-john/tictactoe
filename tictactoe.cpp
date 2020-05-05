#include<string>
#include<iostream>
using namespace std;

class Square{
	public:
 		Square(){
			state = ' ';
		}
		void changeToX(){
			state = 'X';
		}
		void changeToO(){
			state = 'O';
		}
		void change(char c){
			state = c;
		}
		char getState(){
			return state;
		}
	private:
		char state;
};

class Board{
	public:
		Board(){
 
		}
		void change(int row, int col, char letter){
			if (row == 1 && col == 1) {s11.change(letter);}
			else if (row == 1 && col == 2) {s12.change(letter);}
			else if (row == 1 && col == 3) {s13.change(letter);}
			else if (row == 2 && col == 1) {s21.change(letter);}
			else if (row == 2 && col == 2) {s22.change(letter);}
			else if (row == 2 && col == 3) {s23.change(letter);}
			else if (row == 3 && col == 1) {s31.change(letter);}
			else if (row == 3 && col == 2) {s32.change(letter);}
			else if (row == 3 && col == 3) {s33.change(letter);}
			else {throw(1);}
		}
		void printBoard(){
			cout << endl;
			cout << endl;
			cout << s11.getState() << " | " << s12.getState()
			 << " | " << s13.getState() << endl;
			cout << "_________" << endl;
			cout << s21.getState() << " | " << s22.getState()
			 << " | " << s23.getState() << endl;
			cout << "_________" << endl;
			cout << s31.getState() << " | " << s32.getState()
			 << " | " << s33.getState() << endl;
		}
		char checkSquare(int row, int col){
			if (row == 1 && col == 1) {return s11.getState();}
			else if (row == 1 && col == 2) {return s12.getState();}
			else if (row == 1 && col == 3) {return s13.getState();}
			else if (row == 2 && col == 1) {return s21.getState();}
			else if (row == 2 && col == 2) {return s22.getState();}
			else if (row == 2 && col == 3) {return s23.getState();}
			else if (row == 3 && col == 1) {return s31.getState();}
			else if (row == 3 && col == 2) {return s32.getState();}
			else if (row == 3 && col == 3) {return s33.getState();}
			else {throw(1);}
		} 
		char check(char k){
			if (s11.getState() == k && s12.getState() == k 
			&& s13.getState() == k){
				return k;
			} 
			else if (s21.getState() == k && s22.getState() == k 
			&& s23.getState() == k){
				return k;
			} 
			else if (s31.getState() == k && s32.getState() == k 
			&& s33.getState() == k){
				return k;
			} 
			else if (s11.getState() == k && s21.getState() == k 
			&& s31.getState() == k){
				return k;
			} 
			else if (s12.getState() == k && s22.getState() == k 
			&& s32.getState() == k){
				return k;
			} 
			else if (s13.getState() == k && s23.getState() == k 
			&& s33.getState() == k){
				return k;
			}
			else if (s11.getState() == k && s22.getState() == k 
			&& s33.getState() == k){
				return k;
			}  
			else if (s13.getState() == k && s22.getState() == k 
			&& s31.getState() == k){
				return k;
			} 
			else return ' ';
		}
		char check(){
			char ex = this->check('X');
			char oh = this->check('O');
			if (ex == 'X'){
				return 'X';
			}
			else if (oh == 'O'){
				return 'O';
			}
			else return ' ';
		}
		bool isFull(){
			return (s11.getState() != ' ' && s12.getState() != ' ' &&
				s13.getState() != ' ' && s21.getState() != ' ' &&
				s22.getState() != ' ' && s23.getState() != ' ' &&
				s31.getState() != ' ' && s32.getState() != ' ' &&
				s33.getState() != ' ');
		}
	private:
		Square s11, s12, s13, s21, s22, s23, s31, s32, s33;

};

class Game{
	public: 
		void play(){
			cout << "Choose a square with" << endl << endl;
			cout << "q w e" << endl << "a s d" << endl 
				<< "z x c" << endl << endl;
			cout << "type \"quit\" to stop the game at any time"<<endl<<endl;
			board.printBoard();
			int turn = 1;
			while (turn != 0){
				if (turn == 1){
				cout << endl << "X Turn" << endl;
					try{
						string move;
						cin >> move; 
						if (move == "q") {xMove(1, 1); turn = 2;}
						else if (move == "w") {xMove(1, 2); turn = 2;}
						else if (move == "e") {xMove(1, 3); turn = 2;}
						else if (move == "a") {xMove(2, 1); turn = 2;}
						else if (move == "s") {xMove(2, 2); turn = 2;}
						else if (move == "d") {xMove(2, 3); turn = 2;}
						else if (move == "z") {xMove(3, 1); turn = 2;}
						else if (move == "x") {xMove(3, 2); turn = 2;}
						else if (move == "c") {xMove(3, 3); turn = 2;}
						else if (move == "quit") {turn = 0; cout << "no game" << endl << endl;}
						else cout << "Invalid move. Try again."<<endl;
					}
					catch (...){
						cout << "Invalid move. Try again." << endl;
					}
					board.printBoard();
				}
				else if (turn == 2){
				cout << endl << "O Turn" << endl;
					try{
						string move;
						cin >> move; 
						if (move == "q") {oMove(1, 1); turn = 1;}
						else if (move == "w") {oMove(1, 2); turn = 1;}
						else if (move == "e") {oMove(1, 3); turn = 1;}
						else if (move == "a") {oMove(2, 1); turn = 1;}
						else if (move == "s") {oMove(2, 2); turn = 1;}
						else if (move == "d") {oMove(2, 3); turn = 1;}
						else if (move == "z") {oMove(3, 1); turn = 1;}
						else if (move == "x") {oMove(3, 2); turn = 1;}
						else if (move == "c") {oMove(3, 3); turn = 1;}
						else if (move == "quit") {turn = 0; cout << "no game" << endl << endl;}
						else cout << "Invalid move. Try again." << endl;
					}
					catch (...){
						cout << "Invalid move. Try again." << endl;
					}
					board.printBoard();
					
				}
				char winner = board.check();
				if (winner == 'X'){
					cout << endl << "X Wins" << endl;
					turn = 0;
				}
				else if (winner == 'O'){
					cout << endl << "O Wins" << endl;
					turn = 0;
				}
				else if (board.isFull()){
					cout << endl <<"Nobody Wins" << endl << endl;
					turn = 0;
				}
			}			
		}
	private:
		void xMove(int row, int col){
			if (board.checkSquare(row, col) == ' '){
				board.change(row, col, 'X');
			}
			else throw(2);
		}
		void oMove(int row, int col){
			if (board.checkSquare(row, col) == ' '){
				board.change(row, col, 'O');
			}
			else throw(2);
		}	
		Board board;
				
};

void startGame(){
	Game game;
	game.play();
	cout<<"Enter \"x\" to Play Again, or anything else to quit"<<endl;
	string entry;
	cin>>entry;
	if (entry == "x") startGame();
	else cout<<endl<<"Thanks for Playing"<<endl<<endl;
}

void logo(){
	cout <<"  _______ _____ _____   _______       _____   _______ ____  ______ "<<endl;
 	cout <<" |__   __|_   _/ ____| |__   __|/\\   / ____| |__   __/ __ \\|  ____|"<<endl;
	cout <<"    | |    | || |         | |  /  \\ | |         | | | |  | | |__   "<<endl;
  	cout <<"    | |    | || |         | | / /\\ \\| |         | | | |  | |  __|  "<<endl;
   	cout <<"    | |   _| || |____     | |/ ____ \\ |____     | | | |__| | |____ "<<endl;
 	cout <<"    |_|  |_____\\_____|    |_/_/    \\_\\_____|    |_|  \\____/|______|"<<endl;
	cout <<endl<<endl;
}

int main(){
	logo();
	startGame();
	
	return 0;
}
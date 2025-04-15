#include <iostream>
#include <vector>
#include <string>


using namespace std;

// Define constants for chess pieces
const int ROOK = 5;
const int BISHOP = 3;
const int KING = 0;
const int QUEEN = 9;
const int KNIGHT = 2;
const int PAWN = 1;
// Define other constants for the chessboard
const int EMPTY = -1; // Empty square

string getPieceSymbol(int piece, bool isWhite) {
    if (piece == PAWN) return isWhite ? "♙" : "♟";
    if (piece == KNIGHT) return isWhite ? "♘" : "♞";
    if (piece == BISHOP) return isWhite ? "♗" : "♝";
    if (piece == ROOK) return isWhite ? "♖" : "♜";
    if (piece == QUEEN) return isWhite ? "♕" : "♛";
    if (piece == KING) return isWhite ? "♔" : "♚";
    return ".";
}


int main() {
    // Gör 8 vectorer med 8 värden i sig
    // 2-dimensionell vector
    int chessboard[8][8];

    // Fyller brädet med tomma rutor
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessboard[i][j] = EMPTY;
        }
    }
    // Placera ut pjäserna
    for(int i = 0; i < 8; i++){
        chessboard[1][i] = PAWN; // Svarta bönder
        chessboard[6][i] = PAWN; // Vita bönder
    }
    // Hästar
    chessboard[0][1] = KNIGHT;
    chessboard[0][6] = KNIGHT;
    chessboard[7][1] = KNIGHT;
    chessboard[7][6] = KNIGHT;
    // Bishops
    chessboard[0][2] = BISHOP;
    chessboard[0][5] = BISHOP;
    chessboard[7][2] = BISHOP;
    chessboard[7][5] = BISHOP;
    // Drottning och kung
    // Drottning på 1D och kung på 1E
    chessboard[0][3] = QUEEN;
    chessboard[0][4] = KING;
    // Drottning på 8D och kung på 8E
    chessboard[7][3] = QUEEN;
    chessboard[7][4] = KING;

    // Rooks
    chessboard[0][0] = ROOK;
    chessboard[0][7] = ROOK;
    chessboard[7][0] = ROOK;
    chessboard[7][7] = ROOK;

    // Skriv ut brädet i terminalen
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessboard[i][j] == EMPTY) {
                cout << ". ";
            } else {
                cout << chessboard[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Print the board with symbols
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessboard[i][j] == EMPTY) {
                cout << ". ";
            } else {
                bool isWhite = (i >= 6); // top is black, bottom is white
                cout << getPieceSymbol(chessboard[i][j], isWhite) << " ";
            }
        }
        cout << endl;
    }

    
    return 0;
}
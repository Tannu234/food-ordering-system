#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Convert choice number to text
string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

// Determine winner
// Returns:
// 0 = Draw
// 1 = Player Wins
// 2 = Computer Wins
int determineWinner(int player, int computer) {
    if (player == computer)
        return 0;

    if ((player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2))
        return 1;

    return 2;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int rounds;
    int playerScore = 0;
    int computerScore = 0;
    int drawCount = 0;

    cout << "========================================\n";
    cout << "      ROCK PAPER SCISSORS GAME\n";
    cout << "========================================\n\n";

    cout << "Enter the number of rounds: ";
    cin >> rounds;

    while (rounds <= 0) {
        cout << "Please enter a valid number of rounds: ";
        cin >> rounds;
    }

    for (int round = 1; round <= rounds; round++) {
        int playerChoice;

        cout << "\n----------------------------------------\n";
        cout << "Round " << round << " of " << rounds << "\n";
        cout << "----------------------------------------\n";

        cout << "Choose an option:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;

        while (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin >> playerChoice;
        }

        int computerChoice = rand() % 3 + 1;

        cout << "\nYour Choice     : " << getChoiceName(playerChoice) << endl;
        cout << "Computer Choice : " << getChoiceName(computerChoice) << endl;

        int result = determineWinner(playerChoice, computerChoice);

        cout << "\nResult: ";

        if (result == 0) {
            cout << "It's a Draw!" << endl;
            drawCount++;
        }
        else if (result == 1) {
            cout << "You Win!" << endl;
            playerScore++;
        }
        else {
            cout << "Computer Wins!" << endl;
            computerScore++;
        }

        cout << "\nCurrent Score\n";
        cout << "Player   : " << playerScore << endl;
        cout << "Computer : " << computerScore << endl;
        cout << "Draws    : " << drawCount << endl;
    }

    cout << "\n========================================\n";
    cout << "             FINAL RESULT\n";
    cout << "========================================\n";

    cout << "Player Wins   : " << playerScore << endl;
    cout << "Computer Wins : " << computerScore << endl;
    cout << "Draws         : " << drawCount << endl;

    cout << "\nOverall Winner: ";

    if (playerScore > computerScore)
        cout << "Congratulations! You are the Champion!\n";
    else if (computerScore > playerScore)
        cout << "Computer Wins the Game!\n";
    else
        cout << "The Match Ends in a Draw!\n";

    cout << "\nThank you for playing!\n";

    return 0;
}
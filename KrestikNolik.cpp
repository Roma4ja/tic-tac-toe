// KrestikNolik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <windows.h>

class Player {
public:
    char symbol;

    Player(char s) {
        symbol = s;
    }

    bool MakeMove(char board[], int x, int y) {
        if (x < 1 || x > 3 || y < 1 || y > 3)
            return false;

        int index = y * 4 + x;

        if (board[index] != ' ')
            return false;

        board[index] = symbol;
        return true;
    }
};

void printBoard(char board[16]) {
    for (int i = 0; i < 16; i++) {
        std::cout << " " << board[i] << " |";

        if (i % 4 == 3) {
            std::cout << '\n';

            if (i != 15)
                std::cout << "----------------\n";
        }
    }
}

bool CheckWin(char board[], char symbol) {
    int win[8][3] = {
        { 5, 6, 7 },{ 9, 10, 11 },{ 13, 14, 15 },
        { 5, 9, 13 },{ 6, 10, 14 },{ 7, 11, 15 },
        { 5, 10, 15 },{ 7, 10, 13 }
    };

    for (int i = 0; i < 8; i++) {
        if (board[win[i][0]] == symbol &&
            board[win[i][1]] == symbol &&
            board[win[i][2]] == symbol)
            return true;
    }

    return false;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char board[16] = {
        ' ', '1', '2', '3',
        '1', ' ', ' ', ' ',
        '2', ' ', ' ', ' ',
        '3', ' ', ' ', ' '
    };

    int player_choice;

    std::cout << "Кто ходит первым?\n";
    std::cout << "1. Крестики\n";
    std::cout << "2. Нолики\n";

    std::cin >> player_choice;

    if (player_choice != 1 && player_choice != 2) {
        std::cout << "Неверный выбор!\n";
        return 0;
    }

    Player player1(player_choice == 1 ? 'X' : 'O');
    Player player2(player_choice == 1 ? 'O' : 'X');

    Player* current = &player1;

    int moves = 0;
    int x, y;

    while (moves < 9) {
        printBoard(board);

        std::cout << "Ход игрока " << current->symbol << "\n";
        std::cout << "Введите координаты X Y: ";

        std::cin >> x >> y;

        if (!current->MakeMove(board, y, x)) {
            std::cout << "Неверный ход! Попробуйте снова.\n";
            continue;
        }

        moves++;

        if (CheckWin(board, current->symbol)) {
            printBoard(board);
            std::cout << "Победили " << current->symbol << "!\n";
            return 0;
        }

        current = (current == &player1) ? &player2 : &player1;
    }

    printBoard(board);
    std::cout << "Ничья!\n";

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

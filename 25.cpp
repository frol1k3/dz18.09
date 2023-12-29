#include <iostream>
#include <random>
#include <time.h>
using namespace std;

bool coincidence(int* list, int len);
int* bublesort(int* list, int len);

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    bool flag = true;
    while (flag) {
        string answer;
        cout << "Если хотите бросить кости введите любую цифру кроме 0, для выхода введите 0: " << endl;
        cin >> answer;
        if (answer == "0") {
            flag = false;
        }
        else {
            int* player = new int[5];
            cout << "Ваши числа: ";
            for (int i = 0; i < 5; i++) {
                player[i] = rand() % 6 + 1;
                cout << player[i] << " -/- ";
            }
            cout << "\nЧисла ИИ: ";
            int* ai = new int[5];
            for (int i = 0; i < 5; i++) {
                ai[i] = rand() % 6 + 1;
                cout << ai[i] << " -_- ";
            }
            cout << endl;
            if (coincidence(player, 5)) {
                cout << "Вы выиграли!" << endl;
            }
            else if (coincidence(ai, 5)) {
                cout << "Вы проиграли!" << endl;
            }
            else {
                player = bublesort(player, 5);
                ai = bublesort(ai, 5);
                if (player[0] + 1 == player[1] && player[1] + 1 == player[2] && player[2] + 1 == player[3] && player[3] + 1 == player[4]) {
                    cout << "Вы выиграли!" << endl;
                }
                else if (ai[0] + 1 == ai[1] && ai[1] + 1 == ai[2] && ai[2] + 1 == ai[3] && ai[3] + 1 == ai[4]) {
                    cout << "Вы проиграли!" << endl;
                }
                else {
                    int player_sum = 0;
                    int ai_sum = 0;
                    for (int i = 0; i < 5; i++) {
                        ai_sum += ai[i];
                        player_sum += player[i];
                    }
                    if (player_sum > ai_sum) {
                        cout << "Вы выиграли!" << endl;
                    }
                    else if (player_sum == ai_sum) {
                        cout << "Ничья!" << endl;
                    }
                    else {
                        cout << "Вы проиграли!" << endl;
                    }
                }
            }
        }
    }
}
bool coincidence(int* list, int len) {
    for (int i = 0; i < len; i++) {
        if (list[i] != list[0]) {
            return false;
        }
    }
    return true;
}

int* bublesort(int* list, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
    return list;
}
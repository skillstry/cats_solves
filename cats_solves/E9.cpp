#include <fstream>

struct data_line {
    int time_line;
    int attacking_player;
    int victim_player;
    int result_line;
};

int result[11] = { -1,   0, 0, 0, 0, 0,  0, 0, 0, 0, 0, };


void check(int now_id, struct data_line* data, int size_data, int good_time) {
    int fix_time = data[now_id].time_line, fix_victim = data[now_id].victim_player;

    int set_G[] = { 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0 };

    for (int i = now_id; i >= 0; i--) {
        if ((fix_time - data[i].time_line) >= good_time) {
            break;
        }
        if (data[i].victim_player == fix_victim) {
            set_G[data[i].attacking_player] = 1;
        }
    }

    for (int i = now_id + 1; i < size_data; i++) {
        if (data[i].time_line != fix_time) {
            break;
        }
        if (data[i].victim_player == fix_victim) {
            set_G[data[i].attacking_player] = 1;
        }
    }
    for (int i = now_id + 1; i < size_data; i++) {
        if (data[i].time_line != fix_time) {
            break;
        }
        if ((set_G[data[i].attacking_player] == 1) && (data[i].victim_player != fix_victim)) {
            return;
        }
        if ((set_G[data[i].victim_player] == 1) && (data[i].attacking_player != fix_victim)) {
            return;
        }
        if ((data[i].attacking_player == fix_victim) && (set_G[data[i].victim_player] != 1)) {
            return;
        }
    }



    for (int i = now_id - 1; i >= 0; i--) {
        if ((fix_time - data[i].time_line) >= good_time) {
            break;
        }
        if ((set_G[data[i].attacking_player] == 1) && (data[i].victim_player != fix_victim)) {
            return;
        }
        if ((set_G[data[i].victim_player] == 1) && (data[i].attacking_player != fix_victim)) {
            return;
        }
        if ((data[i].attacking_player == fix_victim) && (set_G[data[i].victim_player] != 1)) {
            return;
        }
    }

    for (int i = 1; i < 11; i++) {
        result[i] += set_G[i];
    }
    return;

}



int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n, t;
    int id_to_check, a, b, c, d;
    in >> n >> t;
    data_line* data = new data_line[n];
    for (int id_line = 0; id_line < n; id_line++) {
        in >> a >> b >> c >> d;
        data[id_line].time_line = a;
        data[id_line].attacking_player = b;
        data[id_line].victim_player = c;
        data[id_line].result_line = d;
    }
    for (int id_line = 0; id_line < n; id_line++) {
        if (data[id_line].result_line == 1) {
            check(id_line, data, n, t);
        }
    }
    for (int i = 1; i < 11; i++) {
        out << result[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_vec(const std::vector<char>& vec)
{
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}

int main () {
    vector<char> queue{};
    int n;
    int wq = 0;
    cin >> n;
    for (int i=0; i < n; i++) {
        print_vec(queue);
        string cmd;
        cin >> cmd;
        cout << cmd.size();
        if (cmd.compare("WORRY_COUNT") == 0)
            cout << wq << endl;
        else {
            cout << "here";
            string t;
            cin >> t;
            int arg = atoi(t.c_str());
            int in = (queue.size() - 1) - arg;
            if (cmd.compare("WORRY") == 0)
                if (queue[in] != 'w' && wq++)
                    queue[in] = 'w';
            else if (cmd.compare("QUIET") == 0)
                if (queue[in] != 'q' && wq--)
                    queue[in] = 'q';
            else if (cmd.compare("COME") == 0) {
                if (arg >=0)
                    queue.insert(queue.begin(), arg, 'q');
                else 
                    while (arg++){
                        if (queue[queue.back()] == 'w')
                            wq--;
                        queue.pop_back();
                    }
            }
        }
    }
}
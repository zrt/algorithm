#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int kN = 3e5+10;

int N, Q;
int max_read[kN];
vector<int> app_mesg[kN];
//          app, id
vector<pair<int, int> > mesg;
int readed[kN];

int main() {
    scanf("%d %d", &N, &Q);
    int unread = 0;
    int cur_t = 0;
    for (int i = 1; i <= Q; i++) {
        int op, x; scanf("%d %d", &op, &x);
        if (op == 1) {
            mesg.push_back(make_pair(x, i));
            app_mesg[x].push_back(i);
            unread++;
        } else if (op == 2) {
            for (int &i = max_read[x]; i < app_mesg[x].size(); i++) {
                if (!readed[app_mesg[x][i]]) {
                    readed[app_mesg[x][i]] = 1;
                    unread--;
                }
            }
        } else {
            for (int &i = cur_t; i < mesg.size() and i < x; i++) {
                int which = mesg[i].first, id = mesg[i].second;
                if (!readed[id]) {
                    readed[id] = 1;
                    unread--;
                }
            }
        }
        printf("%d\n", unread);
    }
    return 0;
}

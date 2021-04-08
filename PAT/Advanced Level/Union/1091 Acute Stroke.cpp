//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/8.
//
#include<iostream>
using namespace std;

struct group
{
	int x, y, z, num;
	void operator=(const group& b) {
		x = b.x;
		y = b.y;
		z = b.z;
	}
};

int M, N, L, T, cnt, tmp, input[60][1300][130];
group p[60][1300][130];

bool check(int z, int x, int y) {
	group t = p[z][x][y];
	if (t.x == x && t.y == y && t.z == z)
		return true;
	return false;
}

group* find(int a, int b, int c) {
	group r = p[a][b][c];
	while (!check(r.z, r.x, r.y)) r = p[r.z][r.x][r.y];
	return &p[r.z][r.x][r.y];
}

void merge(int a, int b, int c, int k, int i, int j) {
	group* r = find(a, b, c), * s = find(k, i, j);
	if (r == s) return;
	if (r->num > s->num) {
		r->num += s->num;
		*s = *r;
	}
	else {
		s->num += r->num;
		*r = *s;
	}
}

int main() {
	cin >> M >> N >> L >> T;
	for (int k = 0;k < L;k++) {
		for (int i = 0;i < M;i++) {
			for (int j = 0;j < N;j++) {
				scanf("%d", &input[k][i][j]);
				if (input[k][i][j]) {
					p[k][i][j].x = i;
					p[k][i][j].y = j;
					p[k][i][j].z = k;
					p[k][i][j].num = 1;
					if (k > 0 && input[k - 1][i][j])
						merge(k, i, j, k - 1, i, j);
					if (i > 0 && input[k][i - 1][j])
						merge(k, i, j, k, i - 1, j);
					if (j > 0 && input[k][i][j - 1])
						merge(k, i, j, k, i, j - 1);
				}
			}
		}
	}
	for (int k = 0;k < L;k++) {
		for (int i = 0;i < M;i++) {
			for (int j = 0;j < N;j++) {
				if (input[k][i][j] && check(k, i, j) && p[k][i][j].num >= T) {
					cnt += p[k][i][j].num;
				}
			}
		}
	}
	cout << cnt;
}
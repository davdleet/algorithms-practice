#include <stdio.h>
#include "kewry.h"
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<long long> arr(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	vector<long long> ans = calc(arr, N);
	for (long long& it : ans)
		printf("%lld\n", it);

	return 0;
}

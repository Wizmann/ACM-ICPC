#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

vector<int> ns;
vector<int> ms;

int main() {
    int n;
    input(n);

    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }


    ms = vector<int>(n, 0);
    for (int i = 1; i < n; i++) {
        ms[i] = ns[i] - ns[i - 1];
    }

    sort(ms.begin(), ms.end());

    vector<int> presum(n, 0);

    for (int i = 1; i < n; i++) {
        presum[i] = presum[i - 1] + ms[i];
    }

    const int MAXN = presum[n - 1] * n + 12345;
    vector<llint> dp[2];
    dp[0] = vector<llint>(MAXN, INFLL);
    dp[1] = vector<llint>(MAXN, INFLL);
    dp[0][0] = 0;
    int maxn = 0;
    int p = 0;
    for (int i = 1; i < n; i++) {
        int q = p ^ 1;

        fill(dp[q].begin(), dp[q].begin() + maxn + 19, INFLL);

        for (int j = 0; j <= maxn; j++) {
            if (dp[p][j] >= INFLL) {
                continue;
            }
            // print(">>", i);
            // print(j, p, dp[p][j]);
            int nxt1 = j + ms[i] * i; // add to left
            assert(nxt1 < (int)dp[q].size());
            dp[q][nxt1] = min(dp[q][nxt1],
                             dp[p][j] + 2LL * ms[i] * j + ms[i] * ms[i] * i);
            int nxt2 = j + presum[i];
            assert(nxt2 < (int)dp[q].size()); // add to right
            dp[q][nxt2] = min(dp[q][nxt2], dp[p][j] + 1LL * presum[i] * presum[i]);
        }
        maxn = max(maxn + ms[i] * i, maxn + presum[i]);
        p = q;
    }

    llint ans = INF;
    for (int i = 0; i < (int)dp[p].size(); i++) {
        if (dp[p][i] >= INFLL) {
            continue;
        }
        ans = min(ans, 1LL * n * dp[p][i] - 1LL * i * i);
    }
    print(ans);

    return 0;
}


/*
^^^TEST^^^
4
1 2 4 6
------
52
$$$TEST$$$

^^^^TEST^^^
10
6 19 34 35 56 63 82 82 83 99
------
59865
$$$TEST$$$


^^^TEST^^^
50
1 6 25 27 27 28 29 30 32 32 32 32 32 32 32 32 32 32 32 34 36 38 39 40 40 42 45 49 50 51 52 53 53 54 54 54 56 57 57 57 59 59 59 59 61 63 63 63 64 66
-------
252100
$$$TEST$$$$

^^^TEST^^^
400
1 1 2 2 3 3 4 4 4 4 4 5 6 6 7 7 8 9 9 9 9 11 12 13 13 13 13 13 13 13 14 14 14 14 14 15 15 16 17 18 19 19 20 20 20 21 21 21 21 21 23 24 25 25 26 26 26 26 26 27 28 28 29 29 29 29 29 29 30 30 31 31 31 31 31 31 32 32 32 32 33 34 34 35 36 43 44 45 46 47 48 49 54 55 55 56 114 356 356 356 357 357 358 359 359 359 360 361 362 362 363 363 363 364 364 364 365 366 366 366 367 367 367 368 369 369 370 370 371 372 373 376 377 377 378 379 380 380 380 380 380 381 381 382 383 383 383 383 384 385 386 386 387 388 388 389 389 390 390 390 390 390 390 391 392 399 399 399 400 401 411 412 413 413 413 413 413 413 414 414 414 414 414 414 414 414 415 416 417 418 418 418 418 419 420 420 424 425 425 426 427 427 428 429 429 429 429 429 429 429 429 429 430 431 432 433 434 434 434 434 435 435 436 436 437 437 437 437 437 437 437 437 438 438 439 439 440 440 441 441 441 442 442 443 444 444 444 447 448 448 449 449 457 457 458 459 460 460 461 462 463 463 463 464 464 464 464 465 465 465 465 466 466 467 468 468 468 469 470 470 471 471 471 471 471 471 471 471 472 472 472 472 473 474 475 476 477 478 478 479 480 481 481 481 482 482 482 482 482 483 484 484 484 484 484 484 484 485 485 485 485 485 486 487 487 487 488 489 489 489 489 490 491 491 492 493 494 494 494 495 495 495 495 496 496 496 496 496 496 497 497 497 498 498 498 499 500 500 500 501 502 502 502 503 504 504 504 507 507 507 508 510 510 510 512 513 513 513 513 514 515 515 515 516 516 517 518 518 518 518 518 518 519 520 534 553 576 580 592 600
-------
305460375
$$$TEST$$$
*/

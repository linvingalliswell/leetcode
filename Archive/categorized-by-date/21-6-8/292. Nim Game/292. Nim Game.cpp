/*
Number: 292
Topic: Nim Game
Date: 2021/6/7
Rate: Easy
https://leetcode.com/problems/nim-game/

You are playing the following Nim Game with your friend:

* Initially, there is a heap of stones on the table.
* You and your friend will alternate taking turns, and you go first.
* On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
* The one who removes the last stone is the winner.

Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.

Constraints:
* 1 <= n <= 231 - 1

*/
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }

    // suppose there are x stones left for first player (A), he can take 1,2,3 stones away, so second player B will have three cases to deal with (x -1), (x-2), (x-3). after he pick the stones, there will be 9 cases left for A.

    // B (x-1) -> A: (x-2), (x-3), (x-4)
    // B (x-2) -> A: (x-3), (x-4), (x-5)
    // B (x-3) -> A: (x-4), (x-5), (x-6)
    // Now, if A can guarantee he win at either of three groups, then he can force B to into that one of the three states and A can end up in that particular group after B's move.

    // f(x) = (f(x-2)&&f(x-3)&&f(x-4)) || (f(x-3)&&f(x-4)&&f(x-5)) || (f(x-4)&&f(x-5)&&f(x-6))
    // if we examine the equation a little closer, we can find f(x - 4) is a critical point, if f(x-4) is false, then f(x) will be always false.

    // we can also find out the initial conditions, f(1), f(2), f(3) will be true (A always win), and f(4) will be false. so
    // based on previous equation and initial conditions f(5) = f(6) = f(7) = true, f(8) = false;
    // obviously, f(1), f(2), f(3) can make all f(4n + 1), f(4n + 2), f(4n + 3) to be true, only f(4n) will be false then.
    // so here we go our one line solution:

    // return (n % 4 != 0);
};
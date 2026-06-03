// problem - Happy Number

// bruteforce | hashset | O(k) | memory O(k)
class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;

        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.count(n))
                return false;

            seen.insert(n);
            n = nextNumber(n);
        }

        return true;
    }
};

// Floyd's Tortoise and Hare Algorithm | O(1) memory
class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;

        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
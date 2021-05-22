#include <iostream>
#include <cmath>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <iterator>

bool test(int val, bool is_prime);
//bool test();

static constexpr int TEST_NUM = 10000;
static constexpr size_t MSIZE = 5;

int main()
{
    // ---------#1---------
    int a, b;
    std::cout << "Input a: ";
    std::cin >> a;
    std::cout << "Input b: ";
    std::cin >> b;
    std::cout << std::boolalpha << (a + b >= 10 && a + b <= 20) << std::endl;

    // ---------#2---------
    srand(time(NULL));
    for(size_t i = 0; i < TEST_NUM; ++i)
    {
        int val = rand() % 100000; // 0...99999
        bool is_prime = true;
        if (val <= 1 || (val != 2 && !(val % 2)))
        {
            is_prime = false;
        }
        else
        {
            int max_dev = (int)sqrt(val);
            for(int dev = 3; dev <= max_dev; dev += 2)
            {
                if(!(val % dev))
                {
                    is_prime = false;
                    break;
                }
            }
        }

        // std::cout << val << " is " << (is_prime ? "prime" : "not prime") << std::endl;
        if (!test(val, is_prime))
        {
            std::cout << "TEST FAILED!!!" << std::endl;
            break;
        }
    }

    // ---------#3---------
    const int a1 = 10;
    const int b1 = 10;
    std::cout << std::boolalpha << ((a1 == 10 && b1 == 10) || (a1 + b1 == 10)) << std::endl;

    const int a2 = 4;
    const int b2 = 6;
    std::cout << std::boolalpha << ((a2 == 10 && b2 == 10) || (a2 + b2 == 10)) << std::endl;

    const int a3 = 3;
    const int b3 = 5;
    std::cout << std::boolalpha << ((a3 == 10 && b3 == 10) || (a3 + b3 == 10)) << std::endl;

    // ---------#4---------
    int arr[MSIZE][MSIZE] = {};
    for(size_t i = 0; i < MSIZE; ++i)
    {
        for(size_t j = 0; j < MSIZE; ++j)
        {
            if(i == j || i == MSIZE - j - 1)
                arr[i][j] = 1;
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    // ---------#5---------
    for(size_t i = 0; i < TEST_NUM; ++i)
    {
        int year;
        std::cout << "Input year: ";
        std::cin >> year;
        std::cout << year << " is " << (((!(year % 4) && year % 100) || !(year % 400)) ? "Leap year" : "Normal year" ) << std::endl;
    }

    return 0;
}

bool test(int val, bool is_prime)
{
    static bool init_primes = false;
    static std::unordered_set<int> primes; // primes till 104729
    if(!init_primes)
    {
        std::ifstream in("primes.txt");
        if(in.is_open())
        {
            std::istream_iterator<int> start {in};
            std::istream_iterator<int> end;
            auto insert_it = std::inserter(primes, primes.end());
            std::copy(start, end, insert_it);
        }
        in.close();
        init_primes = true;
    }
    return (primes.find(val) != primes.end() && is_prime) || (primes.find(val) == primes.end() && !is_prime);
}

//bool test()
//{
//    std::ifstream in("primes.txt");
//    std::unordered_set<int> primes;
//    if(in.is_open())
//    {
//        int val;
//        while(!in.eof())
//        {
//            in >> val;
//            primes.insert(val);
//        }
//    }
//    in.close();
//    return true;
//}

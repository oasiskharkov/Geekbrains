#include <iostream>

static constexpr size_t MSIZE {3};

#define ODZ(val, limit) (((val) >= 0) && ((val) < (limit)))
#define PTRM(ptr, i, j) (ptr)[i][j]
#define PTR(ptr, i, j) (ptr)[(i) * MSIZE + (j)]
#define ARR(arr, i, j) *(*((arr) + (i)) + (j))
#define SIZEOF(ref, type_size) sizeof(ref) / sizeof(type_size)

int main()
{
    // ---------#1---------
    std::cout << std::boolalpha << ODZ(-1, 10) << std::endl;
    std::cout << std::boolalpha << ODZ(5, 10) << std::endl;
    std::cout << std::boolalpha << ODZ(0, 10) << std::endl;
    std::cout << std::boolalpha << ODZ(10, 10) << std::endl;
    std::cout << std::boolalpha << ODZ(15, 10) << std::endl;

    int x = 10;
    int y = 12;
    std::cout << std::boolalpha << ODZ(x - 1, y - 1) << std::endl;
    std::cout << std::boolalpha << ODZ(x + 1, y - 1) << std::endl;
    std::cout << std::boolalpha << ODZ(x * x, x * x) << std::endl;
    std::cout << std::boolalpha << ODZ(x * x, x * x + 1) << std::endl;

    // ---------#2---------
    int** m = new int*[MSIZE];
    m[0] = new int[MSIZE] {1, 2, 3};
    m[1] = new int[MSIZE] {4, 5, 6};
    m[2] = new int[MSIZE] {7, 8, 9};

    std::cout << PTRM(m, 0, 0) << std::endl;
    std::cout << PTRM(m, 0 + 1, 0 + 1) << std::endl;
    std::cout << PTRM(m, 0 + 2, 0 + 2) << std::endl;
    std::cout << PTRM(m, 0 + 2, 0) << std::endl;
    std::cout << PTRM(m, 0 + 1, 0 + 2) << std::endl;

    int* p = new int[MSIZE*MSIZE];
    for(size_t i = 0; i < MSIZE * MSIZE; ++i)
    {
        p[i] = i + 1;
    }

    std::cout << PTR(p, 0, 0) << std::endl;
    std::cout << PTR(p, 0 + 1, 0 + 1) << std::endl;
    std::cout << PTR(p, 0 + 2, 0 + 2) << std::endl;
    std::cout << PTR(p, 0 + 2, 0) << std::endl;
    std::cout << PTR(p, 0 + 1, 0 + 2) << std::endl;

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << ARR(arr, 0, 0) << std::endl;
    std::cout << ARR(arr, 0 + 1, 0 + 1) << std::endl;
    std::cout << ARR(arr, 0 + 2, 0 + 2) << std::endl;
    std::cout << ARR(arr, 0 + 2, 0) << std::endl;
    std::cout << ARR(arr, 0 + 1, 0 + 2) << std::endl;

    for(size_t i = 0; i < MSIZE; ++i)
    {
        delete [] m[i];
    }
    delete [] m;
    delete [] p;

    // ---------#3---------
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << SIZEOF(array, int) << std::endl;

    return EXIT_SUCCESS;
}

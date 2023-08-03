#include <stdio.h>

typedef struct Row { 
    int a; 
    int b; 
} Row; 

Row in[] = {{1000,20},{1000,23},{1000,16}};
Row sorted_rows[] = { { 1000, 31 }, { 1000, 72 }, { 1500, 12 }, { 1500, 34 }, { 2000, 22 },{2000,25}, { 2000, 33 }, };
Row sorted_rows_1[] = { { 1000, 31 },{1000,33}, { 1000, 72 }, { 1500, 12 }, { 1500, 34 }, { 2000, 22 },{2000,25},{2000,31}, { 2000, 33 }, {3000,11},{3000,20},{3000,31}};


/*!
    * Task 1.
    *
    * Find out all the rows that sastify below conditions: 
    *
    * ((b >= 10 && b < 50) && 
    * (a == 1000 || a == 2000 || a == 3000))
    *  
    * Print them to the terminal, one row per line, for example: 
    *
    * 1000,20 
    * 1000,23 
    * 2000,16 
    * 
    * @param nrows The total number of rows. 
    * @param rows The rows, for example rows[0] is the first row. 
    */
/*
1. rows 无序，遍历 rows，对于符合条件的，按照格式输出
*/

void task1(const Row *rows, int nrows) 
{
    for (int i = 0; i < nrows; i++)
    {
        int tmp_a = rows[i].a;
        int tmp_b = rows[i].b;

        if (((tmp_b >= 10 && tmp_b < 50) && (tmp_a == 1000 || tmp_a == 2000 || tmp_a == 3000)))
        {
            printf("%d,%d\n", tmp_a, tmp_b);
        }
    }
}

/*
1. rows 有序，从小到大
2. 当 row 中的 a 大于 3000，后面的 row 全部不符合条件，任务结束
3. 当 row 中的 a != 1000 || a != 2000 || a != 3000, 跳过，处理下一个 row
4. 当 row 中的 b >= 10 && b < 50， 按照格式输出
*/
void task2(const Row *rows, int nrows)
{
    for (int i = 0; i < nrows; i++)
    {
        int tmp_a = rows[i].a;
        int tmp_b = rows[i].b;
        if (tmp_a>3000)
        {
           return;
        }
        if (tmp_a != 1000 && tmp_a != 2000  && tmp_a != 3000)
        {
            continue;
        }
        if (tmp_b >= 10 && tmp_b < 50)
        {
            printf("%d,%d\n", tmp_a, tmp_b);
        }
    }
}

/*
1. 依据 task2 中方法找出符合条的 row，
2. 使用二维数组 result[50][3]，存储符合条件的 row, 50 用于存储 row 中 b 的值，3 用于存储相同 b 值下的 1000，2000，3000 的个数
3. 遍历 result，按照格式输出
*/
void task3(const Row *rows, int nrows)
{
    int result[50][3] = {0}; 
    for (int i = 0; i < nrows; i++)
    {
        int tmp_a = rows[i].a;
        int tmp_b = rows[i].b;
        if (tmp_a>3000)
        {
           return;
        }
        if (tmp_a != 1000 && tmp_a != 2000  && tmp_a != 3000)
        {
            continue;
        }
        if (tmp_b >= 10 && tmp_b < 50)
        {
            if (tmp_a==1000)
            {
                result[tmp_b][0] = ++result[tmp_b][0];
            }
            if (tmp_a==2000)
            {
                result[tmp_b][1] = ++result[tmp_b][1];
            }

            if (tmp_a==3000)
            {
                result[tmp_b][2] = ++result[tmp_b][2];
            }
        }
    }

    for (int i = 10; i < 50; i++)
    {
        for (int j = 1; j <= result[i][0]; j++)
        {
            printf("%d,%d\n", i, 1000);
        }

        for (int j = 1; j <= result[i][1]; j++)
        {
            printf("%d,%d\n", i, 2000);
        }

        for (int j = 1; j <= result[i][2]; j++)
        {
            printf("%d,%d\n", i, 3000);
        }
    }
}


int main(int argc, char const *argv[])
{

    // task1(in, sizeof(in)/sizeof(in[0]));
    // task2(sorted_rows, sizeof(sorted_rows)/sizeof(sorted_rows[0]));
    // task3(sorted_rows, sizeof(sorted_rows)/sizeof(sorted_rows[0]));
    task3(sorted_rows_1, sizeof(sorted_rows_1)/sizeof(sorted_rows_1[0]));
    return 0;
}

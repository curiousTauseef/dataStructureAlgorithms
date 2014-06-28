/**********************************************************************
	> File Name: insertion_sort.c
	> Author: Pero.rin
	> E-Mail: Gero.rim@gmail.com
	> Created Time: Sat 28 Jun 2014 06:36:25 PM HKT
 **********************************************************************/

/*!
 * Source code of simple insertion sort implementation using array in
 * ascending or descending order in C programming language.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 77

/* index of internal part loop, index of external part loop */
static int idx_inn, idx_ext, i_temp, i_total_elem;
/* string array use for store user input data */
static char s_user_input[MAXSIZE];
/* buffer array for disorder elements */
static long l_arr_buf[MAXSIZE];

void input_prompt(char *order)
{
        printf("\12Evaluate %s order...\12", order);
        printf("Please input total elements:\12");
        scanf("%d", &i_total_elem);

        printf("\12Please enter %d element%s Or press 'q/Q' key"
               "to leave Command-Line-Interface.. :)\12"
               , i_total_elem, (i_total_elem > 1) ? "s" : "");

        idx_ext = 0;

        while (1) {
                printf("No.%-2d integral element: ", idx_ext + 1);
                scanf("%s", s_user_input);

                if (strcmp(s_user_input, "q") == 0
                    || strcmp(s_user_input, "Q") == 0) {
                        i_total_elem--;
                        break;
                }

                l_arr_buf[idx_ext] = strtol(s_user_input, 0, 0);

                if ((idx_ext + 1) >= i_total_elem) return;

                idx_ext++;
        }
}

void output_prompt(char *order)
{
        printf("\12Array elements sorting in %s order:\12", order);

        for (idx_ext = 0; idx_ext < i_total_elem; idx_ext++)
                printf("%ld ", l_arr_buf[idx_ext]);

        putchar('\12');
        getchar();
}

void insertion_sort_desc(void)
{
        for (idx_ext = 1; idx_ext < i_total_elem; idx_ext += 1) {
                idx_inn = idx_ext - 1;
                i_temp = l_arr_buf[idx_ext];
                for ( ; i_temp > l_arr_buf[idx_inn] && idx_inn >= 0;
                     idx_inn--) {
                     l_arr_buf[idx_inn + 1] = l_arr_buf[idx_inn];
                }
                l_arr_buf[idx_inn + 1] = i_temp;
        }
}

void execute_sort(void (*sort_func)(), char *order) {
        input_prompt(order);
        sort_func();
        output_prompt(order);
}

int main(int argc, char **argv)
{
        execute_sort(insertion_sort_desc, "descending");

        putchar('\12');
        getchar();
        return 0;
}

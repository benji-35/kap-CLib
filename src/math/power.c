/*
** KAP PROJECT, 2023
** C Lib
** File description:
** power
*/

int power(int nb, int p) {
    int result = 1;

    for (int i = 0; i < p; i++)
        result *= nb;
    return result;
}

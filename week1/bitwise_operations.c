#include <stdio.h>
#include <stdint.h>

void set_bit(uint32_t *reg, uint8_t bit)
{
    *reg |= (1U << bit);
}

void clear_bit(uint32_t *reg, uint8_t bit)
{
    *reg &= ~(1U << bit);
}

void toggle_bit(uint32_t *reg, uint8_t bit)
{
    *reg ^= (1U << bit);
}

uint8_t read_bit(uint32_t reg, uint8_t bit)
{
    return (reg >> bit) & 1U;
}

int main(void)
{
    uint32_t GPIOA_ODR = 0;

    set_bit(&GPIOA_ODR, 5);
    printf("After setting bit 5: %u\n", GPIOA_ODR);

    clear_bit(&GPIOA_ODR, 5);
    printf("After clearing bit 5: %u\n", GPIOA_ODR);

    toggle_bit(&GPIOA_ODR, 3);
    printf("After toggling bit 3: %u\n", GPIOA_ODR);

    return 0;
}
